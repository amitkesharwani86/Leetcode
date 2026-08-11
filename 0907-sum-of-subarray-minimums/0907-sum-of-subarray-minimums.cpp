class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long sum = 0;
        int MOD = 1e9 + 7;

        stack<int> st;

        for (int i = 0; i <= n; i++) {

            while (!st.empty() &&
                   (i == n || arr[st.top()] > arr[i])) {

                int mid = st.top();
                st.pop();

                int left;

                if (st.empty())
                    left = mid + 1;
                else
                    left = mid - st.top();

                int right = i - mid;

                sum = (sum +
                       1LL * arr[mid] * left * right) % MOD;
            }

            if (i < n)
                st.push(i);
        }

        return sum;
    }
};