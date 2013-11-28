inherit F_DBASE;


void logon(object ob)
{
	tell_object(ob, "Welcome to Junho's propose server!\n");
	tell_object(ob, "Please enter your name:\n");
	input_to("get_id", ob);
}

void tell_users(string str)
{
	mixed *value_list = values(dbase);
	mixed value;

	foreach(value in value_list)
	{
		tell_object(value, str);
	}
}

protected void get_id(string user_name, object ob)
{
	object old_ob;

	old_ob = query(user_name);
	if (0 != old_ob)
	{
		tell_object(old_ob, "你的账号已在别处登录，你被迫下线。\n");
		destruct(old_ob);
		delete(user_name);
	}

	ob->set("name", user_name);
	this_object()->set(user_name, ob);
	tell_object(ob, sprintf("欢迎你，%s\n", user_name));

	ob->set_temp("login_flag", 1);
	ob->save();

	tell_users(user_name+"进入了系统，大家热烈欢迎！\n");
}

