#include<iostream>
#include"Object.h"
using namespace std;

Object length( Object lst ){
  Object _RetVal;
  if(nullp(Object(lst))){
    _RetVal = Object(0);
  } else {
    _RetVal = (Object(1) + length(listop("cdr", Object(lst))));
  }
  return _RetVal;
}

Object first_helper( Object lst, Object x, Object length ){
  Object _RetVal;
  if((Object(x) > Object(length))){
    _RetVal = Object("()");
  } else {
    _RetVal = cons(listop("car", Object(lst)), first_helper(listop("cdr", Object(lst)), (Object(x) + Object(1)), Object(length)));
  }
  return _RetVal;
}

Object first_half( Object lst ){
  Object _RetVal;
  if(nullp(Object(lst))){
    _RetVal = Object(lst);
  } else {
    _RetVal = first_helper(Object(lst), Object(1), (length (Object (lst)) / Object (2)));
  }
  return _RetVal;
}

Object second_helper( Object fhalf, Object lst ){
  Object _RetVal;
  if(nullp(Object(fhalf))){
    _RetVal = Object(lst);
  } else {
    _RetVal = second_helper(listop("cdr", Object(fhalf)), listop("cdr", Object(lst)));
  }
  return _RetVal;
}

Object second_half( Object lst ){
  Object _RetVal;
  if(nullp(Object(lst))){
    _RetVal = Object(lst);
  } else {
    _RetVal = second_helper(first_half(Object(lst)), Object(lst));
  }
  return _RetVal;
}

int main(){
  Object _RetVal;
  cout << first_half(Object("(41 654 23 765 2 356 98 780 23)"));
  cout << endl;
  cout << second_half(Object("(41 654 23 765 2 356 98 780 23)"));
  cout << endl;
  return 0;
}
