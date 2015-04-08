#include<iostream>
#include<sys/time.h>
#include<new>
#include<cstring>

using namespace std;

/*
 * In my test, the performance declined when using  NRV
 *
 * Why this ?
 */
double global[1000] = {1,2,3};


class Nrv {
	friend Nrv test(double);
	public:
		Nrv(){
			memcpy(this,global,1000 * sizeof(double) );
		}

		/*
		 * we need copy constructor to activate nrv
		 */
/*		Nrv(const Nrv& nrv) {//需要copy constructor来辅助nrv
			memcpy(this,&nrv,1000 * sizeof(double) );
		}
*/
		double array[1000];
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

		for(int cnt=1;cnt<0xffffff;cnt++){
			Nrv nv = test((double)(cnt));
		}

		gettimeofday(&tve,NULL);
		double duration = tve.tv_sec - tvs.tv_sec + (tve.tv_usec - tvs.tv_usec) / 1000000.0;
		cout<<duration<<endl;
	}

}
