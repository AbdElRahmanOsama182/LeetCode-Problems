class TrieNode {
public:
    bool isWord;
    vector<TrieNode*> children;
    TrieNode() {
        isWord = false;
        children = vector<TrieNode*>(26, nullptr);
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children[c - 'a'] == nullptr)
                node->children[c - 'a'] = new TrieNode();
            node = node->children[c - 'a'];
        }
        node->isWord = true;
    }

    bool search(string word, bool isPrefix = false) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children[c - 'a'] == nullptr)
                return false;
            node = node->children[c - 'a'];
        }
        return isPrefix || node->isWord;
    }

    bool startsWith(string prefix) {
        return search(prefix, true);
    }

    string shortestRoot(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (node->children[word[i] - 'a'] == nullptr)
                return word;
            node = node->children[word[i] - 'a'];
            if (node->isWord)
                return word.substr(0, i + 1);
        }
        return word;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie dict;
        for (string word : dictionary)
            dict.insert(word);
        string ans = "", word = "";
        for (char c : sentence) {
            if (c == ' ') {
                ans += dict.shortestRoot(word) + " ";
                word = "";
            }
            else 
                word += c;
        }
        ans += dict.shortestRoot(word);
        return ans;
    }
};