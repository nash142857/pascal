LEX=flex
YACC=yacc
CC=g++ -std=c++11
a.out:lex.yy.o y.tab.o
	$(CC) lex.yy.o y.tab.o -o a.out
lex.yy.o:lex.yy.cpp y.tab.h
	$(CC) -c lex.yy.c
y.tab.o:y.tab.c
	$(CC) -c y.tab.c
y.tab.c y.tab.h:yacc.y
	$(YACC) -d yacc.y
lex.yy.cpp:token.l
	$(LEX) token.l
clean:
	rm -f *.o *.c *.h a.out