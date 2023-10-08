/*//
//  The specific description can be seen below.
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
    ListNode* rotateRight(ListNode* head, int k) {
        // if list is emply, we straight forward return a null pointer.
        if (head == NULL)
        {
            return head;
        }

        //count how many nodes is this list.
        ListNode* ptr1 = head;
        int count = 0;
        while (ptr1 != NULL)
        {
            count++;
            ptr1 = ptr1->next;
        }

        // the times that for rotating will be k%count, as there is a loop when we rotate it every count times.
        // by calculating the final count we can get where the break pointer is, while all nodes after which will be rotated to the head position. 
        count -= (k % count + 1);
        ptr1 = head;
        while (--count >= 0)
        {
            ptr1 = ptr1->next;  //get break pointer position.
        }

        ListNode* newHead = ptr1->next; //  the next position of the break pointer should be the new head node.
        if (newHead == NULL)    //  if the break pointer is at the end of the list, which means that no need to rotate, we can directly return original head.
        {
            return head;
        }
        else    //  otherwise we make the next of break pointer null pointer, and make the next position of the end of the list the original head to rotate, and return the new head node.
        {
            ptr1->next = nullptr;   
            ListNode* ptr2 = newHead;
            while (ptr2->next != NULL)
            {
                ptr2 = ptr2->next;
            }
            ptr2->next = head;
            return newHead;
        }
    }
}; 