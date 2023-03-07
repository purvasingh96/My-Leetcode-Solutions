class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left=0, right=arr.size()-1;
        int ans=-1;
        if(arr.size()<=k){
            return arr;
        }
        
        ans = lower_bound(arr.begin(), arr.end(), x)-arr.begin();
        
        
        left =ans-1;
        right = ans;
       
        while(right-left-1<k){
            if(left == -1){
                right+=1;
                continue;
            }
            cout<<"right: "<<right<<"\n";
            if(right==arr.size() || abs(x-arr[left]) <= abs(x-arr[right])){
                left-=1;
            } else right+=1;
        }
        
        cout<<"working";
        
        vector<int> res;
        for(int i=left+1;i<right;i++){
            res.push_back(arr[i]);
        }
        return res;
        
    }
};