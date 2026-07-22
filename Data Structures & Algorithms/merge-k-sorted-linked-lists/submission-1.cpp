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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        ListNode* temp = head;
        while(list1 != nullptr && list2 != nullptr){
            if(list1->val <= list2->val){
                temp->next = list1;
                temp = temp->next;
                list1 = list1->next;
            }else{
                temp->next = list2;
                temp = temp->next;
                list2 = list2->next;
            }
        }
        if(list1 == nullptr){
            temp->next = list2;
        }else{
            temp->next = list1;
        }
        return head->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0){
            return nullptr;
        }
        ListNode* result = lists[0];
        for(int i=1;i<n;i++){
            result = mergeTwoLists(result,lists[i]);
        }
        return result;
    }
};
