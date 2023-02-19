
#ifndef CARD_H
#define CARD_H

#include <stdbool.h>
#include <stdio.h>

#define RANK_COUNT 13
#define SUIT_COUNT 4

extern char const RANK_PIPS[RANK_COUNT+1];
extern char const SUIT_PIPS[SUIT_COUNT+1];

typedef struct Card {
  int rank, suit;
} Card;

bool Card_rankIsValid (int rank);
bool Card_suitIsValid (int suit);

Card Card_make (int rank, int suit);

bool Card_isPaired (Card card1, Card card2);
bool Card_isSuited (Card card1, Card card2);
bool Card_equals   (Card card1, Card card2);

int  Card_rankFromPip (char rankPip);
int  Card_suitFromPip (char suitPip);

Card Card_makeFromPip (char const pip[]);

char Card_rankPip (Card card);
char Card_suitPip (Card card);

bool Card_pipEquals  (Card card, char const pip[]);

void Card_printPip (Card card, FILE * file);

int Card_compareByRankOnly (Card card1, Card card2);
int Card_compareBySuitOnly (Card card1, Card card2);

int Card_compareByRankFirst (Card card1, Card card2);
int Card_compareBySuitFirst (Card card1, Card card2);

int Card_compareArrayByRankOnly (Card const cards1[],
                                 Card const cards2[], int n);

bool Card_isAce   (Card card);
bool Card_isDeuce (Card card);

bool Card_isAceDeuceConnector       (Card hiCard, Card loCard);
bool Card_isRegularConnector        (Card hiCard, Card loCard);
bool Card_isAceDeuceSuitedConnector (Card hiCard, Card loCard);
bool Card_isRegularSuitedConnector  (Card hiCard, Card loCard);

#endif
