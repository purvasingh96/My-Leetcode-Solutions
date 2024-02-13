class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        string og = s;
        vector<int> pos(10, -1);
        for(int i=0;i<s.length();i++){
           pos[s[i]-'0']=i;
            
        }
        for(int i=0;i<og.length();i++){
            for(int d=9;d>og[i]-'0';d--){
                if(pos[d] > i){
                    swap(og[i], og[pos[d]]);
                    return stoi(og);
                }
            }
        }
        
        return stoi(og);
    }
};