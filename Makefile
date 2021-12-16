





coral: main.c lex.yy.c keywords.cc code-gen.c
	cc -o coral main.c keywords.cc  code-gen.c lex.yy.c -ll


lex.yy.c:
	flex coral.l




clean:
	rm lex.yy.c coral
