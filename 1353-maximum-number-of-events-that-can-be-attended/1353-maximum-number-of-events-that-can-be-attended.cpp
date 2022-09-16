typedef long long ll;
class SegmentTree{
public:
    vector<ll> tree;
    int n;
    SegmentTree(int n){
        this->n=n;
        tree.resize(4*n);
    }
    
    ll l(int node){
        return 2*(ll)node+1;
    }
    
    ll r(int node){
        return 2*(ll)node+2;
    }
    
    void pushUp(int root_idx){
        tree[root_idx] = min(tree[l(root_idx)], tree[r(root_idx)]);
    }
    
    void build(int root_idx, int left, int right){
        if(left == right){
            tree[root_idx] = left;
            return;
        }
        
        int mid = left + (right-left)/2;
        
        build(l(root_idx), left, mid);
        build(r(root_idx), mid+1, right);
        
        pushUp(root_idx);
    }
    
    void modify(int root_idx, int target_idx, int left, int right){
        
        if(left == right){
            tree[root_idx] = INT_MAX;
            return;
        }
        
        int mid = left + (right-left)/2;
        
        if(target_idx <= mid){
            modify(l(root_idx), target_idx, left, mid);
        } else{
            modify(r(root_idx), target_idx, mid+1, right);
        }
        
        pushUp(root_idx);
        
    }
    
    int query(int root_idx, int ql, int qr, int left, int right){
        
        if(ql > right || qr<left) return INT_MAX;
        
        else if(ql<=left && right<=qr) return tree[root_idx];
        
        int mid = left + (right-left)/2;
        
        int q1 = query(l(root_idx), ql, qr, left, mid);
        int q2 = query(r(root_idx), ql, qr, mid+1, right);
        
        return min(q1, q2);
        
    }
    
};

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](auto& a, auto& b){
            return a[1] < b[1];
        });
        
        int n = events.back()[1]+1;
        
        SegmentTree* s = new SegmentTree(n);
        s->build(0, 0, n-1);
        //for(auto x:s->tree) cout<<x<<" ";
        
        
        int count=0;
        
        for(auto e:events){
            
            int q = s->query(0, e[0], e[1], 0, n-1);
            //cout<<q<<"\n";
            if(q!=INT_MAX) {
                count+=1;
                s->modify(0, q, 0, n-1);
            }
            
        }
         
        return count;
    }
};