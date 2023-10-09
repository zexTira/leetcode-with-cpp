/*//
//  In this question we need to add the corresponding elements in two list node by node.
//  During every sum, we need to check if the result is ought to be carried, if the sum is bigger or equal to 10, we keep its last digit and plus 1 to the next calculation result, if not set carry value to 0.
//  The length of two list may not the same, so we copy the remaining elements in longer one to the result and still remember check the carry.
//  Finally check the carry for the last time, if carry==1, we simply add one node whose value is 1 to the end of the list.
//*/


//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode();
        ListNode* resultptr = result;
        int carry = 0;
        int sum;
        while (l1 != NULL && l2 != NULL)
        {
            sum = carry + l1->val + l2->val;
            if (sum >= 10)
            {
                sum -= 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            ListNode* tmpptr = new ListNode(sum);
            resultptr->next = tmpptr;
            resultptr = tmpptr;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1 != NULL)
        {
            while (l1 != NULL)
            {
                sum = carry + l1->val;
                if (sum >= 10)
                {
                    sum -= 10;
                    carry = 1;
                }
                else
                {
                    carry = 0;
                }
                ListNode* tmpptr = new ListNode(sum);
                resultptr->next = tmpptr;
                resultptr = tmpptr;
                l1 = l1->next;
            }
        }
        else
        {
            while (l2 != NULL)
            {
                sum = carry + l2->val;
                if (sum >= 10)
                {
                    sum -= 10;
                    carry = 1;
                }
                else
                {
                    carry = 0;
                }
                ListNode* tmpptr = new ListNode(sum);
                resultptr->next = tmpptr;
                resultptr = tmpptr;
                l2 = l2->next;
            }
        }
        if (carry == 1)
        {
            ListNode* tmpptr = new ListNode(1);
            resultptr->next = tmpptr;
        }
        return result->next;
    }
};