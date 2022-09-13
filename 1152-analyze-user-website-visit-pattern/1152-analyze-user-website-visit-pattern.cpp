class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& name, vector<int>& t, vector<string>& w) {
        map<int, vector<pair<string, string>>> m;

        for(int i=0;i<name.size();i++){
            m[t[i]].push_back({name[i], w[i]});
        }
        
        unordered_map<string, vector<string>> v;
        
        for(auto x:m){
            for(auto y:x.second){
                v[y.first].push_back(y.second);
            }
        }
        
        
        // for(auto x:v){
        //     cout<<x.first<<" -> ";
        //     for(auto y:x.second) cout<<y<<" ";
        //     cout<<"\n";
        // }
        
        
        //cout<<"here";
        map<string, set<string>> f;
        
        for(auto x:v){
            auto y = x.second;
            //cout<<x.first<<"\n";
            if(y.size()>=3){
                for(int i=0;i<=(y.size()-3);i++){
                    for(int j=i+1;j<=(y.size()-2);j++){
                        for(int k=j+1;k<=(y.size()-1);k++){

                            string a = y[i], b=y[j], c=y[k];
                            f[a+'#' + b + '#'+c].insert(x.first);
                            //cout<<(a+'#' + b + '#'+c)<<"\n";

                        }
                    }
                }
            }
            
            //cout<<"done\n";
        }
        
        //cout<<"here";
        
        int maxfreq=0;
        string res;
        for(auto x:f){
            if(x.second.size() > maxfreq){
                maxfreq=x.second.size();
                res=x.first;
            } 
        }
        
        vector<string> ans;
        
        string delimter="#";
        
        size_t pos = res.find(delimter);
        int start=0;
        
        while(pos != string::npos){
            ans.push_back(res.substr(start, pos-start));
            start=pos+1;
            pos = res.find(delimter, start);
        }
        
        ans.push_back(res.substr(start));
        
        return ans;
    }
};