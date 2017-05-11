#include <iostream>
#include "Object.h"
using namespace std;

int main(){
	Object _RetVal;
	if(numberp(Object(4))){
		cout << "is_a_number";
	} else {
		cout << "is_not_a_number";
	}
	cout << endl;
	if (stringp(Object(4))){
		cout << "is_a_string";
	}
	cout << endl;
	return 0;
}
