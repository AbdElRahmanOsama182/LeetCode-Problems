class TrieNode {
public:
    TrieNode* children[26];
    bool isWord;
    string word;
    TrieNode() {
        word = "";
        isWord = false;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
    void addWord(string word) {
        TrieNode* node = this;
        for (char c: word) {
            if (node->children[c-'a'] == nullptr) {
                node->children[c-'a'] = new TrieNode();
            }
            node = node->children[c-'a'];
        }
        node->isWord = true;
        node->word = word;
    }
};

class Solution {
public:
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* dict = new TrieNode();
        for (string word:words)
            dict->addWord(word);
        vector<string> ans;
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                dfs(i,j,n,m,dict,board, ans);            
        return ans;
    }
    void dfs(int i, int j, int n, int m, TrieNode *dict, vector<vector<char>>& board,vector<string>& ans) {
        if (i < 0 || i == n || j < 0 || j == m) return;
        char c = board[i][j];
        if (c == '*' || dict->children[c-'a'] == nullptr) return;
        dict = dict->children[c-'a'];
        if (dict->isWord) {
            ans.push_back(dict->word);
            dict->isWord = false;
        }
        board[i][j] = '*';
        for (int k = 0; k < 4; k++)
        {
            dfs(i+dx[k],j+dy[k],n,m,dict,board,ans);
        }
        board[i][j] = c;
    }
};