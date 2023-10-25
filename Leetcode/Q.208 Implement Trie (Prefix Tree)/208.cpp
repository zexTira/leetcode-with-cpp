/*//
//  This is a simple way to reverse a list node by node with 3 pointers.
//  We need a pointer which indicates current node, and 2 pointers for its previous node and next node.
//  Then we let the next node of current node be the previous node, and make current node the initial next node of current node, and previous node becomes current node.
//  Do this loop until the end of the list.
//*/

struct TrieNode {
    TrieNode* child[26];
    bool isWord;
    TrieNode() {
        isWord = false;
        for (auto& a : child)
        {
            a = nullptr;
        }
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* p = root;
        for (auto& ch : word)
        {
            int i = ch - 'a';
            if (!p->child[i])
            {
                p->child[i] = new TrieNode();
            }
            p = p->child[i];
        }
        p->isWord = true;
    }

    bool search(string word, bool prefix = false) {
        TrieNode* p = root;
        for (auto& a : word)
        {
            int i = a - 'a';
            if (!p->child[i])
            {
                return false;
            }
            p = p->child[i];
        }
        if (prefix == false)
        {
            return p->isWord;
        }
        return true;
    }

    bool startsWith(string prefix) {
        return search(prefix, true);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */