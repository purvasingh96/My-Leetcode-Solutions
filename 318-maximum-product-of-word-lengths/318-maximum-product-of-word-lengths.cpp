class Solution {
public:
    int maxProduct(vector<string>& words) {
        map<int, int> m;
        for(auto word:words){
            int mask=0;
            for(auto c:word){
                mask |= (1<<(c-'a'));
            }
            
            m[mask] = max(m[mask], (int)word.length());
        }
        int ans=INT_MIN;
        for(auto a:m){
            for(auto b:m){
                
                if(!(a.first & b.first)) {
                    ans = max(ans, (a.second*b.second));
                }
                
            }
        }
        
        return ans==INT_MIN?0:ans;
    }
};