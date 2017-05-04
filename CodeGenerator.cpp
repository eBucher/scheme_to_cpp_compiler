#include <iostream>
#include "CodeGenerator.h"
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;

CodeGenerator::CodeGenerator( char* filename ){
	int fnlength = strlen(filename);
	filename[fnlength-2] = 'p';
	filename[fnlength-1] = '3';
	p3file.open( filename );
	startFile();
}

CodeGenerator::~CodeGenerator(){
	cout << "Closing File." << endl;
	p3file.close();
}

void CodeGenerator::startFile() {
	p3file << "#include <iostream>\n#include \"Object.h\"\n\nusing namespace std;\n\n";
}

void CodeGenerator::startFunction( string lexname ){

}
