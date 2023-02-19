#ifndef CARD_TEST_H
#define CARD_TEST_H

void CardTest_rankIsValid (void);
void CardTest_suitIsValid (void);
void CardTest_make (void);

void CardTest_isPaired (void);
void CardTest_isSuited (void);
void CardTest_equals   (void);

void CardTest_rankFromPip (void);
void CardTest_suitFromPip (void);
void CardTest_makeFromPip (void);

void CardTest_rankPip (void);
void CardTest_suitPip (void);
void CardTest_pipEquals (void);
void CardTest_printPip (void);

void CardTest_compareByRankOnly (void);
void CardTest_compareBySuitOnly (void);
void CardTest_compareByRankFirst (void);
void CardTest_compareBySuitFirst (void);
void CardTest_compareArrayByRankOnly (void);

void CardTest_isAce (void);
void CardTest_isDeuce (void);
void CardTest_isAceDeuceConnector (void);
void CardTest_isRegularConnector (void);
void CardTest_isAceDeuceSuitedConnector (void);
void CardTest_isRegularSuitedConnector (void);

void CardTest_runAll (void);

#endif
