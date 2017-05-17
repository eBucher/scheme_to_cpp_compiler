#include <iostream>
#include "Object.h"
using namespace std;

int main(){
	if(stringp(Object("1"))){
		cout << "TRUE" << endl;
	} else{
		cout << "FALSE" << endl;
	}
}
