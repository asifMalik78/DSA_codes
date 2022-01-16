// #include <iostream>
// #include <vector>
// using namespace std;
// class Students {
// public:
//     int marks;
//     string name;
// };
// vector<Students>v[101];
// void bucketSort(Students s[] , int n) {
//     for (int i = 0; i < n; i++) {
//         int m = s[i].marks;
//         v[m].push_back(s[i]);
//     }

//     for (int i = 100 ; i >= 0 ; i--) {
//         for (auto it = v[i].begin() ; it != v[i].end() ; it++) {
//             cout << it->name << " " << it->marks << endl;
//         }
//     }
// }

// int main() {
//     Students s[1000];
//     int n;
//     cin >> n;
//     for (int i = 0 ; i < n ; i++) {
//         cin >> s[i].name  >> s[i].marks;
//     }
//     bucketSort(s , n);
// }




// #include <bits/stdc++.h>
// using namespace std;
// bool isPrime(int n){
//     for(int i=2 ; i<=sqrt(n) ; i++){
//         if(n%i==0){
//             return false;
//         }
//     }
//     return true;
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int>v;
//     for(int i=0;i<n;i++){
//         int a;
//         cin >> a;
//         v.push_back(a);
//     }
//     for(int i=v.size()-1 ; i>=0 ;i--){
//         if(isPrime(v[i])){
//             v.erase(v.begin()+i);
//         }
//     }
//     cout << "[";
//     for(int i =0 ; i<v.size() ; i++){
//         if(i==v.size()-1){
//             cout << v[i];
//         }
//         else{
//             cout << v[i] << ", ";
//         }
//     }
//     cout << "]";
    
// }




#include <iostream>
using namespace std;
class node{
    public :
    int data;
    node *next;
    node(int d){
        data=d;
        next=NULL;
    }
};
void insertAtTail(node *&head , int data){
    if(head==NULL){
        head=new node(data);
        return;
    }
    node *temp=head;
    while(temp->next != NULL){
        temp=temp->next;
    }
    node *newnode=new node(data);
    temp->next=newnode;
}
void buildLL(node *&head){
    int n;
    cin >> n;
    while(n>0){
        int d;
        cin >> d;
        insertAtTail(head , d);
        n--;
    }
    return;
}
void evenAfterOdd(node *head){
    node *odd=head;
    node *even=head->next;
    node *evenStart=even;
    while(odd->next != NULL && even->next != NULL){
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }
    odd->next=evenStart;
    if(odd->next == NULL){
        even->next=NULL;
    }
    return;
}
void print(node *head){
    if(head==NULL){
        return;
    }
    cout << head->data << " ";
    print(head->next);
}
void removeDublicates(node *head){
    node *temp=head;
    node *dummy=temp;
    while(temp && temp->next){
        if(temp->data==temp->next->data){
            temp->next=temp->next->next;
        }
        else
        temp=temp->next;
    }
}
void insertAtHead(node *&head , int data){
    if(head==NULL){
        head=new node(data);
        return;
    }
  node *newnode=new node(data);
  newnode->next=head;
  head=newnode;  
}
int len(node *head){
    int cnt=0;
    while(head){
        cnt++;
        head=head->next;
    }
    return cnt;
}

int addHelper(node *head1 , int s1 , node *head2 , int s2 , node *&res){
    if(head1==NULL && head2==NULL){
        return 0;
    }
    int data=0;
     if(s1 > s2){
         int oc=addHelper(head1->next , s1-1 , head2 , s2 , res);
         data=head1->data+oc;
     }
     else if(s2 > s1){
         int oc=addHelper(head1 , s1 , head2->next , s2-1 , res);
         data=head2->data+oc;
     }
     else{
         int oc=addHelper(head1->next , s1-1 , head2->next , s2-1 , res);
         data=head1->data+head2->data+oc;
     }
     int number=data%10;
     int carry=data/10;
     insertAtHead(res , number);
     return carry;

}
node *addLL(node *head1 , node *head2){
    node *res=NULL;
    int size1=len(head1);
    int size2=len(head2);
    int a=addHelper(head1 , size1 , head2 , size2 , res);
    if(a != 0){
        insertAtHead(res ,a);
    }
    return res;
}
node *intersection(node *head1 , node *head2){
    node *res=NULL;
    while(head1 != NULL && head2 != NULL){
        if(head1->data==head2->data){
            insertAtTail(res , head1->data);
        }
        head1=head1->next;
        head2=head2->next;
    }
    return res;
}
node *helper(node *&head , int d){
    insertAtTail(head , d);
    return head;
}
node* findIntersection(node* head1, node* head2)
{
    node *res=NULL;
    while(head1 != NULL && head2 != NULL){
        if(head1->data==head2->data){
            insertAtTail(res , head1->data);
        }
        head1=head1->next;
        head2=head2->next;
        
    }
    res=helper()
    return res;
}
int main() {
    node *head=NULL;
    buildLL(head);
    node *head1=NULL;
    buildLL(head1);
    node *newhead=findIntersection(head , head1);
    print(newhead);
}

