#include <bits/stdc++.h>
using namespace std;
// Return  subsequence of string
int subsequence(string input , string output[]) {
	if (input.empty()) {
		output[0] = "";
		return 1;
	}
	int smallSize = subsequence(input.substr(1) , output);
	for (int i = 0 ; i < smallSize; i++) {
		output[i + smallSize] = input[0] + output[i];
	}

	return 2 * smallSize;
}

// Return Keypad code
string dial[11] = {"" , "" , "abc" , "def" , "ghi" , "jkl" , "mno" , "pqrs" , "tuv" , "wxyz"};
void keypad(int num , string output){
	if(num==0){
		cout << output << endl;
		return ;
	}

	int lastDigit=num%10;
	int smallNumber=num/10;
	string str=dial[lastDigit];
	for(int i=0 ; i<str.size() ; i++){
		char ch=str[i];
		keypad(smallNumber , ch+output);
	}
}

int keypad(int num, string output[]) {

	if (num == 0) {
		output[0] = "";
		return 1;
	}

	int lastDigit = num % 10;
	int smallNumber = num / 10;
	string smallOutput[500];
	int smallSize = keypad(smallNumber , smallOutput);
	string op = dial[lastDigit];
	int k = 0;
	for (int i = 0 ; i < op.size() ; i++) {
		for (int j = 0; j < smallSize ; j++) {
			output[k] = smallOutput[j] + op[i];
			k++;
		}

	}

	return k;
}

// Return All the Subsets of an Array
int subsetHelper(int *input , int idx , int n , int output[][20]) {
	if (idx == n) {
		output[0][0] = 0;
		return 1;
	}

	int smallSize = subsetHelper(input , idx + 1 , n , output);
	for (int i = 0 ; i < smallSize ; i++) {
		output[i + smallSize][0] = output[i][0] + 1;
		output[i + smallSize][1] = input[idx];
		for (int j = 1; j <= output[i][0] ; j++) {
			output[i + smallSize][j + 1] = output[i][j];
		}

	}

	return 2 * smallSize;
}
int subset(int input[], int n, int output[][20]) {
	return subsetHelper(input , 0 , n , output);
}

// Print All the subsets of an Array
void printSubsetsOfArrayHelper(int *input, int idx , int size , int *output , int osize) {
	if (idx == size) {
		for (int i = 0 ; i < osize ; i++) {
			cout << output[i] << " ";
		}
		cout << endl;
		return;
	}

	int smallOutput[50];
	printSubsetsOfArrayHelper(input , idx + 1 , size , output , osize);
	int i = 0;
	for (i = 0 ; i < osize; i++) {
		smallOutput[i] = output[i];
	}
	smallOutput[i] = input[idx];
	printSubsetsOfArrayHelper(input , idx + 1 , size , smallOutput , osize + 1);
}

void printSubsetsOfArray(int input[], int size) {
	int output[1000];
	printSubsetsOfArrayHelper(input , 0 , size , output , 0);

}

// Return Subset Sum to K
int subsetSumToK(int input[], int n, int output[][50], int k) {
	if (n == 0) {
		if (k == 0) {
			output[0][0] = 0;
			return 1;
		}
		else {
			return 0;
		}
	}

	int smallOutput1[500][50], smallOutput2[500][50];
	int smallSize1 = subsetSumToK(input + 1 , n - 1 , smallOutput1 , k);
	int smallSize2 = subsetSumToK(input + 1 , n - 1 , smallOutput2 , k - input[0]);

	int row = 0;
	for (int i = 0; i < smallSize1 ; i++) {
		for (int j = 0 ; j <= smallOutput1[i][0] ; j++) {
			output[row][j] = smallOutput1[i][j];
		}
		row++;
	}

	for (int i = 0 ; i < smallSize2 ; i++) {
		output[row][0] = smallOutput2[i][0] + 1;
		output[row][1] = input[0];
		for (int j = 1 ; j <= smallOutput2[i][0] ; j++) {
			output[row][j + 1] = smallOutput2[i][j];
		}
		row++;
	}

	return row;

}
// Print subset sum to k
void printSubsetSumToKHelper(int *input , int n , int k , int *output , int osize) {
	if (n == 0) {
		if (k == 0) {
			for (int i = 0 ; i < osize ; i++) {
				cout << output[i] << " ";
			}
			cout << endl;
			return;
		}
		return;
	}

	printSubsetSumToKHelper(input + 1 , n - 1 , k , output , osize);
	// if(k>0){
	int smallOutput[500];
	int i;
	for (i = 0 ; i < osize ; i++) {
		smallOutput[i] = output[i];
	}
	smallOutput[i] = input[0];
	printSubsetSumToKHelper(input + 1 , n - 1 , k - input[0] , smallOutput , osize + 1);
	// }
	return;

}

