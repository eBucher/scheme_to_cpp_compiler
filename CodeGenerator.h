#include <iostream>
#include <fstream>

using namespace std;

class CodeGenerator {
	public:
	 CodeGenerator(char*);
	 ~CodeGenerator();
	 void startFunction(string);
	 void startFile();
	private:
	 ofstream p3file;
};
