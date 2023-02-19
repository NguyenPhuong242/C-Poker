
#include "HandTest.h"
#include "Hand.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// void HandTest_extractKind (void)
// { 
//   Deck d1; Deck_initFromPips (& d1, "Ad Ts Th Td Tc 8s 8c 7d");
//   Deck d2; Deck_initEmpty (& d2);
  
//   bool extracted1= Hand_extractKind (& d1, 3, & d2);
//   assert (extracted1);
//   assert (Deck_pipsEqual (& d1, "Ad 8s 8c 7d"));
//   assert (Deck_pipsEqual (& d2, "Ts Th Td"));
  
//   bool extracted2= Hand_extractKind (& d1, 2, & d2);
//   assert (extracted2);
//   assert (Deck_pipsEqual (& d1, "Ad 7d"));
//   assert (Deck_pipsEqual (& d2, "Ts Th Td 8s 8c"));
  
//   bool extracted3= Hand_extractKind (& d1, 2, & d2);
//   assert ( ! extracted3);
//   assert (Deck_pipsEqual (& d1, "Ad 7d"));
//   assert (Deck_pipsEqual (& d2, "Ts Th Td 8s 8c")); 
// }

// //-----------------------------------------------------------------------------
 
// void HandTest_findHiCard (void) {
//   Deck d1; Deck_initFromPips (& d1, "3d 5c Ad Ts 2c Kh 3s Kd");
//   Deck d2; Deck_initEmpty (& d2);
//   bool found1= Hand_findHiCard (& d1, & d2);
//   assert (found1);
//   assert (Deck_pipsEqual (& d2, "Ad Kh Ts 5c 3s"));

//   Deck d3; Deck_initFromPips (& d3, "As Ac Qd Qc Ah Ad");
//   Deck d4; Deck_initEmpty (& d4);
//   bool found2= Hand_findHiCard (& d3, & d4);
//   assert ( ! found2);
//   assert (Deck_pipsEqual (& d4, "As Qd"));
// }


// void HandTest_findPair (void) {
//   Deck d1; Deck_initFromPips (& d1, "3d 5c Ad Ts 2c Kh 3s Kd");
//   Deck d2; Deck_initEmpty (& d2);
//   bool found1= Hand_findPair (& d1, & d2);
//   assert (found1);
//   assert (Deck_pipsEqual (& d2, "Kh Kd Ad Ts 5c"));

//   Deck d3; Deck_initFromPips (& d3, "As Ac Qd Qc Ah Ad");
//   Deck d4; Deck_initEmpty (& d4);
//   bool found2= Hand_findPair (& d3, & d4);
//   assert ( ! found2);
//   assert (Deck_pipsEqual (& d4, "As Ah Qd"));
// }


// void HandTest_find2Pairs (void) {
//   Deck d1; Deck_initFromPips (& d1, "3d 5c Ad Ts 2c Kh 3s Kd");
//   Deck d2; Deck_initEmpty (& d2);
//   bool found1= Hand_find2Pairs (& d1, & d2);
//   assert (found1);
//   assert (Deck_pipsEqual (& d2, "Kh Kd 3s 3d Ad"));

//   Deck d3; Deck_initFromPips (& d3, "As Ac Qd Qc Ah Ad");
//   Deck d4; Deck_initEmpty (& d4);
//   bool found2= Hand_find2Pairs (& d3, & d4);
//   assert ( ! found2);
//   assert (Deck_pipsEqual (& d4, "As Ah Qd Qc"));
// }


// void HandTest_findTrips (void) {
//   Deck d1; Deck_initFromPips (& d1, "3d 5c Ad 3c 2c Kh 3s Kd");
//   Deck d2; Deck_initEmpty (& d2);
//   bool found1= Hand_findTrips (& d1, & d2);
//   assert (found1);
//   assert (Deck_pipsEqual (& d2, "3s 3d 3c Ad Kh"));

//   Deck d3; Deck_initFromPips (& d3, "As Ac Qd Qc Ah Ad");
//   Deck d4; Deck_initEmpty (& d4);
//   bool found2= Hand_findTrips (& d3, & d4);
//   assert ( ! found2);
//   assert (Deck_pipsEqual (& d4, "As Ah Ad Qd"));
// }


