/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if(head->next == nullptr && head == nullptr) return false;
        ListNode* rabb = head;
        ListNode* tor = head;
        while(rabb && rabb->next ){
            rabb = rabb->next->next;
            tor = tor->next;
            if(tor == rabb) return true;
        }
        return false;
    }
};
