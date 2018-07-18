/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
use two pointer technique.

*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL){
            return NULL;
        }
        ListNode *ptr_f = head ;//fast-pointer 2 steps per round
        ListNode *ptr_s = head ;//slow-pointer 1 step per round
        while(ptr_s->next != NULL && ptr_f->next != NULL){
            
        }

    }
};