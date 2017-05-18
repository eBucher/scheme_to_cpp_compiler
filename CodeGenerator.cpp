#include <iostream>
#include "CodeGenerator.h"
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;

CodeGenerator::CodeGenerator( char* filename ){
	main_func = false;
	int fnlength = strlen(filename);
	string outfile(filename);
	outfile[outfile.size()-2] = 'c';
	outfile[outfile.size()-1] = 'p';
	outfile += 'p';
	p3file.open( outfile.c_str() );
	startFile();
	use_retVal = true;
}

CodeGenerator::~CodeGenerator(){
	cout << "Closing File." << endl;
	p3file.close();
}

void CodeGenerator::startFile() {
	p3file << "#include <iostream>\n#include \"Object.h\"\n\nusing namespace std;\n\n";
}

void CodeGenerator::startFunction( string function_name ){
	if ( function_name == "main" ){
		p3file << "int main( ";
		main_func = true;
	} else {
		main_func = false;
		p3file << "Object " << function_name << "( ";
	}
}

void CodeGenerator::endFunction(){
	if ( main_func )
		p3file << "\treturn 0;\n}";
	else p3file << "\treturn _RetVal;\n}\n";
}

void CodeGenerator::addParam( string param ){
	param_list += "Object " + param + ", "; 
}

void CodeGenerator::outputParams(  ){
	p3file << param_list.substr(0, param_list.size()-2);
	param_list = "";
}

void CodeGenerator::writeCode( string code ) {
	p3file << code;
}

void CodeGenerator::writeObject(string objectName) {
	p3file << "Object(" << objectName << ")";
}

/**************************************************\
 * Function: writeOperator
 * Description: Writes out the element that is currently on top of the operator
 * 		stack with a space after it to the p3file if the first statement
 * 		has already been written. If the first statement has not already
 * 		been written, then nothing will be written and first_stmt will
 * 		be set to false.
 * 		The top element on the stack will not be popped off.
 *************************************************/
void CodeGenerator::writeOperator(){
	if ( first_stmt == false ){
		if(!operator_stack.empty()){
			if ( operator_stack.top() != " ")
				p3file << operator_stack.top();
		}
	} else {
		first_stmt = false;
	}
}

/**************************************************\
 * Function: addToStack
 * Description: Pushes c onto the operator stack and changes
 * 		first_stmt to true.
 *************************************************/
void CodeGenerator::addToStack(string c){
	first_stmt = true;
	operator_stack.push(c);
}


/*************************************************\
 * Function: popFromStack
 * Description: Pops the top element off of operator_stack.
 * Pre:	operator_stack has atleast one element on it.
 *************************************************/
void CodeGenerator::popFromStack(){
	operator_stack.pop();
}


/*************************************************\
 * Function: getRetVal
 * Description: This is an accessor function for getting the private
 * 		data member use_retVal.
 *************************************************/
bool CodeGenerator::getRetVal(){
	return use_retVal;
}


/*************************************************\
 * Function: setRetVal
 * Description: This is a setter function for setting the private data
 * 		member use_retVal.
 *************************************************/
void CodeGenerator::setRetVal(bool val){
	use_retVal = val;
}
