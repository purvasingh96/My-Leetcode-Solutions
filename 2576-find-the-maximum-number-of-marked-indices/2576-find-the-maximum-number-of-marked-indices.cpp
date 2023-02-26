class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i=(n+1)/2, j=n-1;
        
        int ans=0;
        cout<<"n: "<<n<<"\n";
        for(auto x:nums) cout<<x<<" ";
        
        while(i>=0 && j>=(n+1)/2){
            if(2*nums[i]<=nums[j]){
                ans+=2;
                i-=1;
                j-=1;
            } else {
                i-=1;
            }
        }
        
        return ans;
        
    }
};