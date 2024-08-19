struct Node {
    Node* child[26];
    bool isEnd;
    int count;
    Node() {
        isEnd = false;
        count = 0;
        for (int i = 0; i < 26; i++)
            child[i] = nullptr;
    }
};

class WordDictionary {
public:
    Node* root;

    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* cur = root;
        for (char &c : word) {
            if (!cur->child[c - 'a'])
                cur->child[c - 'a'] = new Node();
            cur = cur->child[c - 'a'];
            cur->count++;
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);        
    }

    bool dfs(string &word, int idx, Node* cur) {
        if (idx == word.size()) return cur->isEnd;
        if (word[idx] == '.') {
            for (int i = 0; i < 26; i++) 
                if (cur->child[i] && dfs(word, idx + 1, cur->child[i]))
                    return true;
            return false;
        }
        return cur->child[word[idx] - 'a'] && dfs(word, idx + 1, cur->child[word[idx] - 'a']);
    }   
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */