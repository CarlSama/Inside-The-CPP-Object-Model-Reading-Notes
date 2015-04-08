#include<iostream>

using namespace std;

class _ios {
	public:
		int i;
//		virtual void show();
};
/*void _ios::show() {
	cout<<"ios"<<endl;
}*/


class _istream : virtual public _ios {
	public:
		int is;
//		virtual void show();
};
/*void _istream::show() {
	cout<<"istream"<<endl;
}*/

class _ostream : virtual public _ios {
	public:
		int os;
//		virtual void show();
};
/*void _ostream::show() {
	cout<<"ostream"<<endl;
}*/

class _iostream : public _istream, public _ostream {
	public:
		int ios;
//		virtual void show();
};
/*void _iostream::show() {
	cout<<"iostream"<<endl;
}*/

int main() {
	_ios  * iosptr = new _ios;

	_iostream *iptr = new _iostream;

	_istream *isptr = new _istream;

	_ostream *osptr = new _ostream;

	_iostream ii;
}
