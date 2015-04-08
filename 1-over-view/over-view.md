# 

## 标准化

C++对象模型没有标准化
> virtual function calls一般是通过virtual tables（内含virtual functions的地址）的索引而获得。一定要有virtual tables吗？不，编译器可以自由引进其他做法。如果使用virtual tables，那么布局，存取方法，产生时机等细节都需可以订制。
> 目前大多数编译器对virtual functions的实现都是使用**各个class专属**，**大小固定**，**程序执行前构造**。

## nm指令

nm列举obj文件中的符号。

# OBJECT

member function虽然包含在class声明中，但是不出现在object里．每个non-inline member function只会有一个实例．

## C++带来的负担
Ｃ++在布局和存取时间上**主要额外负担**由**virtual**引起.
derived class和其base clasｓ之间的转换也会造成负担．


## Stroustrup对象模型

### member

class data member

1. static (object外)

2. nostatic (object内)

class member function

1. static (object外)

2. nonstatic (object外)

3. virtual
	1. 每个class产生一堆指向virtual function的指针，放置在virtual table(vtbl)中
	> 每个类关联的type_info（用以支持RTTI)也存放在vtbl中.

	2. 每个obj拥有一个指向vtbl的指针(vptr),	
	> vptr的setting和resetting都由constructor,destructor,copy assignment自动完成．

### space

class object的大小

1.	nonstatic data member的总和

2.	aligment造成的padding

3.	支持virtual而内部产生的overhead

虚函数声明后要定义，不然＂对‘vtable for xxxx’未定义的引用＂

虚继承中，base class无论被derived了多少次，只会存在一个subobject.
> iostream中只有一个virtual ios base class的subobject


### 内部转换

```C++
X foobar(){								void foobar(X &_res){
	Ｘ xx;									_res.X::X();//res取代xx
	X* ptr = new X;							ptr = operator new(sizeof(X));//申请空间
											if(ptr)
												ptr->X::X();//构造对象

	//foo is virtual function			
	xx.foo();								foo(_res);
	ptr->foo();								(*ptr->vtbl[2])(ptr);//ptr代表this指针
													
	delete ptr;								if(ptr){
												(*ptr->vtbl[1])(ptr);//析构函数
												operator delete(ptr);//释放空间
											}
	return xx;								return;
}										}
```

### 内存布局

1.	C++中处于同一access section的数据，必定保证以其声明顺序出现在内存布局中．
	然而多个section中的数据，排列顺序未定.

2.	base class和derived class的data member的布局也没有强制规定.


## Programming Paradigms

1. procedural model.

2. abstract data type model (ADT).

3. object-oriented model. 

## 多态

C++的多态只存在于public class体系中．有以下的方法支持多态：

1.	经隐式的转换．例如derived class指针转换为public base class指针

2.	virtual function机制

3.	dynamic_cast和typeid运算符

多态的主要用途是经共同接口来影响系统，这个接口被定义在抽象的base class中．

pointer或reference之所以支持多态，因为它们不引发内存中任何type-dependent commitment;会改变的只是所指向内存的**大小和解释方式**

