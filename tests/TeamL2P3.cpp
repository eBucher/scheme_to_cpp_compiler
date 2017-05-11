#include <iostream>
#include "Object.h"

using namespace std;

int main(  ) {
Object _RetVal;
cout << numberp(Object(1) );
cout << symbolp(Object(l) );
 cout << listp(Object("a ") );
 cout << zerop(Object(0) );
 cout << nullp(Object(9) );
 cout << charp(Object(d) );
 cout << stringp(Object("test ") );
return 0;
}