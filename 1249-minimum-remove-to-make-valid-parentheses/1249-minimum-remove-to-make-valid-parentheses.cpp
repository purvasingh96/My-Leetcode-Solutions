class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int balance =0;
        vector<char> t;
        
        for(auto c:s){
            if(c == ')'){
                balance -=1;
                if(balance <0){
                    balance+=1;
                    continue;
                }
            } else if(c == '('){
                balance +=1;
            }
            t.push_back(c);
        }
        
        if(balance <= 0){
            // all invalid ) have been removed
            string temp ="";
            for(auto c:t) temp += c;
            return temp;
        }
        
        string res="";
        for(int i=t.size()-1;i>=0;i--){
            if(t[i] == '('){
                balance -=1;
                if(balance >= 0){
                    continue;
                } else {
                    res += t[i];
                }
            } else {
                res += t[i];
            }
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};