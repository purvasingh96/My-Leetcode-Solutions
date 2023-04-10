class Solution {
private:
    void dfs(int l, int r, unordered_map<char, int>& m, string& temp, unordered_set<string>& res, char mid){
        if(l>=r){
            if(l==r) {
                for(auto x:m){
                    if(x.second==1){
                        temp[l] = x.first;
                    }
                }
            }
            res.insert(temp);
            return;
        }
        
        for(auto it:m){
            if(it.second!=0 && it.second>=2){
                char c = it.first;
                temp[l] =c;
                temp[r]=c;
                m[it.first]-=2;
                dfs(l+1, r-1, m, temp, res, mid);
                m[it.first]+=2;
                temp[r] = ' ';
                temp[l] = ' ';
            }
        }
    }
public:
    vector<string> generatePalindromes(string s) {
        unordered_set<string> res;
        int n = s.length();
        unordered_map<char, int> m;
        string temp(n, '#');
        for(auto c:s) m[c]+=1;
        int ones=0;
        char mid;
        for(auto x:m){
            if(x.second==1){
                ones+=1;
                if(ones > 1) return {};
            }
        }
        
        dfs(0, n-1, m, temp, res, mid);
        vector<string> ans(res.begin(), res.end());
        return ans;
    }
};