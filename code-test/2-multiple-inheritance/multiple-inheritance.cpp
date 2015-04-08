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

class OtherBase{
	public:
		int oa;
		virtual void show();
};
void OtherBase::show(){
	cout<<"OtherBase"<<endl;
}

class Final : public OtherBase,public Inheri{
	public:
		virtual void show();
};
void Final::show() {
	cout<<"Final"<<endl;
}

int main() {
	Final *fptr = new Final;
	OtherBase *optr = fptr;
	optr->show();

	Inheri *iptr = fptr;
	iptr->show();

	Inheri inhe1;
	Inheri* iptr1 = & inhe1;
}
