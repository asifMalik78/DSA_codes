//Sum of all submatrix from a given matrix (brute force approach)
#include <bits/stdc++.h>
using namespace std;
void sumOfASubMatrixAp1() {
    int n;
    cin >> n ;
    int a[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int sum = 0;
    for (int li = 0; li < n; li++) {
        for (int lj = 0; lj < n; lj++) {
            for (int bi = li; bi < n; bi++) {
                for (int bj = lj; bj < n; bj++) {
                    for (int i = li; i <= bi; i++) {
                        for (int j = lj; j <= bj; j++) {
                            sum += a[i][j];
                        }
                    }
                }
            }
        }
    }

    cout <<  sum << endl;

}
void sumOfASubMatrixAp2() {
    int n;
    cin >> n;
    int arr[n][n];
    int csum_arr[n][n];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j == 0) csum_arr[i][j] = arr[i][j];
            else csum_arr[i][j] = arr[i][j] + csum_arr[i][j - 1];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j == 0) csum_arr[j][i] = csum_arr[j][i];
            else csum_arr[j][i] = csum_arr[j][i] + csum_arr[j - 1][i];
        }
    }
    for (int x1 = 0; x1 < n; ++x1) {
        for (int y1 = 0; y1 < n; ++y1) {
            for (int x2 = x1; x2 < n; ++x2) {
                for (int y2 = y1; y2 < n; ++y2) {
                    int p = 0, q = 0, r = 0;
                    if (x1 == 0 && y1 == 0) {
                        p = 0; q = 0; r = 0;
                    } else if (x1 == 0) {
                        p = 0;
                        q = csum_arr[x2][y1 - 1];
                        r = 0;
                    } else if (y1 == 0) {
                        p = csum_arr[x1 - 1][y2];
                        q = 0;
                        r = 0;
                    } else {
                        p = csum_arr[x1 - 1][y2];
                        q = csum_arr[x2][y1 - 1];
                        r = csum_arr[x1 - 1][y1 - 1];
                    }
                    sum += csum_arr[x2][y2] - p - q + r;
                }
            }
        }
    }
    cout << sum << endl;
}
void sumOfASubMatrixAp3() {
    int n , m;
    cin >> n >> m;
    int a[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int tl = (i + 1) * (j + 1);
            int br = (n - i) * (m - j);
            sum += tl * br * a[i][j];
        }
    }
    cout << sum << endl;
}
void maximumSumSubMatrix() {
    int n , m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for(int i=n-1;i>=0;i--){
        for(int j=m-2;j>=0;j--){
            a[i][j]+=a[i][j+1];
        }
    }
    for(int i=m-1;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            a[j][i]+=a[j+1][i];
        }
    }
    int maxSum=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            maxSum=max(maxSum , a[i][j]);
        }
    }
    cout << maxSum << endl;
}
void searchingInMatrix(){
    int n , m;
    cin >> n >> m;
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }
    int key;
    cin >> key;
    int i=n-1;
    int j=n-1;
    bool find=false;
    while( i>=0 && j>=0){
         if(a[i][j] == key){
            find=true;
            break;
         }
         if(a[i][j] > key){
            j--;
         }else{
            i++;
         }
    }
    if(find){
        cout << "PRESENT" << endl;
    }else{
        cout << "ABSENT" << endl;
    }
}
int main() {
    searchingInMatrix();
    return 0;
}