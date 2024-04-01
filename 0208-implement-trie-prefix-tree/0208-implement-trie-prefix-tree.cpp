class TrieNode {
    public:
    TrieNode* children[26];
    bool isEnd;
    TrieNode(){
        isEnd = false;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* current = root;
        for (char c : word){
            if (current->children[c - 'a'] == nullptr)
                current->children[c - 'a'] = new TrieNode();
            current = current->children[c - 'a'];
        }
        current->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* current = root;
        for (char c : word){
            if (current->children[c - 'a'] == nullptr)
                return false;
            current = current->children[c - 'a'];
        }
        return current->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* current = root;
        for (char c : prefix){
            if (current->children[c - 'a'] == nullptr)
                return false;
            current = current->children[c - 'a'];
        }
        return true;
    }
};