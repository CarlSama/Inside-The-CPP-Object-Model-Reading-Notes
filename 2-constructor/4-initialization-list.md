# Member Initialization List

### Must Use

1.	初始化reference member时

2.	初始化const member时

3.  调用base class的constructor,而它有参数

4.	调用member class的constructor,而它有参数

如果放在函数体内，会产生临时对象，影响效率．

### Using or not 

```c++
class Word{					
	String str;
public:
	Word(){																
							str.String::String();//需要temporary object
		str = 0;			String tmp(0);
							str.operator = (tmp);
							tmp.String::~String();
	}
};

class Word{ // using initialization list
	String str;
public:
	Word() : str(0){}		Word(){
								str.String::String(0);
							}
};
```

### Attention 

1. 编译器会一一操作initialization list, 以**类内声明的顺序**安插初始化操作，并放置在explicit user code前．
> j(val),i(j)的错误

2.可以使用member function来设定member的初值
> 此时this指针已经构建完成
```c++
X::X(int val)						X::X(X * const this , int val) {
	: i (func(val) ),j (val) {			i = this -> func(val);
										j = val;
	}								}
```
