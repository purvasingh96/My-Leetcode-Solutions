class Solution {
private:
    unordered_map<string, pair<string, double>> root;
    
    pair<string, double> find(pair<string, double> x){
        if(root[x.first].first == x.first) return x;
        double prod = (double)x.second*root[x.first].second;
        return find({root[x.first].first, prod});
    }
    
    void merge(pair<string, double> x, pair<string, double> y){
        auto rx = find(x);
        auto ry = find(y);
        
        if(rx.first != ry.first){
            double div = (double)(ry.second)/rx.second;
            root[rx.first]={ry.first, div};
        }
    }
    
public:
    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& v, vector<vector<string>>& q) {
        for(auto x:e){
            string u = x[0], v=x[1];
            root[u]={u, 1.00};
            root[v]={v, 1.00};
        }
        for(int i=0;i<e.size();i++){
            merge({e[i][0], 1.00}, {e[i][1], v[i]});
        }
        
//         cout<<find({"a", 1.00}).first<<" "<<find({"a", 1.00}).second<<"\n";
//         cout<<find({"b", 1.00}).first<<" "<<find({"b", 1.00}).second<<"\n";
        
        vector<double> res;
        for(auto x:q){
            string u = x[0], v=x[1];
            if(root.find(u)==root.end() || root.find(v)==root.end()) res.push_back(-1.00000);
            else {
                auto ansU = find({u, 1.00});
                auto ansV = find({v, 1.00});
                if(ansU.first != ansV.first) res.push_back(-1.00000);
                else {
                    double ans = (double)ansU.second/ansV.second;
                    res.push_back(ans);
                }
                
            }
            
        }
        return res;
    }
};