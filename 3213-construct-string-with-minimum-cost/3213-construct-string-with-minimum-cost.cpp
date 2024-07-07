class TrieNode {
public:
    unordered_map<char, TrieNode*> childs;
    vector<pair<int, int>> words;
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    void insert(const string& word, int cost) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->childs.find(c) == node->childs.end()) 
                node->childs[c] = new TrieNode();
            node = node->childs[c];
        }
        node->words.push_back({word.size(), cost});
    }
};

class Solution {
public:
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        int n = target.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        Trie trie;
        for (int i = 0; i < words.size(); ++i)
            trie.insert(words[i], costs[i]);
        for (int i = 0; i < n; ++i) {
            if (dp[i] == INT_MAX) continue;
            TrieNode* node = trie.root;
            for (int j = i; j < n; ++j) {
                if (node->childs.find(target[j]) == node->childs.end()) break;
                node = node->childs[target[j]];
                for (const auto& [len, cost] : node->words)
                    if (i + len <= n)
                        dp[i + len] = min(dp[i + len], dp[i] + cost);
            }
        }
        return dp[n] == INT_MAX ? -1 : dp[n];
    }
};