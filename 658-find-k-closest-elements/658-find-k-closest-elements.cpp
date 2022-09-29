class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // find the closest element;
        int n = arr.size();
        int left=0, right=n-1;
        
        while(left<right){
            int mid = left + (right-left)/2;
            if(arr[mid] < x){
                left=mid+1;
            } else right=mid;
        }
        
        left-=1;
        right=left+1;
        
        while(right-left-1<k){
            
            if(left<0) {
                right+=1;
                continue;
            } 
            
            if(right>=n || abs(arr[left] - x) <= abs(arr[right]-x)) left-=1;
            else right+=1;
            
        }
        
        return vector<int>(arr.begin()+left+1, arr.begin()+right);
        
    }
};