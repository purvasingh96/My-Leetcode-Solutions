class Solution {
    static bool cmp1(vector<int> &a, vector<int> &b) {
        if(a[1] == b[1])
            return a[0] > b[0];
        return a[1] < b[1];
    }
    
    static bool cmp2(vector<int> &a, vector<int> &b) {
        return a[0] > b[0];
    }
    
    bool possible(vector<vector<int>>& v1, vector<vector<int>>& v2, long long ans) {
        for(int i = 0; i < v1.size(); i++) {
            if(ans >= v1[i][0]) 
                ans = (ans - v1[i][0] + v1[i][1]);
            else 
                return false;
        }
        
        for(int i = 0; i < v2.size(); i++) {
            if(ans >= v2[i][0]) 
                ans = (ans - v2[i][0] + v2[i][1]);
            else 
                return false;
        }
        
        return true;
    }

public:
    long long minimumMoney(vector<vector<int>>& tr) {
        vector<vector<int>> v1, v2;
        for(int i = 0; i < tr.size(); i++) {
            if(tr[i][1] >= tr[i][0])
                v2.push_back({tr[i][0], tr[i][1]});
            else 
                v1.push_back({tr[i][0], tr[i][1]});
        }
        
        sort(v1.begin(), v1.end(), cmp1);
        sort(v2.begin(), v2.end(), cmp2);
        
        long long ans = 0;
        long long low = 0, high = 1e16;
        while(low <= high) {
            long long mid = (low + high) / 2;
            if(possible(v1, v2, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};