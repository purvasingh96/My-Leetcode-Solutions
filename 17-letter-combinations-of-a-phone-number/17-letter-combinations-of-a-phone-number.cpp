class Solution {

private:
    void back_track(string digits, unordered_map<char, vector<char>>& m, vector<string>& res, string& temp, int idx) {
        
        if(temp.length() == digits.length()) {
            res.push_back(temp);
            return;
        }
        
        if(idx >= digits.length()) return;
        
        for(auto c:m[digits[idx]]) {
            temp += c;
            back_track(digits, m, res, temp, idx+1);
            temp.pop_back();
            
        }
        
    }


public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.length() == 0) return res;
        string temp = "";
        unordered_map<char, vector<char>> m;
        
        m['2'] = {'a', 'b', 'c'};
        m['3'] = {'d', 'e', 'f'};
        m['4'] = {'g', 'h', 'i'};
        m['5'] = {'j', 'k', 'l'};
        m['6'] = {'m', 'n', 'o'};
        m['7'] = {'p', 'q', 'r', 's'};
        m['8'] = {'t', 'u', 'v'};
        m['9'] = {'w', 'x', 'y', 'z'};
        
        cout<<m.size();
        
        back_track(digits, m, res, temp, 0);
        
        return res;
        
    }
};