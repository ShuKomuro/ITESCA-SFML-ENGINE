#pragma once

const int WINDOW_WIDTH{832}; //800
const int WINDOW_HEIGHT{600};
const char* G_NAME{"YEAH PERDONE"};
const int wallsTiles[] =
    {
        55, 56, 56, 56, 56, 56, 56, 56, 59, 60, 60, 60, 60, 
        48, 60, 60, 60, 60, 60, 60, 60, 49, 60, 60, 60, 60,
        48, 60, 60, 60, 60, 60, 60, 60, 49, 60, 60, 60, 60, 
        48, 60, 60, 60, 60, 60, 60, 60, 49, 60, 60, 60, 60, 
        48, 60, 60, 60, 60, 60, 60, 60, 58, 56, 56, 56, 59, 
        48, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 49, 
        48, 60, 60, 55, 56, 59, 60, 60, 60, 60, 60, 60, 49, 
        48, 60, 60, 48, 60, 49, 60, 60, 60, 60, 60, 60, 49, 
        64, 65, 65, 64, 65, 68, 65, 65, 65, 65, 65, 65, 68 
    }; //13 *8 --------- 60 en blanco |||| 9 * 8

    const int floorTiles[] =
    {
        60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 
        51, 42, 43, 44, 52, 42, 51, 53, 51, 60, 60, 60, 60,
        15, 16, 16, 16, 16, 16, 16, 16, 17, 60, 60, 60, 60, 
        24, 12, 21, 12, 11, 12, 12, 22, 26, 60, 60, 60, 60, 
        24, 12, 12, 11, 23, 12, 12, 31, 26, 60, 60, 60, 60, 
        24, 29, 30, 12, 11, 12, 20, 21, 26, 43, 44, 51, 52, 
        24, 29, 30, 21, 12, 12, 12, 11, 12, 29, 23, 32, 32, 
        24, 31, 31, 60, 60, 60, 21, 12, 12, 29, 23, 32, 32, 
        24, 12, 11, 60, 60, 60, 31, 20, 11, 29, 31, 31, 31 
    };

 
    // 0 ,  1,  2,  3,  4,  5,  6,  7,  8    || 1 
    // 9 , 10, 11, 12, 13, 14, 15, 16, 17    || 2
    // 18, 19, 20, 21, 22, 23, 24, 25, 26    || 3
    // 27, 28, 29, 30, 31, 32, 33, 34, 35    || 4
    // 36, 37, 38, 39, 40, 41, 42, 43, 44    || 5
    // 45, 46, 47, 48, 49, 50, 51, 52, 53    || 6
    // 54, 55, 56, 57, 58, 59, 60, 61, 62    || 7
    // 63, 64, 65, 66, 67, 68, 69, 70, 71    || 8
