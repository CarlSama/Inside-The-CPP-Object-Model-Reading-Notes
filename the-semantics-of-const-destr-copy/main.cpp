#include<iostream>

using namespace std;

class Abstruct_base {
	public:
		virtual ~Abstruct_base() = default;

		virtual void interface() const = 0;

		//virtual const char * mumble () const{
		virtual const char * mumble () const{
			return _mumble;
		}//因为之后不会被盖写,所以不用做virtual 

	protected:
		Abstruct_base(char *pc = 0) : _mumble(pc) {}
		//增加constructor给基类使用
		char * _mumble;
};

void Abstruct_base::interface() const {
	int i = 0;
}

class Concrete_derived : public Abstruct_base {
	public:
		void interface() const;
};

void Concrete_derived::interface() const{
	Abstruct_base::interface();//只能invoked statically
	int i = 10;
}
		
int main(){
}

