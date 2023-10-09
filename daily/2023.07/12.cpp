#include <iostream>
using namespace std;

// DFS
class Solution {
public:
    bool solve(vector<vector<int>>& graph, int node, vector<bool>& done, vector<bool>& safe) {
        if(done[node])
            return safe[node];
        done[node] = true;
        for(int next : graph[node]) {
            if(!solve(graph, next, done, safe))
                return safe[node] = false;
        }
        return safe[node] = true;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int size = graph.size();
        vector<bool> safe(size);
        vector<bool> done(size);
        for(int node = 0 ; node < size ; node++) {
            if(graph[node].size() == 0) {
                safe[node] = true;
                done[node] = true;
            }
        }
        vector<int> ans;
        for(int node = 0 ; node < size ; node++) {
            if(solve(graph, node, done, safe))
                ans.push_back(node);
        }
        return ans;
    }
};