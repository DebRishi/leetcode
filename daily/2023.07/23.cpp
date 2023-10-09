#include <iostream>
#include <vector>
using namespace std;

// LEETCODE 894 - All Possible Full Binary Trees

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// TABULATION
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<vector<TreeNode*>> dp(n+1);
        dp[1] = {new TreeNode()};
        for(int i = 2; i <= n; i++) {
            if(i % 2 == 0)
                dp[i] = {};
            else {
                vector<TreeNode*> trees;
                for(int j = 1; j < i; j += 2) {
                    vector<TreeNode*>& ltrees = dp[j];
                    vector<TreeNode*>& rtrees = dp[i-j-1];
                    for(auto ltree : ltrees) {
                        for(auto rtree : rtrees) {
                            TreeNode* root = new TreeNode();
                            root->left = ltree;
                            root->right = rtree;
                            trees.push_back(root);
                        }
                    }
                }
                dp[i] = trees;
            }
        }
        return dp[n];
    }
};

// MEMOIZATION
class Solution {
public:
    vector<vector<TreeNode*>> memo;
    
    vector<TreeNode*> solve(int n) {
        if(n % 2 == 0)
            return {};
        if(n == 1)
            return {new TreeNode()};
        if(!memo[n].empty())
            return memo[n];
        vector<TreeNode*> trees;
        for(int i = 1; i < n; i += 2) {
            vector<TreeNode*> ltrees = solve(i);
            vector<TreeNode*> rtrees = solve(n-i-1);
            for(auto ltree : ltrees) {
                for(auto rtree : rtrees) {
                    TreeNode* root = new TreeNode();
                    root->left = ltree;
                    root->right = rtree;
                    trees.push_back(root);
                }
            }
        }
        return memo[n] = trees;
    }
    
    vector<TreeNode*> allPossibleFBT(int n) {
        memo = vector<vector<TreeNode*>>(n+1);
        return solve(n);
    }
};

// SIMPLE RECURSION
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n % 2 == 0)
            return {};
        if(n == 1)
            return {new TreeNode()};
        vector<TreeNode*> trees;
        for(int i = 1; i < n; i += 2) {
            vector<TreeNode*> ltrees = allPossibleFBT(i);
            vector<TreeNode*> rtrees = allPossibleFBT(n-i-1);
            for(auto ltree : ltrees) {
                for(auto rtree : rtrees) {
                    TreeNode* root = new TreeNode();
                    root->left = ltree;
                    root->right = rtree;
                    trees.push_back(root);
                }
            }
        }
        return trees;
    }
};