#include <iostream>
#include "Object.h"

using namespace std;

int main(  ) {
Object _RetVal;
cout << listop("car", Object("(alpha beta gamma delta )"));
cout << endl;
 cout << listop("cdr", Object("(the time has come the walrus said )"));
 cout << endl;
 cout << listop("cddr", Object("(one 2 three 4 )"));
 cout << endl;
 cout << listop("cadddr", Object("(charlie lucy snoopy pig schroeder linus woodstock )"));
 cout << endl;
return 0;
}