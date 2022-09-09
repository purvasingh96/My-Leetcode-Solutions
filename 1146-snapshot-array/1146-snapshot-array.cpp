class SnapshotArray {
private:
    vector<vector<pair<int, int>>> m;
    int snapshot;
    
    int binary_search(vector<pair<int, int>>& res, int idx){
        int left =0, right=res.size()-1;
        
        while(left<right){
            int mid = left + (right-left)/2;
            if(res[mid].first >= idx){
                right=mid;
            } else {
                left=mid+1;
            }
        }
        
        return left;
        
    }
    
    
public:
    SnapshotArray(int length) {
        m.resize(length);
        snapshot=0;
    }
    
    void set(int index, int val) {
        // m[index] => {snapId, val}
        if(m[index].size()==0 || m[index].back().first <snapshot){
            m[index].push_back({snapshot, val});
        } else {
            m[index].back().second=val;
        }
    }
    
    int snap() {
        return snapshot++;
    }
    
    int get(int index, int snap_id) {
        // O(logn)
        auto it = upper_bound(m[index].begin(), m[index].end(), make_pair(snap_id, INT_MAX));
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