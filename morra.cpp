//****************************************************************************************************
//     File:               morra.cpp
// 
//     Student:            Anna Sargsyan
// 
//     Assignment:         Program #5
// 
//     Course Name:        Programming I
// 
//     Course Number:      COSC 1550-01
// 
//     Due:                February 27, 2023
//
//     This program selectes for players numbers randomly, 
//     then selectes the right answers randomly.
//     After it output who wins in the game "Morra".
//  
//     
//
//****************************************************************************************************

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    const int MIN_FINGERS = 0;
    const int MAX_FINGERS = 5;

    int randNum;

    short seed = time(0);
    srand(seed);

    int fingers1 = rand() % 6;
    int fingers2 = rand() % 6;

    int sum = fingers1 + fingers2;

    int guess1 = rand() % 6 + fingers1;
    int guess2 = rand() % 6 + fingers2;


    ofstream fout;
    fout.open("morrasResult.txt");

    fout << left << setw(20) << "Fingers total:" << endl;
    fout << left << setw(3) << fingers1 << setw(3) << guess1 << endl;
    fout << left << setw(3) << fingers2 << setw(3) << guess2 << endl;

    fout << "Correct total is " << sum << endl;

    fout << endl;

    if (guess1 == sum && guess2 == sum)
    {
        fout << "TIE" << endl;
    }
    else if (guess1 == sum && guess2 != sum)
    {
        fout << "PLAYER 1 WINS" << endl;
    }
    else if (guess2 == sum && guess1 != sum)
    {
        fout << "PLAYER 2 WINS" << endl;
    }
    else
    {
        fout << "NO ONE WINS." << endl;
    }

    fout.close();

    return 0;

}

//****************************************************************************************************

/*

Fingers total:
2  3
1  2
Correct total is 3

PLAYER 1 WINS

*/

/*

Fingers total:
3  5
0  3
Correct total is 3

PLAYER 2 WINS

*/

/*

Fingers total:
4  7
2  2
Correct total is 6

NO ONE WINS.

*/