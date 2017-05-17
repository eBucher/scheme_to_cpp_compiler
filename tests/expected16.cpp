#include <iostream>
#include "Object.h"
using namespace std;

int main(){
	Object _RetVal;
	cout << Object("(quote not)");
	cout << Object("((quote one) (quote two) (quote three))");
	return 0;
}
