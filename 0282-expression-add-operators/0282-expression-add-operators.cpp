class Solution {
private:
    void dfs(int i, long long sum, long long prev, string ans, string num, int target, vector<string>& res){
        if(i == num.length()){
            if(sum == target){
                res.push_back(ans);
            }
            return;
        }
        
        for(int j=i;j<num.length();j++){
            if(num[i] == '0' && j>i){
                return;
            }
            
            string sub = num.substr(i, j-i+1);
            long long digit = stoll(sub);
            
            if(i==0){
                dfs(j+1, digit, digit, ans+sub, num, target, res);
                continue;
            } else {
                dfs(j+1, sum+digit, digit, ans+"+"+sub, num, target, res);
                dfs(j+1, sum-digit, -digit, ans+"-"+sub, num, target, res);
                dfs(j+1, sum-prev+(prev*digit), prev*digit, ans+"*"+sub, num, target, res);
            }
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        long long sum=0, prev=0;
        string ans="";
        
        dfs(0, sum, prev, ans,num, target, res);
        return res;
    }
};