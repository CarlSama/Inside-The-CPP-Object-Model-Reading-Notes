## exception handle

### compiler对exception handling的支持

1.	查看throw操作是否发生在try区段

2.	compiler必须将控制流转移到与exception type吻合的catch子句

3.	如果throw并未发生在try区段,或没有catch吻合,那么必须(a)摧毁所有active local objects,(b)从堆栈中将目前函数"unwind",(c)进行到程序堆栈的下个函数中,重复2~3

## runtime type identification(RTTI)

###	dynamic_cast with pointer

dynamic_cast运算符可以在执行期决定真正的类型.
>	如果downcast是安全的,则返回转换过的指针
>	否则,返回0

#### 成本消耗

```c++
pfct pf = dynamic_cast<pfct>(pt);
```
1.	pfct的类型描述符会被编译器产生

2.	获取pt的类型描述符
>	((type_info*)(pt->vptr[0])) -> _type_descriptor

3.	这两个类型描述符被交给runtime library函数,查看是否吻合

###	dynamic_cast with reference 

如果reference并不是derived class,由于不能传回reference to no object, 因此抛出bad_cast exception

#### 实现

```c++
try{
	fct & rf = dynamic_cast<fct&>(rt);
	...
}catch(bad_cast){
	...
}
```

### typeid

```c++

if( typeid(rt) == typeif(fct) ){
}

```


