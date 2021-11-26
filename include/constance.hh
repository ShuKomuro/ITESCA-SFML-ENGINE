#pragma once

const int WINDOW_WIDTH{1280};
const int WINDOW_HEIGHT{720};
const char* G_NAME{"Goblin Slayer: Goblins Must Die!"};
const float playerSpeed{300.f};
const float playerScale{4.f};
const float boxScale{2.f};
const float enemySpeed{80.f};
const int numWalls = 28;

const int wallsTiles[] =
    {
        55, 56, 56, 56, 56, 56, 56, 56, 59, 60, 60, 60, 60,   60, 60, 40, 56, 55, 55, 56, 55, 55, 56, 55, 56, 55,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,
        48, 60, 60, 60, 60, 60, 60, 60, 49, 60, 60, 60, 60,   60, 60, 49, 60, 60, 60, 60, 60, 60, 60, 60, 60, 49,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 
        48, 60, 60, 60, 60, 60, 60, 60, 49, 60, 60, 60, 60,   60, 60, 58, 60, 60, 60, 60, 60, 60, 40, 59, 59, 68,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 
        48, 60, 60, 60, 60, 60, 60, 60, 49, 60, 60, 60, 60,   60, 60, 49, 60, 60, 60, 60, 60, 60, 49, 60, 60, 60,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 
        48, 60, 60, 60, 60, 60, 60, 60, 58, 56, 56, 56, 59,   60, 60, 58, 60, 60, 60, 60, 60, 60, 49, 60, 60, 60,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 
        48, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 49,   56, 56, 68, 60, 60, 60, 60, 60, 60, 49, 65, 65, 65,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 
        48, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 49,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 
        48, 60, 60, 55, 60, 55, 60, 60, 60, 60, 60, 60, 60,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 49,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 
        64, 65, 65, 48, 60, 49, 65, 65, 65, 65, 65, 65, 65,   55, 56, 56, 56, 56, 56, 60, 60, 60, 60, 60, 60, 49,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 
        
        55, 56, 56, 48, 60, 49, 56, 56, 56, 56, 56, 56, 59,   60, 60, 60, 60, 60, 49, 60, 60, 60, 60, 60, 60, 49,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 
        48, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 49,   60, 60, 60, 60, 60, 49, 60, 60, 60, 60, 60, 60, 49,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 
        48, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 49,   60, 60, 40, 56, 56, 68, 60, 60, 60, 60, 60, 60, 49,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 
        48, 60, 60, 40, 56, 65, 56, 65, 56, 39, 60, 60, 49,   60, 60, 49, 60, 60, 60, 60, 60, 60, 60, 60, 40, 68,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 
        48, 60, 60, 49, 60, 60, 60, 60, 60, 48, 60, 60, 49,   56, 56, 68, 60, 60, 60, 60, 60, 60, 60, 60, 49, 60,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 
        48, 60, 60, 49, 65, 56, 65, 56, 65, 57, 60, 60, 60,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 49, 65,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 
        48, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 49,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 
        48, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 40,   55, 56, 56, 56, 56, 60, 60, 60, 60, 60, 60, 60, 49,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 
        64, 65, 65, 60, 60, 60, 65, 65, 65, 65, 65, 65, 68,   60, 60, 60, 60, 49, 60, 60, 60, 60, 60, 60, 60, 49,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 
        
        55, 56, 68, 60, 60, 60, 64, 56, 59, 60, 60, 60, 60,   60, 60, 40, 56, 68, 60, 60, 60, 60, 60, 60, 60, 49,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 
        48, 60, 60, 60, 60, 60, 60, 60, 49, 60, 60, 60, 60,   60, 60, 49, 60, 60, 60, 60, 60, 60, 60, 60, 60, 49,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 
        48, 60, 60, 60, 60, 60, 60, 60, 49, 60, 60, 60, 60,   60, 60, 49, 60, 60, 60, 69, 13, 69, 60, 60, 60, 49,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 
        48, 60, 60, 60, 60, 60, 60, 60, 49, 60, 60, 60, 60,   60, 60, 49, 60, 60, 60, 64, 56, 68, 60, 60, 60, 49,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 
        48, 60, 60, 60, 60, 60, 60, 60, 58, 56, 56, 56, 59,   60, 60, 49, 56, 60, 60, 60, 60, 60, 60, 60, 40, 68,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 
        48, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 49,   60, 60, 60, 49, 56, 56, 60, 60, 60, 60, 56, 68, 60,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 
        64, 65, 65, 55, 56, 59, 60, 60, 60, 60, 60, 60, 49,   60, 60, 60, 60, 60, 49, 56, 60, 60, 56, 48, 60, 60,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 
        60, 60, 60, 60, 60, 49, 60, 60, 60, 60, 60, 60, 49,   60, 60, 60, 60, 60, 60, 49, 56, 56, 48, 60, 60, 60,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 
        60, 60, 60, 60, 60, 58, 65, 65, 65, 65, 65, 65, 68,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 
    };  //13 *8 --------- 60 en blanco |||| 9 * 8

