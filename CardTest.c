#include "CardTest.h"
#include "Card.h"

#include <assert.h>
#include <string.h>
#include <stdlib.h>

//-----------------------------------------------------------------------------

void CardTest_rankIsValid (void) {
  assert ( ! Card_rankIsValid (-1));
  for (int rank= 0; rank < RANK_COUNT; rank++) {
    assert (Card_rankIsValid (rank));
  }
  assert ( ! Card_rankIsValid (RANK_COUNT));
}

void CardTest_suitIsValid (void) {
  assert ( ! Card_suitIsValid (-1));
  for (int suit= 0; suit < SUIT_COUNT; suit++) {
    assert (Card_suitIsValid (suit));
  }
  assert ( ! Card_suitIsValid (SUIT_COUNT));
}

//-----------------------------------------------------------------------------

void CardTest_make (void) {
  Card card= Card_make (10, 2);
  assert (card.rank == 10);
  assert (card.suit == 2);
}

//-----------------------------------------------------------------------------

void CardTest_isPaired (void) {
  assert (   Card_isPaired (Card_make (8, 2), Card_make (8, 2)));
  assert ( ! Card_isPaired (Card_make (8, 2), Card_make (7, 2)));
  assert (   Card_isPaired (Card_make (8, 2), Card_make (8, 1)));
  assert ( ! Card_isPaired (Card_make (8, 2), Card_make (7, 1)));
}

void CardTest_isSuited (void) {
  assert (   Card_isSuited (Card_make (8, 2), Card_make (8, 2)));
  assert (   Card_isSuited (Card_make (8, 2), Card_make (7, 2)));
  assert ( ! Card_isSuited (Card_make (8, 2), Card_make (8, 1)));
  assert ( ! Card_isSuited (Card_make (8, 2), Card_make (7, 1)));
}

void CardTest_equals (void) {
  assert (   Card_equals (Card_make (8, 2), Card_make (8, 2)));
  assert ( ! Card_equals (Card_make (8, 2), Card_make (7, 2)));
  assert ( ! Card_equals (Card_make (8, 2), Card_make (8, 1)));
  assert ( ! Card_equals (Card_make (8, 2), Card_make (7, 1)));
}

//-----------------------------------------------------------------------------

void CardTest_rankFromPip (void) {
  assert (Card_rankFromPip ('?') == -1);
  assert (Card_rankFromPip ('2') ==  0);
  assert (Card_rankFromPip ('A') == 12);
}

void CardTest_suitFromPip (void) {
  assert (Card_suitFromPip ('?') == -1);
  assert (Card_suitFromPip ('c') ==  0);
  assert (Card_suitFromPip ('s') ==  3); 
}

// //-----------------------------------------------------------------------------

void CardTest_makeFromPip (void) {
  Card card= Card_makeFromPip ("Ks");
  assert (card.rank == 11);
  assert (card.suit ==  3);
}

// //-----------------------------------------------------------------------------

void CardTest_rankPip (void) {
  Card card= Card_makeFromPip ("Ks");
  assert (Card_rankPip (card) == 'K');
}

void CardTest_suitPip (void) {
  Card card= Card_makeFromPip ("Ks");
  assert (Card_suitPip (card) == 's');
}

void CardTest_pipEquals (void) {
  Card card= Card_makeFromPip ("Ks");
  assert (   Card_pipEquals (card, "Ks"));
  assert ( ! Card_pipEquals (card, "Kd"));
  assert ( ! Card_pipEquals (card, "Qs"));
}

// //-----------------------------------------------------------------------------

void CardTest_printPip (void) {
  char * string; size_t length;
  FILE * memstream= open_memstream (& string, & length);
  Card_printPip (Card_makeFromPip ("Ks"), memstream);
  fclose (memstream);
  assert (length == 2);
  assert (strcmp (string, "Ks") == 0);
  free (string);
}

// //-----------------------------------------------------------------------------

void CardTest_compareByRankOnly (void) {
  assert (Card_compareByRankOnly (Card_make(4,1), Card_make(6,3)) <  0);
  assert (Card_compareByRankOnly (Card_make(4,2), Card_make(6,2)) <  0);
  assert (Card_compareByRankOnly (Card_make(4,3), Card_make(6,1)) <  0);
  
  assert (Card_compareByRankOnly (Card_make(5,1), Card_make(5,3)) == 0);
  assert (Card_compareByRankOnly (Card_make(5,2), Card_make(5,2)) == 0);
  assert (Card_compareByRankOnly (Card_make(5,3), Card_make(5,1)) == 0);
 
  assert (Card_compareByRankOnly (Card_make(6,1), Card_make(4,3)) >  0);
  assert (Card_compareByRankOnly (Card_make(6,2), Card_make(4,2)) >  0);
  assert (Card_compareByRankOnly (Card_make(6,3), Card_make(4,1)) >  0);
}

void CardTest_compareBySuitOnly (void) {
  assert (Card_compareBySuitOnly (Card_make(4,1), Card_make(6,3)) <  0);
  assert (Card_compareBySuitOnly (Card_make(5,1), Card_make(5,3)) <  0);
  assert (Card_compareBySuitOnly (Card_make(6,1), Card_make(4,3)) <  0);
  
  assert (Card_compareBySuitOnly (Card_make(4,2), Card_make(6,2)) == 0);
  assert (Card_compareBySuitOnly (Card_make(5,2), Card_make(5,2)) == 0);
  assert (Card_compareBySuitOnly (Card_make(6,2), Card_make(4,2)) == 0);

  assert (Card_compareBySuitOnly (Card_make(4,3), Card_make(4,1)) >  0);
  assert (Card_compareBySuitOnly (Card_make(5,3), Card_make(5,1)) >  0);
  assert (Card_compareBySuitOnly (Card_make(6,3), Card_make(6,1)) >  0);
}

