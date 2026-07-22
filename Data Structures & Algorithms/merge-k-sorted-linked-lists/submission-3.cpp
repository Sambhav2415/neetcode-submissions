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
        if (lists.empty())
            return nullptr;

        int interval = 1;
        int n = lists.size();

        // while (interval < n) {
        //     for (int i = 0; i + interval < n; i += 2 * interval) {
        //         lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
        //     }
        //     interval *= 2;
        // }

        while(interval < n){
            for(int i=0;i+interval<n; i = i+2*interval){
                lists[i] = mergeTwoLists(lists[i],lists[i+interval]);
            }
            interval *=2;
        }

        return lists[0];
    }
};
