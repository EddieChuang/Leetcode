class Solution {
public:

    
    
    Solution(){ num = 0;}
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        shortToLong[num] = longUrl;
        return to_string(num++);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return shortToLong[stoi(shortUrl)];
    }
    
private:
    map<int, string> shortToLong;
    int num;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));