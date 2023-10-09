/*//
//  In this question, we first locate the middle point of the list by a fast and a slow pointer(refer to Q.2095), after that we sign this position and push all values after mid point into a vector.
//  Then go through the list again, add every element with the corresponding elemnt in the vector(reversed order), and compute the maximum value, return it.
//  *Stack can be used in this question as it requires some operations based on reversed order, which corresponds with the feature of stack.  
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
    int pairSum(ListNode* head) {
        if (head->next->next == NULL)
        {
            return head->val + head->next->val;
        }

        ListNode* fastptr = head;
        ListNode* slowptr = head;
        vector<int> nums;
        while (fastptr != NULL && fastptr->next != NULL)
        {
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;
        }
        ListNode* boundary = slowptr;
        while (slowptr != NULL)
        {
            nums.push_back(slowptr->val);
            slowptr = slowptr->next;
        }

        int maxval = 0;
        auto i = nums.size() - 1;
        while (head != boundary)
        {
            maxval = max(maxval, head->val + nums[i--]);
            head = head->next;
        }
        return maxval;
    }
};