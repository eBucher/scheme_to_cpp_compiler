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

/********************************************************\
 * Function: addParam
 * Description: Adds all of the required parameter(s)
 * to the param_list variable for the associated
 * function.
\********************************************************/
void CodeGenerator::addParam( string param ){
	param_list += "Object " + param + ", "; 
}

/********************************************************\
 * Function: outputParams
 * Description: Takes the param_list variable and outputs
 * all of the parameters into the p3file which handles the
 * generation of the Guile code translated to C++ code.
\********************************************************/
void CodeGenerator::outputParams(  ){
	p3file << param_list.substr(0, param_list.size()-2);
	param_list = "";
}

/********************************************************\
 * Function: writeCode
 * Description: A simple function that will simply write
 * out simple symbols of code that are vital to the
 * generation of the Guile code translated to C++ code.
 * i.e (double quotes, parenthesis, brackets etc...)
\********************************************************/
void CodeGenerator::writeCode( string code ) {
	p3file << code;
}

/*******************************************************\
 * Function: writeObject
 * Description: Another simple function that will simply
 * write out data-typed variables casted as an Object,
 * basically whenever a function calls another function
 * within itself.
\*******************************************************/
void CodeGenerator::writeObject(string objectName) {
	p3file << "Object(" << objectName << ")";
}

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

void CodeGenerator::addToStack(string c){
	first_stmt = true;
	operator_stack.push(c);
}


void CodeGenerator::popFromStack(){
	operator_stack.pop();
}


bool CodeGenerator::getRetVal(){
	return use_retVal;
}


void CodeGenerator::setRetVal(bool val){
	use_retVal = val;
}
