class Solution {
private:
    bool isPossible(int len, vector<string>& strs){
        string prefix = strs[0].substr(0, len);
        for(auto s:strs){
            if(s.rfind(prefix, 0)!=0) return false;
        }
        return true;
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        // BS : if f(x) is true and if f(x+1) is also true => binary search to divide search space in half
        // if(isPrefix(of length x) == true) then isPrefix(of length x-1) is also true.
        
        int minlen=INT_MAX;
        for(auto s:strs) minlen = min(minlen, (int)s.length());
        
        int left=0, right=minlen;
        
        int ans=-1;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(isPossible(mid, strs)){
                ans=mid;
                left=mid+1;
            } else right=mid-1;
        }
        
        return ans==-1 ? "" : strs[0].substr(0, ans);
        
    }
};