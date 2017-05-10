#include <iostream>
#include <fstream>

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
	private:
	 ofstream p3file;
	 string param_list;
	 bool main_func;
};
