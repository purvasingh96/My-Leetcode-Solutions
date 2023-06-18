class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> lft(n);
        vector<int> rgt(n);
        
        lft[0] = nums[0];
        rgt[n-1]=nums[n-1];
        int i=0;
        
        for (i = 0; i < n; i++)
			{
				lft[i] = nums[i];
				 // If it start of block, then that element is max so far in the block
				 // Else lft[i] is max so far in the block
				if (i % k !=0) 
					lft[i] = max(lft[i - 1], lft[i]);
			}

			rgt[n - 1] = nums[n - 1];
			for (i = n - 2; i >= 0; i--)
			{
				rgt[i] = nums[i];
				// same as for left, but now traversing from right
				if (i % k != (k - 1))
					rgt[i] = max(rgt[i], rgt[i + 1]);
			}
        
        vector<int> res;
        for(int i=0;i<=n-k;i++){
            int ans = max(lft[i+k-1], rgt[i]);
            res.push_back(ans);
        }
        
        return res;
        
    }
};