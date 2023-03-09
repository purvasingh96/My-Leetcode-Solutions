class Solution {
private:
    bool isPal(string& s){
        int l=0, r=s.length()-1;
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    void dfs(int idx, string s, vector<string>& temp, vector<vector<string>>& res){
        
        if(idx >= s.length()){
            res.push_back(temp);
            return;
        }
        
        for(int i=idx;i<s.length();i++){
            string left = s.substr(0, i+1);
            string right = s.substr(i+1);
            if(isPal(left)){
                temp.push_back(left);
                dfs(0, right, temp, res);
                temp.pop_back();
            }
        }
        
        
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        dfs(0, s, temp, res);
        return res;
    }
};