<p align="center">
    <img height="150px" src="https://raw.githubusercontent.com/eBucher/scheme_to_cpp_compiler/master/readmeAssets/logo.png">
</p>
<h1 align="center">
  Scheme to C++ Compiler
</h1>

This program can be used to convert a subset of the Scheme programming language to C++ code. 

## Setup

1. Download the code from this repository. This was written to work on a Unix system with the make and g++ commands.
2. From the command line, navigate to the outermost directory of the project and run the *make* command. The output file will be named *P3.out*.

## Usage

The program can be run from the command line by typing in *./P3.out pathToInputFile.ss*. As an example: 
> ./P3.out SchemeTest.ss

The given input file must end with a .ss file extension. If it does not, an error message will be printed.

The resulting output file will have the same name as the input file but will have a .cpp extension. Because scheme does not specify datatypes like C++ does, the output file uses a custom Object class for declaring variables and literals. This class can be cast to act as an int, float, double, long, string, or array. In order to compile the C++ file that is produced, it must also be compiled with the *Object.h* and *Object.cpp* files that are in the outermost directory of this project. 

## Tests
Inside the *tests* folder is a series of input and expected files for testing to ensure that the compiler is working as intended. These tests can be run from inside the tests folder by running the *test* bash script in the folder. If any tests should fail, they will be reported in the  output. A file named testResults.txt will also be produced that lists the differences between lines in the expected file and produced file for each input.

<img src="https://raw.githubusercontent.com/eBucher/scheme_to_cpp_compiler/master/readmeAssets/resultsFileImage.png"/>

P3.out already needs to be compiled in the outermost folder of this project to be able to run the tests. If it has not been compiled yet, the tests cannot run.

### Adding a new test
New tests can be added to the tests folder by simply creating two files. The first one is the input file whose name is in the form of *TeamL[num]P3.ss*. The second one should contain the code that is expected to be produced by the compiler and should be named *expected[num].cpp*. The number in the names may be any number, although we encourage the use of incrementing numbers.

In order to print a message describing the test, add a comment to the top of the .ss file. Comments in scheme are written with a semicolon at the beginning of them like this:

> ; Here is a comment that will appear in the output to remind the
> ; user what is being tested.

Once these two files are added, they will automatically be used when the test command is run again.

## Authors
* Jeff Bahns
* Jordan Bergero
* Erich Bucher
* Matt Sweeney
* Kevin Gantsweg
* Tia Watts
