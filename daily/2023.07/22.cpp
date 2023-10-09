#include <iostream>
using namespace std;

// LEETCODE 688 - Knight Probability in Chessboard

// TABULATION
class Solution {
public:
    double knightProbability(int n, int k, int r, int c) {
        vector<pair<int, int>> moves = { {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1} };
        auto dp1 = vector<vector<double>>(n, vector<double>(n));
        auto dp2 = vector<vector<double>>(n, vector<double>(n));
        dp1[r][c] = 1;
        for(int h = 0; h < k; h++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(dp1[i][j] > 0) {
                        for(auto& [x, y] : moves) {
                            int X = i + x;
                            int Y = j + y;
                            if(X >= 0 && Y >= 0 && X < n && Y < n)
                                dp2[X][Y] += dp1[i][j] / 8.0;
                        }
                    }
                }
            }
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    dp1[i][j] = dp2[i][j];
                    dp2[i][j] = 0;
                }
            }
        }
        double ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                ans += dp1[i][j];
            }
        }
        return ans;
    }
};


// MEMOIZATION
class Solution {
public:
    vector<pair<int, int>> moves = { {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1} };
    vector<vector<vector<double>>> memo;
    
    double solve(int n, int k, int i, int j) {
        if(i < 0 || j < 0 || i >= n || j >= n)
            return 0;
        if(k == 0)
            return 1;
        if(memo[i][j][k] != -1)
            return memo[i][j][k];
        double ans = 0;
        for(auto& [x, y] : moves) 
            ans += solve(n, k-1, i+x, j+y);
        return memo[i][j][k] = ans;
    }
    
    double knightProbability(int n, int k, int r, int c) {
        memo = vector<vector<vector<double>>>(n, vector<vector<double>>(n, vector<double>(k+1, -1)));
        return solve(n, k, r, c) / pow(8, k);
    }
};