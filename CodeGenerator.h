/**************************************************\
 * File: CodeGenerator.h
 * Authors: Erich Bucher, Kevin Brooks Gantsweg, Matthew Brian John-Vianney Sweeney
 * Description: The CodeGenerator class is part of the translation process for
 * 		converting Guile code to C++. Its main purpose is to write strings
 * 		that are given to it into a specified file. It also manages
 * 		operators and when to write them between different statements.
 *************************************************/
#include <iostream>
#include <fstream>
#include <stack>

using namespace std;


class CodeGenerator {
	public:
	 CodeGenerator(char*);
	 ~CodeGenerator();
	 void startFile();
	 void startFunction(string);
	 void endFunction();
	 void addParam(string);
	 void outputParams();
	 void writeCode(string);
	 void writeObject(string);
	 void writeOperator();
	 void addToStack(string);
	 void popFromStack();
	 bool getRetVal();
	 void setRetVal(bool);
	private:
	 ofstream p3file;
	 string param_list;
	 bool main_func;
	 bool first_stmt;
	 stack<string> operator_stack;	
	 bool use_retVal;
};
