class Solution {
public:
    struct comp {
        bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
            // Return true if 'a' should come AFTER 'b' (lower priority)
            // For a Min-Heap, larger values have lower priority
            return a.second < b.second; 
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
       priority_queue<pair<int,int>, vector<pair<int,int>>, comp> maxpq;
       map<int, int> mp;
       for(int i=0; i<nums.size(); i++) {
            if(mp.find(nums[i]) != mp.end()) {
                mp[nums[i]]++;
            } else {
                mp[nums[i]] = 1;
            }
       }
       for(const auto& it : mp) {
            int key = it.first;
            int val = it.second;

            maxpq.push({key,val});
       }

        vector<int> ans;
       for(int i=0; i<k; i++) {
            pair<int, int> p = maxpq.top();
            ans.push_back(p.first);
            maxpq.pop();
       }
       return ans;
    }
};