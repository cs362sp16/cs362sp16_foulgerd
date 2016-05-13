#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "dominion.h"

/*
 * THIS TESTS VILLAGE
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
        int number = rand() % 10 + 1;

        return number;
}

int main(int argc, char **argv) {
	srand(time(NULL));
        int result, seed, i, n;
	struct gameState s;

        int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,
                outpost,baron,tribute};

        for (i = 0; i < 1; i++) {
                initializeGame(playerGen(), k, 42, &s);

                result = cardEffect(village, 1, 1, 1, &s, 3, 0);

                assert_fail(result);
        }

        assert_pass(result);

	return 0;
}
