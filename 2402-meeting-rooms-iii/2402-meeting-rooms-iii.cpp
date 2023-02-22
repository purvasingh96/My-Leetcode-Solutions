class MyCmp{
 public:
    bool operator()(const pair<long, long>& a, const pair<long, long>& b){
        if(a.first == b.first) return a.second > b.second;
        return a.first > b.first;
    }
};

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<pair<long, long>, vector<pair<long, long>>, MyCmp> pq;
        vector<long> freq(n, 0);
        
        for(int i=0;i<n;i++) {
            pq.push({0,i});
        }
        
        for(int i=0;i<meetings.size();i++){
            while(pq.top().first < meetings[i][0]){
                pq.push({meetings[i][0], pq.top().second});
                pq.pop();
            }
            
            auto temp = pq.top();
            pq.pop();
            freq[temp.second]+=1;
            temp.first += (meetings[i][1] - meetings[i][0]);
            pq.push(temp);
        }
        
        return max_element(freq.begin(), freq.end()) - freq.begin();
        
    }
};