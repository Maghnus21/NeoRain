/*
⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⡀⣴⡦⢲⣂⣇⣇⣴⣾⡶⢤⣄⠀⠀⠀⠀
⠀⠀⢀⠶⣭⡾⠛⡿⠿⣿⣟⢿⡿⡛⠻⢶⣋⣶⠄⣀
⠀⠰⣧⠞⠁⠀⠀⠀⠸⣿⣿⠄⠀⡇⠀⠀⢈⣷⡛⠁
⢸⠸⠥⠦⢀⠀⠀⠡⢀⠀⠀⣀⠄⠀⣀⣴⡛⠓⠄⠁
⠀⠀⠀⠀⠚⠭⡛⠖⡶⠶⠶⢶⠶⡯⠙⡔⠐⠁⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠁⠑⠘⠀⠘⠓⠈⠁⠀⠀⠀⠀⠀

Maghnus O Donnell
*/




#ifndef RANDOM_ADDITION_H
#define RANDOM_ADDITION_H

#include <vector>           //  vector

class sudo_rand_vec {

public:
    

    static int index;          //  index chosen by user

    double ReturnVectorValue();

private:
    //  sudo random number vector copied from doom source code with vector values replaced with new set
    //  link: https://github.com/id-Software/DOOM/blob/master/linuxdoom-1.10/m_random.c

    //  will be used to add additional values to results of random number generator to prevent
    //  repeating symbols and rain drop locations;
    //  link: https://www.calculatorsoup.com/calculators/statistics/random-number-generator.php 
    
    std::vector<int> vec_sudorand_add = {
    52,  191, 159, 148, 239, 58,  252, 56,  157, 193, 87,  250, 62,  48,  78,  134,
    123, 110, 138, 39,  144, 55,  141, 150, 172, 47,  181, 69,  22,  131, 203, 107,
    63,  215, 217, 44,  129, 188, 226, 240, 133, 213, 156, 103, 17,  237, 46,  81,
    65,  121, 210, 176, 76,  85,  192, 173, 178, 67,  84,  204, 8,   230, 195, 104, 
    139, 170, 24,  10,  146, 16,  115, 161, 179, 199, 27,  95,  162, 185, 37,  119,
    238, 45,  122, 137, 205, 83,  71,  77,  151, 248, 212, 42,  174, 20,  241, 243,
    175, 222, 219, 247, 105, 51,  61,  14,  33,  198, 126, 220, 43,  197, 124, 221,
    184, 89,  227, 166, 90,  206, 233, 116, 86,  25,  19,  136, 153, 132, 234, 94,
    114, 125, 201, 49,  35,  242, 53,  236, 70,  59,  182, 208, 169, 214, 40,  135,
    177, 183, 190, 108, 106, 118, 41,  2,   11,  145, 168, 154, 186, 216, 120, 7,
    127, 31,  101, 253, 34,  3,   93,  112, 209, 102, 128, 60,  80,  66,  100, 147, 
    149, 244, 12,  36,  96,  109, 72,  98,  50,  140, 32,  5,   97,  75,  180, 130,
    165, 4,   9,   91,  64,  225, 211, 18,  224, 167, 251, 163, 142, 255, 13,  73,
    158, 194, 111, 218, 57,  92,  245, 68,  99,  143, 200, 82,  196, 249, 54,  30,
    160, 74,  29,  246, 79,  254, 235, 117, 88,  38,  187, 189, 202, 232, 6,   26,
    231, 152, 23,  223, 1,   15,  207, 228, 113, 164, 28,  229, 155, 171, 21,  0
    };
};





#endif // !RANDOM_ADDITION_H
