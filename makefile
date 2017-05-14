P3.out : Project3.o SetLimits.o LexicalAnalyzer.o SyntacticalAnalyzer.o CodeGenerator.o
	g++ -g -o P3.out Project3.o SetLimits.o LexicalAnalyzer.o SyntacticalAnalyzer.o CodeGenerator.o

P2.out : Project2.o SetLimits.o LexicalAnalyzer.o SyntacticalAnalyzer.o 
	g++ -g -o P2.out Project2.o SetLimits.o LexicalAnalyzer.o SyntacticalAnalyzer.o 

Project3.o : Project3.cpp SetLimits.h CodeGenerator.h
	g++ -g -c Project3.cpp

Project2.o : Project2.cpp SetLimits.h SyntacticalAnalyzer.h
	g++ -g -c Project2.cpp

SetLimits.o : SetLimits.cpp SetLimits.h
	g++ -g -c SetLimits.cpp

CodeGenerator.o : CodeGenerator.cpp CodeGenerator.h SyntacticalAnalyzer.h
	g++ -g -c CodeGenerator.cpp

LexicalAnalyzer.o : LexicalAnalyzer.save
	cp LexicalAnalyzer.save LexicalAnalyzer.o

SyntacticalAnalyzer.o : SyntacticalAnalyzer.cpp SyntacticalAnalyzer.h LexicalAnalyzer.h
	g++ -g -c SyntacticalAnalyzer.cpp


clean : 
	rm -f *.o *.out *.gch *.lst *.dbg *.p2 *.p1 *.p3 test.c

submit : Project2.cpp LexicalAnalyzer.h LexicalAnalyzer.save SyntacticalAnalyzer.h SyntacticalAnalyzer.cpp CodeGenerator.cpp makefile README.txt
	rm -rf TeamNP2
	mkdir TeamNP2
	cp Project2.cpp TeamNP2
	cp LexicalAnalyzer.h TeamNP2
	cp LexicalAnalyzer.save TeamNP2
	cp SyntacticalAnalyzer.h TeamNP2
	cp SyntacticalAnalyzer.cpp TeamNP2
	cp makefile TeamNP2
	cp README.txt TeamNP2
	tar cfvz TeamNP2.tgz TeamNP2
	cp TeamNP2.tgz ~tiawatts/cs460drop
