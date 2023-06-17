class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // monotonic queue
        deque<int> q;
        int profit=0;
        
        for(int i=0;i<prices.size();i++){
            if(q.size()==0) q.push_back(prices[i]);
            else {
                while(q.size()!=0 && q.back() >= prices[i]){
                    q.pop_back();
                }
                if(q.size()!=0){
                    int diff = prices[i] - q.front();
                    profit = max(profit, diff);
                }
                q.push_back(prices[i]);
            }
        }
        
        return profit;
    }
};