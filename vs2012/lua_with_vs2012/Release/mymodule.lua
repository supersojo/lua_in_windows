--
-- test lua module
--


local mymodule = {}

local function foo()
    print('foo')
end
local function bar()
    print('bar')
end

local meta = {
['name']='mymodule',
['type']='module'
}

mymodule.meta = meta
mymodule.foo = foo
mymodule.bar = bar

return mymodule