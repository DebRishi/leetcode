#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

// LEETCODE 146 - LRU Cache

class LRUCache {
public:
    int size;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> map;
    
    LRUCache(int cap) {
        size = cap;
    }
    
    int get(int key) {
        if(map.find(key) == map.end())
            return -1;
        int val = map[key]->second;
        cache.erase(map[key]);
        cache.push_front({key, val});
        map[key] = cache.begin();
        return val;
    }
    
    void put(int key, int val) {
        if(map.find(key) != map.end()) 
            cache.erase(map[key]);
        if(cache.size() == size) {
            int back = cache.back().first;
            cache.pop_back();
            map.erase(back);
        }
        cache.push_front({key, val});
        map[key] = cache.begin();
    }
};