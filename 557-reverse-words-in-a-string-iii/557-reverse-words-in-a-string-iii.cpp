class Solution {
public:
    string reverseWords(string s) {
        vector<string> res;
        size_t pos = 0;
        string token;
        string delimiter = " ";
        s+= " ";
        
        while ((pos = s.find(delimiter)) != string::npos) {
            token = s.substr(0, pos);
            reverse(token.begin(), token.end());
            
            res.push_back(token);
            s.erase(0, pos + delimiter.length());
            //cout<<s<<"\n";
        }
        
        string ans="";
        for(auto x:res){
            ans+=x;
            ans+=" ";
        }
        ans.pop_back();
        
        return ans;
        
    }
};