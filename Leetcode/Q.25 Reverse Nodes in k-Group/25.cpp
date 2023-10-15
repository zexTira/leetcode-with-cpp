/*//
//  First we define a function that calculate the length of a list.
//  Then we get the length of the list, for each loop, we copy each node and insert them at the front position to reverse the group, and after that we travel through the new list to the end and start another loop.
//  In each loop we substract k on the total length, and finally length will smaller than k, in this case we directly return the head node of the list.
//*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int LinkListLen(ListNode* head) {
        int res = 0;
        while (head != NULL)
        {
            res++;
            head = head->next;
        }
        return res;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ans = new ListNode(-1);
        ListNode* dummy = ans;
        int len = LinkListLen(head);
        while (head != NULL)
        {
            if (len >= k)
            {
                ListNode* tem = NULL;
                for (int i = 0; i < k; i++)
                {
                    ListNode* n = new ListNode(head->val);
                    head = head->next;
                    n->next = tem;
                    tem = n; 
                    len--;
                }
                dummy->next = tem;
                while (dummy->next != NULL)
                {
                    dummy = dummy->next;
                }
            }
            else
            {
                dummy->next = head;
                break;
            }
        }
        return ans->next;
    }
};