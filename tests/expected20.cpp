#include<iostream>
#include"Object.h"
using namespace std;

int main(){
  Object _RetVal;
  if((listp(Object("2")) && zerop(Object(7)))){
    cout << Object("both_parts_are_true");
  } else{
    cout << Object("something_is_false");
  }
  return 0;
}
