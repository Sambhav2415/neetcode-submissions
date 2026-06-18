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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* toRet = new ListNode(head->val);
        ListNode* temp = head;
        ListNode* main = toRet;
        temp = temp->next;
        int prev = head->val;
        while(temp != nullptr){
            int curr = temp->val;
            int k = gcd(curr,prev);
            main->next = new ListNode(k);
            main = main->next;
            main->next = new ListNode(curr);
            main = main->next;
            prev = curr;
            temp = temp->next;
        }
        return toRet;
    }
};