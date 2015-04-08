# Default Constructor

	C++ Standard描述：对于class X,如果没有任何user-declared constructor,那么会有一个default constructor被implicitly declared.
	explicit declared default constructor是trival constructor.

### Misunderstand

	1. 任何没有定义default constructor的class,会合成一个

	2. 编译器合成的default constructor会explicitly设定class内每一个data member的默认值

### Implicit Nontrival Default Constructor
只能满足编译器需要

	1) 带有default constructor的member class object

	2) 带有default constructor的base class

	3) 带有virtual function的class

		需要正确的初始化class object的vptr

	4) 带有virtual base class的class
	
		设置指向virtual base class的指针

### implicit trival default constructor

实际上并不被合成

