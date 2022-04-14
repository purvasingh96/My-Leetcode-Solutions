class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        map<string,vector<string>> mp;
        for(string &st: strings)
        {
            vector<int> temp;
            string t="";
            for(int i=1; i<st.size(); i++) {
                t += ((26 + st[i] - st[i-1])%26 + 'a') + ',';
            }
            mp[t].push_back(st);
        }
        vector<vector<string>> ans;
        cout<<('z' - 'a')<<"\n";
        cout<<(26 + 'z' - 'a')%26;
        
        
        for(auto &t:mp) ans.push_back(t.second);
        return ans;
    }
};