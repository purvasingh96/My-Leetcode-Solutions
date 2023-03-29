class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        vector<int> q;
        bool c=false;
        int v1, v2, index;
        
        for(int i=0;i<nums.size();i++){
            int x = nums[i];
            if(q.empty() || q.back()<x){
                q.push_back(x);
            } else {
                if(c) return false;
                v1=q.back();
                q.pop_back();
                v2 = x;
                index=i;
                c=true;
                
            }
        }
        
        if(!c) return true;
        
        int idx1 = upper_bound(q.begin(), q.end(), v1) - q.begin();
        
        int idx2 = upper_bound(q.begin(), q.end(), v2) - q.begin();
        
        if(idx1==index-1){
            if(idx1>=1) {
                if( q[idx1-1]!=v1) return true;
                else return false;
            }
            return true;
            
        }
        
        if(idx2==index-1){
            if(idx2>=1) {
                if(q[idx2-1]!=v2) return true;
                else return false;
            }
            return true;
            
        }
        
        return false;
    }
};