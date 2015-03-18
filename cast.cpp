#include<iostream>

using namespace std;

class BaseClass{
	public:
		void test(){
			cout<<"base tes"<<endl;
		}
		virtual void func(){
			cout<<"base"<<endl;
		};
		int i;
};

class SonClass: public BaseClass{
	public:
		static void modify(){
			//k = 1;
		}			
		void test(){
			cout<<"son tes"<<endl;
		}
		virtual void func(){
			cout<<"son"<<endl;
		};

		int j = -1;
		char c = 'a';
//		static int k;
};

//int SonClass::k = 10;

int main(){
	cout<<sizeof(SonClass)<<endl;
	BaseClass base;
	BaseClass *bptr = &base;
	cout<<"Use it as base :"<<endl;
	cout<<"orig pos: "<<bptr<<endl;
	//bptr->j;
	bptr->test();
	bptr->func();


	cout<<endl;
	cout<<"Use it as son :"<<endl;
	//SonClass *sptr1 = static_cast<SonClass*>(&base);
	SonClass *sptr1 = &base;
	cout<<"static cast: "<<sptr1<<endl;
	sptr1->test();
	sptr1->func();
	cout<<(sptr1->j)<<endl;
//	cout<<(sptr1->k)<<endl;
	sptr1->j =10;
//	sptr1->k = 100;
	cout<<"j pos : "<<(&(sptr1->j))<<endl;
//	cout<<"k pos : "<<(&(sptr1->k))<<endl;

	sptr1->modify();

	SonClass *sptr2 = dynamic_cast<SonClass*>(bptr);
	cout<<"dynamic cast: "<<sptr2<<endl;
}
