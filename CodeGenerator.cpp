#include <iostream>
#include "CodeGenerator.h"
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;

CodeGenerator::CodeGenerator( char* filename ){
	int fnlength = strlen(filename);
	string outfile(filename);
	outfile[outfile.size()-2] = 'c';
	outfile[outfile.size()-1] = 'p';
	outfile += 'p';
	p3file.open( outfile.c_str() );
	startFile();
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
		p3file << "Object " << function_name << "( ";
	}
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
