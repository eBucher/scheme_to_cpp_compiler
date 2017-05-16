#include <iostream>
#include "Object.h"

using namespace std;

int main(  ) {
	Object _RetVal;
	if( listop("car", Object("(1 2 3 4)")) < Object(2)){
		_RetVal = Object("(1 2 3)");
	} else {
		_RetVal = Object("(4 5 6)");
	}
	return 0;
}


