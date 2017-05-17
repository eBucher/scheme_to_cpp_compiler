#include <iostream>
#include "Object.h"
using namespace std;

int main(){
	Object _RetVal;
	if(!(nullp(Object("()")))){
		cout << Object("that_list_has_something_in_it");
	} else{
		cout << Object("that_list_is_empty");
	}
	return 0;
}
