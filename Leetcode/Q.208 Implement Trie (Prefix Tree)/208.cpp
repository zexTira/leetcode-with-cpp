/*//
//  In trie data structure, we define a child node array representing next character and a bool vaule isWord representing if it is a word.
//  For each input word, we push it in the each level of the trie in char sequence and when it comes to the last character, set the bool isWord of the node true.
//  When we need to search, if we search for a whole word, we just need to check if the bool value of the node for last letter in the trie is true, and return the result.
//  If we search for prefix, we should search for each letter in trie in sequence and check if there's corresponding child node for each letter.
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