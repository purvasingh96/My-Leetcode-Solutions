class Solution {
private:
    string dfs(int& i, string& s, int freq){
        
        string d="";
        string ans="";
        
        for(;i<s.length() && s[i]!=']';i++){
            if(isdigit(s[i])){
                d.push_back(s[i]);
            } else{
                if(s[i] == '['){
                    int count = stoi(d);
                    d="";
                    i+=1;
                    ans += dfs(i, s, count);
                } else{
                    ans.push_back(s[i]);
                }
            }
        }
        
        string res="";
        while(freq--){
            res+=ans;
        }
        return res;
    }
public:
    string decodeString(string s) {
        int i=0;
        return dfs(i, s, 1);
    }
};