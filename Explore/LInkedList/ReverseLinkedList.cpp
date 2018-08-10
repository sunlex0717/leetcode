/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// can be implemented recursively or iteratively;
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* black_node = head;
        ListNode* next;
        
        while( black_node != NULL && black_node->next != NULL ){
            next = black_node->next;
            black_node->next = next->next;
            next->next = head;
            head = next;
        }

        return head;
    }
};