#include <iostream>
using namespace std;

// LEETCODE 735 - Asteroid Collision

// Attempt 2
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for(int asteroid : asteroids) {
            if(asteroid > 0)
                ans.push_back(asteroid);
            else {
                while(!ans.empty() && ans.back() > 0 && ans.back() < -asteroid)
                    ans.pop_back();
                if(!ans.empty() && ans.back() == -asteroid)
                    ans.pop_back();
                else if(!ans.empty() && ans.back() > -asteroid)
                    continue;
                else
                    ans.push_back(asteroid);
            }
        }
        return ans;
    }
};

// Attempt 1
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack;
        vector<int> index;
        for(int i = 0 ; i < asteroids.size() ; i++) {
            if(asteroids[i] > 0)
                stack.push_back(i);
            else {
                while(!stack.empty() && asteroids[stack.back()] < abs(asteroids[i]))
                    stack.pop_back();
                if(!stack.empty() && asteroids[stack.back()] == abs(asteroids[i]))
                    stack.pop_back();
                else if(stack.empty())
                    index.push_back(i);
            }
        }
        while(!stack.empty()) {
            index.push_back(stack.back());
            stack.pop_back();
        }
        sort(index.begin(), index.end());
        vector<int> ans;
        for(int idx : index)
            ans.push_back(asteroids[idx]);
        return ans;
    }
};