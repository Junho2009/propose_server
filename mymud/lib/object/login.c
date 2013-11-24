object logon()
{
	string str = "这是中文====";
	int len = sizeof(str);
	write(sprintf("%c", len));
	write("\n"+str);
    return this_object();
}