// void HandTest_findBoat (void) {
//   Deck d1; Deck_initFromPips (& d1, "3d 5c Ad 3c 2c Kh 3s Kd");
//   Deck d2; Deck_initEmpty (& d2);
//   bool found1= Hand_findBoat (& d1, & d2);
//   assert (found1);
//   assert (Deck_pipsEqual (& d2, "3s 3d 3c Kh Kd"));

//   Deck d3; Deck_initFromPips (& d3, "As Ac Qd Kc Ah Ad");
//   Deck d4; Deck_initEmpty (& d4);
//   bool found2= Hand_findBoat (& d3, & d4);
//   assert ( ! found2);
//   assert (Deck_pipsEqual (& d4, "As Ah Ad"));
// }


// void HandTest_findQuads (void) {
//   Deck d1; Deck_initFromPips (& d1, "3d 5c Ad 3c 2c Kh 3s Kd");
//   Deck d2; Deck_initEmpty (& d2);
//   bool found1= Hand_findQuads (& d1, & d2);
//   assert ( ! found1);
//   assert (Deck_pipsEqual (& d2, ""));

//   Deck d3; Deck_initFromPips (& d3, "As Ac Qd Kc Ah Ad");
//   Deck d4; Deck_initEmpty (& d4);
//   bool found2= Hand_findQuads (& d3, & d4);
//   assert (found2);
//   assert (Deck_pipsEqual (& d4, "As Ah Ad Ac Kc"));
// }

// //-----------------------------------------------------------------------------

// void HandTest_extractRegularStraight (void) {
//   Deck d1; Deck_initFromPips (& d1, "Ks Jd Td 9c 8d 7s 6c 4h 2s");
//   Deck d2; Deck_initEmpty (& d2);
//   bool extracted1= Hand_extractRegularStraight (& d1, & d2);
//   assert (extracted1);
//   assert (Deck_pipsEqual (& d1, "Ks 6c 4h 2s"));
//   assert (Deck_pipsEqual (& d2, "Jd Td 9c 8d 7s"));
  
//   Deck d3; Deck_initFromPips (& d3, "Ks Jd Td 9c 8d 6s 5c 4h 2s");
//   Deck d4; Deck_initEmpty (& d4);
//   bool extracted2= Hand_extractRegularStraight (& d3, & d4);
//   assert (! extracted2);
//   assert (Deck_pipsEqual (& d3, "Ks Jd Td 9c 8d 6s 5c 4h 2s"));
//   assert (Deck_pipsEqual (& d4, ""));
// }

// void HandTest_extractWheelStraight (void) {
//   Deck d1; Deck_initFromPips (& d1, "Ac Th 7d 6s 5s 4h 3d 2s");
//   Deck d2; Deck_initEmpty (& d2);
//   bool extracted1= Hand_extractWheelStraight (& d1, & d2);
//   assert (extracted1);
//   assert (Deck_pipsEqual (& d1, "Th 7d 6s"));
//   assert (Deck_pipsEqual (& d2, "5s 4h 3d 2s Ac"));
  
//   Deck d3; Deck_initFromPips (& d3, "Ac Th 7d 6s 4h 3d 2s");
//   Deck d4; Deck_initEmpty (& d4);
//   bool extracted2= Hand_extractWheelStraight (& d3, & d4);
//   assert (! extracted2);
//   assert (Deck_pipsEqual (& d3, "Ac Th 7d 6s 4h 3d 2s"));
//   assert (Deck_pipsEqual (& d4, ""));

//   Deck d5; Deck_initFromPips (& d5, "Th 7d 6s 5s 4h 3d 2s");
//   Deck d6; Deck_initEmpty (& d6);
//   bool extracted3= Hand_extractWheelStraight (& d5, & d6);
//   assert (! extracted3);
//   assert (Deck_pipsEqual (& d5, "Th 7d 6s 5s 4h 3d 2s"));
//   assert (Deck_pipsEqual (& d6, ""));
// }

// void HandTest_findStraight (void) {
//   Deck d1; Deck_initFromPips (& d1, "Ac Th 7d 6s 5s 4h 3d 2s");
//   Deck d2; Deck_initEmpty (& d2);
//   bool found1= Hand_findStraight (& d1, & d2);
//   assert (found1);
//   assert (Deck_pipsEqual (& d2, "7d 6s 5s 4h 3d"));
  
//   Deck d3; Deck_initFromPips (& d3, "Ac 3d Th 5s 7d 4h 2s");
//   Deck d4; Deck_initEmpty (& d4);
//   bool found2= Hand_findStraight (& d3, & d4);
//   assert (found2);
//   assert (Deck_pipsEqual (& d4, "5s 4h 3d 2s Ac"));

