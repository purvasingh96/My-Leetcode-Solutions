class Solution {
private:
    void mergesort(int start, int end, vector<int>& nums, int& ans){
        if(start>=end) return;
        
        int mid = start + (end-start)/2;
        
        mergesort(start, mid, nums, ans);
        mergesort(mid+1, end, nums, ans);
        
        int i=start, j=mid+1, n = nums.size();
        //cout<<i<<" "<<j<<"\n";
        
        while(i<=mid && j<=end) {
            //long target = 2*(long)nums[j];
            
            if(nums[i] > 2L * nums[j]){
                ans += end-j+1;
                i+=1;
            } else {
                j+=1;
            }
        }
        
        //cout<<ans<<"\n";
        
        vector<int> temp;
        int i1=start, j1=mid+1;
        
        while(i1<=mid && j1<=end){
            if(nums[i1] > nums[j1]){
                temp.push_back(nums[i1]);
                i1+=1;
            } else {
                temp.push_back(nums[j1]);
                j1+=1;
            }
        }
        
        //cout<<"main done\n";
        
        while(i1<=mid){
            temp.push_back(nums[i1]);
            i1+=1;
        }
        
        //cout<<"i1 done\n";
        
        while(j1<=end){
            temp.push_back(nums[j1]);
            j1+=1;
        }
        //cout<<"i2 done\n";
        
        int idx=0;
        for(int k=start;k<=end;k++){
            nums[k] = temp[idx++];
        }
    }
public:
    int reversePairs(vector<int>& nums) {
        int ans=0, n = nums.size();
        mergesort(0, n-1, nums, ans);
        return ans;
    }
};