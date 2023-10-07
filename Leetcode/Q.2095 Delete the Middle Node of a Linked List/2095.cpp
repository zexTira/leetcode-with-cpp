/*//
//  In this question we define two node pointers, one is faster, which crosses two nodes in a single move, while the slower one moves nodes by nodes.
//  Two pointers both move from the head node, when faster pointer reaches the end, the slower one will exactly at the mid point of the list.
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
    ListNode* deleteMiddle(ListNode* head) {
        if (head->next == NULL)
        {
            return nullptr;
        }

        ListNode* slowptr = head;
        ListNode* fastptr = head;
        while (fastptr != NULL && fastptr->next != NULL)
        {
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;
        }

        ListNode* temp = head;
        while (temp->next != slowptr)
        {
            temp = temp->next;
        }
        if (slowptr->next == NULL)
        {
            temp->next = nullptr;
        }
        else
        {
            temp->next = slowptr->next;
            slowptr->next = nullptr;
        }
        return head;
    }
};