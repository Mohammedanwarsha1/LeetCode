//sort based on end time
bool cmp(vector<int> &a,vector<int> &b){
    return a[1] < b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int ans=0;
        int lastEndTime=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<lastEndTime){
                ans++;
            }
            else{
                lastEndTime=intervals[i][1];
            }
        }
        return ans;
    }
};

//sort based on start time
// bool cmp(vector<int> &a,vector<int> &b){
//     return a[0] < b[0];
// }
// class Solution {
// public:
//     int eraseOverlapIntervals(vector<vector<int>>& intervals) {
//         sort(intervals.begin(),intervals.end(),cmp);
//         int ans=0;
//         int lastEndTime=intervals[0][1];
//         for(int i=1;i<intervals.size();i++){
//             if(intervals[i][0]<lastEndTime){
//                 ans++;
//                 lastEndTime=min(lastEndTime,intervals[i][1]);
//             }
//             else{
//                 lastEndTime=intervals[i][1];
//             }
//         }
//         return ans;
//     }
// };