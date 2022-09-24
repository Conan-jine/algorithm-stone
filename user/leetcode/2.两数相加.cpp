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
class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode *res, *head;
        res = new ListNode(l1->val + l2->val);
        head = res;
        while(1)
        {
            if(l1->next != nullptr && l2->next != nullptr)
            {
                res->next = new ListNode(l1->next->val + l2->next->val);
                res = res->next;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if(l1->next == nullptr && l2->next != nullptr)
            {
                res->next = new ListNode(l2->next->val);
                res = res->next;
                l2 = l2->next;
            }
            else if(l1->next != nullptr && l2->next == nullptr)
            {
                res->next = new ListNode(l1->next->val);
                res =res->next;
                l1 = l1->next;
            }
            else if(l1->next == nullptr && l2->next == nullptr) break;
        }
        res = head;
        while(res->next != nullptr)
        {
            if(res->val > 9)
            {
                res->val -= 10;
                (res->next->val)++;
            }
            res = res->next;
        }
        if(res->val > 9)
        {
            res->next = new ListNode(1);
            res->val -= 10;
        }
        return head;
    }
};