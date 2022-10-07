class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> m;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back(make_pair(timestamp, value));
    }
    
    string get(string key, int timestamp) {
        int left=0, right=m[key].size()-1;
        int ans=-1;
        
        while(left<=right){
            int mid = left + (right-left)/2;
            //cout<<"mid: "<<mid<<"\n";
            if(m[key][mid].first <=timestamp) {
                ans=mid;
                left=mid+1;
            }
            else right=mid-1;
        }
        
        //cout<<ans<<"\n";
        
        return ans==-1 ? "":m[key][ans].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */