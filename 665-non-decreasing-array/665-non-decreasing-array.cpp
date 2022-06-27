class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int c =0, i=0;
        
        vector<int> q;
        if(nums.size()<3) return true;
        nums.push_back(INT_MAX);
        
        while(i+1<nums.size()){
            // cout<<i<<" ";
            // if(q.size()>0) cout<<q.back()<<" ";
            // cout<<nums[i]<<"\n";
            if(q.empty() || q.back() <= nums[i]){
                q.push_back(nums[i]);
                i+=1;
            } else{
                //out<<"c: "<<c<<"\n";
                if(c!=0) return false;
                if(q.back() <= nums[i+1]){
                    c+=1;
                    i+=1;
                    
                } else if(nums[i] <= nums[i+1]){
                    c+=1;
                    q.pop_back();
                    
                }
                else return false;
            }
        }
        
        return true;
        
    }
};