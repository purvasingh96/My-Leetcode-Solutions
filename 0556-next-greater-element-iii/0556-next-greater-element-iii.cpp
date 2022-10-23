class Solution {
private:
    int binary(vector<pair<int, int>>& res, int target){
        
        int l = 0, r=res.size()-1;
        int ans=-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(res[mid].first > target) {
                ans=res[mid].second;
                r=mid-1;
            } else l=mid+1;
        }
        
        return ans;
    }
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        vector<pair<int, int>> res;
        
        for(int i=s.length()-1;i>=0;i--){
            
            if(res.empty() || res.back().first <= s[i]-'0')  res.push_back({s[i]-'0', i});
            else {
                int idx = binary(res, s[i]-'0');
                cout<<idx<<"\n";
                if(idx==-1) return -1;
                char t = s[i];
                s[i] = s[idx];
                s[idx]=t;
                sort(s.begin()+i+1, s.end());
                break;
            }
        }
        
        long long ans = stoll(s);
        if(ans > INT_MAX || ans == n) return -1;
        return (int)ans;
        
    }
};