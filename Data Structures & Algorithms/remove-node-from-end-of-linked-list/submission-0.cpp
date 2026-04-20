/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        ListNode* node = head;
        while(node) {
            cnt++;
            node = node->next;
        }
        if(n == cnt) return head->next;
        ListNode* prev = NULL;
        node = head;
        cnt-=n;
        int idx = 1;
        while(idx < cnt) {
            node = node->next;
            idx++;
        }
        node->next = node->next->next;
        return head;
    }
};