//   Deck d5; Deck_initFromPips (& d5, "Js Ac Kd 9d Qs 8h Td");
//   Deck d6; Deck_initEmpty (& d6);
//   bool found3= Hand_findStraight (& d5, & d6);
//   assert (found3);
//   assert (Deck_pipsEqual (& d6, "Ac Kd Qs Js Td"));

//   Deck d7; Deck_initFromPips (& d7, "Ac Kd 9d Qs 8h Td");
//   Deck d8; Deck_initEmpty (& d8);
//   bool found4= Hand_findStraight (& d7, & d8);
//   assert ( ! found4);
//   assert (Deck_pipsEqual (& d8, ""));
// }

// //-----------------------------------------------------------------------------

// void HandTest_extractFlush (void) {
//   Deck d1; Deck_initFromPips (& d1, "Jd Td 8d Qc Jc 4c 2c");
//   Deck d2; Deck_initEmpty (& d2);
//   bool extracted1= Hand_extractFlush (& d1, & d2);
//   assert ( ! extracted1);
//   assert (Deck_pipsEqual (& d1, "Jd Td 8d Qc Jc 4c 2c"));
//   assert (Deck_pipsEqual (& d2, ""));
  
//   Deck d3; Deck_initFromPips (& d3, "Jd Td 8d 5d 3d 2d Qc Jc 9c 7c 4c 2c");
//   Deck d4; Deck_initEmpty (& d4);
//   bool extracted2= Hand_extractFlush (& d3, & d4);
//   assert (extracted2);
//   assert (Deck_pipsEqual (& d3, "Jd Td 8d 5d 3d 2d 2c"));
//   assert (Deck_pipsEqual (& d4, "Qc Jc 9c 7c 4c"));
// }

// void HandTest_findFlush  (void) {
//   Deck d1; Deck_initFromPips (& d1, "6s Jd 8s 9d Ad 7s Td 5s Kd 4s");
//   Deck d2; Deck_initEmpty (& d2);
//   bool found1= Hand_findFlush (& d1, & d2);
//   assert (found1);
//   assert (Deck_pipsEqual (& d2, "Ad Kd Jd Td 9d"));
//   Deck d3; Deck_initFromPips (& d3, "6s Jd 8s 9d 7s Td Kd 3s");
//   Deck d4; Deck_initEmpty (& d4);
//   bool found2= Hand_findFlush (& d3, & d4);
//   assert ( ! found2);
//   assert (Deck_pipsEqual (& d4, ""));
 
// }

// //-----------------------------------------------------------------------------

// void HandTest_extractRegularStrFlush (void) {
//   Deck d1; Deck_initFromPips (& d1, "9s 8s 7s 6s 5s 2s Ad Qd Jd Td 9d 8d 2c");
//   Deck d2; Deck_initEmpty (& d2);
//   bool extracted1= Hand_extractRegularStrFlush (& d1, & d2);
//   assert (extracted1);
//   assert (Deck_pipsEqual (& d1, "9s 8s 7s 6s 5s 2s Ad 2c"));
//   assert (Deck_pipsEqual (& d2, "Qd Jd Td 9d 8d"));
  
//   Deck d3; Deck_initFromPips (& d3, "9s 8s 7s 6s 4s 3s Ad Qd Jd Td 9d 2c");
//   Deck d4; Deck_initEmpty (& d4);
//   bool extracted2= Hand_extractRegularStrFlush (& d3, & d4);
//   assert (! extracted2);
//   assert (Deck_pipsEqual (& d3, "9s 8s 7s 6s 4s 3s Ad Qd Jd Td 9d 2c"));
//   assert (Deck_pipsEqual (& d4, ""));
// }

// void HandTest_extractWheelStrFlush (void) {
//   Deck d1; Deck_initFromPips (& d1, "Ts 9s Ah Th 7h 6h 5h 4h 3h 2h Qc");
//   Deck d2; Deck_initEmpty (& d2);
//   bool extracted1= Hand_extractWheelStrFlush (& d1, & d2);
//   assert (extracted1);
//   assert (Deck_pipsEqual (& d1, "Ts 9s Th 7h 6h Qc"));
//   assert (Deck_pipsEqual (& d2, "5h 4h 3h 2h Ah"));
  
