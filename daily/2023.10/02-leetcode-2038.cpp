#include<iostream>
using namespace std;

// LEETCODE 2038 - Remove Colored Pieces if Both Neighbors are the Same Color

class Solution {
public:
    bool winnerOfGame(string colors) {
        int a = 0;
        int b = 0;
        for (int i = 1 ; i < colors.size()-1 ; i++) {
            if (colors[i] == 'A' && colors[i-1] == 'A' && colors[i+1] == 'A')
                a++;
            if (colors[i] == 'B' && colors[i-1] == 'B' && colors[i+1] == 'B')
                b++;
        }
        return a > b;
    }
};