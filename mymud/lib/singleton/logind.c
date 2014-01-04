nosave mapping users = ([]);

nosave int cur_user_id = 0;
nosave int* free_userid_list = ({});


void tell_users(string str)
{
	mixed *value_list = values(users);
	mixed value;

	foreach(value in value_list)
	{
		tell_object(value, str);
	}
}

void logon(object ob)
{
	string user_name;
	int user_id;

	if (0 == sizeof(free_userid_list))
	{
		user_id = ++cur_user_id;
	}
	else
	{
		user_id = free_userid_list[0];
		free_userid_list -= ({free_userid_list[0]});
	}

	user_name = sprintf("user%d", user_id);
	ob->set_name(user_name);
	users[user_name] = ob;

	tell_users(user_name+"进入了系统，大家热烈欢迎！\n");
}

void logout(object ob)
{
	int user_id = 0;

	map_delete(users, ob->get_name());

	sscanf(ob->get_name(), "user%d", user_id);
	free_userid_list += ({user_id});
}

mapping get_users()
{
	return users;
}