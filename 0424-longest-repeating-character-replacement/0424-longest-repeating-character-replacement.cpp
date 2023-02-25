class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxFreq=0;
        vector<int> count(26,0);
        int left=0, ans=0, right=0;
        
        for(;right<s.length();right++){
            count[s[right]-'A']+=1;
            maxFreq = max(maxFreq, count[s[right]-'A']);
            //cout<<"maxFDreq: "<<maxFreq<<" "; 
            int n = right-left+1;
            //cout<<"n: "<<n<<"\n";
            if(n-maxFreq > k){
                //cout<<right<<"\n";
                ans =max(ans, right-left);
                count[s[left]-'A']-=1;
                left+=1;
            } 
        }
        
        return max(ans, right-left);
    }
};