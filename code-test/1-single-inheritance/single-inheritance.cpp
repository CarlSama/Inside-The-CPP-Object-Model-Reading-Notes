#include<iostream>
using namespace std;

class Base {
	public:
		int a = 21;
		static int b;
		int c = 22;

		virtual void show();//inline
};
int Base::b = 10;
void Base::show() {
	cout<<"Base"<<endl;
}

class Inheri : public Base {
	public:
		int c = 23;
		static int d;

		 virtual void show();
};
int Inheri::d = 11;
void Inheri::show(){
	cout<<"Inheri"<<endl;
}

int main() {
	Inheri inhe;
	Inheri* iptr = & inhe;
	Base base;
	Base* bptr = & base;
	Base* bbptr = new Inheri;
	Inheri inhe1;
	Inheri* iptr1 = & inhe1;
}
