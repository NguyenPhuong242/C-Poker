#include "DeckTest.h"
#include "Deck.h"

#include <assert.h>
#include <string.h>
#include <stdlib.h>

// //-----------------------------------------------------------------------------

void DeckTest_isEmpty (void) {
  Deck d; Deck_initEmpty (& d);
  assert (Deck_isEmpty (& d));
  Deck_appendCard (& d, Card_make (0, 0));
  assert ( ! Deck_isEmpty (& d));
}

void DeckTest_isFull (void) {
  Deck d; Deck_initEmpty (& d);
  assert ( ! Deck_isFull (& d));
  for (int k= 0; k < DECK_CAPACITY-1; k++) { 
    Deck_appendCard (& d, Card_make (0, 0));
    assert ( ! Deck_isFull (& d));
  }
  Deck_appendCard (& d, Card_make (0, 0));
  assert (Deck_isFull (& d));
}


//-----------------------------------------------------------------------------

void DeckTest_appendCard (void) {
  Deck d; Deck_initEmpty (& d);

  Deck_appendCard (& d, Card_makeFromPip ("2c")); assert (d.length == 1);
  Deck_appendCard (& d, Card_makeFromPip ("3d")); assert (d.length == 2);
  Deck_appendCard (& d, Card_makeFromPip ("4h")); assert (d.length == 3);
  
  assert (Card_pipEquals (d.cards[0], "2c"));
  assert (Card_pipEquals (d.cards[1], "3d"));
  assert (Card_pipEquals (d.cards[2], "4h"));
}

void DeckTest_popCard (void) {
  Deck d; Deck_initEmpty (& d);
  Deck_appendCard (& d, Card_makeFromPip ("2c"));
  Deck_appendCard (& d, Card_makeFromPip ("3d"));
  Deck_appendCard (& d, Card_makeFromPip ("4h"));
  assert (d.length == 3);
  
  Card popped1= Deck_popCard (& d);
  assert (d.length == 2);
  assert (Card_pipEquals (popped1,"4h"));
  
  Card popped2= Deck_popCard (& d);
  assert (d.length == 1);
  assert (Card_pipEquals (popped2, "3d"));
  
  Card popped3= Deck_popCard (& d);
  assert (d.length == 0);
  assert (Card_pipEquals (popped3, "2c"));
}

//-----------------------------------------------------------------------------

void DeckTest_initEmpty (void) {
  Deck d; Deck_initEmpty (& d);
  assert (d.length == 0);
}

void DeckTest_initComplete (void) {
  Deck d; Deck_initComplete (& d);
  assert (d.length == DECK_CAPACITY);
  assert (Deck_isSortedBySuitFirst (& d));
}

// //-----------------------------------------------------------------------------

void DeckTest_appendPips (void) {
  Deck d; Deck_initEmpty (& d);
  Deck_appendPips (& d, "2c 3d 4h");
  assert (d.length == 3);
  assert (Card_pipEquals (d.cards[0], "2c"));
  assert (Card_pipEquals (d.cards[1], "3d"));
  assert (Card_pipEquals (d.cards[2], "4h"));
}

void DeckTest_initFromPips (void) {
  Deck d; Deck_initFromPips (& d, "2c 3d 4h");
  assert (d.length == 3);
  assert (Card_pipEquals (d.cards[0], "2c"));
  assert (Card_pipEquals (d.cards[1], "3d"));
  assert (Card_pipEquals (d.cards[2], "4h"));
}

// //-----------------------------------------------------------------------------

void DeckTest_pipsEqual (void) {
  Deck d; Deck_initFromPips (& d, "2c 3d 4h");
 
  assert (   Deck_pipsEqual (& d, "2c 3d 4h"));
  assert ( ! Deck_pipsEqual (& d, "2c 5d 4h"));
  assert ( ! Deck_pipsEqual (& d, "2c 3d"  ));
}

// //-----------------------------------------------------------------------------

