class TrieNode {
public:
    bool isWord;
    TrieNode* children[26];
    TrieNode () {
        isWord = false;
        for (int i = 0; i < 26; i++) children[i] = nullptr;
    }
};


class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for (auto& c : word) {
            if (!curr->children[c-'a']) curr->children[c-'a'] = new TrieNode();
            curr = curr->children[c-'a'];
        }
        curr->isWord = true;
    }
    
    bool search(string word, bool prefix = false) {
        TrieNode* curr = root;
        for (auto& c : word) {
            if (!curr->children[c-'a']) return false;
            curr = curr->children[c-'a'];
        }
        if (!prefix) return curr->isWord;
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