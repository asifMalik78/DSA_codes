#include <bits/stdc++.h>
using namespace std;
// maximum subarray of size k
void max_Sum(int *arr , int n , int k) {
    int currentSum = 0;
    int maxSum = 0;
    int start = 0;
    for (int i = 0 ; i < n ; i++) {
        currentSum += arr[i];
        if (i - start + 1 == k) {
            maxSum = max(maxSum , currentSum);
            currentSum -= arr[start];
            start++;
        }
    }
    cout << maxSum << endl;
}
// first -ve number in every window of size k
void negativeNum(int *arr , int n , int k) {
    vector<int> v;
    int start = 0;
    for (int i = 0 ; i < n ; i++) {
        if (arr[i] < 0) {
            v.push_back(arr[i]);
        }

        if (i - start + 1 == k) {
            if (v.size() == 0) {
                cout << "0" << " ";
            }
            else if (arr[start] >= 0) {
                cout << v[0] << " ";
            }
            else {
                cout << v[0] << " ";
                v.erase(v.begin());
            }
            start++;
        }
    }
}
// sliding window maximum
void slidingWindow(int *arr , int n , int k) {
    deque<int>dq;
    vector<int>ans;
    for (int i = 0 ; i < k ; i++) {
        while (!dq.empty() and arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    for (int i = k ; i < n ; i++) {
        ans.push_back(arr[dq.front()]);
        while (!dq.empty() and dq.front() <= i - k) {
            dq.pop_front();
        }

        while (!dq.empty() and arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }
        dq.push_back(i);

    }
    ans.push_back(arr[dq.front()]);
    for (auto i : ans) {
        cout << i << " ";
    }

}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }
        int k;
        cin >> k;
        // max_Sum(arr , n , k);
        negativeNum(arr , n , k);
        // slidingWindow(arr , n , k);
        cout << endl;
    }

}
