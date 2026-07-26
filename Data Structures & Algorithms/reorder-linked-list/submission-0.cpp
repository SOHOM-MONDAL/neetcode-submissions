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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode* li = head;
        int cnt =0;
        while(li){
            cnt++;
            li= li->next;
        }
        int mid = (cnt+1)/2;
        ListNode*  div = head;
        ListNode* pre = nullptr;
        for(int i = 0 ; i < mid ; i++){
            pre = div;
            div = div->next; 
        }
        pre->next = nullptr;
        ListNode * prev = nullptr;
        while(div){
            ListNode * temp = div->next;
            div->next = prev;
            prev = div ;
            div = temp;
        }
        ListNode* front= head;
        ListNode dummy(0);
        ListNode * tail = &dummy; 
        while(front && prev){
            tail->next = front;
            front = front->next;
            tail = tail->next;
            tail->next = prev;
            prev = prev->next;
            tail = tail->next; 
        }
        if(front){
            tail->next=front;
        }
    }
};
