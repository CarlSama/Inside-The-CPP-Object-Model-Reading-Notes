##

### pure virtual function

虚基类中必须定义destructor

虚基类可以定义其纯虚函数,子类只能通过静态的方式调用

### Plain OI Data

在C++中,trival constructor,trival destructor,trival copy constructor, trival copy assign operator可能不会被定义,调用

#### 全局多次声明

在C中,全局未初始化对象被视为"临时定义",一个"临时定义"可以在程序中发生多次,会被链接器折叠起来,只留下单独实例,存放在BSS段.
> Point global;
> block start by symbol

在C++中,因为class有隐式构造的原因,不支持"临时定义",global会当做完全定义,编译器会阻止第二或更多的定义.

### trival

对于只有built-in type的类,不需要定义copy constructor或copy constructor,因为default bitwise semantics足够用.

不需要提供destructor,因为默认的内存管理足够.

### 继承带来的

在类中包含virtual function时

1.	每个class object多包含一个vptr

2.	constrctor会增加代码来初始化vptr

3.	合成copy constructor和copy assign operator,其操作不再是trival

### 虚继承

```c++
		    Point
	Point3d		  Vertex
		  Vertex3d
		  PVertex


Point3d* Point3d::Point3d(									Point3d* Point3d::Point3d(
		Point3d *this, ...){										Point3d *this, bool __most_derived, ...)
	this->Point::Point(x, y);									if(__most_derived != false){
																	this->Point::Point(..);//由最深对象负责
																}
	this->_vptr_Point3d = _vtbl_Point3d;						this->_vptr_Point3d = _vtbl_Point3d

	...															...
}															}
```








