#include <bits/stdc++.h>
using namespace std;
void swap(int *x , int *y) {
  int t = *x;
  *x = *y;
  *y = t;
}
void rotateWithourSTL(int a[][100] , int n ) {
  for (int i = 0 ; i < n ; i++){
    reverse(a[i] , a[i] + n);
  }
  for (int i = 0 ; i < n ; i++) {
    for (int j = 0 ; j < n ; j++) {
      if (i < j) {
        swap(&a[i][j] , &a[j][i]);
      }

    }
  }
  for (int i = 0 ; i < n ; i++) {
    for (int j = 0 ; j < n ; j++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
}
int main() {
  int arr[100][100];
  int n ;
  cin >> n ;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }
  // for(int i=0;i<n;i++){
  //   for(int j=0;j<n;j++){
  //     cout << arr[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  rotateWithourSTL(arr , n );
}
