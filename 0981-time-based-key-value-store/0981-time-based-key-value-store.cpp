#define p pair<int, string>
class TimeMap {
private:
    unordered_map<string, vector<p>> m;
public:
    TimeMap() {
        
    }

    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        int idx = upper_bound(m[key].begin(), m[key].end(), p(timestamp, ""), [](const p& a, const p& b){
            return a.first < b.first;
        }) - m[key].begin();
        
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