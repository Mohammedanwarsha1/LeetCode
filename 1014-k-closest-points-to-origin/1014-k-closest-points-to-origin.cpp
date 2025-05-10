class Solution {
public:
    typedef pair<int,vector<int>>pi;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pi>pq;
        for(vector<int> v:points){
            int x=v[0],y=v[1];
            int distance=x*x + y*y;
            pi p={distance,v};
            pq.push(p);
            if(pq.size()>k) pq.pop();
        }
        
        vector<vector<int>>ans;
        while(pq.size()>0){
            vector<int> ele=pq.top().second;
            ans.push_back(ele);
            pq.pop();
        }
        return ans;
    }
};