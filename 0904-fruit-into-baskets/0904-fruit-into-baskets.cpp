class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0, r=0;
        int ans=0;
        unordered_map<int, int> m;
        
        for(;r<fruits.size();r++){
            m[fruits[r]]+=1;
            
            if(m.size() > 2){
                
                while(m.size()>2 && l<r){
                    m[fruits[l]]-=1;
                    if(m[fruits[l]] == 0){
                        m.erase(fruits[l]);
                    }
                    l+=1;
                }
                
            }
            ans = max(ans, r-l+1);
        }
        
        
        return ans;
        
    }
};