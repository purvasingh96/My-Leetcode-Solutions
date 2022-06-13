class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if(arr.size()==k){
            return arr;
        }
        
        vector<int> res;
        int left=0, right = arr.size()-1;
        
        
        // find lower bound
        while(left<right){
            int mid = left + (right-left)/2;
            if(arr[mid] >= x){
                right=mid;
            } else{
                left=mid+1;
            }
        }
        
        left-=1;
        right=left+1;
        
        while(right-left-1 < k){
            if(left==-1){
                right+=1;
                continue;
            }
            
            if(right==arr.size() || abs(arr[left] - x ) <= abs(arr[right] - x)){
                left-=1;
            } else{
                right+=1;
            }
        }
        
        for(int i=left+1;i<right;i++){
            res.push_back(arr[i]);
        }
        
        return res;
        
    }
};