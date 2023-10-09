#include <iostream>
using namespace std;

class Solution {
public:
    bool isSubsequence(string str1, string str2) {
        int i = 0;
        int j = 0;
        while(i < str1.size() && j < str2.size()) {
            if(str1[i] == str2[j])
                i++;
            j++;
        }
        return i == str1.size();
    }
};