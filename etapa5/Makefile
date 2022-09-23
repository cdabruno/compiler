# Made by Bruno Correa and Alexadre Crestani


# compile everything
etapa5: hash.o ast.o decompiler.o y.tab.o lex.yy.o semantic.o tac.o main.o 
	gcc hash.o ast.o decompiler.o y.tab.o lex.yy.o semantic.o tac.o main.o -o etapa5

# generates the main object
main.o: main.c
	gcc -c main.c

# generates our auxiliar structures objects
hash.o: hash.c
	gcc -c hash.c

ast.p: ast.c
	gcc -c ast.c

decompiler.o: decompiler.c
	gcc -c decompiler.c

semantic.o: semantic.c
	gcc -c semantic.c

tac.o: tac.c
	gcc -c tac.c

# generates our code  top of third party software other than C only files
y.tab.o: y.tab.c
	gcc -c y.tab.c

y.tab.c: parser.y
	bison -dy parser.y

lex.yy.o: lex.yy.c
	gcc -c lex.yy.c

lex.yy.c: scanner.l
	flex --header-file=lex.yy.h scanner.l

# clean the folder of all compilation generated files
clean:
	rm -rf *.o lex.yy.c y.tab.c y.tab.h etapa5

tgz: clean
	tar cvzf etapa5.tgz .