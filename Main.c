#include "Hand.h"
#include "CardTest.h"
#include "DeckTest.h"
// #include "HandTest.h"

#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//-----------------------------------------------------------------------------

// long wikiTotal= 133784560L;

// long wikiHits [HAND_COUNT]= {  
//   23294460L, 58627800L, 31433400L,
//   6461620L, 6180020L, 4047644L,
//   3473184L,  224848L, 4324L + 37260L
// };

//-----------------------------------------------------------------------------

int main (void) { 
  CardTest_runAll();
  DeckTest_runAll();
  // HandTest_runAll();

  // srand(time(NULL));  
  // int hits[HAND_COUNT]= { 0 };
  // int deal_count= 900000;
  
  // for (int k= 0; k < deal_count; k++) {
  //   Deck deck, dealt, witness;
  //   Deck_initComplete (& deck);
  //   Deck_shuffle (& deck);
  //   Deck_initEmpty (& dealt);
  //   Deck_dealCardsTo (& deck, 7, & dealt); 

  //   Hand hand= Hand_findBest (& dealt, & witness);
  //   assert (hand != HAND_UNKNOWN);
  //   hits[hand]++;

  //   if ((k+1) % 1000 != 0) continue;
    
  //   Deck_printPips (& witness, stdout);
  //   printf (" (%s)\n", HAND_NAMES[hand]);
    
  //   for (int h= 0; h < HAND_COUNT; h++) {
  //     double percent=  100.0 * hits    [h] / (k+1);
  //     double expected= 100.0 * wikiHits[h] / wikiTotal;
  //     printf ("%10s: %8d / %8d = %8.4f %% (%+.4f)\n",
  //             HAND_NAMES[h], hits[h], k+1, percent, percent-expected);
  //   }
  // }
  
  
  return 0;
}


