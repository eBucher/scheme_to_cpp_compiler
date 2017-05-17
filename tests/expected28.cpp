#include <iostream>
#include "Object.h"

using namespace std;

int main(  ) {
	Object _RetVal;
	if(( listop("car", Object("(1 2 3 4)")) < Object(2))){
	  cout << Object("(1 2 3)");
	} else {
	  cout << Object("(4 5 6)");
	}
	return 0;
}


