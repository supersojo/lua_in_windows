/**
 * lua extension module example
 *
 */

#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

static int ext_func1(lua_State* L)
{
	return 0;
}

static int ext_func2(lua_State* L)
{
	return 0;
}

static const struct luaL_Reg func_map[] = {
    {"func1", ext_func1},
	{"func2", ext_func2},
    {NULL, NULL},
};

_declspec(dllexport)
int luaopen_lua_ext(lua_State* L)
{
    luaL_newlib(L,func_map);
    return 1;
}


