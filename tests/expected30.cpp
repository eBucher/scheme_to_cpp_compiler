#include <iostream>
#include "Object.h"
using namespace std;

Object getThird(Object myList){
	Object _RetVal;
	if( (nullp(Object(myList)) || nullp(listop("cdr", Object(myList))) || nullp(listop("cdr", listop("cdr", Object(myList)))))){
		_RetVal = Object("()");
	} else {
		_RetVal = listop("car", listop("cdr", listop("cdr", Object(myList))));
	}
	return _RetVal;
}

Object firsts(Object list1, Object list2){
	Object _RetVal;
	_RetVal = cons(listop("car", Object(list1)), cons(listop("car", Object(list2)), Object("()")));
	return _RetVal;
}

int main(){
	Object _RetVal;
	if( (listop("car", firsts(Object("(1 2 3 4 5)"), Object("(6 7 8 9 10)"))) < ( Object (1) + Object(2) + Object(2) + (Object(0) * Object(8) * Object(9) * (Object(6) / Object(2)))))){
		cout << Object("the_first_value_is_greater_than_5");
	} else{
		cout << Object("the_first_value_is_not_greater_than_5");
	}
	cout << endl;
	return 0;
}
