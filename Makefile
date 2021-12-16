





coral: main.c lex.yy.c keywords.cc
	cc -o coral main.c keywords.cc  #lex.yy.c


lex.yy.c:
	flex coral.l




clean:
	rm lex.yy.c coral
