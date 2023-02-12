class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        map<pair<int, int>, int> m;
        long long ans=0;
       sort(nums.begin(), nums.end());
           
          
        for(int i=0;i<nums.size();i++){
            
            int key = nums[i];
            int l1 = lower-key;
            int l2 = upper-key;
            
            
            //cout<<"l1: "<<l1<<" l2: "<<l2<<"\n";
            auto start = lower_bound(nums.begin()+i+1, nums.end(), l1)-nums.begin();
            auto end = upper_bound(nums.begin()+i+1, nums.end(), l2)-nums.begin();
            
            // int start = min(s, e);
            // int end = max(s, e);
            
            if(start == nums.size()) continue;
            
            if(end!=nums.size() && nums[end]>l2) {
                while(end>start && nums[end]>l2) end--;
            }
            
            while(start<end && key > nums[start]){
                start+=1;
            }
            
            //cout<<"i: "<<i<<" start: "<<start<<" end: "<<end<<" ";
            if(start == end){
                int val = key + nums[start];
                if(key <= nums[start] && (val>=lower && val <= upper)){
                    //cout<<"adding one\n";
                    ans+=1;
                }
            } else{
                //cout<<"here\n";
               end==nums.size() ? ans += (end-start): ans+=(end-start+1); 
            }
            
            
            
        }
        
        return ans;
        
    }
};