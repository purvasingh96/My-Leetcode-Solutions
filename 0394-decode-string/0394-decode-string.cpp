class Solution {
private:
    string dfs(int& i, string& s){
        string res="";
        while(i<s.length() && s[i]!=']'){
            if(!isdigit(s[i])){
                res.push_back(s[i++]);
            } else {
                int k=0;
                while(isdigit(s[i])){
                    k = k*10 + s[i]-'0';
                    i+=1;
                }
                
                i+=1;
                string decodedString = dfs(i, s);
                i+=1;
                while(k--){
                    res += decodedString;
                }
            }
        }
        
        return res;
    }
public:
    string decodeString(string s) {
        int i=0;
        return dfs(i, s);
    }
};