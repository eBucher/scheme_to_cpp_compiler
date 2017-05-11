#include <iostream>
#include "Object.h"
using namespace std;

int main(){
	Object _RetVal;
	cout << (Object(1) + (Object(2) - Object(3) - Object(4)) + (Object(5) * Object(6) * Object(7) * (Object(8) / Object(9))) + Object(10));
	cout << endl;
	return 0;
}
//(display (+ 1 (- 2 3 4) (* 5 6 7 (/ 8 9)) 10))
