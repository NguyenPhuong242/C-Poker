#include "Card.h"
#include <assert.h>
#include <string.h>
#include "Deck.h"

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
    assert(deck->length == strlen[pips]);
    int i;
    for(i = deck->length - 1; i >= 0;){
        if(pips[i] == Deck_popCard(deck)){
            i = i - 1;
        }
        else{
            return false;
        }
    }
    return deck->cards[i] == pips[i];
}

void Deck_printPips (Deck const * deck, FILE * file){
    assert(!Deck_isEmpty(deck));
    int i;
    for(i = 0; i < deck->length -1; i ++){
        fprintf(file, "%c%c", deck->cards[i]);
    }
}

void Deck_appendPips   (Deck * deck, char const pips []){
    assert(!Deck_isFull(deck));
    assert(strlen(pips)!=0);
    int i;
    for(i = 0; i < deck->length - 1; i++){
        if(strlen(pips)%2==0){
            if(deck->cards[i] != Card_make(pips[i], pips[i+1])){
                Deck_appendCard(deck, Card_make(pips[i], pips[i+1]));
            }
            return 0;
        }
    }
    return -1;
}
void Deck_initFromPips (Deck * deck, char const pips []){
    assert(!Deck_isEmpty(deck));
    int i;
    if(strlen(pips)%2==0){
        deck->length = strlen(pips) / 2;
        for(i = deck->length; i>=0; i--){
            deck->cards[i] = Card_make(pips[i])
        }
    }
}


// void Deck_appendPips(Deck* deck, char const pips[]) {
//     char* carddesk = strtok(pips, " ");
//     while (carddesk != NULL) {
//         Card card = Card_fromPips(carddesk);
//         Deck_appendCard(deck, card);
//         carddesk = strtok(NULL, " ");
//     }
// }

// void Deck_initFromPips(Deck* deck, char const pips[]) {
//     Deck_initEmpty(deck);
//     Deck_appendPips(deck, pips);
// }

bool Deck_indexIsValid(Deck const* deck, int index) {
    return index >= 0 && index < deck->count;
}

bool Deck_rangeIsValid(Deck const* deck, int start, int length) {
    return start >= 0 && start + length <= deck->count;
}




