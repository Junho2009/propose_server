int do_cmd(object me,string verb,string arg)
{
	return(CMD_USER_PATH+verb)->main(me,arg);
}