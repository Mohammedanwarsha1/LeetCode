class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited;
        queue<int> q;
        q.push(0);
        visited.insert(0);
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(int neighbor:rooms[curr]){
                if(visited.count(neighbor)==0){
                     q.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }
        return visited.size()==rooms.size();
    }
};