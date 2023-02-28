class MyCalendarTwo {
private:
     map<long long, long long> tree;
    map<long long, long long> lazy;

    int updateAdd(int rootIdx, int low, int high, int l, int r){
        
         if(high<l || r<low)return 0 ; 
        if(low>=l && high<=r)
        {
            tree[rootIdx]++;
            lazy[rootIdx]++;
            
           return tree[rootIdx] ;
        }
        
            int mid = (low+high)/2 ;
            updateAdd(1LL*2*rootIdx+1 , low ,mid ,l ,r ); 
            updateAdd(1LL*2*rootIdx+2 , mid+1 ,high , l ,r ); 
        return tree[rootIdx] =lazy[rootIdx]+ max(tree[1LL*2*rootIdx+1] , tree[1LL*2*rootIdx+2]); 
    }
    
    int updateUndo(int rootIdx, int low, int high, int l, int r){
        if(high<l || r<low)return 0 ; 
        
       if(l<=low && high<=r){
           tree[rootIdx]-=1;
           lazy[rootIdx]-=1;
           return tree[rootIdx];
       }

        
        int mid = low + (high-low)/2;
        updateUndo(1LL*2*rootIdx+1, low, mid,  l,  r);
         updateUndo(1LL*2*rootIdx+2, mid+1, high, l, r);
        
        return tree[rootIdx] = lazy[rootIdx]+max(tree[1LL*2*rootIdx+1], tree[1LL*2*rootIdx+2]);
    }
    
    
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
       int res = updateAdd(0, 0, 1000000000, start, end-1);
       
        if(res==1||res==2) return true;
        else {
            updateUndo(0, 0, 1000000000, start, end-1);
            return false;
        }
        
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */