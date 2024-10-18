#include "Colors.h"
#include <vector>
using namespace std;

const Color darkGray = {26, 31, 48, 255};  // Define dark gray color
const Color green = {47, 230, 23, 255};    // Define green color
const Color red = {232, 18, 18, 255};      // Define red color
const Color orange = {226, 116, 17, 255};  // Define orange color
const Color yellow = {237, 234, 4, 255};   // Define yellow color
const Color purple = {166, 0, 247, 255};   // Define purple color
const Color cyan = {21, 204, 209, 255};    // Define cyan color
const Color blue = {13, 64, 216, 255};     // Define blue color
const Color lightblue = {59, 85, 162, 255};
const Color darkblue = {44, 44, 127, 255};

vector<Color> GetCellColors(){
        // Return a vector containing all the defined colors
    return {darkGray, green, red, orange, yellow, purple, cyan, blue};
}