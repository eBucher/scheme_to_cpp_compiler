#include <iostream>
#include "Object.h"
using namespace std;

int main(){
	Object _RetVal;
	cout << (Object(100) / Object(5) / Object(10) / Object(2) / Object(1));
	cout << endl;
	return 0;
}
