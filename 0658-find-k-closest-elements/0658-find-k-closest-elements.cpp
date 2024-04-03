class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l=0, r=arr.size()-k;
        
        while(l<r){
            int mid = l + (r-l)/2;
            if(x - arr[mid] > arr[mid+k] - x){
                l=mid+1;
            } else {
                r=mid;
            }
        }
        
        cout<<"here";
        
        vector<int> ans;
        
        for(int j=l;j<l+k;j++){
            ans.push_back(arr[j]);
        }
        
        return ans;
            
    }
};