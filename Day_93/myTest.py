#!/usr/bin/python

import MyPyLib
print("MyPyLib.myMessage() ->", MyPyLib.myMessage())
print("MyPyLib.myAdd ->",MyPyLib.myAdd(3,4))

ml = MyPyLib.MyClass("This is John Test Class constructor")
print("name =",ml.name)
ml.name = "RE-Assign Message"
print("name =",ml.name)

ml.Set(17.3)
print("Get() 17.3 ->",ml.Get())
