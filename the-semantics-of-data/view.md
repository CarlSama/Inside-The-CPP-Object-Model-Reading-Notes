##

### sizeof

```c++
class X{};
class Y : public virtual X{}
class Z : public virtual X{}
class K : public Y, public Z{}
```

1.	sizeof X == 1

2.	sizeof Y == 4/8
>	当语言支持virtual base class时，在derived class中，存在vptr．

3.	sizeof Z == 8/16
>	


#### 原因

1.	编译器在内存中放置char的占位符,这样两个Ｘ object有不同地址

2.	编译器对特殊情况的优化．virtual base class X subobject的1 bytes出现在derived class的尾端．某些编译器提供特殊支持,对于empty virtual base class,不占用１char.

3.	alignment

### member的排列

Ｃ++ Standard 要求同一个access section中，member的排列只需符合＂较晚出现的member在object中有较高的地址＂
>	不需要连续排列

允许编译器将内部产生的member放置在任何位置

允许多个access section中data member自由排列

derived class members 和 base class members的排列顺序不强制

### data member的存取

#### static data member

存放在data segment中,有唯一实例,通过name-mangling来避免冲突.
> C++中通过pointer和object来存取对象完全相同

#### nonstatic data member

直接存放在object中
> 在member function中直接处理nonstatic data member,会发生implict class object(this)

C++ 保证出现在derived class中的base class subobjec有其完整的原样性.
> char + padding + char(两个char不同类)
> 不然不同层赋值有问题

:wq



