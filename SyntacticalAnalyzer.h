/********************************************************************************/
/* Project: Project 3								*/
/* Author: Kevin Gantsweg, Erich Bucher, Matt Sweeney				*/
/* Date: 5/18/17								*/
/* Description:	A syntactical analyzer built on top of Project 1. When a new    */
/* 		SyntacticalAnalyzer object is created, it will open up the      */
/*		file given as the constructors argument, parse through it, and  */
/*		write out information to the following files:			*/
/*		.p2 file:  A list of when each nonterminal begins and ends,	*/
/*			   which rule starts the nonterminals, the first	*/
/*			   token of each nonterminal, and the number of errors  */
/*		.dbg file: Each line of the input file, followed by the tokens  */
/*			   in that line and the nonterminals beginning or	*/
/*			   beginning.						*/
/*		.lst file: All of the lines from the input file, followed by	*/
/*			   all of the lexical and syntactical errors.		*/
/*		.cpp file: The scheme code that has been translated to C++.     */

/********************************************************************************/

#ifndef SYN_H
#define SYN_H

#include <iostream>
#include <fstream>
#include "LexicalAnalyzer.h"
#include "CodeGenerator.h"
#include <vector>

using namespace std;

class SyntacticalAnalyzer 
{
    public:
	SyntacticalAnalyzer (char * filename);
	~SyntacticalAnalyzer ();
    private:
	LexicalAnalyzer * lex;
	ofstream p2file;
	ofstream lstfile;
	token_type token;
	int program();
	int define();
	int more_defines();
	int stmt_list();
	int stmt();
	int literal();
	int quoted_lit();
	int more_tokens();
	int param_list();
	int else_part();
	int action();
	int any_other_token();
	int GetRule(int, token_type);
	void print(string, token_type, int);
	void ending(string, token_type, int);
        int enforce(token_type &token, vector<int>expected_vector);
	int runNonterminal(string n);
	token_type NextToken();
	string lstOutput;
	
	//Project 3
	CodeGenerator * cg;
};
	
#endif
