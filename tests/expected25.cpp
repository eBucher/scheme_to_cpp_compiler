#include <iostream>
#include "Object.h"

using namespace std;

int main(  ) {
	Object _RetVal;
	if ((Object(9) < Object(1) )){
		cout << Object(1);
	} else {
		cout << Object(0);
	}
	cout << endl;
	return 0;
}

