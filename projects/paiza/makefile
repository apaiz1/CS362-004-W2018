CFLAGS = -Wall -fpic -coverage -lm
testme: testme.c
	gcc -o testme -g testme.c $(CFLAGS)
	-./testme
	touch testmecoverage.out
	gcov testme.c &> testmecoverage.out
	cat testme.c.gcov >> testmecoverage.out