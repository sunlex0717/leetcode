/*https://leetcode.com/explore/learn/card/linked-list/214/two-pointer-technique/1214/discuss/44781/Concise-O(n)-solution-by-using-C++-with-Detailed-Alogrithm-Description

Leetcode discussion link, to solve this problem, a mathematical analysis is necessary.
*/
class Solution {
public:
ListNode *detectCycle(ListNode *head) {
    if (head == NULL || head->next == NULL)
        return NULL;
    
    ListNode *slow  = head;
    ListNode *fast  = head;
    ListNode *entry = head;
    
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {                      // there is a cycle
            while(slow != entry) {               // found the entry location
                slow  = slow->next;
                entry = entry->next;
            }
            return entry;
        }
    }
    return NULL;                                 // there has no cycle
}
};