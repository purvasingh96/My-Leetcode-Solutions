class Solution {
private:
    void backtrack(int pos, string digits, string& temp, unordered_map<int, string>& m, vector<string>& res){
        if(temp.length() == digits.length()){
            res.push_back(temp);
            return;
        }
        
        int digit = digits[pos] - '0';
        for(int i=0;i<m[digit].length();i++){
            temp.push_back(m[digit][i]);
            backtrack(pos+1, digits, temp, m, res);
            temp.pop_back();
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return {};
        unordered_map<int, string> m;
        m[2] = "abc";
        m[3] = "def";
        m[4] = "ghi";
        m[5] = "jkl";
        m[6] = "mno";
        m[7] = "pqrs";
        m[8] = "tuv";
        m[9] = "wxyz";
        
        string temp="";
        vector<string> res;
        
        backtrack(0, digits, temp, m, res);
        return res;
    }
};