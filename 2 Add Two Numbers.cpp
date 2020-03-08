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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* q = dummyHead;

        int carry = 0; // ½øÎ»
        
        while (l1 && l2) {
            int tmpSum = l1->val + l2->val + carry;
            ListNode* p = new ListNode(tmpSum % 10);
            carry = tmpSum / 10;
            q->next = p;
            q = q->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            int tmpSum = l1->val + carry;
            ListNode* p = new ListNode(tmpSum % 10);
            carry = tmpSum / 10;
            q->next = p;
            q = q->next;
            l1 = l1->next;
        }
        while (l2) {
            int tmpSum = l2->val + carry;
            ListNode* p = new ListNode(tmpSum % 10);
            carry = tmpSum / 10;
            q->next = p;
            q = q->next;
            l2 = l2->next;
        }
        if (carry != 0) {
            ListNode* p = new ListNode(carry);
            q->next = p;
            q = q->next;
        }
        return dummyHead->next;
    }
};
