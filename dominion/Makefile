CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player

unittestresults.out: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4

randomtestresults.out: randomtestadventurer randomtestcard1 randomtestcard2

unittest1:
	#./playdom 2
	gcc -o unittest1.o unittest1.c -g dominion.o rngs.o interface.o $(CFLAGS)
	./unittest1.o > temp
	echo "UNITTEST1" >> unittestresults.out
	gcov dominion.c > unittestresults.out

unittest2:
	gcc -o unittest2.o unittest2.c -g dominion.o rngs.o interface.o $(CFLAGS)
	./unittest2.o > temp
	echo "UNITTEST2" >> unittestresults.out
	gcov dominion.c >> unittestresults.out

unittest3:
	gcc -o unittest3.o unittest3.c -g dominion.o rngs.o interface.o $(CFLAGS)
	./unittest3.o > temp
	echo "UNITTEST3" >> unittestresults.out
	gcov dominion.c >> unittestresults.out


unittest4:
	gcc -o unittest4.o unittest4.c -g dominion.o rngs.o interface.o $(CFLAGS)
	./unittest4.o > temp
	echo "UNITTEST4" >> unittestresults.out
	gcov dominion.c >> unittestresults.out

cardtest1:
	gcc -o cardtest1.o cardtest1.c -g dominion.o rngs.o interface.o $(CFLAGS)
	./cardtest1.o > temp
	echo "CARDTEST1" >> unittestresults.out
	gcov dominion.c >> unittestresults.out

cardtest2:
	gcc -o cardtest2.o cardtest2.c -g dominion.o rngs.o interface.o $(CFLAGS)
	./cardtest2.o > temp
	echo "CARDTEST2" >> unittestresults.out
	gcov dominion.c >> unittestresults.out

cardtest3:
	gcc -o cardtest3.o cardtest3.c -g dominion.o rngs.o interface.o $(CFLAGS)
	./cardtest3.o > temp
	echo "CARDTEST3" >> unittestresults.out
	gcov dominion.c >> unittestresults.out

cardtest4:
	gcc -o cardtest4.o cardtest4.c -g dominion.o rngs.o interface.o $(CFLAGS)
	./cardtest4.o > temp
	echo "CARDTEST4" >> unittestresults.out
	gcov dominion.c >> unittestresults.out

randomtestadventurer:
	gcc -o randomtestadventurer.o randomtestadventurer.c -g dominion.o rngs.o interface.o $(CFLAGS)
	./randomtestadventurer.o > temp
	echo "CARD TEST ADVENTURER" >> randomtestadventurer.out
	gcov -f dominion.c >> randomtestadventurer.out

randomtestcard1:
	gcc -o randomtestcard1.o randomtestcard1.c -g dominion.o rngs.o interface.o $(CFLAGS)
	./randomtestcard1.o > temp
	echo "CARD TEST 1: VILLAGE" >> randomtestcard1.out
	gcov -f dominion.c >> randomtestcard1.out

randomtestcard2:
	gcc -o randomtestcard2.o randomtestcard2.c -g dominion.o rngs.o interface.o $(CFLAGS)
	./randomtestcard2.o > temp
	echo "CARD TEST 2: GREAT HALL" >> randomtestcard2.out
	gcov -f dominion.c >> randomtestcard2.out

clean:
	rm -f *.o playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.a *.dSYM temp
