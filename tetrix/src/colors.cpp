#include "colors.h"

const Color black = { 0,0,0,255 };
const Color white = { 200,200,200,255 };
const Color red = { 201, 32,32,255 };
const Color purple = {90,0,180,255};


vector<Color> getCellColorsId()
{
    return { black, red, purple, white, white, red, purple, white};
}
