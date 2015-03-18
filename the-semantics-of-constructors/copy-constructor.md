##

### 安全性

memory leak ?

address aliasing ?

### 应用场景

1.	初始化
2.	作为参数
3.	作为返回值

### nontrival copy constructor

class展现出bitwise copy semantics

#### bitwise copy semantics

ptr = c.ptr// 指向同一个内存空间

#### memberwise copy semantics

1.	class内含member object,后者声明中有copy constructor
2.	class继承base class,后者存在一个copy constructor 

需要保证vtbl的正确性的情况：
3.	class声明virtual function

4.	class派生于virtual base class
> 当同类型拷贝时，vtbl信息相同，可以bitwise
> 当class object以其derived class的某个object作为初值时，需要memberwise

### member initialization list

#### must use

1.	初始化reference member时

2.	初始化const member时

3.　调用base class的constructor,而它有参数

4.	调用member class的constructor,而它有参数

如果放在函数体内，会产生临时对象，影响效率．

##### 反思

```c++
class Word{					
	String str;
public:
	Word(){																
		str = 0;			str.String::String();
							String tmp(0);
							str.operator = (tmp);
							tmp.String::~String();
	}
};
```

使用initialization list
```c++
class Word{
	String str;
public:
	Word() : str(0){}		Word(){
								str.String::String(0);
							}
};
```

编译器会一一操作initialization list, 以**类内声明的顺序**安插初始化操作，并放置在explicit user code前．
> j(val),i(j)的错误

可以使用member function来设定member的初值
> 此时this指针已经构建完成







