class Solution {
private:
    void backtrack(int n, int k, int idx, int lastDigit, string& curr, vector<int>& res){
        if(idx == n) {
            res.push_back(stoi(curr));
            return;
        }
        
        for(int d=0;d<=9;d++){
            if(abs(lastDigit - d) == k){
                string temp(1, d+'0');
                curr+=temp;
                backtrack(n, k, idx+1, d, curr, res);
                curr.pop_back();
            }
        }
        
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> res;
        for(int lastDigit=1;lastDigit<=9;lastDigit++){
            string curr = to_string(lastDigit);
            backtrack(n, k, 1, lastDigit, curr, res);
        }
        
        return res;
    }
};