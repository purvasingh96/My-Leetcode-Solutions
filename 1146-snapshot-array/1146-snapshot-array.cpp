class SnapshotArray {
vector<vector<pair<int,int>>> m;
int s;
public:
    SnapshotArray(int length) {
        m.resize(length);
        s=0;
    }
    
    void set(int index, int val) {
        if(!m[index].empty() && m[index].back().first == s){
            m[index].pop_back();
        }
        m[index].push_back({s, val});
    }
    
    int snap() {
        s+=1;
        return s-1;
    }
    
    int get(int index, int snap_id) {
        // auto it = upper_bound(m[index].begin(), m[index].end(), pair<int, int>(snap_id, 0), [](const pair<int, int>& a, const pair<int, int>& b){
        //     return a.first < b.first;
        // });
        auto it = upper_bound(m[index].begin(), m[index].end(), pair<int, int>(snap_id, INT_MAX), [](const pair<int, int>& a, const pair<int, int>& b){
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