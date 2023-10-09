#include<iostream>
using namespace std;

// LEETCODE 557 - Reverse Words in a String III

class Solution {
public:
    
    vector<string> split(string str, string del = " ") {
        vector<string> ans;
        int start = 0;
        int end = str.find(del);
        while(end != -1) {
            ans.push_back(str.substr(start, end-start));
            start = end + 1;
            end = str.find(del, start);
        }
        ans.push_back(str.substr(start));
        return ans;
    }
    
    string reverseWords(string str) {
        int idx = 0;
        while(idx < str.size()) {
            if(str[idx] != ' ') {
                int i = idx;
                int j = idx;
                while(idx < str.size() && str[idx] != ' ')
                    j = idx++;
                while(i < j)
                    swap(str[i++], str[j--]);
            }
            while(idx < str.size() && str[idx] == ' ')
                idx++;
        }
        return str;
    }
};