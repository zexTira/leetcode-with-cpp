/*//
//  The step of the solution can be seen below.
//*/

// First we define a struct which implements a double linked list, and the content part should be key(needed later) and value.
struct MyListNode {
    int key;
    int val;
    MyListNode* next;
    MyListNode* prev;
    MyListNode() : key(0), val(0), next(nullptr), prev(nullptr) {}
    MyListNode(int a, int b) :key(a), val(b), next(nullptr), prev(nullptr) {}
    MyListNode(int a, int b, MyListNode* ptr1, MyListNode* ptr2) :key(a), val(b), next(ptr1), prev(ptr2) {}
};

//  Definition of solution class
class LRUCache {
private:
    int maxCap;     //maximum capicity given by tester
    int curCap;     //current number of members 
    unordered_map<int, MyListNode*> umap;   // hashmap storing keys and their corresponding nodes
    MyListNode* curPtr;     // indicates the most recently used node
    MyListNode* head;       // points to the first node of the cache all the time

public:
    LRUCache(int capacity) {        //construct function for initializing the capacity and an empty head node.
        this->maxCap = capacity;
        this->curCap = 0;
        this->head = new MyListNode();
        this->curPtr = head;
    }

    void AddNode(int key, int val) {    //Add a new node to the end of the list (A less used node will be more near the head node in this way)
        MyListNode* tmp = new MyListNode(key, val, nullptr, curPtr);        //initialize a new node with its prev node pointer being curPtr and next node pointer being null.
        curPtr->next = tmp;
        curPtr = curPtr->next;      //curPtr now is pointing to this new node
        umap[key] = curPtr;     //add information of this node to umap
    }

    void DeleteNode() {     //  Delete the node which is at the next position of head node.
        MyListNode* p = head->next;
        auto it = umap.find(p->key);
        umap.erase(it);     //  erase its info from umap.
        head->next = p->next;
        p->next->prev = head;   //update the connection of head and its next node.
        delete p;   //release the memory for this node.
    }
    void UpdateMostRecentNode(MyListNode* currentPtr) {     // update this node which currentPtr points to to the end of the list
        currentPtr->prev->next = currentPtr->next;      // update the connection at initial position
        currentPtr->next->prev = currentPtr->prev;
        currentPtr->next = nullptr;     //  modify its current connection
        curPtr->next = currentPtr;
        currentPtr->prev = curPtr;
        curPtr = currentPtr;    //  set curPtr points to current node.
    }

    int get(int key) {      
        if (umap.find(key) == umap.end())
        {
            return -1;      // if we can not find that key in umap when calling get(int), return -1, 
        }
        else
        {
            auto tmpPtr = umap.find(key)->second;   // otherwise we check if this node is the node curPtr points to, if so it has already been at the end of list, we don't need more operations.
            if (curPtr != tmpPtr)
            {
                UpdateMostRecentNode(tmpPtr);   // otherwise we update it to the end of the list, as it was used just now.
            }
            return tmpPtr->val;
        }
    }

    void put(int key, int value) {
        if (umap.find(key) == umap.end())   // find the key in
        {     // if we cannot find the key in hashmap, we need to add this node.
            if (curCap < maxCap)
            {
                AddNode(key, value);    //add one node at the end of array and set current member number.
                ++curCap;
            }
            else
            {
                AddNode(key, value);    // if there's no remaining capacity, we need to delete the next node of head, as it's least recently used. 
                DeleteNode();
            }
        }
        else
        {
            MyListNode* tmpPtr = umap.find(key)->second;    //if we can find that key, we should update both its value and its position.
            if (tmpPtr->val != value)
            {
                tmpPtr->val = value;
            }
            if (curPtr != tmpPtr)
            {
                UpdateMostRecentNode(tmpPtr);
            }
        }
    }
};