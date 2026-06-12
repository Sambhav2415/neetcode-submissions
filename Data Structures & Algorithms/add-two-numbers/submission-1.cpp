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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int n1=0,n2=0;
        ListNode* head = new ListNode();
        ListNode* ans = head;
        int carry = 0;
        while(temp1 != nullptr || temp2 != nullptr){
            if(temp1 == nullptr){
                n1 = 0;
                n2 = temp2->val;
                temp2 = temp2->next;
            }else if(temp2 == nullptr){
                n1 = temp1->val;
                n2 = 0;
                temp1 = temp1->next;
            }else{
                n1 = temp1->val;
                n2 = temp2->val;
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            int res = n1+n2+carry;
            carry = res/10;
            ans->next = new ListNode(res%10);
            ans = ans->next;
        }
        if(carry == 1){
            ans->next = new ListNode(1);
        }
        return head->next;
    }
};
