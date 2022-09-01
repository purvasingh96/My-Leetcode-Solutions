class Solution {
private:
    int merge(int left, int right, vector<long long>& ps, int lower, int upper){
        if(left == right){
            return (ps[left] >= lower && ps[left]<=upper)? 1:0;
        }
        
        int mid = left + (right-left)/2;
        
        int left_count = merge(left, mid, ps, lower, upper);
        int right_count = merge(mid+1, right, ps, lower, upper);
        int count=0;
        int i=left, j=mid+1, k=mid+1;
        
        while(i<=mid){
            
            long long lower_new = lower+ps[i];
            long long upper_new = upper+ps[i];
            
            while(j<=right && ps[j]<=upper_new){
                j+=1;
            }
            
            while(k<=right && ps[k] < lower_new){
                k+=1;
            }
            
            count+= (j-k);
            i+=1;
        }
        
        vector<long long> temp;
        int i1=left, j1=mid+1;
        
        while(i1<=mid && j1<=right){
            if(ps[i1] < ps[j1]) {
                temp.push_back(ps[i1]);
                i1+=1;
            } else{
                temp.push_back(ps[j1]);
                j1+=1;
            }
        }
        
        while(i1<=mid){
            temp.push_back(ps[i1]);
            i1+=1;
        }
        
        while(j1<=right){
            temp.push_back(ps[j1]);
            j1+=1;
        }
        
        int q=0;
        for(int p=left;p<=right;p++){
            ps[p] = temp[q++];
        }
        
        return left_count + right_count + count;
    }
    
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> ps(n, 0);
        ps[0] = nums[0];
        for(int i=1;i<n;i++){
            ps[i] = ps[i-1]+nums[i];
        }
        
        return merge(0, n-1, ps, lower, upper);
    }
};