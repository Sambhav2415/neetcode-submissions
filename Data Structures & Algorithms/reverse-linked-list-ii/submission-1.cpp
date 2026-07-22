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
        if(left == right){
            return head;
        }
        ListNode* beforeLeft = nullptr;
        ListNode* temp = head;
        int idx = 1;
        while(idx < left){
            beforeLeft = temp;
            temp=temp->next;
            idx++;
        }
        ListNode* leftNode = temp;
        ListNode* prev = nullptr;
        for(int i=0;i<=right-left;i++){
            ListNode* newNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = newNode;
        }
        if(beforeLeft == nullptr){
            head = prev;
        }else{
            beforeLeft->next = prev;
        }
        leftNode->next = temp;
        return head;
    }
};