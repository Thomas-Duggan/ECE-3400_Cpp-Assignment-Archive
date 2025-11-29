// Copyright (c) 2025 Thomas Duggan
// This work is licensed under CC BY-SA 4.0


#include <vector>
#define BOARD_DIM 5

using namespace std;

typedef struct
{
  short number; // 0 if free square, otherwise the number on the square
  bool covered; // checks if location is pressed or not
} 

ThreeDBingoSquare; // Name of previous type definition

typedef vector<vector<vector<ThreeDBingoSquare>>> ThreeDBingoBoard;

// Expected vector layout:
// {
//   {
//     {{chosen_val, status},{chosen_val, status},{chosen_val, status},{chosen_val, status},{chosen_val, status}},
//     {{chosen_val, status},{chosen_val, status},{chosen_val, status},{chosen_val, status},{chosen_val, status}},
//     {{chosen_val, status},{chosen_val, status},{chosen_val, status},{chosen_val, status},{chosen_val, status}}, Layer 1
//     {{chosen_val, status},{chosen_val, status},{chosen_val, status},{chosen_val, status},{chosen_val, status}},
//     {{chosen_val, status},{chosen_val, status},{chosen_val, status},{chosen_val, status},{chosen_val, status}},
//   },
//   {
//     {{chosen_val, status},{chosen_val, status},{chosen_val, status},{chosen_val, status},{chosen_val, status}},
//     {{chosen_val, status},{chosen_val, status},{chosen_val, status},{chosen_val, status},{chosen_val, status}},
//     {{chosen_val, status},{chosen_val, status},{chosen_val, status},{chosen_val, status},{chosen_val, status}}, Layer 2
//     {{chosen_val, status},{chosen_val, status},{chosen_val, status},{chosen_val, status},{chosen_val, status}},
//     {{chosen_val, status},{chosen_val, status},{chosen_val, status},{chosen_val, status},{chosen_val, status}},
//   },
//   {
//     {{chosen_val, status},{chosen_val, status},{chosen_val, status},{chosen_val, status},{chosen_val, status}},
//     {{chosen_val, status},{chosen_val, status},{chosen_val, status},{chosen_val, status},{chosen_val, status}},
//     {{chosen_val, status},{chosen_val, status},{chosen_val, status},{chosen_val, status},{chosen_val, status}}, Layer 3
//     {{chosen_val, status},{chosen_val, status},{chosen_val, status},{chosen_val, status},{chosen_val, status}},
//     {{chosen_val, status},{chosen_val, status},{chosen_val, status},{chosen_val, status},{chosen_val, status}},
//   }
// }

