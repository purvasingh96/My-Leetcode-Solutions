class Solution {

public:
    int longestSemiRepetitiveSubstring(string s) {
        unordered_map<int, vector<int>> m;
 
//         }
        
        int ans=0;
        
        for(int len=1;len<=s.length();len++){
            for(int i=0;i<s.length();i++){
                string sub = s.substr(i, len);
                //cout<<"sub: "<<sub<<" "<<check(sub)<<"\n";
                int c=0;
                for(int k=0;k<sub.length()-1;k++){
                    if(sub[k] == sub[k+1]) {
                        c+=1;
                    }
                }
                
                if(c <= 1) {
                    ans = max(ans, (int)sub.length());
                }
            }
        }
        
        
        
       
        
        return ans;
        
        
    }
};