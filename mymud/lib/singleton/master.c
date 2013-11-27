string get_root_uid()
{
   return ROOT_UID;
}

string get_bb_uid()
{
   return BACKBONE_UID;
}

object connect(int port)
{
    object user;
    user = new(USER_OB);
    return user;
}

string creator_file(string filename)
{
    return ROOT_UID;
}

int valid_write(string file, mixed user, string func)
{
	write("============\n");
	return 1;
}