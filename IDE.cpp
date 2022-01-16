#include <bits/stdc++.h>
#include "Hashing.h"
using namespace std;

// Hash fn for custom class
class student {
public:
    string firstName;
    string lastName;
    string rollNo;

    student(string f , string l , string r) {
        firstName = f;
        lastName = l;
        rollNo = r;
    }

    bool operator ==(const student &s) const {
        return rollNo == s.rollNo ? true : false;
    }
};

class hashFn {
public:
    size_t operator ()(const student &s) const {
        return s.firstName.size() + s.lastName.size();
    }
};
int main() {
    // hashTable<int> priceList;
    // priceList.insert("Burger" , 120);
    // priceList.insert("Pepsi" , 20);
    // priceList.insert("BurgerPizza" , 150);
    // priceList.insert("Noodles" , 125);
    // priceList.insert("Coke" , 200);
    // priceList.print();


    // int n;
    // cin >> n;
    // for (int i = 0 ; i < n ; i++) {
    //  string str;
    //  int val;
    //  cin >> str >> val;
    //  priceList.insert(str , val);
    // }
    // priceList.print();

    student s1("Prateek", "Narang", "010");
    student s2("Rahul", "Kumar", "023");
    student s3("Prateek", "Gupta", "030");
    student s4("Rahul", "Kumar", "120");
    unordered_map<student , int , hashFn> m;
    m[s1] = 100;
    m[s2] = 200;
    m[s3] = 300;
    m[s4] = 400;
    for (auto i : m) {
        cout << i.first.firstName << " " << i.first.lastName << " " << i.first.rollNo << " -> "  << i.second << endl;
    }

    cout <<  m[s3] << endl;
    if (m.count(s1)) {
        cout << m[s1] << endl;
    }



    // unordered_map<string , vector<string> > m;
    // m["rahul"].push_back("3939");
    // m["rahul"].push_back("1234");
    // m["mehta"].push_back("4567");
    // m["mehta"].push_back("9761");

    // for(auto p : m){
    //     cout << "Name " << p.first << " " << endl;
    //     for(auto i : p.second){
    //         cout << "Mobile No " << i  << endl;
    //     }
    //     cout << endl;
    // }

    // string name;
    // cin >> name;
    // if (m.count(name)) {
    //     for (string str : m[name]) {
    //         cout << str << endl;
    //     }
    // }
    // else {
    //     cout << "name is absent " << endl;
    // }



    return 0;
}