int main(object obj, string arg)
{
	LOGIN_D->tell_users(sprintf("%s: %s\n", obj->get_name(), arg));
	return 1;
}