const int floorTiles[] =
    {
        60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,
        51, 42, 43, 44, 52, 42, 51, 53, 51, 60, 60, 60, 60,   60, 60, 60, 53, 42, 44, 52, 42, 44, 43, 53, 42, 51,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,
        15, 16, 16, 16, 16, 16, 16, 16, 17, 60, 60, 60, 60,   60, 60, 60, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,
        24, 12, 21, 12, 11, 12, 12, 22, 26, 60, 60, 60, 60,   60, 60, 60, 15, 15, 15, 15, 15, 15, 15, 60, 60, 60,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,
        24, 12, 12, 11, 23, 12, 12, 31, 26, 60, 60, 60, 60,   60, 60, 60, 17, 17, 17, 17, 17, 17, 17, 60, 60, 60,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,
        24, 29, 30, 12, 11, 12, 20, 21, 26, 43, 44, 51, 52,   60, 60, 60, 15, 15, 15, 15, 15, 15, 15, 60, 60, 60,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,
        24, 29, 30, 21, 12, 12, 12, 11, 12, 29, 23, 32, 32,   43, 53, 53, 17, 17, 17, 17, 17, 17, 17, 42, 53, 44,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,
        24, 31, 31, 21, 12, 11, 21, 12, 12, 29, 23, 32, 32,   32, 32, 32, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,
        24, 12, 11, 12, 12, 12, 12, 20, 11, 29, 31, 31, 31,   31, 31, 31, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,
        
        60, 60, 60, 12, 12, 12, 60, 60, 60, 60, 60, 60, 60,   60, 60, 60, 60, 60, 60, 16, 16, 16, 16, 16, 16, 16,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,
        51, 42, 43, 11, 12, 11, 51, 53, 51, 42, 51, 42, 53,   60, 60, 60, 60, 60, 60, 20, 11, 21, 31, 30, 11, 12,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,
        15, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 17,   60, 60, 60, 60, 60, 60, 29, 12, 20, 11, 23, 21, 31,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,
        24, 12, 21, 12, 11, 12, 12, 22, 31, 11, 12, 22, 26,   60, 60, 60, 42, 52, 44, 11, 12, 12, 22, 30, 29, 11,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,
        24, 12, 12, 11, 60, 60, 60, 60, 60, 20, 21, 31, 26,   60, 60, 60, 12, 21, 11, 20, 11, 21, 31, 30, 11, 60,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,
        24, 29, 30, 12, 60, 60, 60, 60, 60, 12, 11, 12, 11,   11, 20, 21, 23, 21, 12, 11, 12, 12, 22, 31, 11, 60,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,
        24, 29, 30, 21, 12, 12, 12, 11, 12, 29, 21, 12, 21,   20, 21, 22, 20, 11, 31, 29, 12, 20, 11, 23, 21, 31,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,
        24, 31, 31, 21, 11, 12, 21, 12, 12, 29, 11, 21, 12,   11, 22, 11, 12, 21, 12, 11, 12, 12, 22, 30, 29, 11,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,
        33, 12, 11, 11, 30, 31, 31, 20, 11, 29, 12, 30, 35,   60, 60, 60, 60, 60, 22, 22, 22, 22, 22, 22, 22, 22,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,
        
        60, 60, 60, 22, 22, 22, 60, 60, 60, 60, 60, 60, 60,   60, 60, 60, 60, 60, 23, 23, 23, 23, 23, 23, 23, 23,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,
        53, 53, 53, 23, 23, 23, 53, 53, 53, 60, 60, 60, 60,   60, 60, 60, 52, 53, 23, 23, 23, 23, 23, 23, 23, 23,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,
        23, 23, 23, 23, 23, 23, 23, 23, 23, 60, 60, 60, 60,   60, 60, 60, 23, 23, 23, 60, 69, 60, 23, 23, 23, 23,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,
        23, 23, 23, 23, 23, 23, 23, 23, 23, 60, 60, 60, 60,   60, 60, 60, 23, 23, 23, 60, 60, 60, 23, 23, 23, 23,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,
        23, 23, 23, 23, 23, 23, 23, 23, 23, 60, 60, 60, 60,   60, 60, 60, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,
        23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23,   60, 60, 60, 60, 23, 23, 23, 23, 23, 23, 23, 23, 60,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,
        23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23,   60, 60, 60, 60, 60, 60, 23, 23, 23, 23, 60, 60, 60,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,
        60, 60, 60, 60, 60, 60, 23, 23, 23, 23, 23, 23, 23,   60, 60, 60, 60, 60, 60, 60, 23, 23, 60, 60, 60, 60,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,
        60, 60, 60, 60, 60, 60, 23, 23, 23, 23, 23, 23, 23,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,   60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60
    };  

const float wallWH [numWalls][2] = {   
    {288.f, 1.f}, {96, 80}, {176, 80} 
    , {1, 960} , {96, 80}, {96, 80}
    , {144, 176}, {192, 64}, {224, 1}
    , {128, 128}, {224, 132}, {320, 1}
    , {96, 32}, {1, 800}, {96, 112}
    , {32, 72}, {416, 52}, {192, 64}
    , {96, 64}, {160, 64}, {1, 128}
    , {96, 64}, {64, 64}, {64, 64}
    , {32, 32}, {32, 32}, {72, 1}
    , {32, 32}
    };
const int wallPos [numWalls][2] = {    
    {144, 72}, {48, 584}, {328, 832}
    , {0, 576} , {48, 1160}, {432, 1160}
    , {640, 1208}, {86, 1600}, {496, 1700}
    , {888, 1536}, {680, 136}, {1168, 72}
    , {872, 342}, {1656, 448}, {1512, 224}
    , {1608, 848}, {584, 576}, {920, 680}
    , {872, 784}, {904, 1096}, {1016, 1280}
    , {1264, 1312}, {1112, 1544}, {1512, 1544}
    , {1224, 1592}, {1432,1592}, {1312, 1640}
    , {1608, 1464}
    }; 
