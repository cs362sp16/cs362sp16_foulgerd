#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "dominion.h"

/*
 * THIS TESTS SMITHY
 */
int failed = 0;

void assert_fail(int ans) {
	if (ans == -1) {
		printf("TEST FAILED\n");
		failed = 1;
	}
}

void assert_pass() {
	if (!failed) {
		printf("TEST PASSED\n");
	}
}

int playerGen() {
        int number = rand() % 10 + 1;
        return number;
}

int stateGen() {
        //struct gameState s;
        int number = rand() % 10 + 1;

        return number;
}

int main(int argc, char **argv) {
	srand(time(NULL));
        int result, seed, i;
	struct gameState s;
        //srand(time(NULL));
	
        if (argc == 2) {
                seed = atoi(argv[1]);
        } else {
                seed = rand() % 200 + 1;
                printf("seed: %d\n", seed);
        }

        int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,
                outpost,baron,tribute};

        for (i = 0; i < 1; i++) {
                initializeGame(playerGen(), k, seed, &s);

                cardGreat_hall(2, &s, 1, 1);
        }

	return 0;
}
