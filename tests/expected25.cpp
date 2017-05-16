#include <iostream>
#include "Object.h"

using namespace std;

int main(  ) {
	Object _RetVal;
	_RetVal = (Object(9) < Object(1) < Object(0));
	return 0;
}

