/*
    cmp need to reverse for the priority queue
*/
typedef pair<int, string> PSI;
class Solution {
public:
    // need to reverse from the normal style of writing 
    struct cmp {
        bool operator()(const PSI& a, const PSI& b) const {
            if (a.first == b.first) return a.second > b.second;
            else return a.first < b.first;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> hash;
        for (auto& s : words) hash[s]++;
        priority_queue<PSI, vector<PSI>, cmp> pq;
        for (auto [k, v] : hash) {
            pq.push({v, k});
        }
        vector<string> res;
        for (int i = 0; i < k; i++) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};