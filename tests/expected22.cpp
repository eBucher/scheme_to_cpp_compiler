#include<iostream>
#include"Object.h"
using namespace std;

int main(){
  Object _RetVal;
  if((nullp(Object("()")) && stringp(Object("1")) && listp(Object("()")))){
    cout << Object("all_parts_are_true");
  } else{
    cout << Object("something_is_false");
  }
  return 0;
}
