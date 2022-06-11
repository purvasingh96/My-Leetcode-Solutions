class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.length();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        int ans=0;
        
        for(int i=0;i<n;i++){
            int j=i-1;
            while(j>=0){
                if(s[j]==s[i]){
                    break;
                }
                j-=1;
            }
            
            left[i] = i-j;
            
            j=i+1;
            
            while(j<n){
                if(s[j]==s[i]) break;
                j+=1;
            }
            
            right[i] = j-i;
        }
        
        for(int i=0;i<n;i++){
            ans += (left[i]*right[i]);
        }
        
        return ans;
    }
};