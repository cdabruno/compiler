etapa3: y.tab.c lex.yy.c
	gcc -o etapa3 lex.yy.c

y.tab.c: parser.y
	bison -dy parser.y

lex.yy.c: scanner.l
	flex scanner.l 

clean:
	rm lex.yy.c etapa3 y.tab.c y.tab.h