void printSubsetSumToK(int input[], int size, int k) {
	int output[1000];
	printSubsetSumToKHelper(input , size , k , output , 0);
}


// Return All Codes of a string
int getCodes(string input, string output[10000]) {

	if (input.empty()) {
		output[0] = "";
		return 1;
	}
	string smallOutput1[500]; string smallOutput2[500];

	int first = input[0] - '0';
	char firstChar = first + 'a' - 1;
	char secondChar = '\0';
	int smallSize1 = getCodes(input.substr(1) , smallOutput1);
	int smallSize2 = 0;
	if (input[1] != '\0') {
		int second = input[1] - '0';
		int no = first * 10 + second;
		if (no >= 10  and no <= 26) {
			secondChar = no + 'a' - 1;
			smallSize2 = getCodes(input.substr(2) , smallOutput2);
		}

	}

	int k = 0;

	for (int i = 0 ; i < smallSize1 ; i++) {
		output[k] = firstChar + smallOutput1[i];
		k++;
	}

	for (int i = 0 ; i < smallSize2 ; i++) {
		output[k] = secondChar + smallOutput2[i];
		k++;
	}



	return k;
}

// Return All Permutation of a string
int returnPermutations(string input, string output[]) {
	if (input.empty()) {
		output[0] = "";
		return 1;
	}

	int size = 0;
	int k = 0;
	for (int i = 0 ; i < input.size() ; i++) {
		char ch = input[i];
		string smalloutput[1000];
		string ros = input.substr(0 , i) + input.substr(i + 1);
		size = returnPermutations(ros , smalloutput);
		for (int i = 0 ; i < size ; i++) {
			output[k++] = ch + smalloutput[i];
		}
	}
	return k;
}
// parenthesis

void generate(string &str , int open , int close , vector<string>&ans){
	if(open==0 and close==0){
		ans.push_back(str);
		return;
	}

	if(open > 0){
		str.push_back('(');
		generate(str , open-1 , close , ans);
		str.pop_back();
	}


	if(close > 0){
		if(open < close){
			str.push_back(')');
			generate(str , open , close-1 , ans);
			str.pop_back();
		}
	}
}
int main() {
	// string str;
	// cin >> str;
	// string *output = new string[1000];
	// int cnt = subsequence(str , output);
	// for (int i = 0 ; i < cnt ; i++) {
	// 	cout << output[i] << endl;
	// }
	// cout << endl << endl;
	// int n;
	// cin >> n;
	// string *ou = new string[1000];
	// int size = keypad(n , ou);
	// for (int i = 0; i < size; ++i)
	// {
	// 	cout << ou[i] << endl;
	// }

	// cout << endl << endl;
	// int arr[100];
	// int out[3500][20];
	// int m;
	// cin >> m;
	// for (int i = 0 ; i < m ; i++) {
	// 	cin >> arr[i];
	// }

	// int count = subset(arr , m , out);
	// for (int i = 0 ; i < count ; i++) {
	// 	for (int j = 1 ; j <= out[i][0] ; j++) {
	// 		cout << out[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	// int n;
	// cin >> n;
	// int arr[n];
	// for(int i=0 ; i<n ; i++){
	// 	cin >> arr[i];
	// }
	// printSubsetsOfArray(arr , n);

	// int input[20], length, output[10000][50], k;
	// cin >> length;
	// for (int i = 0; i < length; i++)
	// 	cin >> input[i];

	// cin >> k;

	// int size = subsetSumToK(input, length, output, k);

	// for ( int i = 0; i < size; i++) {
	// 	for ( int j = 1; j <= output[i][0]; j++) {
	// 		cout << output[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

 //    vector<string>ans;
 //    string str;
	// generate(str , 3 , 3 , ans);
	// for(auto i : ans){
	// 	cout << i << endl;
	// }

	string abc[1000];
	int d=getCodes("223" , abc);
	cout << abc << endl;
}