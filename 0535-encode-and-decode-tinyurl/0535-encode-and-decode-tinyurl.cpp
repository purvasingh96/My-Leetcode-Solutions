class Solution {
private:
    unordered_map<string, string> shortToLong;
    string url = "http://tinyurl.com/";
    int uid=1;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string encodedUrl = url + to_string(uid);
        uid+=1;
        shortToLong[encodedUrl] = longUrl;
        return encodedUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return shortToLong[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));