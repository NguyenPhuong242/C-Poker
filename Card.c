#include "Card.h"
#include <assert.h>
#include <string.h>
#include <stdbool.h>


char const RANK_PIPS[] = "23456789TJQKA";
char const SUIT_PIPS[] = "cdhs";

bool Card_rankIsValid(int rank){
    return ( rank >= 0) && (rank < RANK_COUNT);
}

bool Card_suitIsValid(int suit){
    return ( suit >= 0) && (suit < SUIT_COUNT);
}

Card Card_make(int rank, int suit){
    return (Card){.rank = rank, .suit= suit};
}

bool Card_isPaired(Card card1, Card card2){
    return card1.rank == card2.rank;
}

bool Card_isSuited(Card card1, Card card2){
    return card1.suit == card2.suit;
}

bool Card_equals(Card card1, Card card2){
    return (Card_isPaired(card1,card2)) && (Card_isSuited(card1,card2));
}

int Card_rankFromPip(char rankPip){
    char * f = strchr(RANK_PIPS, rankPip);
    if(f==NULL){
        return -1;
    }
    return f - RANK_PIPS;
}

int Card_suitFromPip(char suitPip){
    char * f = strchr(SUIT_PIPS, suitPip);
    if(f==NULL){
        return -1;
    }
    return f - SUIT_PIPS;
}

Card Card_makeFromPip(const char pip[]){
    assert(strlen(pip)==2);
    int rank = Card_rankFromPip(pip[0]);
    assert(rank!=-1);
    int suit = Card_suitFromPip(pip[1]);
    assert(suit!=-1);
    return Card_make(rank, suit);
}

char Card_rankPip (Card card){
    return RANK_PIPS[card.rank];
}

char Card_suitPip (Card card){
    return SUIT_PIPS[card.suit];
}

bool Card_pipEquals(Card card, char const pip[]){
    return (Card_rankPip(card) == pip[0]) && (Card_suitPip(card) == pip[1]);
}

void Card_printPip(Card card, FILE * file){
    fprintf(file, "%c%c", Card_rankPip(card), Card_suitPip(card));
}

int Card_compareByRankOnly(Card card1, Card card2){
    return card1.rank - card2.rank;
}

int Card_compareBySuitOnly(Card card1, Card card2){
    return card1.suit - card2.suit;
}

int Card_compareByRankFirst (Card card1, Card card2){
    if(Card_compareByRankOnly(card1, card2)==0){
        return Card_compareBySuitOnly(card1,card2);
    }
    return Card_compareByRankOnly(card1, card2);
}

int Card_compareBySuitFirst (Card card1, Card card2){
    if(Card_compareBySuitOnly(card1, card2)==0){
        return Card_compareByRankOnly(card1,card2);
    }
    return Card_compareBySuitOnly(card1, card2);
}

int Card_compareArrayByRankOnly (Card const cards1[], Card const cards2[], int n){
    assert(cards1 == 0 && cards2 == 0);
    int i;
    for(i = 0; i < n ;){
        if(cards1[i].rank == cards2[i].rank){
            i = i + 1;
        }
    }
    return cards1[i+1].rank - cards2[i+1].rank;
}

bool Card_isAce(Card card){
    return Card_rankPip(card) == 'A';
}
bool Card_isDeuce(Card card){
    return Card_rankPip(card) == '2';
}
bool Card_isAceDeuceConnector (Card hiCard, Card loCard){
    return (Card_isAce(hiCard)&&Card_isDeuce(loCard));

}
bool Card_isRegularConnector(Card hiCard, Card loCard){
    return (hiCard.rank - loCard.rank) == 1;
}
bool Card_isAceDeuceSuitedConnector (Card hiCard, Card loCard){
    return Card_isAceDeuceConnector(hiCard, loCard) && (hiCard.suit == loCard.suit);
}
bool Card_isRegularSuitedConnector  (Card hiCard, Card loCard){
    return Card_isRegularConnector(hiCard, loCard) && (hiCard.suit == loCard.suit);
}











