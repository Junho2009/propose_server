#ifndef __GLOBALS_H__
#define __GLOBALS_H__


#define nosave static
#define protected static

#define PROTO_DELIMITER "|" // 协议中字段之间的分隔符


// paths
#define CMD_USER_PATH	"/cmds/user/"


//User IDs
#define ROOT_UID        "Root"
#define BACKBONE_UID    "Backbone"

// singletons
#define CMD_D			"/singleton/cmdd"
#define LOGIN_D			"/singleton/logind"

// features
#define F_DBASE			"/feature/dbase"

// objects
#define LOGIN_OB		"/object/login"
#define USER_OB			"/object/user"


#endif

