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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> arr;
        ListNode * curr = head;
        while(curr){
            arr.push_back(curr);
            curr = curr->next;
        }
        int n_arr = arr.size();

        int idx = n_arr - n ;
        
        if (idx == 0) {
            return head->next;
        }
        arr[idx - 1]->next = arr[idx]->next;
        return head;
    }
};
