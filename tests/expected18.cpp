#include <iostream>
#include "Object.h"
using namespace std;

Object domath( Object a, Object b ){
	Object _RetVal;
	cout << (Object(a) + Object(b));
	cout << endl;
	return _RetVal;
}

int main(){
	Object _RetVal;
	_RetVal = domath(Object(0),Object(-8));
	return 0;
}
