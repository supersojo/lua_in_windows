#include <stdio.h>
#include "lauxlib.h"
#include "lua.h"
/* one function called by lua interpreter */
static int foo (lua_State *L)
{
	int arg1;
	int arg2;
	int sum;

	arg1 = lua_tointeger(L,1);
	arg2 = lua_tointeger(L,2);

	sum = arg1+arg2;
	printf("%d %d\n",arg1,arg2);

	//只需结果压栈lua会调整到合适的位置
	lua_pushinteger(L,sum);
	return 1;
}
/*
lua bytecode
*/
int main()
{
	int idx;

	// new lua virtual machine
	lua_State* L = luaL_newstate();

	// call lua vm
	lua_pushcfunction(L,foo);
	lua_pushinteger(L,2);
	lua_pushinteger(L,4);

	lua_pcall(L,2,1,0);
	printf("%d\n",lua_tointeger(L,1));

	//restore stack
	lua_pop(L,1);


	// call load lua script
	luaL_dofile(L, "D:\\projects\\lua\\vs2012\\lua_with_vs2012\\Release\\luafile.lua");
#if 0
	// call lua function 计算两个数的和
	lua_getglobal(L, "LuaFunc");
	lua_pushinteger(L,4);
	lua_pushinteger(L,8);

	lua_pcall(L, 2, 1, 0);
	
	//print result
	printf("%d\n",lua_tointeger(L,1));

	//restore stack
	lua_pop(L,1);
#endif
	lua_getglobal(L, "i");

	lua_getglobal(L, "j");

	lua_getglobal(L, "t");

	printf("%d\n",lua_tointeger(L,1));
	printf("%d\n",lua_tointeger(L,2));
	lua_rawgeti(L,3,1);
	lua_rawgeti(L,3,2);
	//
	printf("%s\n",lua_tostring(L,lua_gettop(L)));
	printf("%s\n",lua_tostring(L,lua_gettop(L)-1));
	lua_close(L);
	return 0;
}