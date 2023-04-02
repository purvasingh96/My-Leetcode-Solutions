#define ll long long
class Solution {
private:
    vector<int> rank;
    vector<int> root;
    
    int find(int x) {
        if(root[x]==x) return x;
        return root[x] = find(root[x]);
    }
    
    void merge(int x, int y){
        int rx = find(x);
        int ry = find(y);
        
        if(rx!=ry){
            if(rank[rx] >= rank[ry]){
                root[ry] = rx;
                rank[rx]+=rank[ry];
            } else {
                root[rx]=ry;
                rank[rx]+=rank[ry];
            }
        }
        
    }
    
    ll stepsToMakeEqual(vector<ll>& nums){
        if (nums.size()==0) return 0;
        sort(nums.begin(), nums.end());
        vector<ll> ps;
        ps.push_back(0);
        
        for(int i=0;i<nums.size();i++){
            ps.push_back(nums[i]+ps.back());
        }
        
        
        int n = nums.size();
        ll res=1e14+1;
        
        for(int i=1;i<=n;i++){
            ll target = nums[i-1];
        
            ll left_count = i-1;
            ll left_sum = ps[i-1];

            ll right_count = n-i;
            ll right_sum = ps[n] - ps[i];

            res = min(res, (right_sum - (right_count*target) + ((left_count*target) - left_sum)));
        }
        
        return res;
        
    }
    
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        
        vector<ll> indices;
        int n = arr.size();
        
        root.resize(n);
        rank.resize(n, 1);
        for(int i=0;i<n;i++) root[i]=i;
        
        // cyclic array
        for(int i=0;i<n;i++) indices.push_back(i);
        for(int i=0;i<n;i++) indices.push_back(i);
        
        vector<ll> actual(n+k-1);
        int val=0;
        for(int i=0;i<actual.size();i++){
            actual[i] = val;
            val+=1;
            if(val==k) val=0;
        }
        
        
        for(int i=0;i<actual.size();i++){
            if(actual[i] != indices[i]){
                merge(actual[i], indices[i]);
            }
        }
        
        vector<vector<ll>> groups(n);
        for(int i=0;i<n;i++){
            groups[find(root[i])].push_back(arr[i]);
        }
        
        
        
        ll res=0;
        for(int i=0;i<n;i++){
            //groups[i].push_back(arr[i]);
         // for(auto x:groups[i]) cout<<x<<" ";
         //    cout<<"\n";
            res += stepsToMakeEqual(groups[i]);
        }
        
        return res;
        
    }
};