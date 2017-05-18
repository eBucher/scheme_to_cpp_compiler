#include <iostream>
#include "Object.h"
using namespace std;

int main(){
	Object _RetVal;
	cout << listop("car", Object("(hello 1000 cons if display newline car cdr and or not define number? symbol? list? zero? null? char? string? + - * / = < <= > >=)"));
	return 0;
}


