class Logger {
private:
    unordered_map<string, int> m;
public:
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(m.find(message)==m.end()){
            m[message] = (timestamp+10);
            return true;
        } else {
            if(timestamp >= m[message]){
                m[message] = (timestamp+10);
                return true;
            } return false;
        }
        
        
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */