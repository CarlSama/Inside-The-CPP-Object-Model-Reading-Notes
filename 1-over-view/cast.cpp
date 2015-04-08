#include<iostream>

using namespace std;

class Base {
	public:
		int i;
};

class Base2 {
	public:
		int k;
};

class Derived : public Base , public Base2{
	public:
		long long j;
};

class vBase {
	public:
		virtual void show(){}
		int i;
};

class vBase2 {
	public:
		virtual void show(){}
		int k;
};

class vDerived : public vBase , public vBase2{
	public:
		virtual void show(){}
		long long j;
};
int main(){
	Derived derived;
	cout<<"The address of derived object is :"<<&derived<<endl;
	Base base;
	cout<<"The address of base object is :"<<&base<<endl;
	/*
	 * Derived class to Base class
	 */

	/*
	 *	Without virtual machinizm
	 *
	 1) to the left most class or not
		Same address remained !	Just different way to explian ptr
	*/
	Base* bptr = &derived;
	cout<<"The address of ( Derived -> base ) is :"<<bptr<<endl;
	Base2* b2ptr = &derived;
	cout<<"The address of ( Derived -> base2 ) is :"<<bptr<<endl;

	/*
	 *	With virtual machinizm
	 *
	 1) to the left most class 
		Same address remained !	Just different way to explian ptr
	 2) other
		Changed !
	*/
	vDerived vderived;
	cout<<"The address of vDerived is :"<<&vderived<<endl;
	vBase* vbptr = &vderived;
	cout<<"The address of ( vDerived -> vbase ) is :"<<vbptr<<endl;
	vBase2* v2bptr = &vderived;
	cout<<"The address of ( vDerived -> vbase2 ) is :"<<v2bptr<<endl;


}
