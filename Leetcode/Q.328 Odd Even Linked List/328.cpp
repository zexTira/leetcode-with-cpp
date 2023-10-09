/*//
//  Refer to the solution of Q.86 Partition List
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* evenDummy = new ListNode();
        ListNode* oddDummy = new ListNode();
        ListNode* evenptr = evenDummy;
        ListNode* oddptr = oddDummy;
        int count = 1;

        while (head != NULL)
        {
            if (count % 2 == 0)
            {
                evenptr->next = head;
                evenptr = evenptr->next;
            }
            else
            {
                oddptr->next = head;
                oddptr = oddptr->next;
            }
            head = head->next;
            count++;
        }

        oddptr->next = evenDummy->next;
        evenptr->next = nullptr;
        return oddDummy->next;
    }
};