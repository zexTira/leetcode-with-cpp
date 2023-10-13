/*//
//  We need a hashmap in this question.
//  First we consider the pointer of each node as a key, and its copy as a value.
//  Then we check each value by the key again, and set their next and random pointer.
//  Finally return the head of the copy.
//*/


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> umap;
        Node* ptr = head;

        while (ptr != NULL)
        {
            umap[ptr] = new Node(ptr->val);
            ptr = ptr->next;
        }

        ptr = head;
        while (ptr != NULL)
        {
            umap[ptr]->next = umap[ptr->next];
            umap[ptr]->random = umap[ptr->random];
            ptr = ptr->next;
        }

        return umap[head];
    }
};