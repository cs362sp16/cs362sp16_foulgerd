#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "dominion.h"

#define MAX_PLAYERS 4

int failed = 0;
int pickedCards[10];

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

void randCard() {
        //int random = rand() % 20;
        int i;
        int tempArray[20];

        //populate array
        for (i = 0; i < 20; i++) {
                tempArray[i] = i;
        }

        //shuffle array
        for (i = 0; i < 20; i++) {
                int temp = tempArray[i];
                int index = rand() % 20;
                tempArray[i] = tempArray[index];
                tempArray[i] = temp;
        }

        //populate card array
        for (i = 0; i < 10; i++) {
                pickedCards[i] = tempArray[i];
        }
        
        //Get the actual card name
        for (i = 0; i < 10; i++) {
                switch(pickedCards[i]) {
                        case 0:
                                pickedCards[i] = adventurer;
                                break;
                        case 1:
                                pickedCards[i] = council_room;
                                break;
                        case 2:
                                pickedCards[i] = feast;
                                break;
                        case 3:
                                pickedCards[i] = gardens;
                                break;
                        case 4:
                                pickedCards[i] = mine;
                                break;
                        case 5:
                                pickedCards[i] = remodel;
                                break;
                        case 6:
                                pickedCards[i] = smithy;
                                break;
                        case 7:
                                pickedCards[i] = village;
                                break;
                        case 8:
                                pickedCards[i] = baron;
                                break;
                        case 9:
                                pickedCards[i] = great_hall;
                                break;
                        case 10:
                                pickedCards[i] = minion;
                                break;
                        case 11:
                                pickedCards[i] = steward;
                                break;
                        case 12:
                                pickedCards[i] = tribute;
                                break;
                        case 13:
                                pickedCards[i] = ambassador;
                                break;
                        case 14:
                                pickedCards[i] = cutpurse;
                                break;
                        case 15:
                                pickedCards[i] = embargo;
                                break;
                        case 16:
                                pickedCards[i] = outpost;
                                break;
                        case 17:
                                pickedCards[i] = salvager;
                                break;
                        case 18:
                                pickedCards[i] = sea_hag;
                                break;
                        case 19:
                                pickedCards[i] = treasure_map;
                                break;
                }
        }
        
        //return random;
}

int randPlayers() {
        int random = rand() % 3 + 2;
        return random;
}

