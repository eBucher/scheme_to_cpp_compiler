#include <iostream>
#include "Object.h"

using namespace std;

int main(){
	Object _RetVal;
	_RetVal = (Object(1) + Object(2));
	cout << Object("end_of_main");
	return 0;
}
