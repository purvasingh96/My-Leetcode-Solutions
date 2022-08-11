class Solution {
public:
    string getHint(string secret, string guess) {
        map<char, int> m;
        map<char, int> y;
        for(auto x:secret) m[x]+=1;
        int total = 0, count=0;
        
        for(int i=0;i<secret.length();i++){
            if(secret[i] == guess[i]) count+=1;
            y[guess[i]] +=1;
        }
        
        for(auto x:y){
            if(m.find(x.first)!=m.end()) {
                total += min(m[x.first], x.second);
            }
        }
        
        string hint = to_string(count) + "A" + to_string(total-count) + "B";
        return hint;
        
    }
};