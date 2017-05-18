#include <iostream>
#include "CodeGenerator.h"
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;


 /**************************************************************\
 * Function: CodeGenerator Constructor                          *
 * Description: Initilizes the CodeGenerator class. Creates the *
 * 			 output file, and calls startFile().             *
 \**************************************************************/
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

 /**************************************\
 * Function: CodeGenerator Destructor   *
 * Description: Closes the output file. *
 \**************************************/
CodeGenerator::~CodeGenerator(){
	cout << "Closing File." << endl;
	p3file.close();
}

 /*********************************************************************\
 * Function: startFile 										 *
 * Description: Writes the includes, and namespace to the output file. *
 \*********************************************************************/
void CodeGenerator::startFile() {
	p3file << "#include <iostream>\n#include \"Object.h\"\n\nusing namespace std;\n\n";
}

 /**********************************************************************\
 * Function: startFunction 									  *
 * Description: Outputs the beginning of a function to the output file. *
 * 			 If function_name is "main" it sets the function to an   *
 * 			 int, otherwise it is an Object.                         *
 \**********************************************************************/
void CodeGenerator::startFunction( string function_name ){
	if ( function_name == "main" ){
		p3file << "int main( ";
		main_func = true;
	} else {
		main_func = false;
		p3file << "Object " << function_name << "( ";
	}
}

 /****************************************************************\
 * Function: endFunction 							      *
 * Description: Outputs the return object and closing brackets.   *
 * 			 If main_func = true, the function returns 0, else *
 * 			 the function returns _RetVal. 				 *
 \****************************************************************/
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
