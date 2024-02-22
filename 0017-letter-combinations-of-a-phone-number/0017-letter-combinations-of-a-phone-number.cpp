class Solution {
private:
    void backtrack(string digits, int i, unordered_map<int, vector<char>>& m, string& res, vector<string>& ans){
        if(i >= digits.length()){
            ans.push_back(res);
            return;
        }
        
        for(auto c:m[digits[i] -'0']){
            res += c;
            backtrack(digits, i+1, m, res, ans);
            res.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0){
            return {};
        }
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
        string res="";
        
        backtrack(digits, 0, m, res, ans);
        
        return ans;
        
    }
};