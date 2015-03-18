#include<iostream>

using namespace std;

class X{};

class Y : public virtual X{};

class Z : public virtual X{};

class K : public Y ,public Z{
};

class A{
	public:
		A() = default;
		int a = 1;
		int b = 2;
};

class B : public A{
	public:
		int c = 3;
		B& operator += (const A& a){
			a = a.a;
			b = a.b;
			c = a.c;
		}
}

int main(){
	cout<<sizeof(X)<<endl;
	cout<<sizeof(Y)<<endl;
	cout<<sizeof(Z)<<endl;
	cout<<sizeof(K)<<endl;

	A a;
	cout<<(&a)<<endl;
	cout<<(&a.a)<<endl;
	cout<<(&a.b)<<endl;

	B b;
}
