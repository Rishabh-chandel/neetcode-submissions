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
private:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* node = head;
        ListNode* prev = nullptr;
        while(node != NULL) {
            ListNode* nxt = node->next;
            node->next = prev;
            prev = node;
            node = nxt;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* nxt = slow->next;
        slow->next = NULL;
        ListNode* rev = reverseList(nxt);
        while(head && rev) {
            ListNode* nxt1 = head->next;
            ListNode* nxt2 = rev->next;
            head->next = rev;
            rev->next = nxt1;
            head = nxt1;
            rev = nxt2;
        }
    }
};
