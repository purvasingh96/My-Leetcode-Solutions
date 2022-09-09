class SnapshotArray {
private:
    unordered_map<int, vector<pair<int, int>>> m;
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
        snapshot=0;
    }
    
    void set(int index, int val) {
        // find if we already have that element: binary search
        // lower bound;
        // m[snapshot] = {idx, val};
        if(m[snapshot].size()==0 || m[snapshot].back().first < index){
            m[snapshot].push_back({index, val});
        } else{
            int idx = binary_search(m[snapshot], index);
            if(m[snapshot][idx].first == index){
                m[snapshot][idx].second = val;
            } else {
                m[snapshot].insert(m[snapshot].begin()+idx, {index, val});
            }
        }
    }
    
    int snap() {
        snapshot+=1;
        m[snapshot] = m[snapshot-1];
        return snapshot-1;
    }
    
    int get(int index, int snap_id) {
        
        int idx = binary_search(m[snap_id], index);
        if(m[snap_id].size()==0 || m[snap_id][idx].first != index) return 0;
        return m[snap_id][idx].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */