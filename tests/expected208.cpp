#include <iostream>
#include "Object.h"

using namespace std;

Object someString(){
	Object _RetVal;
	_RetVal = Object("here");
	_RetVal = Object("are");
	_RetVal = (Object(100) + Object(50));
	_RetVal = Object("numbers");
	return _RetVal;
}

int main(){
	Object _RetVal;
	cout << someString();
	return 0;
}

