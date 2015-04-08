#include<iostream>
using namespace std;

class Animal {
	public:
		//Animal() = default;
		//virtual ~Animal() = default;
		Animal() {};
		virtual ~Animal() {};
		virtual int get_age(){};
	protected:
		int age;
		string name;
};

class Bear : public Animal{	
	public:
		//Bear() = default;
		//virtual ~Bear() = default;
		Bear() {};
		virtual ~Bear() {};
		virtual int get_age(){};
		virtual void number(){};
		void show(){
			cout<<"ok"<<endl;
		}
	protected:
		int num;
};

int wuboya;

int main() {
	Bear* prt = NULL;
	ptrt->show();

	//check memory layout 
	Animal ani;
	Bear bear;

	//using static cast
	//check memory layout
	Bear* scptr = static_cast<Bear*>(&ani);

	//using dynamic cast
	//check memory layout
	Bear* dcptr = dynamic_cast<Bear*>(&ani);
}



