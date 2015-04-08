# Copy Constructor

以一个class object作为另一个class object的初始值.

### 应用场景

	1.	initialization
	2.  used as parameter	
	3.	used as return value

### C++ Standard

	就像default constructor一样,C++ Standard上说,如果class没有声明copy constructor,就会implicitly declared or implicitly defined.

	C++ Standard也将copy constructor区分为trival和nontrival.之后nontrival的实例才会被synthesis.

	copy constructor trival     <--->    class展现出bitwise copy semantics.

##### Bitwise Copy Semantics可能带来的问题

	ptr = c.ptr// 指向同一个内存空间
			   // address aliasing

##### Memberwise Copy Semantics

1.	class内含member object,后者声明中有copy constructor

2.	class继承base class,后者存在一个copy constructor 

3.	class声明virtual function
>widget.flip() -> ( pointer->vptr[1] )( pointer ) 

4.	class派生于virtual base class
> 编译器有责任维护virtual base class subobject位置的完成性

Situation 3, 4中:
> 构造函数里增加了vtbl和vptr.
> 当同类型拷贝时，vtbl信息相同，可以bitwise(vptr vtbl相同)
> 当以derived class object来初始化base class object时，需要memberwise(需要合理的设定vptr)

