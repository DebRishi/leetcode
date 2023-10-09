#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int minNum = INT_MAX;
        stack<int> stack;
        for(int num : nums) {
            if(num <= minNum)
                minNum = num;
            else if (stack.empty())
                stack.push(num);
            else {
                while(!stack.empty() && stack.top() <= num)
                    stack.pop();
                if (!stack.empty())
                    return true;
                else
                    stack.push(num);
            }
        }
        return false;
    }
};