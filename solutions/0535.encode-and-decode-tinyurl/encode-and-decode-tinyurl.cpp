/*
 * @lc app=leetcode id=535 lang=cpp
 *
 * [535] Encode and Decode TinyURL
 *
 * https://leetcode.com/problems/encode-and-decode-tinyurl/description/
 *
 * algorithms
 * Medium (76.14%)
 * Total Accepted:    69.3K
 * Total Submissions: 91K
 * Testcase Example:  '"https://leetcode.com/problems/design-tinyurl"'
 *
 * Note: This is a companion problem to the System Design problem: Design
 * TinyURL.
 *
 * TinyURL is a URL shortening service where you enter a URL such as
 * https://leetcode.com/problems/design-tinyurl and it returns a short URL such
 * as http://tinyurl.com/4e9iAk.
 *
 * Design the encode and decode methods for the TinyURL service. There is no
 * restriction on how your encode/decode algorithm should work. You just need
 * to ensure that a URL can be encoded to a tiny URL and the tiny URL can be
 * decoded to the original URL.
 *
 */
#include <map>
#include <string>

using namespace std;

class Solution {
  public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) { return longUrl; }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) { return shortUrl; }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
