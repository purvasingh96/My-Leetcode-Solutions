#define pp pair<int, int>

class StockPrice {
private:
    map<int, int> m;
    priority_queue<pp> pq_max;
    priority_queue<pp, vector<pp>, greater<pp>> pq_min;
public:
    StockPrice() {
    }
    
    void update(int timestamp, int price) {
        m[timestamp] = price;
        pq_max.push({price, timestamp});
        pq_min.push({price, timestamp});
    }
    
    int current() {
        return prev(m.end())->second;
    }
    
    int maximum() {
        while(!pq_max.empty() && m[pq_max.top().second]!=pq_max.top().first){
            pq_max.pop();
        }
        return pq_max.top().first;
    }
    
    int minimum() {
        while(!pq_min.empty() && m[pq_min.top().second]!=pq_min.top().first){
            pq_min.pop();
        }
        return pq_min.top().first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */