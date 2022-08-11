class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> m(10, 0);
        vector<int> y(10, 0);
        
        for(auto x:secret) m[x-'0']+=1;
        int total = 0, count=0;
        
        for(int i=0;i<secret.length();i++){
            if(secret[i] == guess[i]) count+=1;
            y[guess[i]-'0'] +=1;
        }
        
        for(int i=0;i<10;i++){
            if(m[i] != 0 && y[i]!=0) {
                total += min(m[i], y[i]);
            }
        }
        
        string hint = to_string(count) + "A" + to_string(total-count) + "B";
        return hint;
        
    }
};