int main(int argc, char **argv) {
	int result, seed, i;
	struct gameState state;
        struct gameState *p = &state;
        srand(time(NULL));
        int players = randPlayers();
        int playerArray[MAX_PLAYERS];
        int j = 200;
    
        while (j != 0) {
        j--;
        //initializes the card array
        for (i = 0; i < 10; i++) {
                pickedCards[i] = -1;
        }
        
        //Randomize cards
        randCard();
        
        if (argc == 2) {
                seed = atoi(argv[1]);
        } else {
                seed = 42;
        }

        //int k[10] = {adventurer, steward, embargo, village, feast, mine, cutpurse, 
	//       tribute, baron, smithy};

        int k[10] = {pickedCards[0], pickedCards[1], pickedCards[2], pickedCards[3], 
                pickedCards[4], pickedCards[5], pickedCards[6], pickedCards[7], 
                pickedCards[8], pickedCards[9]};

        initializeGame(players, k, seed, p); 

  int money = 0;
  int smithyPos = -1;
  int adventurerPos = -1;
  int baronPos = -1;
  int tributePos = -1;
  int feastPos = -1;
  i=0;

  int numSmithies = 0;
  int numAdventurers = 0;
  int numBarons = 0;
  int numTributes = 0;
  int numFeasts = 0;
 
  //int numProvince = 0;
  //int numGold = 0;

  printf("\n~~~~~~ NEW GAME ~~~~~~\n");

  while (!isGameOver(p)) {
    //Card positions
    smithyPos = -1;
    adventurerPos = -1;
    baronPos = -1;
    tributePos = -1;
    feastPos = -1;
    money = 0;

    //Picking card
    for (i = 0; i < numHandCards(p); i++) {
      if (handCard(i, p) == copper)
    money++;
      else if (handCard(i, p) == silver)
    money += 2;
      else if (handCard(i, p) == gold)
    money += 3;
      else if (handCard(i, p) == smithy)
    smithyPos = i;
      else if (handCard(i, p) == adventurer)
    adventurerPos = i;
      else if (handCard(i, p) == baron)
    baronPos = i;
      else if (handCard(i, p) == tribute)
    tributePos = i;
      else if (handCard(i, p) == feast)
    feastPos = i;
    } 

    //player 0
    if (whoseTurn(p) == 0) {
      if ((smithyPos != -1) && (numSmithies < 2)) {
        printf("0: smithy played from position %d\n", smithyPos); 
	playCard(smithyPos, -1, -1, -1, p); 
	//printf("smithy played.\n");
	money = 0;
	i=0;
	while(i<numHandCards(p)){
	  if (handCard(i, p) == copper){
	    playCard(i, -1, -1, -1, p);
	    money++;
	  }
	  else if (handCard(i, p) == silver){
	    playCard(i, -1, -1, -1, p);
	    money += 2;
	  }
	  else if (handCard(i, p) == gold){
	    playCard(i, -1, -1, -1, p);
	    money += 3;
	  }
	  i++;
	}
      } else if ((baronPos != -1) && (numBarons < 2)) {
        printf("0: baron played from position %d\n", baronPos); 
	playCard(baronPos, -1, -1, -1, p); 
	money = 0;
	i=0;
	while(i<numHandCards(p)){
	  if (handCard(i, p) == copper){
	    playCard(i, -1, -1, -1, p);
	    money++;
	  }
	  else if (handCard(i, p) == silver){
	    playCard(i, -1, -1, -1, p);
	    money += 2;
	  }
	  else if (handCard(i, p) == gold){
	    playCard(i, -1, -1, -1, p);
	    money += 3;
	  }
	  i++;
	}
      } if ((feastPos != -1) && (numFeasts <= 2)) {
        printf("0: feast played from position %d\n", feastPos); 
	playCard(feastPos, 1, -1, -1, p); 
	money = 0;
	i=0;
	while(i<numHandCards(p)){
	  if (handCard(i, p) == copper){
	    playCard(i, -1, -1, -1, p);
	    money++;
	  }
	  else if (handCard(i, p) == silver){
	    playCard(i, -1, -1, -1, p);
	    money += 2;
	  }
	  else if (handCard(i, p) == gold){
	    playCard(i, -1, -1, -1, p);
	    money += 3;
	  }
	  i++;
	}
      }

      if (money >= 8) {
        printf("0: bought province\n"); 
        buyCard(province, p);
      }
      else if (money >= 6) {
        printf("0: bought gold\n"); 
        buyCard(gold, p);
      }
      if ((money >= 4) && (numSmithies < 2)) {
        printf("0: bought smithy\n"); 
        buyCard(smithy, p);
        numSmithies = numSmithies + 1;
      } 
      if ((money >= 4) && (numFeasts < 2)) {
              printf("0: bought feast\n");
              buyCard(feast, p);
              numFeasts = numFeasts + 1;
      }
      else if ((money >= 4) && (numBarons < 2)) {
        printf("0: bought baron\n");
        buyCard(baron, p);
        numBarons = numBarons + 1;
      }
      else if (money >= 3) {
        printf("0: bought silver\n"); 
        buyCard(silver, p);
      }

      printf("0: end turn\n");
      endTurn(p);
    }
    //Player 1
    else if (whoseTurn(p) == 1) {
      /*if ((adventurerPos != -1) && (numAdventurers <= 2)) {
        printf("1: adventurer played from position %d\n", adventurerPos);
	playCard(adventurerPos, -1, -1, -1, p); 
	money = 0;
	i=0;
	while(i<numHandCards(p)){
	  if (handCard(i, p) == copper){
	    playCard(i, -1, -1, -1, p);
	    money++;         
	  }
	  else if (handCard(i, p) == silver){
	    playCard(i, -1, -1, -1, p);
	    money += 2;
	  }
	  else if (handCard(i, p) == gold){
	    playCard(i, -1, -1, -1, p);
	    money += 3;
	  }
	  i++;
	}
      }*/
      if (tributePos != -1) {
        printf("1: tribute played from position %d\n", tributePos); 
	playCard(tributePos, -1, -1, -1, p); 
	//printf("smithy played.\n");
	money = 0;
	i=0;
	while(i<numHandCards(p)){
	  if (handCard(i, p) == copper){
	    playCard(i, -1, -1, -1, p);
	    money++;
	  }
	  else if (handCard(i, p) == silver){
	    playCard(i, -1, -1, -1, p);
	    money += 2;
	  }
	  else if (handCard(i, p) == gold){
	    playCard(i, -1, -1, -1, p);
	    money += 3;
	  }
	  i++;
	}
      }
      if (money >= 8) {
        printf("1: bought province\n");
        buyCard(province, p);
      } 
      else if ((money >= 5) && (numTributes < 2)) {
              printf("1: bought tribute\n");
              buyCard(tribute, p);
              numTributes++;
      }
      else if ((money >= 6) && (numAdventurers < 2)) {
        printf("1: bought adventurer\n");
	buyCard(adventurer, p);
	numAdventurers = numAdventurers + 1;
      }else if (money >= 6){
        printf("1: bought gold\n");
	    buyCard(gold, p);
        }
      else if (money >= 3){
        printf("1: bought silver\n");
	    buyCard(silver, p);
      }
      printf("1: endTurn\n");
      
      endTurn(p);      
    } 
    //player 2
    else if (whoseTurn(p) == 2) {
      if (adventurerPos != -1) {
        printf("2: adventurer played from position %d\n", adventurerPos);
        playCard(adventurerPos, -1, -1, -1, p); 
	money = 0;
	i=0;
	while(i<numHandCards(p)){
	  if (handCard(i, p) == copper){
	    playCard(i, -1, -1, -1, p);
	    money++;         
	  }
	  else if (handCard(i, p) == silver){
	    playCard(i, -1, -1, -1, p);
	    money += 2;
	  }
	  else if (handCard(i, p) == gold){
	    playCard(i, -1, -1, -1, p);
	    money += 3;
	  }
	  i++;
	}
      }


      if (money >= 8) {
        printf("2: bought province\n");
        buyCard(province, p);
      }
      else if ((money >= 6) && (numAdventurers < 2)) {
        printf("2: bought adventurer\n");
	buyCard(adventurer, p);
	numAdventurers++;
      }else if (money >= 6){
        printf("2: bought gold\n");
	    buyCard(gold, p);
        }
      else if (money >= 3){
        printf("2: bought silver\n");
	    buyCard(silver, p);
      }
      printf("2: endTurn\n");
      
      endTurn(p);      
    }
    //player 3
    else {
      if (adventurerPos != -1) {
        printf("3: adventurer played from position %d\n", adventurerPos);
	playCard(adventurerPos, -1, -1, -1, p); 
	money = 0;
	i=0;
	while(i<numHandCards(p)){
	  if (handCard(i, p) == copper){
	    playCard(i, -1, -1, -1, p);
	    money++;         
	  }
	  else if (handCard(i, p) == silver){
	    playCard(i, -1, -1, -1, p);
	    money += 2;
	  }
	  else if (handCard(i, p) == gold){
	    playCard(i, -1, -1, -1, p);
	    money += 3;
	  }
	  i++;
	}
      }


      if (money >= 8) {
        printf("3: bought province\n");
        buyCard(province, p);
      }
      else if ((money >= 6) && (numAdventurers < 2)) {
        printf("3: bought adventurer\n");
	buyCard(adventurer, p);
	numAdventurers++;
      }else if (money >= 6){
        printf("3: bought gold\n");
	    buyCard(gold, p);
        }
      else if (money >= 3){
        printf("3: bought silver\n");
	    buyCard(silver, p);
      }
      printf("3: endTurn\n");
      
      endTurn(p);      
    }

      printf ("Player 0: %d\nPlayer 1: %d\n", scoreFor(0, p), scoreFor(1, p));
      if (players == 3) {
              printf("Player 2: %d\n", scoreFor(2, p));
      } else if (players == 4) {
              printf("Player 2: %d\nPlayer 3: %d\n", scoreFor(2, p), scoreFor(3,p));
      }


  } // end of While

  printf ("Finished game.\n");
  printf ("Player 0: %d\nPlayer 1: %d\n", scoreFor(0, p), scoreFor(1, p));
  if (players == 3) {
              printf("Player 2: %d\n", scoreFor(2, p));
      } else if (players == 4) {
              printf("Player 2: %d\nPlayer 3: %d\n", scoreFor(2, p), scoreFor(3,p));
      }

  fullDeckCount(1, baron, p);
  getWinners(playerArray, p);
        } //end of while loop for multiple games
        return 0;
}
