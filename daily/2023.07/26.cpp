#include <iostream>
using namespace std;

// LEETCODE 1870 - Minimum Speed to Arrive on Time
// https://leetcode.com/problems/minimum-speed-to-arrive-on-time/solutions/1226468/binary-answer-cheat-sheet/
// https://leetcode.com/discuss/study-guide/1233854/a-noobs-guide-to-the-binary-search-algorithm
// https://leetcode.com/discuss/general-discussion/786126/Python-Powerful-Ultimate-Binary-Search-Template.-Solved-many-problems
// https://leetcode.com/discuss/interview-question/1322500/5-variations-of-Binary-search-(A-Self-Note)

// Binary Search - Removing the left search space in else
class Solution {
public:
    bool check(vector<int>& dist, double hour, int mid) {
        double time = 0;
        for(int num : dist) {
            time = ceil(time);
            time += (double) num / (double) mid;
            if(time > hour)
                return false;
        }
        return true;
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low = 1;
        int hii = 1e7+1;
        while(low < hii) {
            int mid = (low + hii) >> 1;
            if(check(dist, hour, mid))
                hii = mid;
            else
                low = mid + 1;
        }
        return hii > 1e7 ? -1 : hii;
    }
};