class Solution {
private:
    void matchingIndices(string s, string word, vector<vector<int>>& intervals){
        int k=word.length(), n = s.length();
        long long sHash=0, pHash=0, h=1;
        int base=31, mod=1e9+7;
        
        for(int i=0;i<k-1;i++){
            h = h*base;
            h=h%mod;
        }
        
        for(int i=0;i<k && i<s.length();i++){
            sHash = (sHash*base + s[i])%mod;
            pHash = (pHash*base + word[i])%mod;
        }
        
        for(int i=0;i<=(n-k);i++){
            if(sHash == pHash) {
                intervals.push_back({i, i+k-1});
            }
            
            if(i<(n-k)){
                sHash = ((sHash - h*s[i])*base)%mod + s[i+k];
                if(sHash < 0) sHash += mod;
            }
        }
        
    }
public:
    string addBoldTag(string s, vector<string>& words) {
        vector<vector<int>> intervals;
        
        
        for(auto word:words){
            matchingIndices(s, word, intervals);
        }
        
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> res;
        
        for(auto idx:intervals){
            if(res.size()==0 || res.back()[1] < idx[0]-1){
                res.push_back(idx);
            } else{
                auto back = res.back();
                res.pop_back();
                res.push_back({back[0], max(back[1], idx[1])});
            }
        }
        
        
        
        string ans="";
        int k=0, i=0;
        
        while(i<s.length() && k<res.size()){
            if(i!=res[k][0]) ans+= s[i++];
            else {
                int start=res[k][0], end=res[k][1];
                int len = end-start+1;
                
                ans+="<b>";
                
                ans+=s.substr(start, len);
                ans+="</b>";
                k+=1;
                i+=len;
            }
        }
        
        if(i<s.length()) ans+=s.substr(i);
        
        return ans;
    }
};