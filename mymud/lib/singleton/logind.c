void logon(object ob)
{
	write("Welcome to Junho's propose server!\n");
	write("Please enter your name:\n");
	input_to("get_id", ob);
}

protected void get_id(string arg, object ob)
{
	tell_object(ob, "欢迎你，"+arg+"~\n");
	ob->set_temp("login_flag", 1);
	tell_object(ob, sprintf("存储用户文件，执行结果：%d\n", ob->save_object("/data/user.txt")));
}

