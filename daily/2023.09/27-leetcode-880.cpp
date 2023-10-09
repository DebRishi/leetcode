#include<iostream>
using namespace std;

// LEETCODE 880 - Decoded String at Index

class Solution {
public:
    string decodeAtIndex(string str, int k) {
        long len = 0;
        long idx = 0;
        while (len < k && idx < str.size()) {
            if (str[idx] >= '2' && str[idx] <= '9')
                len = len * (str[idx] - '0');
            else
                len++;
            idx++;
        }
        for (idx = idx-1 ; idx >= 0 ; idx--) {
            if (str[idx] >= '2' && str[idx] <= '9') {
                len = len / (str[idx] - '0');
                k = k % len;
            }
            else {
                if (k == 0 || k == len)
                    return string(1, str[idx]);
                else
                    len--;
            }
        }
        return "";
    }
};