// #include <bits/stdc++.h>
// using namespace std;
// int addition(int b ,int n1 , int n2){
// 	int result =0;
// 	int carry=0;
// 	int i=1;
// 	while(n1 > 0 || n2 >0 || carry > 0){
// 		int num1=n1%10;
// 		int num2=n2%10;
// 		int d=num1+num2+carry;
// 		carry=d/b;
// 		d=d%b;
// 		result+=d*i;
// 		i*=10;
// 		n1/=10;
// 		n2/=10;
// 	}
// 	return result;
// }
// int multiplicationHelper(int b , int n1 , int b2){
//     int result=0;
//     int carry=0;
//     int i=1;
//     while(n1 > 0 || carry > 0){
//     	int numb=n1%10;
//     	int d=numb*b2+carry;
//     	carry=d/b;
//     	d=d%b;
//     	result+=d*i;
//     	i*=10;
//     	n1/=10;
//     }
//     return result;
// }
// int multiplication(int b , int n1 , int n2){
// 	int result=0;
// 	int i=1;
// 	while(n2 > 0){
// 	int b2=n2%10;
// 	int smallAns=multiplicationHelper(b , n1 , b2);
// 	smallAns=smallAns*i;
// 	result=addition(b ,result , smallAns);
// 	i*=10;
// 	n2/=10;
// }
// return result;

// }
// int main() {
// 	int  b , n1 , n2;
// 	cin >> b>> n1 >> n2;
// 	cout << multiplication(b , n1 , n2);

// 	return 0;
// }
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n1;
    cin >> n1;
    int *arr1=new int[n1];
    for(int i=0;i<n1;i++){
        cin >> arr1[i];
    }
    int n2;
    cin >> n2;
    int *arr2=new int[n2];
    for(int i=0;i<n2;i++){
        cin >> arr2[i];
    }
    int result[n2];
    int i=n1-1;
    int j=n2-1;
    int carry=0;
    int k=n2-1;
    while(j>=0){
        int d=arr2[j]+carry;
        int ans=0;
        int a1value=(i>0)?arr1[i] : 0;
        if(d >=a1value){
           carry=0;
           ans=arr2[j]-a1value;
        }
        else{
            carry=-1;
            ans=d+10-a1value;
        }
        result[k]=ans;
        j--;
        k--;
    }
    int idx=0;
    while(result[idx]==0){
        idx++;
    }
    for(int i=idx;i<n2;i++){
    	cout << result[i] << endl;
    }
    
}