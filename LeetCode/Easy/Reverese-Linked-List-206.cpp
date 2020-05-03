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
    ListNode* reverseList(ListNode* head) {
        ListNode *current = NULL;
        ListNode *previous = NULL;
        while(head){
            current = head;
            head = head->next;
            current->next = previous;
            previous = current;
        }
        head = current;
        return head;
    }
};


