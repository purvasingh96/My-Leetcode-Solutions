class Solution {
public:
    string largestPalindromic(string num) {
        vector<int> m(10, 0);
        
        for(int i=0;i<num.length();i++){
            m[num[i]-'0'] += 1;
        }
        
        string left="", right="";
        int maxIndex =-1;
        for(int i=9;i>=0;i--){
            if(m[i]!=0){
                string c(m[i]/2, (i+'0'));
                left += c;
                right+=c;
                
                m[i]= m[i]%2;
                
                if(m[i] == 1) {
                    if(maxIndex==-1) maxIndex=i;
                }
            }
        }
     
        reverse(right.begin(), right.end());
        string mid="";
        
        if(maxIndex!=-1) {
            string c(1, maxIndex+'0');
            mid = c;
        }
        
        string ans = left + mid + right;
        
        int i=0, j=ans.length()-1;
        
        while(i<j && ans[i]=='0' && ans[j]=='0'){
            i+=1;
            j-=1;
            
        }
//         cout<<num.length()<<" "<<ans.length()<<"\n";
//         cout<<i<<" "<<j;
        
        
        return j<i ? ans.substr(j, 1) : ans.substr(i, j-i+1);        
    }
};