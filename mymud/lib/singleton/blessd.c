inherit F_DBASE;
inherit F_SAVE;


int count = 0;
string *blesses = ({});

string query_save_file();
int save();


void create()
{
    if (0 != restore())
        count = sizeof(blesses);
    else
        count = 0;
    write(sprintf("载入祝福数据，总条目：%d", count));
}

int add_bless(string content)
{
    string author_name;
    string msg;
    object bless;
    string bless_save_str;
    object tmp_bless;

    write(content+"\n");
    sscanf(content, "%s|%s", author_name, msg);
    bless = new(BLESS_OB);
    bless->init(author_name, msg, time());

    bless_save_str = bless->get_save_str();
    blesses += ({bless_save_str});
    ++count;
    save();

    tmp_bless = new(BLESS_OB);
    write("目前收到的祝福：\n");
    foreach(bless_save_str in blesses)
    {
        tmp_bless->update(bless_save_str);
        write(sprintf("%s发来祝福：%s\n", tmp_bless->author_name(), tmp_bless->msg()));
    }

    return 1;
}

string query_save_file()
{
    return COMMON_SAVE_PATH + "blesses";
}

