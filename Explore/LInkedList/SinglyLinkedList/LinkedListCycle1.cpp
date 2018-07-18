/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
use two pointer technique
A fast-point and slow-point
*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL){
            return false;
        }
        ListNode *ptr_f = head->next ;//fast-pointer 2 steps per round
        ListNode *ptr_s = head ;//slow-pointer 1 step per round
        while(1){
            if(ptr_f == ptr_s){
                return true;
            }else if(ptr_f == NULL){ //corner case 1: only one component [1], so ptr->next does not exist
                return false;
            }
            else{
                ptr_f = ptr_f->next;
                //ptr_s = ptr_s->next;
                if(ptr_f == NULL){  //corner case 2 : the number of rest nodes are odd
                    return false;
                }else{
                    ptr_f = ptr_f->next;
                    ptr_s = ptr_s->next;
                }
            }
        }
        
    }
};