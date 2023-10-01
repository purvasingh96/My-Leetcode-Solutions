class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<pair<int, int>> st;
        int n = prices.size();
        vector<int> discount(n, -1);
        
        for(int i=0;i<n;i++){
            
            while(!st.empty() && prices[st.top().second] >= prices[i]){
                discount[st.top().second] = i;
                st.pop();
            }
            st.push({prices[i], i});
        }
        
        //for(auto x:discount) cout<<x<<" ";
        
        for(int i=0;i<n;i++){
            if(discount[i]!=-1){
                prices[i]-=prices[discount[i]];
            }
        }
        
        return prices;
        
    }
};