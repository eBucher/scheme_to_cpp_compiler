#include <iostream>
#include "Object.h"
using namespace std;

int main(){
	Object _RetVal;
	if ((Object(8) == Object(9))){
		cout << Object("EQUAL");
	} else {
		cout << Object("NOT_EQUAL");
	}
	return 0;
}
