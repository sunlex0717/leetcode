/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>       // std::cout
#include <stack>          // std::stack
#include <vector>         // std::vector
#include <deque>          // std::deque

using namespace std;
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> nodevector;
        ListNode* tmp = head;
        
        while(tmp != NULL){
            nodevector.push_back(tmp);
            //len++;
            tmp = tmp->next;
        }
        int len = nodevector.size();
        if(n==len){//remove head
            head = head->next;
            return head;
        }
        //ListNode* to_remove = nodevector[len-n];
        ListNode* prev_remove = nodevector[len-n-1]
        
        if(n==1){//remove the final one
            prev_remove->next = NULL;
            return head;
        }
        ListNode* next_remove = nodevector[len-n+1]
        prev_remove->next = next_remove;
        return head;


    }
};