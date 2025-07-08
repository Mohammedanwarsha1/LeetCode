class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prev(n);
        vector<int> next(n);
        vector<int> mini(n);

        prev[0] = -1;
        int maxH = height[0];
        for(int i = 1; i < n; i++) {
            prev[i] = maxH;
            if(maxH < height[i]) maxH = height[i];
        }

        next[n - 1] = -1;
        maxH = height[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            next[i] = maxH;
            if(maxH < height[i]) maxH = height[i];
        }

        for(int i = 0; i < n; i++) {
            mini[i] = min(prev[i], next[i]);
        }

        int water = 0;
        for(int i = 0; i < n; i++) {
            if(height[i] < mini[i]) {
                water += (mini[i] - height[i]);
            }
        }

        return water;
    }
};
