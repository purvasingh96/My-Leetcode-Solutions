class Solution {
public:
    int maximumRobots(vector<int>& ct, vector<int>& rc, long long b) {
        int left=0, right=0;
        long long tc=0, sum_rc=0;
        int maxK = 0, n = ct.size();
        
        // back of multiset will be our answer
        multiset<int> max_ct;
        
        while(right<n){
            
            max_ct.insert(ct[right]);
            sum_rc += rc[right];
            int k = max_ct.size();
            
            if(max_ct.size()!=0) tc = *prev(max_ct.end()) + k*sum_rc;
            
            if(tc > b){
                
                while(left<=right && tc > b && max_ct.size()!=0){
                    max_ct.erase(max_ct.find(ct[left]));
                    sum_rc-=rc[left];
                    k=max_ct.size();
                    if(max_ct.size()!=0) tc = *prev(max_ct.end()) + k*sum_rc;
                    left+=1;
                }
                
            }
            
            maxK = max(maxK, k);
            right+=1;
            
        }
        
        return maxK;
    }
};