void DeckTest_indexIsValid (void) {
  Deck d; Deck_initFromPips (& d, "2c 3d 4h");

  assert ( ! Deck_indexIsValid (& d, -1));
  assert (   Deck_indexIsValid (& d,  0));
  assert (   Deck_indexIsValid (& d,  1));
  assert (   Deck_indexIsValid (& d,  2));
  assert ( ! Deck_indexIsValid (& d,  3));
}

void DeckTest_rangeIsValid (void) {
  Deck d; Deck_initFromPips (& d, "2c 3d 4h");

  assert ( ! Deck_rangeIsValid (& d, -1, 1));
   
  assert (   Deck_rangeIsValid (& d, 0, 1));
  assert (   Deck_rangeIsValid (& d, 0, 2));
  assert (   Deck_rangeIsValid (& d, 0, 3));
  assert ( ! Deck_rangeIsValid (& d, 0, 4));
  
  assert (   Deck_rangeIsValid (& d, 1, 1));
  assert (   Deck_rangeIsValid (& d, 1, 2));
  assert ( ! Deck_rangeIsValid (& d, 1, 3));
  
  assert (   Deck_rangeIsValid (& d, 2, 1));
  assert ( ! Deck_rangeIsValid (& d, 2, 2));

  assert ( ! Deck_rangeIsValid (& d, 3, 1));
}

// //-----------------------------------------------------------------------------

void DeckTest_swapCardsAt (void) {
  Deck d; Deck_initFromPips (& d, "2c 3d 4h 5s");
  Deck_swapCardsAt (& d, 1, 3);
  assert (Deck_pipsEqual (& d, "2c 5s 4h 3d"));
}

// //-----------------------------------------------------------------------------

void DeckTest_sortBySuitFirst (void) {
  Deck d; Deck_initFromPips (& d, "8c 4s 7c 3s");
  Deck_sortBySuitFirst (& d);
  assert (Deck_pipsEqual (& d, "4s 3s 8c 7c"));
}

void DeckTest_sortByRankFirst (void) {
  Deck d; Deck_initFromPips (& d, "8c 4d 8h 4s");
  Deck_sortByRankFirst (& d);
  assert (Deck_pipsEqual (& d, "8h 8c 4s 4d"));
}

// //-----------------------------------------------------------------------------

void DeckTest_isSortedByRankFirst (void) {
  Deck d1; Deck_initFromPips (& d1, "8h 8c 4s 4d");
  Deck d2; Deck_initFromPips (& d2, "8h 8c 4s 5d");
  assert (   Deck_isSortedByRankFirst (& d1));
  assert ( ! Deck_isSortedByRankFirst (& d2));
}

void DeckTest_isSortedBySuitFirst (void) {
  Deck d1; Deck_initFromPips (& d1, "4s 3s 8c 7c");
  Deck d2; Deck_initFromPips (& d2, "4s 3s 8c 7d");
  assert (   Deck_isSortedBySuitFirst (& d1));
  assert ( ! Deck_isSortedBySuitFirst (& d2));
}

void DeckTest_isSortedBySuitFirstWithNoEqual (void) {
  Deck d1; Deck_initFromPips (& d1, "4s 3s 8c 7c");
  Deck d2; Deck_initFromPips (& d2, "4s 3s 8c 8c");
  assert (   Deck_isSortedBySuitFirstWithNoEqual (& d1));
  assert ( ! Deck_isSortedBySuitFirstWithNoEqual (& d2));
}

void DeckTest_isSortedByRankWithNoKind (void) {
  Deck d1; Deck_initFromPips (& d1, "8h 7c 4s 3d");
  Deck d2; Deck_initFromPips (& d2, "8h 7c 4s 4d");
  assert (   Deck_isSortedByRankWithNoKind (& d1));
  assert ( ! Deck_isSortedByRankWithNoKind (& d2));
}

// //-----------------------------------------------------------------------------


void DeckTest_printPips (void) {
  char * string; size_t length;
  FILE * memstream= open_memstream (& string, & length);
  Deck d; Deck_initFromPips (& d, "2c 3d 4h 5s");
  Deck_printPips (& d, memstream);
  fclose (memstream);
  assert (strcmp (string, "2c 3d 4h 5s") == 0);
  free (string);
}


