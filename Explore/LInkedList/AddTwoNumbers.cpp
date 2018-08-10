/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/
using namespace std;
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy_node(0);
        ListNode* tail = &dummy_node;
        ListNode* head_l2 = l2;
        ListNode* head_l1 = l1;
        int carry_bit = 0;
        int tmp_sum;
        int tmp_remainder = 0;
        tail->next = l1;
        while(l1 && l2){
            tmp_sum = l1->val + l2->val + carry_bit ;
            carry_bit = tmp_sum/10;
            
            tmp_remainder = tmp_sum - carry_bit*10;
            cout<<"carry_bit: " << carry_bit <<" ,remainder: "<< tmp_remainder <<endl;
            
            tail->next->val = tmp_remainder;
            l1=l1->next;
            l2=l2->next;
            tail = tail->next;
        }
        if(l1==NULL){ //l1 is the shorter one.
            cout<<"l1 is the shorter one " <<endl;
            tail->next = head_l2;
            //if(tail->next == NULL && carry_bit!=0 )
            while(l2 !=NULL){
                //cout<<"traverse l2" <<endl;
                tmp_sum =l2->val + carry_bit;
                carry_bit = tmp_sum/10;
                tmp_remainder = tmp_sum - carry_bit*10;
                tail->next->val = tmp_remainder;
                l2=l2->next;
                tail = tail->next;
            }
            if(carry_bit != 0){
                tail->next->val = carry_bit;
                tail = tail->next;
            }
            tail -> next = NULL;
            //tail = NULL;
            
            return dummy_node.next;
        }else { //l2 is the shorter one.
            cout<<"l2 is the shorter one " <<endl;
            //tail->next = l1;
             while(l1 !=NULL){
                cout<<"traverse l1" <<endl;
                tmp_sum =l1->val + carry_bit;
                
                carry_bit = tmp_sum/10;
                tmp_remainder = tmp_sum - carry_bit*10;
               
                tail->next->val = tmp_remainder;
                l1=l1->next;
                tail = tail->next;
            }
            if(carry_bit != 0){
                tail->next = head_l2;
                tail->next->val = carry_bit;
                tail = tail->next;
            }

            tail -> next = NULL; //cut down the list
            return dummy_node.next;
        }
    }
};