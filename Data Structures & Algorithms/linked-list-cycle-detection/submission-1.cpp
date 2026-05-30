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
    bool hasCycle(ListNode* head) {
        ListNode* head1 = head;
        ListNode* head2 = head;
        // head1 = head1->next->next;
        // head2 = head2->next;
        bool isCorrect = true;
        while(head1 != nullptr && head2 != nullptr){
            if(head1 == head2 && !isCorrect){
                return true;
            }else{
                if(head1->next != nullptr){
                    head1 = head1->next->next;
                    head2 = head2->next;
                }else{
                    return false;
                }
            }
            isCorrect = false;
        }

        return false;
    }
};
