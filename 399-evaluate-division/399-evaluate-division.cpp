class Solution {
private:
    pair<string, double>& find(string& var, unordered_map<string, pair<string, double>>& root){
        // No record, create a new record for it
        if(root.find(var) == root.end())
            return root[var] = make_pair(var, 1.0);
        
        // It has itself as the root
        auto &origInfo = root[var];
        if(origInfo.first == var)
            return origInfo;
        
        // var = origRoot / origQ = newRoot / (origQ * newQ)
        double origQ = origInfo.second;
        auto &newInfo = find(origInfo.first, root);
        return root[var] = make_pair(newInfo.first, newInfo.second * origQ);
    }
    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, pair<string, double>> root;
        unordered_set<string> zero;
        
        // Make graph
        int nEquations = equations.size();
        for(int i = 0; i < nEquations; ++i){
            auto &vars = equations[i];
            string var0 = vars[0];
            string var1 = vars[1];
            double q = values[i];
            
            // var0 is zero
            if(q == 0){
                zero.insert(var0);
                continue;
            }
            
            // Retrieve root info for var0
            auto &info0 = find(var0, root);
            string root0 = info0.first;
            double q0 = info0.second;  // var0 = root0 / q0
            
            // Retrieve root info for var1
            auto &info1 = find(var1, root);
            string root1 = info1.first;
            double q1 = info1.second;  // var1 = root1 / q1
            
            // Update root info
            // root1 / q1 = var1 = var0 / q = root0 / (q * q0)
            //  => root1 = root0 / (q * q0 / q1)
            root[root1] = make_pair(root0, q * q0 / q1);
        }
        
        vector<double> ans;
        for(auto &query : queries){
            string var0 = query[0];
            string var1 = query[1];
            
            // var0 is zero
            if(zero.find(var0) != zero.end()){
                ans.push_back(0.0);
                continue;
            }
            
            // var0 or var1 doesn't appear before
            if(root.find(var0) == root.end() || root.find(var1) == root.end()){
                ans.push_back(-1.0);
                continue;
            }
            
            // var0 and var1 doesn't have the same root
            auto &info0 = find(var0, root);
            auto &info1 = find(var1, root);
            if(info0.first != info1.first){
                ans.push_back(-1.0);
                continue;
            }
            
            // var0 / var1 = (root0 / q0) / (root0 / q1) = q1 / q0
            double q0 = info0.second;
            double q1 = info1.second;
            ans.push_back(q1 / q0);
        }
        
        return ans;
    }
};