void CardTest_compareByRankFirst (void) {
  assert (Card_compareByRankFirst (Card_make(4,1), Card_make(6,3)) <  0);
  assert (Card_compareByRankFirst (Card_make(4,2), Card_make(6,2)) <  0);
  assert (Card_compareByRankFirst (Card_make(4,3), Card_make(6,1)) <  0);
  
  assert (Card_compareByRankFirst (Card_make(5,1), Card_make(5,3)) <  0);
  assert (Card_compareByRankFirst (Card_make(5,2), Card_make(5,2)) == 0);
  assert (Card_compareByRankFirst (Card_make(5,3), Card_make(5,1)) >  0);
 
  assert (Card_compareByRankFirst (Card_make(6,1), Card_make(4,3)) >  0);
  assert (Card_compareByRankFirst (Card_make(6,2), Card_make(4,2)) >  0);
  assert (Card_compareByRankFirst (Card_make(6,3), Card_make(4,1)) >  0);
}

void CardTest_compareBySuitFirst (void) {
  assert (Card_compareBySuitFirst (Card_make(4,1), Card_make(6,3)) <  0);
  assert (Card_compareBySuitFirst (Card_make(5,1), Card_make(5,3)) <  0);
  assert (Card_compareBySuitFirst (Card_make(6,1), Card_make(4,3)) <  0);
  
  assert (Card_compareBySuitFirst (Card_make(4,2), Card_make(6,2)) <  0);
  assert (Card_compareBySuitFirst (Card_make(5,2), Card_make(5,2)) == 0);
  assert (Card_compareBySuitFirst (Card_make(6,2), Card_make(4,2)) >  0);

  assert (Card_compareBySuitFirst (Card_make(4,3), Card_make(4,1)) >  0);
  assert (Card_compareBySuitFirst (Card_make(5,3), Card_make(5,1)) >  0);
  assert (Card_compareBySuitFirst (Card_make(6,3), Card_make(6,1)) >  0);
}

void CardTest_compareArrayByRankOnly (void) {
  Card cards1[]= { Card_make(5,1), Card_make(3,2), Card_make (2,3) };
  Card cards2[]= { Card_make(5,3), Card_make(4,2), Card_make (2,1) };

  assert (Card_compareArrayByRankOnly (cards1, cards2, 3) <  0);
  assert (Card_compareArrayByRankOnly (cards2, cards1, 3) >  0);
  assert (Card_compareArrayByRankOnly (cards1, cards1, 3) == 0);
  assert (Card_compareArrayByRankOnly (cards2, cards2, 3) == 0);
}

// //-----------------------------------------------------------------------------

void CardTest_isAce (void) {
  assert (   Card_isAce (Card_makeFromPip ("As")));
  assert ( ! Card_isAce (Card_makeFromPip ("2s")));
}

void CardTest_isDeuce (void) {
  assert (   Card_isDeuce (Card_makeFromPip ("2s")));
  assert ( ! Card_isDeuce (Card_makeFromPip ("As")));
}

void CardTest_isAceDeuceConnector (void) {
  assert (   Card_isAceDeuceConnector (Card_makeFromPip ("As"),
                                       Card_makeFromPip ("2c")));
  
  assert ( ! Card_isAceDeuceConnector (Card_makeFromPip ("Kc"),
                                       Card_makeFromPip ("As")));
  
  assert ( ! Card_isAceDeuceConnector (Card_makeFromPip ("2c"),
                                       Card_makeFromPip ("As")));
             
}

void CardTest_isRegularConnector (void) {
  assert (   Card_isRegularConnector (Card_makeFromPip ("As"),
                                      Card_makeFromPip ("Kc")));
  
  assert ( ! Card_isRegularConnector (Card_makeFromPip ("As"),
                                      Card_makeFromPip ("2c")));

  assert ( ! Card_isRegularConnector (Card_makeFromPip ("Ks"),
                                      Card_makeFromPip ("Ac")));
}

// //-----------------------------------------------------------------------------

void CardTest_isAceDeuceSuitedConnector (void) {
  assert (   Card_isAceDeuceSuitedConnector (Card_makeFromPip ("As"),
                                             Card_makeFromPip ("2s")));
  
  assert ( ! Card_isAceDeuceSuitedConnector (Card_makeFromPip ("Ah"),
                                             Card_makeFromPip ("2d")));
}

void CardTest_isRegularSuitedConnector (void) {
  assert (   Card_isRegularSuitedConnector (Card_makeFromPip ("As"),
                                            Card_makeFromPip ("Ks")));
  
  assert ( ! Card_isRegularSuitedConnector (Card_makeFromPip ("Ah"),
                                            Card_makeFromPip ("Kd")));
}

//-----------------------------------------------------------------------------


void CardTest_runAll (void) {
  CardTest_rankIsValid();
  CardTest_suitIsValid();
  CardTest_make();
  CardTest_isPaired();
  CardTest_isSuited();
  CardTest_equals();
  CardTest_rankFromPip();
  CardTest_suitFromPip();
  CardTest_makeFromPip();
  CardTest_rankPip();
  CardTest_suitPip();
  CardTest_pipEquals();
  CardTest_printPip();
  CardTest_compareByRankOnly();
  CardTest_compareBySuitOnly();
  CardTest_compareByRankFirst();
  CardTest_compareBySuitFirst();
  CardTest_compareArrayByRankOnly();
  CardTest_isAce();
  CardTest_isDeuce();
  CardTest_isAceDeuceConnector();
  CardTest_isRegularConnector();
  CardTest_isAceDeuceSuitedConnector();
  CardTest_isRegularSuitedConnector();
}
