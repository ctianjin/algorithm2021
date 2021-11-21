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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode* phead = new ListNode(0); 
        ListNode* pnode = phead;

        while (l1 && l2)
        {
            if (l2->val <= l1->val)
            {
                pnode->next = l2;
                pnode = pnode->next;
                l2 = l2->next;
            }
            else
            {
                pnode->next = l1;
                pnode = pnode->next;
                l1 = l1->next;
            }
        }

        if (l1)
        {
            pnode->next = l1;
        }
        else
        {
            pnode->next = l2;
        }

        pnode = phead;
        phead = phead->next;
        delete(pnode);

        return phead;

    }
};