/*//
//  In this question we define two node pointers fast and slow, in each loop fast travels across two nodes while slow travels one.
//  If the list does not conclude a cycle, fast pointer will either point to a null node or a node whose next node is a null node.
//  Otherwise both two pointers will enter the cycle, and in each loop the pace of fast pointer is one step more than slow pointer. in this way no matter their distance is, they will finally overlap.
//  If two pointers overlap, return true.
//*/


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow)
                return true;
        }
        return false;
    }
};