/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL){
            return head;
        }
        ListNode* cur;
        ListNode* prev = head;
        
        while( prev != NULL ){
            
            if(head->val == val && prev==head){
                head = head->next;
                //free(prev);
                prev = head;
                if(head == NULL){
                    return head;
                }
                continue;
            }
            cur = prev->next;
            if(cur != NULL && cur->val == val){
                prev->next = cur->next;
                //free(cur);
            }
            prev = prev->next;
        }
        return head;
    }
};