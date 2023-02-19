
// #include "Deck.h"
// #ifndef HAND_H
// #define HAND_H

// //------------------------------------------------------------------------------

// typedef enum Hand {
//   HAND_UNKNOWN= -1,
//   HAND_HICARD,
//   HAND_PAIR,
//   HAND_2PAIRS,
//   HAND_TRIPS,
//   HAND_STRAIGHT,
//   HAND_FLUSH,
//   HAND_BOAT,
//   HAND_QUADS,
//   HAND_STRFLUSH,
//   HAND_COUNT
// } Hand;

// extern char const * HAND_NAMES[HAND_COUNT];

// //------------------------------------------------------------------------------

// bool Hand_extractKind           (Deck * source, int kindLength, Deck * target);
// bool Hand_extractRegularStraight (Deck * source, Deck * target);
// bool Hand_extractWheelStraight   (Deck * source, Deck * target);
// bool Hand_extractFlush           (Deck * source, Deck * target);
// bool Hand_extractRegularStrFlush (Deck * source, Deck * target);
// bool Hand_extractWheelStrFlush   (Deck * source, Deck * target);

// bool Hand_findHiCard   (Deck const * source, Deck * target);
// bool Hand_findPair     (Deck const * source, Deck * target);
// bool Hand_find2Pairs   (Deck const * source, Deck * target);
// bool Hand_findTrips    (Deck const * source, Deck * target);
// bool Hand_findBoat     (Deck const * source, Deck * target);
// bool Hand_findQuads    (Deck const * source, Deck * target);

// bool Hand_findStraight (Deck const * source, Deck * target);
// bool Hand_findFlush    (Deck const * source, Deck * target);
// bool Hand_findStrFlush (Deck const * source, Deck * target);

// Hand Hand_findBest (Deck const * source, Deck * target);
  
// //------------------------------------------------------------------------------

// #endif
