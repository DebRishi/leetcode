#include<iostream>
#include<vector>
using namespace std;

// LEETCODE 2272 - Substring With Largest Variance

class Solution {
public:
    int largestVariance(string str) {
        int ans = 0;
        vector<int> freq(26);
        for(char& ch : str)
            freq[ch-'a']++;
        for(char ch1 = 'a' ; ch1 <= 'z' ; ch1++) {
            for(char ch2 = 'a' ; ch2 <= 'z' ; ch2++) {
                if(ch1 == ch2 || !freq[ch1-'a'] || !freq[ch2-'a'])
                    continue;
                for(int rev = 1 ; rev <= 2 ; rev++) {
                    int cnt1 = 0;
                    int cnt2 = 0;
                    for(char& ch : str) {
                        cnt1 += ch == ch1;
                        cnt2 += ch == ch2;
                        if(cnt1 < cnt2)
                            cnt1 = cnt2 = 0;
                        if(cnt1 > 0 && cnt2 > 0)
                            ans = max(ans, cnt1 - cnt2);
                    }
                    reverse(str.begin(), str.end());
                }
            }
        }
        return ans;
    }
};

// Modified Kadane's Algorithm
class Solution {
public:
    int largestVariance(string str) {
        int ans = 0;
        vector<string> strs(2, str);
        reverse(strs[1].begin(), strs[1].end());
        for(char ch1 = 'a' ; ch1 <= 'z' ; ch1++) {
            for(char ch2 = 'a' ; ch2 <= 'z' ; ch2++) {
                if(ch1 == ch2)
                    continue;
                for(string& str : strs) {
                    int cnt1 = 0;
                    int cnt2 = 0;
                    for(char& ch : str) {
                        cnt1 += ch1 == ch;
                        cnt2 += ch2 == ch;
                        if(cnt1 < cnt2)
                            cnt1 = cnt2 = 0;
                        if(cnt1 > 0 && cnt2 > 0)
                            ans = max(ans, cnt1 - cnt2);
                    }
                }
            }
        }
        return ans;
    }
};

// TLE - Brute Force Approach O(N^3)
class Solution {
public:
    int largestVariance(string str) {
        int ans = 0;
        for(char ch1 = 'a' ; ch1 <= 'z' ; ch1++) {
            for(char ch2 = 'a' ; ch2 <= 'z' ; ch2++) {
                for(int i = 0 ; i < str.size() ; i++) {
                    for(int j = 0 ; j <= i ; j++) {
                        int cnt1 = 0;
                        int cnt2 = 0;
                        for(int k = j ; k <= i ; k++) {
                            cnt1 += ch1 == str[k] ? 1 : 0;
                            cnt2 += ch2 == str[k] ? 1 : 0;
                        }
                        if(cnt1 > 0 && cnt2 > 0)
                            ans = max(ans, cnt1 - cnt2);
                    }
                }
            }
        }
        return ans;
    }
};