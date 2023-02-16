class Solution {
private:
    string dfs(int& idx, string s){
        int num=0;
        string res="";
        for(;idx<s.length();idx++){
            if(s[idx] == '['){
                string repeat = dfs(++idx, s);
                while(num>0){
                  res += repeat;
                    num-=1;
                } 
            } else if(s[idx] >= '0' && s[idx] <='9'){
                num = num*10 + (s[idx]-'0');
            } else if(s[idx]==']'){
                return res;
            } else{
                res += s[idx];
            }
        }
        
        return res;
    }
public:
    string decodeString(string s) {
        int idx=0;
        return dfs(idx, s);
    }
};