#define p pair<int, string>
class TimeMap {
private:
    unordered_map<string, vector<p>> m;
public:
    TimeMap() {
        
    }
    
    int binary(vector<p>& res, int target){
        //upper bound
        int l=0, r=res.size()-1;
        int ans=-1;
        while(l<r){
            int mid = l + (r-l)/2;
            if(res[mid].first > target){
                r=mid;
            } else l=mid+1;
        }
        
        if(l<res.size() && res[l].first<=target) l+=1;
        return l;
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        int idx = binary(m[key], timestamp);
        //cout<<"idx: "<<idx<<"\n";
        if(idx==0) return "";
        else{
            idx-=1;
            return m[key][idx].second;
        }
        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */