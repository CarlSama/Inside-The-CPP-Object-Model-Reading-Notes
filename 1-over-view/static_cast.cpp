#include<iostream>

using namespace std;
class Base{
	public:
		Base(){
			i = 1;
		}
		virtual void show(){
			cout<<"base"<<endl;
		}
		int i;
		char c;
};

class Derived : public Base{
	public:
		Derived(){
			j = 10;
		}
		//virtual void show(){
		void show(){
			cout<<"Derived"<<endl;
		}
		int k;
		char c;
		int j;
};

class empty{
	int i;
	char c;
	char c2;
};
int main(){
/*	cout<<sizeof(int)<<endl;
	cout<<sizeof(empty)<<endl;
	empty e;
	empty e2;
	cout<<&e<<endl<<&e2<<endl;*/

	//When using static_cast 
	//		the compiler wouldn't do any vptr modification for object
	//		it's just a new attitude to explain the pointer.
	

	//derived class to base class 
	//the ptr can only have offset information of base class,
	//  ,BUT the virtual function haven't been changed...
	//  SO, it would leads to derived class's virtual function :)
	Derived derived;
	Base* ptr = static_cast<Base*>(&derived);
	ptr->show();
	cout<<(sizeof(Derived))<<endl;

	//the Base pointer of ptr can only access the subobject
	//	ptr->j = 10;

	//when we convert base ptr to derived class ptr
	//the ptr can obtain the offset information of derived class(because it's a derived class ptr now !)
	//	,which means we can access the derived class data member
	//	BUT this data is unproper initialized !
	Base base;
	Derived* ptr2 = static_cast<Derived*>(&base);
	ptr2->show();


	//Memory alignment and awkward explination
	
}

