class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> m;
    
    string bs(int target, vector<pair<int, string>>& nums){
        //sort(nums.begin(), nums.end());
        
        int left=0, right=nums.size()-1;
        int ans=-1;
        
        while(left<=right){
            int mid = left + (right-left)/2;
            //cout<<"mid: "<<mid<<"\n";
            if(nums[mid].first <=target) {
                ans=mid;
                left=mid+1;
            }
            else right=mid-1;
        }
        
        //cout<<ans<<"\n";
        
        return ans==-1 ? "":nums[ans].second;
        
    }
    
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back(make_pair(timestamp, value));
    }
    
    string get(string key, int timestamp) {
        return bs(timestamp, m[key]);
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */