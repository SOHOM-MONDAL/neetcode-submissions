class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto no : nums){
            mp[no]++;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> ans;
        
        for(const auto &[key, val] : mp) {
            pq.push({val, key});      // Push the new pair first
            
            if(pq.size() > k) {      // If we exceed size k, remove the smallest frequency
                pq.pop();            // Fixed: use pop() instead of pop_back()
            }
        }
        
        // Fixed: Extract elements using top() and pop()
        while(!pq.empty()) {
            ans.push_back(pq.top().second); // .second is the key (the actual number)
            pq.pop();
        }
        
        return ans;
    }
};