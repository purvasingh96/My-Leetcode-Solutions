class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        // array length = odd || array[0]'s double is not present; return empty array
        // sort array
        // if double found make that as nums[i+1];
        // as soon as res size==changed/2 return res;
        
        sort(changed.begin(), changed.end());
        vector<double> res(changed.begin(), changed.end());
        vector<int> ans;
        int n = changed.size();
        if(n%2!=0) return ans;
        
        //for(auto x:res) cout<<x<<" ";
        
        for(int i=0;i<res.size()-1;i++) {
            
            // deal only with integer folks
            if(int(res[i])!=res[i]) continue;
            
            int target = 2*int(res[i]);
            
            auto it = lower_bound(res.begin()+i+1, res.end(), target);
            
            if(it!=res.end() && *it == target){
                //cout<<"here";
                ans.push_back(int(res[i]));
                int idx = it - res.begin();
                res[idx] = res[idx-1]+0.0001;
                if(ans.size()==n/2) return ans;
                
            }
            
            
            
        }
        
        
        
        return {};
        
        
        
    }
};