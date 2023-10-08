/*//
//  In this question we need two pointers to indicate the smaller list and the larger list.
//  First we define two pre-head node which links to the list storing smaller namber and larger number respectively.
//  Next we move the head pointer node by node until the end of the list, if the value in this node is smaller than x, link it to the small list, otherwise link it to large list.
//  Finally we make the last node of small list linked to the head node of large node, invalidate the next pointer of last node of large list, then just return the head node of small list.
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummySmall = new ListNode(0);
        ListNode* dummyLarge = new ListNode(0);

        ListNode* smallPtr = dummySmall;
        ListNode* largePtr = dummyLarge;

        while (head != NULL)
        {
            if (head->val < x)
            {
                smallPtr->next = head;
                smallPtr = smallPtr->next;
            }
            else
            {
                largePtr->next = head;
                largePtr = largePtr->next;
            }
            head = head->next;
        }
        smallPtr->next = large->next;
        largePtr->next = NULL;

        return small->next;
    }
};