// //-----------------------------------------------------------------------------

void DeckTest_dealCardsTo (void) {
  Deck d1; Deck_initFromPips (& d1, "2c 3d 4h 5s");
  Deck d2; Deck_initFromPips (& d2, "Ah");
  Deck_dealCardsTo (& d1, 2, & d2);
  assert (Deck_pipsEqual (& d1, "2c 3d"));
  assert (Deck_pipsEqual (& d2, "Ah 5s 4h"));
}

// //-----------------------------------------------------------------------------

// void DeckTest_lengthOfKindAt (void) {
//   Deck d; Deck_initFromPips (& d, "Ac Td Th Ts 2d");
//   assert (Deck_lengthOfKindAt (& d, 1) == 3);
// }

// void DeckTest_lengthOfFlushAt (void) {
//   Deck d1; Deck_initFromPips (& d1, "2c 8d Jd Kd As");
//   Deck d2; Deck_initFromPips (& d2, "2c 8d Jd Kd Ad");
//   assert (Deck_lengthOfFlushAt (& d1, 1) == 3);
//   assert (Deck_lengthOfFlushAt (& d2, 1) == 4);
// }

// void DeckTest_lengthOfRegularStraightAt (void) {
//   Deck d1; Deck_initFromPips (& d1, "Kc Qd Js Tc 8s");
//   Deck d2; Deck_initFromPips (& d2, "Kc Qd Js Tc 9s");
//   assert (Deck_lengthOfRegularStraightAt (& d1, 1) == 3);
//   assert (Deck_lengthOfRegularStraightAt (& d2, 1) == 4);
// }

// void DeckTest_lengthOfRegularStrFlushAt (void) {
//   Deck d1; Deck_initFromPips (& d1, "Ac Qs Js Ts 8s");
//   Deck d2; Deck_initFromPips (& d2, "Ac Qs Js Ts 9s");
//   assert (Deck_lengthOfRegularStrFlushAt (& d1, 1) == 3);
//   assert (Deck_lengthOfRegularStrFlushAt (& d2, 1) == 4);
// }

// void DeckTest_lengthOfEqualsAt (void) {
//   Deck d1; Deck_initFromPips (& d1, "Ac Ts Ts Ts 2s");
//   Deck d2; Deck_initFromPips (& d2, "Ac Ts Ts Ts Ts");
//   assert (Deck_lengthOfEqualsAt (& d1, 1) == 3);
//   assert (Deck_lengthOfEqualsAt (& d2, 1) == 4);
// }

// //-----------------------------------------------------------------------------

// void DeckTest_startOfHighestKind (void) {
//   Deck d; Deck_initFromPips (& d, "As Ts Th Td 2c");
//   assert (Deck_startOfHighestKind (& d, 1) ==  0);
//   assert (Deck_startOfHighestKind (& d, 2) ==  1);
//   assert (Deck_startOfHighestKind (& d, 3) ==  1);
//   assert (Deck_startOfHighestKind (& d, 4) == -1);
// }

// void DeckTest_startOfHighestFlush (void) {
//   Deck d; Deck_initFromPips (& d, "As Ts Qh 8h 5h");
//   assert (Deck_startOfHighestFlush (& d, 1) ==  0);
//   assert (Deck_startOfHighestFlush (& d, 2) ==  0);
//   assert (Deck_startOfHighestFlush (& d, 3) ==  2);
//   assert (Deck_startOfHighestFlush (& d, 4) == -1);
// }

// void DeckTest_startOfHighestRegularStraight (void) {
//   Deck d; Deck_initFromPips (& d, "As Ks Th 9d 8c");
//   assert (Deck_startOfHighestRegularStraight (& d, 1) ==  0);
//   assert (Deck_startOfHighestRegularStraight (& d, 2) ==  0);
//   assert (Deck_startOfHighestRegularStraight (& d, 3) ==  2);
//   assert (Deck_startOfHighestRegularStraight (& d, 4) == -1);
// }

