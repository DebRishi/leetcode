#include <iostream>
using namespace std;

// LEETCODE 445 - Add Two Numbers II

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverse(ListNode*& head) {
        ListNode* next = 0;
        ListNode* prev = 0;
        while(head) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return head = prev;
    }
    
    ListNode* addTwoNumbers(ListNode* num1, ListNode* num2) {
        ListNode* head = new ListNode();
        ListNode* node = head;
        ListNode* rev1 = reverse(num1);
        ListNode* rev2 = reverse(num2);
        int sum = 0;
        int car = 0;
        while(rev1 || rev2 || car) {
            sum = car;
            if(rev1) {
                sum += rev1->val;
                rev1 = rev1->next;
            }
            if(rev2) {
                sum += rev2->val;
                rev2 = rev2->next;
            }
            car = sum / 10;
            sum = sum % 10;
            node->next = new ListNode(sum);
            node = node->next;
        }
        return reverse(head->next);
    }
};