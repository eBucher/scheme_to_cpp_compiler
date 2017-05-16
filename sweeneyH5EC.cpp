#include <iostream>
#include "Object.h"

using namespace std;

Object odd_copy( Object mylist ) {
	Object _RetVal;
	if(nullp(Object(mylist) )){
		Object("()")
	} else {
		cons(listop("car", Object(mylist)), if(nullp(listop("cdr", Object(mylist)) )){
				Object("()")
				} else {
				odd_copy(listop("cdr", ,listop("cdr", ,Object(mylist))))}
		    )}
	return _RetVal;
}
Object even_copy( Object mylist ) {
	Object _RetVal;
	if(nullp(Object(mylist) )){
		Object("()")
	} else {
		listop("cdr", cons(listop("car", Object(mylist)), if(nullp(listop("cdr", Object(mylist)) )){
					Object("()")
					} else {
					odd_copy(listop("cdr", ,Object(mylist)))}
					))}
	return _RetVal;
}
Object merge( Object L1, Object L2 ) {
	Object _RetVal;
	if(nullp(Object(L1) )){
		Object(L2)
	} else {
		if(nullp(Object(L2) )){
			Object(L2)
		} else {
			if((listop("car", >Object(L1))>listop("car", >Object(L2)))){
				cons(listop("car", Object(L1)), merge(listop("cdr", ,Object(L1)),Object(L2)))
			} else {
				cons(listop("car", Object(L2)), merge(listop("cdr", ,Object(L2)),Object(L1)))}
		}
	}
	return _RetVal;
}
Object mergesort( Object L ) {
	Object _RetVal;
	if((nullp(||Object(L) )||nullp(||listop("cdr", ||Object(L)) ))){
		Object(L)
	} else {
		merge(mergesort(odd_copy(Object(L))),mergesort(even_copy(Object(L))))}
	return _RetVal;
}
Object less_than( Object pivot, Object L ) {
	Object _RetVal;
	if(nullp(Object(L) )){
		Object(L)
	} else {
		if((listop("car", <Object(L))<Object(pivot))){
			cons(listop("car", Object(L)), less_than(Object(pivot),listop("cdr", ,Object(L))))
		} else {
			less_than(Object(pivot),listop("cdr", ,Object(L)))}
	}
	return _RetVal;
}
Object equal_to( Object pivot, Object L ) {
	Object _RetVal;
	if(nullp(Object(L) )){
		Object(L)
	} else {
		if((listop("car", ==Object(L))==Object(pivot))){
			cons(listop("car", Object(L)), equal_to(Object(pivot),listop("cdr", ,Object(L))))
		} else {
			equal_to(Object(pivot),listop("cdr", ,Object(L)))}
	}
	return _RetVal;
}
Object greater_than( Object pivot, Object L ) {
	Object _RetVal;
	if(nullp(Object(L) )){
		Object(L)
	} else {
		if((listop("car", >Object(L))>Object(pivot))){
			cons(listop("car", Object(L)), greater_than(Object(pivot),listop("cdr", ,Object(L))))
		} else {
			greater_than(Object(pivot),listop("cdr", ,Object(L)))}
	}
	return _RetVal;
}
Object comb_helper( Object L1, Object L2 ) {
	Object _RetVal;
	if(nullp(Object(L1) )){
		Object(L2)
	} else {
		cons(listop("car", Object(L1)), comb_helper(listop("cdr", ,Object(L1)),Object(L2)))}
	return _RetVal;
}
Object combine( Object L1, Object L2, Object L3 ) {
	Object _RetVal;
	_RetVal = comb_helper(comb_helper(Object(L1),Object(L2)),Object(L3));
	return _RetVal;
}
Object qs( Object L ) {
	Object _RetVal;
	if(nullp(Object(L) )){
		Object(L)
	} else {
		combine(qs(less_than(listop("car", ,Object(L)),listop("cdr", ,Object(L)))),equal_to(listop("car", ,Object(L)),Object(L)),qs(greater_than(listop("car", ,Object(L)),listop("cdr", ,Object(L)))))}
	return _RetVal;
}
Object numeric_copy( Object L ) {
	Object _RetVal;
	if(nullp(Object(L) )){
		Object(L)
	} else {
		if(numberp(listop("car", Object(L)) )){
			cons(listop("car", Object(L)), numeric_copy(listop("cdr", ,Object(L))))
		} else {
			numeric_copy(listop("cdr", ,Object(L)))}
	}
	return _RetVal;
}
Object quicksort( Object L ) {
	Object _RetVal;
	if(listp(Object(L) )){
		qs(numeric_copy(Object(L)))
	} else {
		Object("enter_a_list ")}
	return _RetVal;
}
