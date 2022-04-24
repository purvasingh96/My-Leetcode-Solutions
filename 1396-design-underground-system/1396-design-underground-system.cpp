class UndergroundSystem {
private:
    map<int, pair<string, int>> cache;
    map<pair<string, string>, pair<int, int>> m;
    
public:
    UndergroundSystem() {
        //cache.resize(1000000);    
    }
    
    void checkIn(int id, string stationName, int t) {
        auto info = make_pair(stationName, t);
        cache[id] = info;
        
    }
    
    void checkOut(int id, string stationName, int t) {
        auto checkInInfo = cache[id];
        
        cache[id] = {};
        
        int time_diff = t - checkInInfo.second;
      
        auto p = make_pair(checkInInfo.first, stationName);
        
        
            // last time, cur size
        auto timeInfo = m[p];
        int total_time =   timeInfo.first + time_diff;
        int size = timeInfo.second+1;
        auto new_info = make_pair(total_time, size);
        m[p] = new_info;
            
         
         
       
    }
    
    double getAverageTime(string startStation, string endStation) {
        double avg = 0.0;
        auto p = make_pair(startStation, endStation);
        
        avg = (double)m[p].first/m[p].second;
        
        return avg;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */