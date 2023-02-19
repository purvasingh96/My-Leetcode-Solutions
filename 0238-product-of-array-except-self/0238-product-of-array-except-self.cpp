class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prod(n, 1);
        int left=0, prev=1;
        for(int i=1;i<n;i++){
            prod[i] = prev*nums[left++];
            prev = prod[i];
        }
        
        int right=n-1, fwd=1;
        for(int i=n-2;i>=0;i--){
            prod[i]= prod[i] * (fwd*nums[right]);
            fwd = fwd*nums[right];
            right-=1;
        }
        
        //for(auto x:prod) cout<<x<<" ";
        return prod;
    }
};