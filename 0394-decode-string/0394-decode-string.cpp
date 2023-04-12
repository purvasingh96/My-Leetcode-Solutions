class Solution {
private:
    string dfs(int& idx, int t, int prev, string& temp, string soFar, string s){
        //cout<<"idx: "<<idx<<" t: "<<t<<" prev: "<<prev<<" ";
        while(idx<s.length() && s[idx]!=']'){
            if(isdigit(s[idx])){
                //temp="";
                t = t*10 + s[idx]-'0';
                idx+=1;
            } else if(isalpha(s[idx])){
                t=0;
                temp.push_back(s[idx]);
                idx+=1;
            } else if(s[idx] == '['){
                idx+=1;
                soFar = temp;
                temp = "";
                string val = dfs(idx, 0, t, temp, soFar, s);
                t=0;
                temp = soFar + val;
                //cout<<"idx: "<<idx<<" sofar: "<<soFar<<" val: "<<val<<"\n";
                idx+=1;
            }
            //cout<<"idx: "<<idx<<" temp: "<<temp<<"\n";
        }
        
        int tt = t==0?1:t;
        int tp = prev==0?1:prev;
        int freq = tt*tp;
        
        string ans="";
        while(freq--){
            ans += temp;
        }
        
        return ans;
    }
public:
    string decodeString(string s) {
        s = "["+s+"]";
        int idx=0;
        string temp="";
        string sofar="";
        return dfs(idx, 0, 0, temp, sofar, s);
    }
};