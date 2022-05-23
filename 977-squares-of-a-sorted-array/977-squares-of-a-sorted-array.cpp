class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        /*
        - create temp vector of size n
        - push squares of all +ve nums first
        - p1 = m-1, p=n-1, p2=0
        - for(p=(m+n-1);//) {
            if()
        }
        */
        
        vector<int> temp(nums.size(), INT_MAX);
        int n = nums.size();
        int idx=0;
        while(idx<n && nums[idx]<0){
            idx+=1;
        }
        
        if(idx==n){
            // all negative numbers
            idx-=1;
            int i=0;
            while(idx>=0){
                temp[idx--] = pow(nums[i++], 2);
            }
            return temp;
        }
        
        int p2=0, p1=0, p=n-1;
        while(idx<n){
            temp[p1++] = pow(nums[idx++], 2);
        }
        
        p1-=1;
        
        while(p1>=0 && p2<idx && p>=0){
            
            if(temp[p1] > pow(nums[p2],2)) {
                temp[p--]=temp[p1];
                p1-=1;
            } else{
                temp[p--]=pow(nums[p2], 2);
                p2+=1;
            }
            
        }
        
        cout<<"here";
        
        while(p>=0){
            temp[p--] = pow(nums[p2++],2);
        }
        
        
        return temp;
        
    }
};