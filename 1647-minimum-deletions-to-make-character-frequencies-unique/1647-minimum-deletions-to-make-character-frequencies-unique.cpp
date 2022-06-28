class Solution {
public:
    int minDeletions(string s) {
        sort(s.begin(), s.end());
        //cout<<s<<" ";
        vector<int> freq(100001, -1);
        int n = s.length();
        int i=0;
        int left=0, right=0;
        int count=0;
        
        while(right<n){
            
            while(right+1<n && s[right] == s[right+1]){
                right+=1;
            }
            
            int cur_freq = right-left+1;
            
            if(freq[cur_freq]==-1){
                freq[cur_freq] = 1;
            }
            
            else{
                
                while(cur_freq>0 && freq[cur_freq]!=-1){
                    count+=1;
                    cur_freq-=1;
                }
                
                if(cur_freq!=0) freq[cur_freq]=1;
            }
            
            right+=1;
            left=right;
            
        }
        
        return count;
        
    }
};