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
