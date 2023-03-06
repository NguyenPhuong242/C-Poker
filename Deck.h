
#ifndef DECK_H
#define DECK_H

#include "Card.h"

#define DECK_CAPACITY (RANK_COUNT * SUIT_COUNT)

typedef struct Deck {
  Card cards [DECK_CAPACITY];
  int length;
} Deck;


bool Deck_isFull  (Deck const * deck);
bool Deck_isEmpty (Deck const * deck);

void Deck_appendCard (Deck * deck, Card card);
Card Deck_popCard    (Deck * deck);

void Deck_initEmpty (Deck * deck);
void Deck_initComplete (Deck * deck);

bool Deck_pipsEqual    (Deck const * deck, char const pips[]);

void Deck_appendPips   (Deck * deck, char const pips []);
void Deck_initFromPips (Deck * deck, char const pips []);

bool Deck_indexIsValid (Deck const * deck, int index);
bool Deck_rangeIsValid (Deck const * deck, int start, int length);

void Deck_swapCardsAt (Deck * deck, int index1, int index2);
void Deck_shuffle     (Deck * deck);

void Deck_sortBySuitFirst (Deck * deck);
void Deck_sortByRankFirst (Deck * deck);

bool Deck_isSortedByRankFirst (Deck const * deck);
bool Deck_isSortedBySuitFirst (Deck const * deck);
bool Deck_isSortedBySuitFirstWithNoEqual (Deck const * deck);
bool Deck_isSortedByRankWithNoKind (Deck const * deck);

void Deck_printPips (Deck const * deck, FILE * file);

void Deck_dealCardsTo (Deck * deck, int cardCount, Deck * dealed);

// int Deck_lengthOfKindAt            (Deck const * deck, int start);
// int Deck_lengthOfFlushAt           (Deck const * deck, int start);
// int Deck_lengthOfRegularStraightAt (Deck const * deck, int start);
// int Deck_lengthOfRegularStrFlushAt (Deck const * deck, int start);
// int Deck_lengthOfEqualsAt          (Deck const * deck, int start);

// int Deck_startOfHighestKind  (Deck const * deck, int kindLength);
// int Deck_startOfHighestFlush (Deck const * deck, int flushLength);
// int Deck_startOfHighestRegularStraight (Deck const * deck, int straightLength);
// int Deck_startOfHighestRegularStrFlush (Deck const * deck, int strFlushLength);

// void Deck_killRangeAt (Deck * deck, int start, int length);
// void Deck_copyRangeAt (Deck const *deck, int start, int length, Deck *copy);

// void Deck_keepOnlyOneCardPerKind  (Deck * deck);
// void Deck_keepOnlyOneCardPerEqual (Deck * deck);

#endif
