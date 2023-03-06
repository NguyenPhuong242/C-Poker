#ifndef DECK_TEST_H
#define DECK_TEST_H

void DeckTest_isFull(void);
void DeckTest_isEmpty(void);

void DeckTest_appendCard(void);
void DeckTest_popCard(void);

void DeckTest_initEmpty(void);
void DeckTest_initComplete(void);

void DeckTest_appendPips(void);
void DeckTest_initFromPips(void);

void DeckTest_pipsEqual(void);

void DeckTest_indexIsValid(void);
void DeckTest_rangeIsValid(void);

void DeckTest_swapCardsAt(void);

void DeckTest_sortBySuitFirst(void);
void DeckTest_sortByRankFirst(void);

// void DeckTest_isSortedByRankFirst (void);
// void DeckTest_isSortedBySuitFirst (void);
// void DeckTest_isSortedBySuitFirstWithNoEqual (void);
// void DeckTest_isSortedByRankWithNoKind (void);

void DeckTest_printPips(void);

void DeckTest_dealCardsTo(void);

// void DeckTest_lengthOfKindAt (void);
// void DeckTest_lengthOfFlushAt (void);
// void DeckTest_lengthOfRegularStraightAt (void);
// void DeckTest_lengthOfRegularStrFlushAt (void);
// void DeckTest_lengthOfEqualsAt (void);

// void DeckTest_startOfHighestKind (void);
// void DeckTest_startOfHighestFlush (void);
// void DeckTest_startOfHighestRegularStraight (void);
// void DeckTest_startOfHighestRegularStrFlush (void);

// void DeckTest_killRangeAt (void);
// void DeckTest_copyRangeAt (void);

// void DeckTest_keepOnlyOneCardPerKind (void);
// void DeckTest_keepOnlyOneCardPerEqual (void);

void DeckTest_runAll(void);

#endif
