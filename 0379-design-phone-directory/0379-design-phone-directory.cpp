class PhoneDirectory {

    unordered_set<int> available;
    int k;
public:
    PhoneDirectory(int maxNumbers) {
        
        for(int i=0;i<maxNumbers;i++){
            available.insert(i);
        }
    }
    
    int get() {
        if(available.size()==0) return -1;
        auto it = available.begin();
        int ans = *it;
        available.erase(it);
        return ans;
    }
    
    bool check(int number) {
        return available.count(number)>0;
    }
    
    void release(int number) {
        available.insert(number);
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */