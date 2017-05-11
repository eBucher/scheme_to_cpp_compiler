#include <iostream>
#include "Object.h"
using namespace std;

int main(){
	Object _RetVal;
	if(numberp(Object(4))){
		cout << Object("is_a_number");
	} else {
		cout << Object("is_not_a_number");
	}
	cout << endl;
	if (stringp(Object(4))){
		cout << Object("is_a_string");
	} else {

	}
	cout << endl;
	return 0;
}
