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
        int len = 0;
        ListNode* temp = head;
        while(temp != nullptr){
            len++;
            temp = temp->next;
        }
        int toDel = len-n;
        temp = head;
        ListNode* prev = nullptr;
        while(toDel > 0){
            prev = temp;
            temp = temp->next;
            toDel--;
        }
        if(prev == nullptr){
            return head->next;
        }else{
            prev->next = temp->next;
            delete temp;
        }
        return head;
    }
};
