LEX=flex
YACC=yacc
CC=g++ -std=c++11
a.out:common.o lex.yy.o y.tab.o 
	$(CC) common.o lex.yy.o y.tab.o -o a.out
common.o: 
	$(CC) -c common.cpp
lex.yy.o:lex.yy.c y.tab.h
	$(CC) -c lex.yy.c
y.tab.o:y.tab.c
	$(CC) -c y.tab.c
y.tab.c y.tab.h:parse.y
	$(YACC) -d parse.y
lex.yy.c:token.l
	$(LEX) token.l
clean:
	rm -f *.o lex.yy.c y.tab.h y.tab.c a.out *.gch
