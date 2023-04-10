class Solution {
private:
    int dfs(int& i, string s, vector<int> res, char op, int temp){
        
        while(i<s.length() && s[i]!=')'){
            if(s[i]==' '){
                i+=1;
                continue;
            }
            else if(isdigit(s[i])){
                temp = temp*10 + (s[i]-'0');
                i+=1;
            } else if(s[i] == '+' || s[i] == '-'){
                // original operator
                if(temp!=0){
                    if(op=='+'){
                        res.push_back(temp);
                    } else {
                        res.push_back(-temp);
                    }
                }
                
                op = s[i];
                temp=0;
                i+=1;
            } else if(s[i] == '('){
                vector<int> t;
                i+=1;
                temp=0;
                int val = dfs(i, s, t, '+', temp);
                
                if(op == '+') res.push_back(val);
                else res.push_back(-val);
                
                i+=1;
            }
        }
        
        if(temp){
            if(op=='+'){
                res.push_back(temp);
            } else res.push_back(-temp);
        }
        
        return accumulate(res.begin(), res.end(), 0);
    }
public:
    int calculate(string s) {
        s = "("+s+")";
        int i=0;
        vector<int> res;
        int temp=0;
        char op='+';
        return dfs(i, s, res, op, temp);
    }
};