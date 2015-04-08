#include<iostream>

using namespace std;

class Alignment {
	public:
//		long long ll;
//		int i;
		short s;
		char c;
};

class Between {
	long long ll1, ll2;
	char c;
};

int main(){
	//The alignment in class is related to the biggest type
	//The result would alignment to its edge 
	cout<<"The size of long long is : "<<sizeof(long long)<<endl;
	cout<<"The size of int is : "<<sizeof(int)<<endl;
	cout<<"The size of short is : "<<sizeof(short)<<endl;
	cout<<"The size of char is : "<<sizeof(char)<<endl;
	cout<<"The size of Alignment is : "<<sizeof(Alignment)<<endl;

	//The alignment between class
	cout<<"The size of Between is : "<<sizeof(Between)<<endl;
	//0) in array
	//		one closely by one
	Between arr[2];
	cout<<"The first elem locate in : "<<&arr[0]<<endl;
	cout<<"The sec elem locate in :"<<&arr[1]<<endl;
	cout<<"The distance in arr is :"<<((unsigned long long)&arr[1] - (unsigned long long)&arr[0])<<endl;
	//1) not in array
	//		would be adjuct to the edge to 16/8(64 bit or 32 bit) 
	Between b1,b2;
	cout<<"The first elem locate in : "<<&b1<<endl;
	cout<<"The sec elem locate in :"<<&b2<<endl;
	cout<<"The distance is :"<<((unsigned long long)&b2 - (unsigned long long)&b1)<<endl;


}


