#include<iostream>
#include<sys/time.h>
#include<new>

using namespace std;

class Base{
	public:
		void test(){
			cout<<"base"<<endl;
		}
};

class Nrv : public Base{
	friend Nrv test(double);
	public:
		Nrv(){
			try{
				array = new double[100];
			}catch(bad_alloc ba){
				cout<<"bad_alloc"<<endl;
			}
		}
		
		void test(){
			cout<<"nrv"<<endl;
		}

		double *array;
};

Nrv test(double d){
	Nrv local;
	local.array[0] = d;
	local.array[99] = d;

	return local;
}

int main(){
	{
		struct timeval tvs,tve;
		gettimeofday(&tvs,NULL);
		//for(int c=1;c<0xff;c++){
			for(int cnt=1;cnt<0xfffff;cnt++){
				//Nrv nv = test(static_cast<double>(cnt));
				Nrv nv = test((double)(cnt));
			}
		//}
		gettimeofday(&tve,NULL);
		double duration = tve.tv_sec - tvs.tv_sec + (tve.tv_usec - tvs.tv_usec) / 1000000.0;
		cout<<duration<<endl;
	}

}
