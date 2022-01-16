#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n){
    if(n==0 || n==1){
        return false;
    }
    if(n==2){
        return true;
    }
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
int main() {
    int n;
    cin >> n;
    char a[n];
    cin >> a;
    int count =0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            string temp="";
            for(int k=i;k<=j;k++){
                temp+=a[k];
            }
            if(isPrime(stoi(temp))){
                count++;
                i=j;
                break;

            }

        }
    }
    cout << count << endl;

	return 0;
}
