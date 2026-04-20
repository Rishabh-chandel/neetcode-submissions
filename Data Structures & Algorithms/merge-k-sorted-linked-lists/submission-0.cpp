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
    ListNode* mergeKLists(vector<ListNode*>& arr) {
        int n = arr.size();
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        vector<int> nums;
        for(int i=0;i<n;i++) {
            ListNode* head = arr[i];
            while(head) {
                nums.push_back(head->val);
                head = head->next;
            }
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++) {
            ListNode* newnode = new ListNode(nums[i]);
            temp->next = newnode;
            temp = temp->next;
        }
        return dummy->next;
    }
};
