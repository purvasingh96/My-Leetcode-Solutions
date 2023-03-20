class Solution {
private:
    
public:
    bool canPlaceFlowers(vector<int>& nums, int n) {
        if(nums.size()==1) {
            if((nums[0]==0 && n==1) || n==0) return true;
            else return false;
        }
        bool prev=(nums[0] == 1);
        int i= (prev?2:0);
        int s = nums.size();
        
        while(i<s){
            if(n==0) return true;
            if(nums[i]==0){
                if(i+1<s && nums[i+1]==0) {
                    nums[i]=1;
                    n-=1;
                    i += 2;
                } else {
                    if(i+1<s && nums[i+1]==1){
                        i+=3;
                    } else if(i+1>=s && nums[i-1]==0){
                        nums[i]=1;
                        i+=2;
                        n-=1;
                    } else i+=1;
                }
            } else {
                i+=2;
            }
        }
        return n==0;
    }
};