//   Deck d3; Deck_initFromPips (& d3, "Ts 9s Ah Th 7h 6h 5h 4h 3h Qc");
//   Deck d4; Deck_initEmpty (& d4);
//   bool extracted2= Hand_extractWheelStrFlush (& d3, & d4);
//   assert (! extracted2);
//   assert (Deck_pipsEqual (& d3, "Ts 9s Ah Th 7h 6h 5h 4h 3h Qc"));
//   assert (Deck_pipsEqual (& d4, ""));

//   Deck d5; Deck_initFromPips (& d5, "Ts 9s Th 7h 6h 5h 4h 3h 2h Qc");
//   Deck d6; Deck_initEmpty (& d6);
//   bool extracted3= Hand_extractWheelStrFlush (& d5, & d6);
//   assert (! extracted3);
//   assert (Deck_pipsEqual (& d5, "Ts 9s Th 7h 6h 5h 4h 3h 2h Qc"));
//   assert (Deck_pipsEqual (& d6, ""));
// }

// void HandTest_findStrFlush (void) {
//   Deck d1; Deck_initFromPips (& d1, "6s 5s Ac Th 3s 2s 7s 4s");
//   Deck d2; Deck_initEmpty (& d2);
//   bool found1= Hand_findStrFlush (& d1, & d2);
//   assert (found1);
//   assert (Deck_pipsEqual (& d2, "7s 6s 5s 4s 3s"));
  
//   Deck d3; Deck_initFromPips (& d3, "Td 5s 7s As 8d 3s 4s 2s");
//   Deck d4; Deck_initEmpty (& d4);
//   bool found2= Hand_findStrFlush (& d3, & d4);
//   assert (found2);
//   assert (Deck_pipsEqual (& d4, "5s 4s 3s 2s As"));

//   Deck d5; Deck_initFromPips (& d5, "Js As Qh Ks 9d Qs 8h 2c Ts");
//   Deck d6; Deck_initEmpty (& d6);
//   bool found3= Hand_findStrFlush (& d5, & d6);
//   assert (found3);
//   assert (Deck_pipsEqual (& d6, "As Ks Qs Js Ts"));

//   Deck d7; Deck_initFromPips (& d7, "As Ks 9s Qs 8s Ts");
//   Deck d8; Deck_initEmpty (& d8);
//   bool found4= Hand_findStrFlush (& d7, & d8);
//   assert ( ! found4);
//   assert (Deck_pipsEqual (& d8, ""));
// }


// //-----------------------------------------------------------------------------

// void HandTest_findBest (void) {
//   char * pips[HAND_COUNT]= {
//     "Ts Jc Ah Qd 8d",
//     "As Ks Qd Kc Tc",
//     "As Qc Ad Qh Kh",
//     "Qh As Qd Ts Qc",
//     "Ts Qh Jd 9s Ks",
//     "As 4s 9s Ts 5s",
//     "Qh As Qd Ac Qc",
//     "2s Kd 2d 2c 2h",
//     "As 2s 5s 3s 4s"
//   };
//   char * expected[HAND_COUNT]= {
//     "Ah Qd Jc Ts 8d",
//     "Ks Kc As Qd Tc",
//     "As Ad Qh Qc Kh",
//     "Qh Qd Qc As Ts",
//     "Ks Qh Jd Ts 9s",
//     "As Ts 9s 5s 4s",
//     "Qh Qd Qc As Ac",
//     "2s 2h 2d 2c Kd",
//     "5s 4s 3s 2s As"
//   };
//   for (Hand h= 0; h < HAND_COUNT; h++) {
//     Deck d1; Deck_initFromPips (& d1, pips[h]);
//     Deck d2; Hand hand= Hand_findBest (& d1, & d2);
//     assert (hand == h);
//     assert (Deck_pipsEqual (& d2, expected[h]));
//   }
// }

// //-----------------------------------------------------------------------------

// void
// HandTest_runAll (void) {
//   HandTest_extractKind();
//   HandTest_findHiCard();
//   HandTest_findPair();
//   HandTest_find2Pairs();
//   HandTest_findTrips();
//   HandTest_findBoat();
//   HandTest_findQuads();
  
//   HandTest_extractRegularStraight ();
//   HandTest_extractWheelStraight ();
//   HandTest_findStraight ();
  
//   HandTest_extractFlush();
//   HandTest_findFlush();

//   HandTest_extractRegularStrFlush();
//   HandTest_extractWheelStrFlush();
//   HandTest_findStrFlush();

//   HandTest_findBest();
// }
