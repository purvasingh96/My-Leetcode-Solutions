class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int m = potions.size();
        int n = spells.size();
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            
            int left=0, right=m-1;
            
            
            while(left<right){
                
                int mid = left + (right-left)/2;
                
                auto prod = (long)spells[i]* (long)potions[mid];
                
                if( prod >= success){
                    right=mid;
                }
                
                else if(prod < success){
                    
                    left = mid+1;
                    
                }
                
            }
            
            auto prod = (long)spells[i]* (long)potions[left];
            if(prod < success) {
                ans.push_back(0);
            } else{
                int len = (m-left);
                ans.push_back(len);
            }
            
        }
        
        return ans;
        
    }
};