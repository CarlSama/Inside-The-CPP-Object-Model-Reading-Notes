##

### explicit initialization

```c++
X x0;				X x0;

X x1(x0);			X x1;
					x1.X::X(x0);//copy constructor X::X(const X& x)
```

### argument initialization

```c++
					X _temp0;
X xx;				X xx;	
					_temp0.X::X(xx); // copy constructor

foo(xx);			foo(_temp0);
					_temp0.X::~X();
```
需要修改foo的形参为**引用类型**

### return value initialization

在cfront中，是在参数列别中添加引用类型的返回对象．

```c++
X bar(){				void bar(X & _result){
	X xx;					X xx;
							_result.X::X();
							
							_result.X::~X();
	return xx;				return ;
}
```
例子:
	bar().func();	==>		X _tmp0;
							(func(_tmp0), _tmp0).func();

这种编译优化也称为Named Return Value(NRV).

### copy constructor 何时需要？

在编译器提供nrv优化时，提供copy constructor的explicit inline函数实例．

```c++
Point::Point(const &Point p){
	x = p.x;								memcpy(this, &p, sizeof(Point);//更高效
	y = p.y;
}
```

上述的转换只有在class不含任何编译器内部产生的member时有效．如果含有virtual functions或virtual base class，则上述函数会导致**编译器内部产生的member**的初值被修改．


