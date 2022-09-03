class Solution {
private:
    void backtrack(string& s, int n, int k, vector<int>& res){
        if(s.length() == n) {
            res.push_back(stoi(s));
            return;
        }
        
        int start = s.length()==0?1:0;
        
        for(int i=start;i<10;i++){
            if(s.length() == 0 || abs((s.back()-'0') - i)==k){
                s+=(i+'0');
                backtrack(s, n, k, res);
                s.pop_back();
            }
        }
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> res;
        string s = "";
        backtrack(s, n, k, res);
        return res;
    }
};