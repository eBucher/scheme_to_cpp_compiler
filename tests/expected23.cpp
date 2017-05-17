#include<iostream>
#include"Object.h"
using namespace std;

int main(){
	Object _RetVal;
	if((nullp(Object("()")) || listp(Object("1")) || listp(Object("()")))){
		cout << Object("something_is_true");
	} else{
		cout << Object("all_parts_are_false");
	}
	cout << endl;
	return 0;
}
