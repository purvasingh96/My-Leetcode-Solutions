class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        map<vector<int>,vector<string>> mp;
        for(string &st: strings)
        {
            vector<int> temp;
            for(int i=1; i<st.size(); i++) temp.push_back((26+st[i]-st[i-1])%26);
            mp[temp].push_back(st);
        }
        vector<vector<string>> ans;
        cout<<('z' - 'a')<<"\n";
        cout<<(26 + 'z' - 'a')%26;
        
        
        for(auto &t:mp) ans.push_back(t.second);
        return ans;
    }
};