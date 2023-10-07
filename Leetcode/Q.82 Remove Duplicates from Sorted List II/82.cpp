/*//
//  In this question we need a hashmap and go throughout the list once to record all elements in the list and how many times a value occurs.
//  By doing this we can locate those duplicate values. Go throughout the array for the second time, if the value of one node occurs more than once, we simply delete the node.
//  After the second going through, we return the head pointer.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        unordered_map<int, int> umap;
        ListNode* fastptr = head;
        while (fastptr != NULL)
        {
            umap[fastptr->val]++;
            fastptr = fastptr->next;
        }

        while (head && umap[head->val] > 1)
        {
            head = head->next;
        }
        if (head == NULL)
        {
            return head;
        }

        ListNode* slowptr = head->next;
        ListNode* temp = head;
        while (slowptr != NULL)
        {
            if (umap[slowptr->val] > 1)
            {
                temp->next = slowptr->next;
                slowptr->next = nullptr;
                slowptr = temp->next;
            }
            else
            {
                temp = temp->next;
                slowptr = slowptr->next;
            }
        }
        return head;
    }
};