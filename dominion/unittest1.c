#include <stdio.h>
#include "dominion.h"

/*
 * THIS TESTS DRAWCARD
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

int main() {
	int result;
	struct gameState s;

        int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,
                outpost,baron,tribute};

        initializeGame(2, k, 5, &s); 
        
        result = drawCard(1, &s);
	
	assert_fail(result == -1);
	
	assert_pass();
	
	return 0;
}

