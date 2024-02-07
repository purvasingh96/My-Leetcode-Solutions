class Solution {
public:
    int maximumSwap(int num) {
        string og = to_string(num);
        unordered_map<int, int> m;
        string s = to_string(num);
        
        sort(s.begin(), s.end(), [](const char& a, const char& b){
            return a-'a'>b - 'a';
        });
        
        
       
        for(int i=0;i<og.length();i++){
            m[og[i]] = i;
        }
        
        for(int i=0;i<s.length();i++){
            if(og[i]!=s[i]){
                int j = m[s[i]];
                swap(og[i], og[j]);
                return stoi(og);
            }
        }
        
        return num;
    }
};