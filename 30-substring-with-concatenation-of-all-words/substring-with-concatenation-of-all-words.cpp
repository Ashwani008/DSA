class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (s.empty() || words.empty()) return ans;

        int wordlen = words[0].length();
        int numWords = words.size();
        int totalLen = wordlen * numWords;
        int n = s.length();

        if (n < totalLen) return ans;

        unordered_map<string, int> mp;
        for (const string& w : words) {
            mp[w]++;
        }

        // Run sliding window for each offset from 0 to wordlen - 1
        for (int i = 0; i < wordlen; ++i) {
            int left = i, right = i, count = 0;
            unordered_map<string, int> seen;

            while (right + wordlen <= n) {
                string w = s.substr(right, wordlen);
                right += wordlen;

                if (mp.count(w)) {
                    seen[w]++;
                    count++;

                    // Shrink window from left if word frequency exceeds requirement
                    while (seen[w] > mp[w]) {
                        string leftWord = s.substr(left, wordlen);
                        seen[leftWord]--;
                        count--;
                        left += wordlen;
                    }

                    // Valid concatenation found
                    if (count == numWords) {
                        ans.push_back(left);
                    }
                } else {
                    // Invalid word encountered -> reset window
                    seen.clear();
                    count = 0;
                    left = right;
                }
            }
        }
        return ans;
    }
};