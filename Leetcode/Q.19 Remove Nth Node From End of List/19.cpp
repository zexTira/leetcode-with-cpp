/*//
// In this question there are 2 general conditions. 
// We first define a right pointer and move it right n-1 times to record the offset which indicates the distance from the end to the element we are going to delete.
// If rptr reaches the end of the list, the node we want to delete is obviously the head, sowe just return the next node of head.
// Othwise we need to define a middle pointer which indicates the desirable element and a left pointer indicates the previous node of that pointed by midptr.
// We move all 3 pointers to the right stimutaneously until right pointer reaches the end, then all we need to do is make the next of lptr node point to next of midptr, and invalidate next of midptr 
     to delete midptr node.
// Finally return the head ptr.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* rptr = head;
        while (--n > 0)
        {
            rptr = rptr->next;
        }
        if (rptr->next == NULL)
        {
            head = head->next;
            return head;
        }

        ListNode* lptr = head;
        ListNode* midptr = head->next;
        rptr = rptr->next;
        while (rptr->next != NULL)
        {
            rptr = rptr->next;
            midptr = midptr->next;
            lptr = lptr->next;
        }
        lptr->next = midptr->next;
        midptr->next = NULL;
        return head;
    }
};