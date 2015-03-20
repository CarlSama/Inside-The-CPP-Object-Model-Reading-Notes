##

###	functions

####	nonstatic member function

C++的设计原则之一是:nostatic member function至少必须和一般的nonmember function有相同的效率.

```C++
Point3d Point3d::normalize() const{			void Point3d::normalize_7Point3dFv(
														const Point3d *const this, Point3d &res){

	Point3d normal;								_res.Point3d::Point3d();

	normal.x = x/mag;							_res.x = this->x_7Point3d / mag;

	return normal;								return ;
}											}
```

name mangling + NRV + this

##### name mangling

member的名称会在前面加上class的名字,形成独一无二的命名.

####	virtual member function

```c++

ptr-> normalize();								( *(ptr->vptr[1]) )(ptr);//ptr赋值this指针

```

####	static member function

```c++

obj.normalize();								normalize_7Point3dSFv();

ptr->normalize();								normalize_7Point3dSFv();

```

1.	没有this指针
> 无法访问class中nostatic member

2.	不能被声明为const, volatile或 virtual

3.	不需要经class object调用

		

