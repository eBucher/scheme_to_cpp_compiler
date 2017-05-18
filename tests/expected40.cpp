#include <iostream>
#include "Object.h"

using namespace std;


Object do_stuff(Object a,Object b,Object c,Object d,Object e){
	Object _RetVal;
	if( (((Object(a)+Object(b)+Object(c)+Object(d)+Object(e)) - (Object(2) * Object(9) * (Object(1) / Object(9))) - Object(90)) < Object(910)) ){
		if(!(stringp( (Object(a) + (Object(b) - Object(1)))))){
			cout << Object("stuff_happened");
		} else {
			cout << Object("(1 2 3 4 5)");
		}
	} else {
	}
	return _RetVal;
}
Object get_second(Object L){
	Object _RetVal;
	if( ! (listp(Object(L)))){
		cout << Object("that_aint_no_list");
	} else {
		if( numberp(listop("car", listop("cdr", Object(L))))){
			_RetVal = listop("car", listop("cdr", Object(L)));
		} else {
			cout << Object("that_aint_no_numbah");
		}
	}		
	
	return _RetVal;
}

int main(  ) {
	Object _RetVal;
	if( (get_second(Object("(1 2 3 4 5 6 7 8 9)")) > Object(3))){
		_RetVal = do_stuff(Object(5),Object(6),Object(7),Object(8),Object(9));
	} else {
		_RetVal = Object(5);
	}
	cout << endl;
	return 0;
}


