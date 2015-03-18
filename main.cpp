#include<iostream>
#include<cstdio>

using namespace std;

class X{
	public:
		int i : 1;
};

class Y : public virtual X{
	public:
		int j : 2;
};

class Z : public virtual X{
	public:
		int k : 3;
};

class Point : public Y, public Z{
	public:
		int z : 4;
};

class String{
	public:
		String(char *c,int l):ch(c),len(l){
			cout<<"oo"<<endl;
		}
		char * ch;
		int len;
};

int main(){
	char *c = new char[10];
	String str(c,1);
	String nstr = str;

	delete str.ch;
	delete nstr.ch;


	Poin* ptr = new Point;
	cout<<(ptr->i)<<endl;
	cout<<(ptr->j)<<endl;
	cout<<(ptr->k)<<endl;
	cout<<(ptr->z)<<endl;

}
