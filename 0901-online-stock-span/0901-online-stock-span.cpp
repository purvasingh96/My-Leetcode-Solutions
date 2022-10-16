class StockSpanner {
private:
    stack<int> st;
    int idx;
    vector<int> res;
public:
    StockSpanner() {
        st.push(-1);
        idx=0;
    }
    
    int next(int price) {
        res.push_back(price);
        
        while(st.top()!=-1 && res[st.top()] <= price){
            st.pop();
        }
        
        int ans = idx-st.top();
        st.push(idx);
        idx+=1;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */