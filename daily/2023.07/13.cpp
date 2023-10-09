#include <iostream>
#include <queue>
using namespace std;

// LEETCODE 207 - Course Schedule

// Cycle Detection in Directed Graph - BFS / Topological Sort (Kahn's Algorithm)
class Solution {
public:
    bool canFinish(int size, vector<vector<int>>& edges) {
        vector<vector<int>> graph(size);
        vector<int> indeg(size);
        for(auto& edge : edges) {
            graph[edge[1]].push_back(edge[0]);
            indeg[edge[0]]++;
        }
        queue<int> queue;
        for(int node = 0 ; node < size ; node++) {
            if(!indeg[node])
                queue.push(node);
        }
        int nodes = 0;
        while(!queue.empty()) {
            int node = queue.front();
            queue.pop();
            nodes++;
            for(int next : graph[node]) {
                if(!--indeg[next])
                    queue.push(next);
            }
        }
        return nodes == size;
    }
};

// Cycle Detection in Directed Graph - DFS
class Solution {
public:
    bool foundCycle(vector<vector<int>>& graph, vector<int>& visited, int node) {
        if(visited[node] == 1)
            return true;
        if(visited[node] == 2)
            return false;
        visited[node] = 1;
        for(int next : graph[node]) {
            if(foundCycle(graph, visited, next))
                return true;
        }
        visited[node] = 2;
        return false;
    }
    
    bool canFinish(int size, vector<vector<int>>& edges) {
        vector<vector<int>> graph(size);
        vector<int> visited(size);
        for(auto& edge : edges)
            graph[edge[1]].push_back(edge[0]);
        for(int node = 0 ; node < size ; node++) {
            if(foundCycle(graph, visited, node))
                return false;
        }
        return true;
    }
};