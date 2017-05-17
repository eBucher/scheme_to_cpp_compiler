#include<iostream>
#include"Object.h"
using namespace std;

int main(){
	Object _RetVal;
	if((Object(13) >= Object(13))){
		cout << Object("thirteen_is_greater_than_or_equal_to_thirteen");
	} else{
		cout << Object("thirteen_is_not_greater_than_or_equal_to_thirteen");
	}
	return 0;
