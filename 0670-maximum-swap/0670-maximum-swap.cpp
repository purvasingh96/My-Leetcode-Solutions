class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        string og = s;
        vector<int> pos(10, -1);
        for(int i=0;i<s.length();i++){
           pos[s[i]-'0']=i;
            
        }
        
        sort(s.begin(), s.end(), [](const char& a, const char& b){
            return a-'0' > b-'0';
        });
        
        
        
        for(int i=0;i<og.length();i++){
            if(og[i]!=s[i]){
                swap(og[i], og[pos[s[i]-'0']]);
                return stoi(og);
            }
        }
        
        return stoi(og);
    }
};