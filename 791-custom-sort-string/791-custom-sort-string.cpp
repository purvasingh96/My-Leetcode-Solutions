class Solution {
public:
    string customSortString(string order, string s) {
        
        vector<int> freq(26, 0);
        string res="";
        //for(auto x:order) m[x] +=1;
        
        for(auto x:s) freq[x - 'a'] +=1;
        
        for(auto x:order) {
            if(freq[x-'a']!=0) {
                while(freq[x - 'a']) {
                    res += x;
                    freq[x-'a'] -=1;
                }
            }
            
        }
        
       for(int i=0;i<freq.size();i++) {
           if(freq[i]!=0) {
               
               while(freq[i]!=0) {
                   res += (i+'a');
                   freq[i]-=1;
               }
               
           }
       }
        
        return res;
        
    }
};