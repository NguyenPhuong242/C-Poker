#include "Card.h"
#include <assert.h>
#include <string.h>
#include "Deck.h"
#include <stdlib.h>

bool Deck_isEmpty(Deck const * deck){
    return(deck ->length == 0);
}

bool Deck_isFull(Deck const * deck){
    return(deck->length == DECK_CAPACITY);
}

void Deck_appendCard(Deck * deck, Card card){
    assert(!Deck_isFull(deck));
    deck->cards[deck->length] = card;
    deck->length++;
}

Card Deck_popCard(Deck * deck){
    assert(!Deck_isEmpty(deck));
    deck->length--;
    return deck->cards[deck->length];
}

void Deck_initEmpty(Deck * deck){
    deck->length = 0;
}

void Deck_initComplete (Deck * deck){
    Deck_isEmpty(deck);
    int suit;
    int rank;
    for(suit = SUIT_COUNT - 1; suit >= 0; suit--){
        for(rank = RANK_COUNT - 1; rank >= 0; rank--){
            Deck_appendCard(deck, Card_make(rank,suit));
        }
    }
}

bool Deck_pipsEqual(Deck const * deck, char const pips[]){
    assert(deck->length == (int) strlen(pips));
    int i;
    bool result;
    for(i = 0; i < deck->length; i++){
        if(!Card_pipEquals(deck->cards[i], pips)){
            result = false;
        }
        result =  true;
    }
    return result;
}

void Deck_printPips (Deck const * deck, FILE * file){
    assert(!Deck_isEmpty(deck));
    int i;
    for(i = 0; i < deck->length ; i ++){
        Card_printPip(deck->cards[i], file);
    }
}

void Deck_appendPips   (Deck * deck, char const pips []){
    assert(!Deck_isFull(deck));
    assert(strlen(pips)!=0);
    int i;
    for(i = 0; i < deck->length ; i++){
        if(strlen(pips)%2==0){
            if(!Card_equals(Card_make(pips[2*i], pips[2*i+1]),deck->cards[i])){   
                Deck_appendCard(deck, Card_make(pips[i], pips[i+1]));
            }
        }
    }
}

void Deck_initFromPips(Deck* deck, char const pips[]) {
    Deck_initEmpty(deck);
    Deck_appendPips(deck, pips);
}

bool Deck_indexIsValid(Deck const* deck, int index) {
    return index >= 0 && index < deck->length;
}

bool Deck_rangeIsValid(Deck const* deck, int start, int length) {
    return start >= 0 && start + length <= deck->length;
}

static int Random_intBetween(int left, int right) {
    return left + rand()%(right-left+1);
}

void Deck_swapCardsAt(Deck* deck, int index1, int index2) {
    Card temp = deck->cards[index1];
    deck->cards[index1] = deck->cards[index2];
    deck->cards[index2] = temp;
}

void Deck_shuffle(Deck* deck) {
    int i;
    for (i = 0; i < deck->length; i++) {
        int j = Random_intBetween(i, deck->length - 1);
        Deck_swapCardsAt(deck, i, j);
    }
}

void Deck_dealCardsTo(Deck* deck, int cardCount, Deck* target) {
    int i;
    for (i = cardCount - 1; i >= 0; i--) {
        Deck_appendCard(target, deck->cards[deck->length - 1]);
        Deck_popCard(deck);
    }
}

static int reverseCompareCardBySuitFirst(void const* data1, void const* data2) {
    Card const* card1 = (Card const*)data1;
    Card const* card2 = (Card const*)data2;
    return -Card_compareBySuitFirst(*card1, *card2);
}

static int reverseCompareCardByRankFirst(void const* data1, void const* data2) {
    Card const* card1 = (Card const*)data1;
    Card const* card2 = (Card const*)data2;
    return -Card_compareByRankFirst(*card1, *card2);
}

bool Deck_isSortedBySuitFirst (Deck const * deck) {
    qsort(deck->cards, deck->length, sizeof(Card), reverseCompareCardBySuitFirst);
}

bool Deck_isSortedByRankFirst (Deck const * deck) {
    qsort(deck->cards, deck->length, sizeof(Card), reverseCompareCardByRankFirst);
}


