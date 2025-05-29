#define ll long long int
class Solution {
public:
    ll minTaps(int n, vector<int>& ranges) {
        if (ranges.size() != n + 1) return -1; // Defensive check

        vector<ll> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (ll i = 0; i <= n; i++) {
            ll start = max((ll)0, i - ranges[i]);
            ll end = min((ll)n, i + ranges[i]);
            for (ll j = start; j <= end; j++) {
                if (dp[start] != INT_MAX)
                    dp[j] = min(dp[j], dp[start] + 1);
            }
        }

        return dp[n] == INT_MAX ? -1 : dp[n];
    }
};
