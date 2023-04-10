class Solution {
private:
    void backtrack(int l, int r, unordered_map<char, int>& m, string& s, string& temp, vector<string>& res){
        if(l>=r){
            if(l==r){
                for(auto x:m){
                    if(x.second==1){
                        temp[l]=x.first;
                    }
                }
            }
            res.push_back(temp);
            return;
        }
        
        for(auto it:m){
            if(it.second >= 2){
                temp[l]=it.first;
                temp[r] = it.first;
                m[it.first]-=2;
                backtrack(l+1, r-1, m, s, temp, res);
                m[it.first]+=2;
                temp[r]='#';
                temp[l]='#';
            }
        }
    }
        
public:
    vector<string> generatePalindromes(string s) {
        unordered_map<char, int> m;
        for(auto c:s) m[c]+=1;
        int count=0;
        for(auto x:m) {
            if(x.second==1){
                count+=1;
                if(count>1) return {};
            }
        }
        vector<string> res;
        int n = s.length();
        string temp(n, '#');
        backtrack(0, n-1, m, s, temp, res);
        return res;
    }
};