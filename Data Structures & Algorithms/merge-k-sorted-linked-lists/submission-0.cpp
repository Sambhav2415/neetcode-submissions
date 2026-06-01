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
    ListNode* mergetwo(ListNode* list1 , ListNode* list2){
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        while(list1 != nullptr && list2 != nullptr){
            ListNode* node;
            if(list1->val <= list2->val){
                node = list1;
                list1 = list1->next;
            }else{
                node = list2;
                list2 = list2->next;
            }

            if(head == nullptr){
                head = node;
                tail = node;
            }else{
                tail->next = node;
                tail = tail->next;
            }
        }
        if(head == nullptr){
            if(list1 == nullptr){
                head = list2;
            }else if(list2 == nullptr){
                head = list1;
            }
        }else{
            if(list1 == nullptr){
                tail->next = list2;
            }else if(list2 == nullptr){
                tail->next = list1;
            }
        }
        return head;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return nullptr;
        }

        ListNode* result = lists[0];
        for(int i=1;i<lists.size();i++){
            result = mergetwo(result , lists[i]);
        }
        return result;
    }
};
