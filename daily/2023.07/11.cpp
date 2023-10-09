#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// BRUTE FORCE - Creating custom parent links
class Solution {
public:
    struct Node {
        int val;
        Node* lnode;
        Node* rnode;
        Node* pnode;
    };
    
    Node* addParent(TreeNode* root, Node* parent) {
        if(!root)
            return 0;
        Node* node = new Node();
        node->val = root->val;
        node->lnode = addParent(root->left, node);
        node->rnode = addParent(root->right, node);
        node->pnode = parent;
        return node;
    }
    
    Node* getTarget(Node* root, TreeNode* target) {
        if(!root)
            return 0;
        if(root->val == target->val)
            return root;
        Node* lnode = getTarget(root->lnode, target);
        Node* rnode = getTarget(root->rnode, target);
        return lnode ? lnode : rnode;
    }
    
    void traverse(Node* root, int k, vector<int>& ans, unordered_set<Node*>& set) {
        if(!root || set.find(root) != set.end())
            return;
        set.insert(root);
        if(k == 0) {
            ans.push_back(root->val);
            return;
        }
        traverse(root->pnode, k-1, ans, set);
        traverse(root->lnode, k-1, ans, set);
        traverse(root->rnode, k-1, ans, set);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        Node* rootNode = addParent(root, nullptr);
        Node* targetNode = getTarget(rootNode, target);
        vector<int> ans;
        unordered_set<Node*> set;
        traverse(targetNode, k, ans, set);
        return ans;
    }
};