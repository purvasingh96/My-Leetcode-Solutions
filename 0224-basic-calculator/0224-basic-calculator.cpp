class Solution {
private:
    int dfs(int& i, string s, vector<int> res, int t, char op){
        while(i<s.length() && s[i]!=')'){
            if(s[i]==' ') {
                i+=1;
                continue;
            } else if(isdigit(s[i])){
                t = t*10 + (s[i]-'0');
                i+=1;
            } else if(s[i] == '+' || s[i]=='-'){
                if(t!=0){
                    if(op == '+'){
                        res.push_back(t);
                    } else res.push_back(-t);
                }
                op=s[i];
                t=0;
                i+=1;
            } else if(s[i] == '('){
                t=0;
                vector<int> temp;
                i+=1;
                int val = dfs(i, s, temp, t, '+');
                if(op == '+') res.push_back(val);
                else res.push_back(-val);
                i+=1;
            }
        }
        
        if(t){
            if(op == '+') res.push_back(t);
            else res.push_back(-t);
        }
        
        return accumulate(res.begin(), res.end(), 0);
    }
public:
    int calculate(string s) {
        s = "(" + s +")";
        int i=0;
        vector<int> res;
        int t=0;
        char op='+';
        return dfs(i, s, res, t, op);
    }
};