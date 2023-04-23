class Solution {
private:
    string dfs(int& idx, string s, int t){
        string temp = "";
        while(idx<s.length() && s[idx]!=']'){
            if(isdigit(s[idx])){
                t = t*10+(s[idx]-'0');
                idx+=1;
            } else if(isalpha(s[idx])){
                temp.push_back(s[idx]);
                idx+=1;
            } else if(s[idx] == '['){
                idx+=1;
                int f = t;
                string res = dfs(idx, s, 0);
                
                while(f--){
                    temp+=res;
                }
                idx+=1;
                t=0;
            }
        }
        
        return temp;
    }
public:
    string decodeString(string s) {
        string answer="";
        int idx=0;
        return dfs(idx, s, 0);
        
    }
};