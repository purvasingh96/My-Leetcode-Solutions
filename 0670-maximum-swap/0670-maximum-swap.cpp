class Solution {
public:
    int maximumSwap(int num) {
        vector<int> lastPos(10);
        string s = to_string(num);
        for(int i=0;i<s.length();i++){
            lastPos[s[i]-'0']=i;
        }
        
        for(int i=0;i<s.length();i++){
            for(int j='9';j>s[i];j--){
                if(lastPos[j-'0']>i){
                    swap(s[i], s[lastPos[j-'0']]);
                    return stoi(s);
                }
            }
        }
        
        return num;
        
    }
};