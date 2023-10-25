/*//
//  In trie data structure question the idea is similar as that in Q.208, the only difference is on searching, as we need to search words with '.'.
//  When it comes to '.' we need to recursively search the child node for the word with letters only after this '.', and check if there are child nodes are not empty.
//*/

struct TrieNode {
    char c;
    int count;
    int endshere;
    TrieNode* child[26];
    TrieNode(int cf) {
        c = 'a' + cf;
        count = endshere = 0;
        for (int i = 0; i < 26; i++)
        {
            child[i] = NULL;
        }
    }
};

class WordDictionary {
public:
    TrieNode* root;
    map<string, int>mp;

    WordDictionary() {
        root = new TrieNode('/');
    }
    void addWord(string word) {
        TrieNode* curr = root;
        int c = 0;
        for (int i = 0; i < word.size(); i++)
        {
            if (curr->child[word[i] - 'a'] == NULL)
            {
                curr->child[word[i] - 'a'] = new TrieNode(word[i] - 'a');
            }
            curr = curr->child[word[i] - 'a'];
        }
        curr->endshere = 1;
    }
    void searcht(string& word, int idx, TrieNode* t, bool& ans) {
        if (idx == word.size())
        {
            if (t->endshere)
            {
                ans = true;
            }
            return;
        }
        if (word[idx] != '.')
        {
            if (t->child[word[idx] - 'a'] != NULL)
            {
                searcht(word, idx + 1, t->child[word[idx] - 'a'], ans);
            }
            else
            {
                return;
            }
        }
        else
        {
            for (int i = 0; i < 26; i++)
            {
                if (t->child[i] != NULL)
                {
                    searcht(word, idx + 1, t->child[i], ans);
                }
            }
        }
    }
    bool search(string word) {
        bool ans = false;
        TrieNode* r = root;
        searcht(word, 0, r, ans);
        return ans;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */