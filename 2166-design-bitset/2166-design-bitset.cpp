class Bitset {
private:
    int cs;
    string res;
    string flip_res;
public:
    Bitset(int size) {
        cs=0;
        res.resize(size, '0');
        flip_res.resize(size, '1');
    }
    
    void fix(int idx) {
        if(res[idx]=='0') {
            res[idx] = '1';
            cs += 1;
        }
        
        if(flip_res[idx]=='1'){
            flip_res[idx] = '0';
        }
    }
    
    void unfix(int idx) {
        if(res[idx]=='1') {
            res[idx] = '0';
            cs -= 1;
        }
        
        if(flip_res[idx]=='0'){
            flip_res[idx] = '1';
        }
    }
    
    void flip() {
        swap(flip_res, res);
        cs = res.length()-cs;
    }
    
    bool all() {
        return cs == res.length();
    }
    
    bool one() {
        return cs> 0;
    }
    
    int count() {
        return cs;
    }
    
    string toString() {
        return res;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */