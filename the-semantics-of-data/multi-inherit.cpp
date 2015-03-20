#include<iostream>

using namespace std;

class X{
	public:
	int a;
};

class Y :public virtual X{
	public:
		int b;
};

class Z : public virtual X	{
	public:
		int c;
};

class K: public Y,public Z{
	public:
		int d;
		int f;
		int g;
};

int main(){
	K* kptr = new K;
	cout<<(&(kptr->d))<<endl;
	cout<<(&(kptr->f))<<endl;
	cout<<(&(kptr->g))<<endl;
/*	Y* yptr = kptr;
	X* zptr = kptr;
	cout<<(&(yptr->a))<<endl;
	cout<<(&(zptr->a))<<endl;*/
}

