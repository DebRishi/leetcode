#include <iostream>
using namespace std;

// LEETCODE 808 - Soup Servings

// Hack - with Larger value N, the probability will grow closer to 1. Approximately is N > 5000 -> P(5000) ~ 1
class Solution {
public:
    vector<vector<double>> memo;
    
    double solve(int soup1, int soup2) {
        if(soup1 <= 0 && soup2 <= 0)
            return 0.5;
        if(soup1 <= 0)
            return 1;
        if(soup2 <= 0)
            return 0;
        if(memo[soup1][soup2] != -1)
            return memo[soup1][soup2];
        return memo[soup1][soup2] = 0.25 * (
            solve(soup1 - 100, soup2 - 0) + 
            solve(soup1 - 75, soup2 - 25) + 
            solve(soup1 - 50, soup2 - 50) + 
            solve(soup1 - 25, soup2 - 75)
        );
    }
    
    double soupServings(int n) {
        if(n > 5000)
            return 1;
        memo = vector<vector<double>>(n+1, vector<double>(n+1, -1));
        return solve(n, n);
    }
};

// MEMOIZATION - Memory Limit Exceeded (MLE)
class Solution {
public:
    vector<vector<double>> memo;
    
    double solve(int soup1, int soup2) {
        if(soup1 <= 0 && soup2 <= 0)
            return 0.5;
        if(soup1 <= 0)
            return 1;
        if(soup2 <= 0)
            return 0;
        if(memo[soup1][soup2] != -1)
            return memo[soup1][soup2];
        return memo[soup1][soup2] = 0.25 * (
            solve(soup1 - 100, soup2 - 0) + 
            solve(soup1 - 75, soup2 - 25) + 
            solve(soup1 - 50, soup2 - 50) + 
            solve(soup1 - 25, soup2 - 75)
        );
    }
    
    double soupServings(int n) {
        memo = vector<vector<double>>(n+1, vector<double>(n+1, -1));
        return solve(n, n);
    }
};

// RECURSION - Time limit Exceeded (TLE)
class Solution {
public:
    double solve(int soup1, int soup2) {
        if(soup1 <= 0 && soup2 <= 0)
            return 0.5;
        if(soup1 <= 0)
            return 1;
        if(soup2 <= 0)
            return 0;
        return 0.25 * (
            solve(soup1 - 100, soup2 - 0) + 
            solve(soup1 - 75, soup2 - 25) + 
            solve(soup1 - 50, soup2 - 50) + 
            solve(soup1 - 25, soup2 - 75)
        );
    }
    
    double soupServings(int n) {
        return solve(n, n);
    }
};