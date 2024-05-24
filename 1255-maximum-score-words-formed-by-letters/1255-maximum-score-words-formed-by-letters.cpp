class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> freq(26, 0);
        for(auto c: letters) freq[c-'a']++;
        int maxScore = 0;
        backtrack(words, score, freq, words.size()-1, 0, maxScore);
        return maxScore;
    }

    void backtrack(vector<string>& words, vector<int>& score, vector<int>& freq, int idx, int currScore, int& maxScore){
        if (idx < 0){
            maxScore = max(maxScore, currScore);
            return;
        }
        backtrack(words, score, freq, idx-1, currScore, maxScore);
        int len = words[idx].size();   
        bool valid = true;
        for (int i = 0; i < len; i++){
            if (freq[words[idx][i]-'a'] == 0)
                valid = false;
            freq[words[idx][i]-'a']--;
            currScore += score[words[idx][i]-'a'];
        }
        if (valid)
            backtrack(words, score, freq, idx-1, currScore, maxScore);
        for (int i = 0; i < len; i++){
            freq[words[idx][i]-'a']++;
            currScore -= score[words[idx][i]-'a'];
        }
    }
};