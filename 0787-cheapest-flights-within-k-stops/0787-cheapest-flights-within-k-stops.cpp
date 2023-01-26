class MyCompare{
 public:
    bool operator()(const vector<int>& a, const vector<int>& b){
         if(a[0] == b[0]) return a[2] > b[2];
            return a[0] > b[0];
    }
};


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // price, stop, #stops
        priority_queue<vector<int>, vector<vector<int>>, MyCompare> pq;
        // node -> {next, price}
        unordered_map<int, vector<vector<int>>> adj;
        
        vector<int> st(n, INT_MAX);
        
        st[src]=0;
        
        for(auto f:flights){
            adj[f[0]].push_back({f[1], f[2]});
        }
        
        pq.push({0, src, 0});
        
        while(!pq.empty()){
            auto f = pq.top();
            pq.pop();
            int price = f[0], node = f[1], stops=f[2];
            //cout<<"price: "<<price<<" node: "<<node<<" stops: "<<stops<<"\n";
            if(stops > st[node] || stops > k+1) continue;
            st[node] =stops;
            
            if(node == dst) return price;
            
            for(auto next:adj[node]){    
                pq.push({price+next[1], next[0], stops+1});
            }
        }
        
        return -1;
        
    }
};