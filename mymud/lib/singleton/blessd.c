inherit F_DBASE;
inherit F_SAVE;


// 协议头
nosave int PROTO_HEAD_RECV_BLESS = 13141;
nosave int PROTO_HEAD_BLESS_INFO = 13142;

nosave int BLESS_NUM_PER_PAGE = 20;


int count = 0;
int total_page = 0;
string *blesses = ({});


string query_save_file();
void blesses_broadcast(object* bless_list);


void create()
{
    if (0 != restore())
        count = sizeof(blesses);
    else
        count = 0;
    total_page = count / BLESS_NUM_PER_PAGE;
    write(sprintf("载入祝福数据，总条目：%d\n", count));
}

int add_bless(object sender, string content)
{
    string author_name;
    string msg;
    object bless;
    string bless_save_str;
    object tmp_bless;

    sscanf(content, "%s|%s", author_name, msg);
    bless = new(BLESS_OB);
    bless->init(author_name, msg, time());

    bless_save_str = bless->get_save_str();
    blesses += ({bless_save_str});
    ++count;
    total_page = count / BLESS_NUM_PER_PAGE;
    save();

    return 1;
}

void query_bless_info(object receiver)
{
    string info = sprintf("%d|%d\n", count, total_page);
    tell_object(receiver, info);
}

void send_blesses(object receiver, int page)
{
    //
}

void blesses_broadcast(object* bless_list)
{
    object bless;
    string broadcast_strlist = "";

    foreach (bless in bless_list)
    {
        broadcast_strlist += sprintf("%d|%s|%s|%d\n", PROTO_HEAD_RECV_BLESS, bless->author_name(), bless->msg(), bless->send_time());
    }
    LOGIN_D->tell_users(broadcast_strlist);
}

string query_save_file()
{
    return COMMON_SAVE_PATH + "blesses";
}

void handle_protos(object user, string proto)
{
    int head = 0;
    string content = "";

    sscanf(proto, "%d|%s", head, content);

    if (PROTO_HEAD_RECV_BLESS == head)
        add_bless(user, content);
    else if (PROTO_HEAD_BLESS_INFO == head)
        query_bless_info(user);
}