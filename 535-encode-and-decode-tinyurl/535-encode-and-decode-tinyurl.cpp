class Solution {
private:
    string encodeString = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    map<string, string> m;
    //srand(time(NULL));
public:
    string generateKey() {
        string key = "";
        for(int i=0;i<6;i++) {
            
            key += encodeString[rand()%62 + 0];
            
        }
        
        return key;
    }
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(m.find(longUrl) == m.end()) {
            string key = generateKey();
            string tinyURL = "https://tinyurl.com/"+key;
            m[longUrl] = tinyURL;
            m[tinyURL] = longUrl;
        }
        
        return m[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return m[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));