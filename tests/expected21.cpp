#include<iostream>
#include"Object.h"
using namespace std;

int main(){
  Object _RetVal;
  if((listp(Object("2")) || zerop(Object(7)))){
    cout << Object("one_part_is_true");
  } else{
    cout << Object("its_all_false");
  }
  return 0;
}
