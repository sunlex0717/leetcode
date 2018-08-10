/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
using namespace std;
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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return true;
        }
        
        vector<ListNode*> list_vec;
        ListNode* cur = head;
        while(cur !=NULL){
            list_vec.push_back(cur);
            cur = cur->next;
        }
        ListNode* reversed = reverseList(head);
        int i = 0;
        while(reversed != NULL){
            if(reversed->val != list_vec[i]->val ){
                return false;
            }
            ++i;
            reversed = reversed->next;
        }
        return true;
    }
};