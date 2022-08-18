class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> m;
        int maxcount=0;
        
        for(auto x:arr){
            m[x]+=1;
            if(m[x] > maxcount) maxcount = m[x];
        }
        
        vector<int> buckets(maxcount+1, 0);
        
        for(auto x:m){
            buckets[x.second] += x.second;
        }
        
        int half = arr.size()/2;
        int bucket = maxcount;
        int ans=0;
        
        while(half>0){
            
            if(buckets[bucket] <= 0){
                bucket-=1;
            } else {
                
                ans+=1;
                buckets[bucket] -= bucket;
                half -= bucket;
                
            }
            
            
        }
        
        return ans;
        
    }
};