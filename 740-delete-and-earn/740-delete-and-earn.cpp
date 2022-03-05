class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        map<int, int> m;
        for(auto x:nums) {
            m[x] += x;
        }
        
        vector<int> arr;
        
        for(auto x:m) {
            arr.push_back(x.first);
        }
        
        
        sort(arr.begin(), arr.end());
        
        
        for(auto x: arr){
            cout<<x<<" ";
        }
        
        int twoback = 0, oneback = m[arr[0]];
        
        for(int i=1;i<arr.size();i++) {
            
            int temp = oneback;
            
            if(arr[i] == arr[i-1]+1) {
                
                oneback = max(oneback, twoback+m[arr[i]]);
                
            } else {
                
                oneback += m[arr[i]];
                
            }
            
            twoback = temp;
            
        }
        
        return oneback;
        
        
        
    }
};