// void DeckTest_startOfHighestRegularStrFlush (void) {
//   Deck d; Deck_initFromPips (& d, "Ks Qs Th 9h 8h 8d 7d 6d 5d Ac");
//   assert (Deck_startOfHighestRegularStrFlush (& d, 1) ==  9);
//   assert (Deck_startOfHighestRegularStrFlush (& d, 2) ==  0);
//   assert (Deck_startOfHighestRegularStrFlush (& d, 3) ==  2);
//   assert (Deck_startOfHighestRegularStrFlush (& d, 4) ==  5);
//   assert (Deck_startOfHighestRegularStrFlush (& d, 5) == -1);
// }

// //-----------------------------------------------------------------------------

// void DeckTest_killRangeAt (void) {
//   Deck d1; Deck_initFromPips (& d1, "As Ks Qs Qh Qc 8c");
//   Deck_killRangeAt (& d1, 2, 3);
//   assert (Deck_pipsEqual (& d1, "As Ks 8c"));

//   Deck d2; Deck_initFromPips (& d2, "As Ks Kh Kc 8c");
//   Deck_killRangeAt (& d2, 2, 3);
//   assert (Deck_pipsEqual (& d2, "As Ks"));
// }

// void DeckTest_copyRangeAt (void) {
//   Deck d1; Deck_initFromPips (& d1, "Ks Qh Qd Qc Tc");
//   Deck d2; Deck_initFromPips (& d2, "As");
   
//   Deck_copyRangeAt (& d1, 2, 3, & d2);
//   assert (Deck_pipsEqual (& d1, "Ks Qh Qd Qc Tc"));
//   assert (Deck_pipsEqual (& d2, "As Qd Qc Tc"));
// }

// void DeckTest_keepOnlyOneCardPerKind (void) {
//   Deck d; Deck_initFromPips (& d, "Qs Qh Jh Td Tc");
//   Deck_keepOnlyOneCardPerKind (& d);
//   assert (Deck_pipsEqual (& d, "Qs Jh Td"));
// }

// void DeckTest_keepOnlyOneCardPerEqual (void) {
//   Deck d; Deck_initFromPips (& d, "Qs Qs Qh Td Td");
//   Deck_keepOnlyOneCardPerEqual (& d);
//   assert (Deck_pipsEqual (& d, "Qs Qh Td"));
// }

void DeckTest_runAll (void) {
  DeckTest_isFull();
  DeckTest_isEmpty();
  DeckTest_appendCard();
  DeckTest_popCard();
  DeckTest_initEmpty();
  DeckTest_initComplete();
  DeckTest_appendPips();
  DeckTest_initFromPips();
  DeckTest_pipsEqual();
  DeckTest_indexIsValid();
  DeckTest_rangeIsValid();
  DeckTest_swapCardsAt();
  DeckTest_sortBySuitFirst();
  DeckTest_sortByRankFirst();
  DeckTest_isSortedByRankFirst();
  DeckTest_isSortedBySuitFirst();
  DeckTest_isSortedBySuitFirstWithNoEqual();
  DeckTest_isSortedByRankWithNoKind();
  DeckTest_printPips();
  DeckTest_dealCardsTo();
//   DeckTest_lengthOfKindAt ();
//   DeckTest_lengthOfFlushAt(); 
//   DeckTest_lengthOfRegularStraightAt();
//   DeckTest_lengthOfRegularStrFlushAt();
//   DeckTest_lengthOfEqualsAt();
//   DeckTest_startOfHighestKind();
//   DeckTest_startOfHighestFlush();
//   DeckTest_startOfHighestRegularStraight();
//   DeckTest_startOfHighestRegularStrFlush();
//   DeckTest_killRangeAt();
//   DeckTest_copyRangeAt();
//   DeckTest_keepOnlyOneCardPerKind();
//   DeckTest_keepOnlyOneCardPerEqual();
}
