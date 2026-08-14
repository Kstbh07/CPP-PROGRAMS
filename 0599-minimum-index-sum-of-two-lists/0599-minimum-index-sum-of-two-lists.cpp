class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1,
                                  vector<string>& list2) {
        unordered_map<string, int> mp1;

        priority_queue<pair<int, string>, vector<pair<int, string>>,
                       greater<pair<int, string>>>
            pq;
        for (int i = 0; i < list1.size(); i++) {
            mp1[list1[i]] = i;
        }

        for(int i=0;i<list2.size();i++){
            if(mp1.count(list2[i])){
                pq.push({i+mp1[list2[i]],list2[i]});
            }
        }

        vector<string> ans;

        if(pq.empty()) return ans;

        int mini = pq.top().first;

        while(!pq.empty() && pq.top().first==mini){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};