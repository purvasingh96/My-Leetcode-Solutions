class Solution {
private:
    void backtrack(int idx, string digits, string currWord, unordered_map<int, vector<char>> m, vector<string>& ans){
        
        if(idx >= digits.length()){
            if(currWord.length()!=0){
                ans.push_back(currWord);
            }
            return;
        }
        
        for(auto x:m[digits[idx] - '0']){
            currWord += x;
            backtrack(idx+1, digits, currWord, m, ans);
            currWord.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<int, vector<char>> m;
        m[2] = {'a', 'b', 'c'};
        m[3] = {'d', 'e', 'f'};
        m[4] = {'g', 'h', 'i'};
        m[5] = {'j', 'k', 'l'};
        m[6] = {'m', 'n', 'o'};
        m[7] = {'p', 'q', 'r', 's'};
        m[8] = {'t', 'u', 'v'};
        m[9] = {'w', 'x', 'y', 'z'};
        vector<string> ans;
        
        backtrack(0, digits, "", m, ans);
        return ans;
    }
};