/**************************************************\
 * File: CodeGenerator.cpp
 * Authors: Erich Bucher, Kevin Brooks Gantsweg, Matthew Brian John-Vianney Sweeney
 * Description: The CodeGenerator class is part of the translation process for
 * 		converting Guile code to C++. Its main purpose is to write strings
 * 		that are given to it into a specified file. It also manages
 * 		operators and when to write them between different statements.
 *************************************************/
#include <iostream>
#include "CodeGenerator.h"
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;


 /**************************************************************\
 * Function: CodeGenerator Constructor                          
 * Description: Initilizes the CodeGenerator class. Creates the 
 * 			 output file, and calls startFile().      
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
 * Function: startFile 										 
 * Description: Writes the includes, and namespace to the output file. 
 \*********************************************************************/
void CodeGenerator::startFile() {
	p3file << "#include <iostream>\n#include \"Object.h\"\n\nusing namespace std;\n\n";
}

 /**********************************************************************\
 * Function: startFunction 						
 * Description: Outputs the beginning of a function to the output file. 
 * 			 If function_name is "main" it sets the function to an   
 * 			 int, otherwise it is an Object.                         
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
 * Function: endFunction 			
 * Description: Outputs the return object and closing brackets.   
 * 			 If main_func = true, the function returns 0, else 
 * 			 the function returns _RetVal. 		
 \****************************************************************/
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
