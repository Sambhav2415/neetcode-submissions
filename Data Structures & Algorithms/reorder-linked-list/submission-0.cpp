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
    void reorderList(ListNode* head) {
        queue<int> q;
        stack<int> s;
        ListNode* temp = head;
        while(temp != nullptr){
            q.push(temp->val);
            s.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        int i=0;
        while(temp != nullptr){
            int num;
            if(i%2==0){ // even
                num = q.front();
                q.pop();
            }else{
                num = s.top();
                s.pop();
            }
            temp->val = num;
            temp = temp->next;
            i++;
        }
    }
};
