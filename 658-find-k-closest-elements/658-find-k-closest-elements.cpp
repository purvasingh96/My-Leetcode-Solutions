class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left=0;
        int right = arr.size() - k;
        
        while(left<right){
            int mid = left + (right-left)/2;
            
            if(x - arr[mid] > arr[mid+k]-x){
                left = mid+1;
            } else{
                right = mid;
            }
        }
        
        vector<int> res;
        for(int i=left;i<left+k;i++){
            res.push_back(arr[i]);
        }
        return res;
    }
};