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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* tmp_head;
        ListNode tmp(0);
        tmp_head = &tmp;
        while(l1 && l2){
            if(l1->val < l2->val){
                tmp_head->next = l1;
                l1 = l1->next;
            }else{
                tmp_head->next = l2;
                l2 = l2->next;
            }
            tmp_head = tmp_head->next;
        }
        tmp_head->next = l1? l1:l2;
        return tmp.next;
    }
};