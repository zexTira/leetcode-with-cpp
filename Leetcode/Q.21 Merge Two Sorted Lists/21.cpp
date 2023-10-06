/*//
//  In this question we need a heap to solve it.
//  First we define a class function cmp to compare the value of two nodes.
//*/


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class cmp {
public:
    bool operator()(const ListNode* a, const ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(0);
        ListNode* temp = head;
        priority_queue<ListNode*, vector<ListNode*>, cmp> minHeap;
        if (list1 != NULL)
        {
            minHeap.push(list1);
        }
        if (list2 != NULL)
        {
            minHeap.push(list2);
        }

        while (!minHeap.empty())
        {
            auto lowest = minHeap.top();
            minHeap.pop();
            temp->next = lowest;
            temp = temp->next;
            if (lowest->next)
            {
                minHeap.push(lowest->next);
            }               
        }
        return head->next;
    }
};