#include <iostream>
#include "Object.h"
using namespace std;

int main(){
	Object _RetVal;
	if(stringp(Object(100))){
		cout << Object("yes_it_is");
	} else{
		cout << Object("no_it_is_not");
	}
	return 0;
}
