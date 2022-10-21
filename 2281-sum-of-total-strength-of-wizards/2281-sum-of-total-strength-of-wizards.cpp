

class Solution {
private:
    vector<int> previousSmaller(vector<int>& s){
        int n = s.size();
        vector<int> pse(n, -1);
        stack<int> st;
        
        // increasing monotonic stack
        for(int i=0;i<s.size();i++){
            while(!st.empty() && s[st.top()] >= s[i]){
                st.pop();
            }
            
            if(!st.empty()) pse[i] = st.top();
            st.push(i);
        }
        return pse;
    }
    
    vector<int> nextSmallerOrEqual(vector<int>& s){
        int n = s.size();
        vector<int> nse(n, n);
        stack<int> st;
        
        for(int i=0;i<s.size();i++){
            while(!st.empty() && s[st.top()] >= s[i]){
                nse[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        return nse;
        
    }
    
    vector<long> preps(vector<int>& s){
        int mod = 1e9+7;
        int n = s.size();
        vector<long> ps(n+1, 0);
        vector<long> pps(n+1, 0);
        
        
        for(int i=1;i<=s.size();i++){
            ps[i] = ps[i-1] + s[i-1];
            ps[i] %= mod;
        }
        
        for(int i=1;i<=n;i++){
            pps[i] = pps[i-1] + ps[i];
            pps[i] %= mod;
        }
        
        return pps;
    }
    
public:
    int totalStrength(vector<int>& s) {
        int mod = 1e9+7;
        vector<int> pse = previousSmaller(s);
        vector<int> nse = nextSmallerOrEqual(s);
        vector<long> pps = preps(s);
        
        
        
        int n = s.size();
        long res=0;
        
        for(int i=0;i<n;i++){
            
            int left = pse[i];
            
            int right = nse[i];
            
            long plus = (i-left) * (pps[right-1+1] - pps[i-1+1]) % mod + mod;
            
            long minus = (right - i) * (pps[i-1+1] - pps[left-1+1 < 0 ? 0: left-1+1])%mod;
            //cout<<"i: "<<i<<"\n"; 
            long ans = plus - minus;
            ans = ans * s[i];
            
            ans %= mod;
            res += ans;
            res %= mod;
        }
        
        
        return (int)res;
        
    }
};