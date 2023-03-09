class SnapshotArray {
public:
    // idx, snapid, val
    vector<vector<pair<int, int>>> m;
    int snapId;
   
    SnapshotArray(int length) {
        m.resize(length);
        snapId=0;
    }
    
    void set(int index, int val) {
        if(!m[index].empty() && m[index].back().first==snapId){
            m[index].pop_back();
        } 
            m[index].push_back({snapId, val});
        
    }
    
    int snap() {
        snapId+=1;
        return snapId-1;
    }
    
    int get(int index, int snap_id) {
        auto it = upper_bound(m[index].begin(), m[index].end(), pair<int, int>(snap_id, 0), [](const pair<int, int>& a, const pair<int, int>& b){
            return a.first < b.first;
        });
        if(it==m[index].begin()) return 0;
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