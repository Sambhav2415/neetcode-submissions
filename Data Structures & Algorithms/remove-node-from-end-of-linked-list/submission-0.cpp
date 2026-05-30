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
        ListNode*temp = head;
        int tot = 0;
        while(temp != nullptr){
            tot++;
            temp = temp->next;
        }
        int toDelete = -n + tot;

        temp = head ;
        ListNode* prev = nullptr;
        while(toDelete >0){
            prev = temp;
            temp = temp->next;
            toDelete--;
        }
        if(prev == nullptr){
            return head->next;
        }else{
            prev->next = temp->next;
        }
        return head;
    }
};
