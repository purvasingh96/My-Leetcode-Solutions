class SnapshotArray {
private:
    unordered_map<int, vector<pair<int, int>>> m;
    int snap_id;
    int length;
public:
    SnapshotArray(int length) {
        snap_id = 0;
        this->length = length;
        for(int i=0;i<length;i++){
            m[i].push_back({snap_id, 0});
        }
    }
    
    void set(int index, int val) {
        if(m[index].back().first == snap_id){
            m[index].pop_back();  
        } 
        m[index].push_back({snap_id, val});
    }
    
    int snap() {
        int t = snap_id;
        snap_id+=1;
        // for(int i=0;i<length;i++){
        //     m[i].push_back({snap_id, m[i].back().second});
        // }
        return t;
    }
    
    int get(int index, int snap_id) {
        auto it = upper_bound(m[index].begin(), m[index].end(), pair<int, int>(snap_id, INT_MAX), [](const pair<int, int>& a, const pair<int, int>& b){
            return a.first < b.first;
        });
        if(it == m[index].begin()) return 0;
        
        return prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */