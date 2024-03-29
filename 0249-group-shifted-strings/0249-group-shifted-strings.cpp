class Solution {
private:
    string hash(string s){
        cout<<s<<" ";
        string res="";
        for(int i=0;i<s.length()-1;i++){
            
            int diff = (abs(s[i]-'a' - s[i+1]-'a') + 26)%26;
            res += to_string(diff);
            res+="#";
        }
        cout<<"res:: "<<res<<"\n";
        return res;
    }
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> m;
        for(auto s:strings){
            m[hash(s)].push_back(s);
        }
        
        vector<vector<string>> res;
        for(auto x:m){
            res.push_back(x.second);
        }
        
        return res;
    }
};