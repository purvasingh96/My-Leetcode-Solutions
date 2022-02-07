class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> bucket1(26, -1);
        vector<int> bucket2(26, -1);
        
        for(auto c:s) {
            bucket1[(c - 'a')] +=1;
        }
        
        for(auto c:t) {
            bucket2[(c - 'a')] +=1;
        }
        
        for(int i=0;i<26;i++) {
            
            if(bucket1[i]!=bucket2[i]) {
                char k = (i+'a');
                return k;
            }
            
        }
        
        
        
        return t[t.length()-1];
        
        
    }
};