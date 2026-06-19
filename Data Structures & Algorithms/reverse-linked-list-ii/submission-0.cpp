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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp = head;
        int i=1;
        ListNode* base = new ListNode(1000);
        // ListNode* extra = base;
        while(i <=right){
            if(i < left){
                i++;
                temp = temp->next;
                continue;
            }
            ListNode* curr = new ListNode(temp->val);
            curr->next = base;
            base = curr;
            i++;
            temp = temp->next;
        }
        // return base;
        temp = head;
        i=1;
        while(i <=right){
            if(i < left){
                i++;
                temp = temp->next;
                continue;
            }
            if(base->val == 1000){
                break;
            }
            temp->val = base->val;
            temp = temp->next;
            base = base->next;
            i++;
        }
        return head;
    }
};