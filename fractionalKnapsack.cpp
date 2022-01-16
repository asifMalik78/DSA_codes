#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int , int>p1 , pair<int , int>p2) {
    double v1 = (double)p1.first / (double) p1.second;
    double v2 = (double)p2.first / (double) p2.second;
    return v1 > v2;
}
double fractionalKnapsack(vector<pair<int , int>>&v , int cap) {
    sort(v.begin() , v.end() , cmp);
    int currentWt = 0;
    double finalVal = 0.0;
    for (int i = 0 ; i < v.size() ; i++) {
        if (currentWt + v[i].second <= cap) {
            currentWt += v[i].second;
            finalVal += v[i].first;
        }
        else {
            int rem = cap - currentWt;
            finalVal += (double)(v[i].first / (double)currentWt * (double) rem);
            break;
        }
    }
    
    return finalVal;
}
int main() {
    int n;
    cin >> n;
    vector<pair<int , int>>v;
    int arr[n];
    for (int i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }

    int wt[n];
    for (int i = 0 ; i < n ; i++) {
        cin >> wt[i];
    }

    for (int i = 0 ; i < n ; i++) {
        v.push_back({arr[i] , wt[i]});
    }

    int cap;
    cin >> cap;

    // for(auto i : v){
    //     cout << i.first << " " << i.second << endl;
    // }
    double ans=fractionalKnapsack(v , cap);
    cout << ans << endl;
}