object logon()
{
	string str = sprintf("%d%s%s%s%d%s%s", 1000, PROTO_DELIMITER, "abcdefg", PROTO_DELIMITER, 12345, PROTO_DELIMITER, "end");
	tell_object(this_object(), str);

    return this_object();
}