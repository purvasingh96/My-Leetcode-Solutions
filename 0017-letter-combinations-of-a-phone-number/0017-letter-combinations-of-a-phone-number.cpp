class Solution {
private:
    void backtrack(string digits, int i, string temp, vector<string>& ans, unordered_map<int, vector<char>>& m){
        if(i >= digits.length()){
            if(temp!=""){
                ans.push_back(temp);    
            }
            return;
        }
        
        for(auto c:m[digits[i]-'0']){
            temp += c;
            backtrack(digits, i+1, temp, ans, m);
            temp.pop_back();
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
        
        backtrack(digits, 0, "", ans, m);
        return ans;
    }
};