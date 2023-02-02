class Solution {
private:
    string convert(string& s, vector<int>& res){
        string ans="";
        for(auto c:s){
            string temp(1, (res[c-'a']+'a'));
            ans+=temp;
        }
         return ans;   
    }
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> res(26, 0);
        vector<string> ans;
        for(int i=0;i<26;i++){
            res[order[i] - 'a'] = i;
        }
        
        for(auto x:words){
            string t = convert(x, res);
            ans.push_back(t);
            //cout<<t<<"\n";
        }
        
        vector<string> og = ans;
        sort(ans.begin(), ans.end());
        return og == ans;
    }
};