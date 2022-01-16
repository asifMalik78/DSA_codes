i#include <iostream>
using namespace std;
class node {
public :
    int data;
    node *next;
    node(int d) {
        data = d;
        next = NULL;
    }
};
void insertAtHead(node *&head , int data) {
    node *newnode = new node(data);
    if (head == NULL) {
        head = newnode;
        return ;
    }
    newnode->next = head;
    head = newnode;
}
int len(node *head) {
    int cnt = 0;
    while (head != NULL) {
        cnt++;
        head = head->next;
    }
    return cnt;
}
void insertAtTail(node *head , int data) {
    if (head == NULL) {
        head = new node(data);
        return;
    }
    node *newnode = new node(data);
    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;

}
void insertAtPosition(node *&head , int data , int p) {
    if (head == NULL or p == 1) {
        insertAtHead(head , data);
        return;
    }
    else if (p > len(head)) {
        insertAtTail(head , data);
    }
    else {
        int i = 1;
        node *newnode = new node(data);
        node *temp = head;
        while (i < (p - 1)) {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }

}
void display(node *head) {
    while (head != NULL) {
        cout << head->data << "-> " ;
        head = head->next;
    }
    cout << "END" << endl;
}
void deleteAtHead(node *&head) {
    if (head == NULL) {
        cout << "Nothing to delete" << endl;
        return ;
    }
    node *temp = head;
    head = head->next;
    delete temp;
}
void deleteAtPosition(node *&head , int p) {
    if (head == NULL) {
        cout << "Nothing to delete" << endl;
        return ;
    }
    if (p > len(head)) {
        cout << "invalid position" << endl;
        return;
    }
    if (p == 1) {
        deleteAtHead(head);
    }
    else {
        node *temp = head;
        node *nextNode = head->next;
        int jump = 1;
        while (jump < (p - 1)) {
            nextNode = nextNode->next;
            temp = temp->next;
            jump++;
        }
        cout << "deleted data is -> " << nextNode->data << endl;
        temp->next = nextNode->next;
        delete nextNode;
    }
}

bool search(node *head , int key) {
    if (head == NULL) {
        return false;
    }
    node *temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

bool searchRec(node *head , int key) {
    if (head == NULL) {
        return false;
    }
    if (head->data == key) {
        return true;
    }
    return searchRec(head->next , key);
}

node* reverseLL(node *head) {
    if (head == NULL) {
        cout << "Nothing to reverse" << endl;
        return head;
    }
    node *prevN = NULL;
    node *currentN = head;
    node *nextN;
    while (currentN != NULL) {
        nextN = currentN->next;
        currentN->next = prevN;
        prevN = currentN;
        currentN = nextN;
    }
    return prevN;
}

node * reverseRec(node *head) {
    if (head->next == NULL or head == NULL) {
        return head;
    }

    node *sHead = reverseRec(head->next);
    node *temp = sHead;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    head->next = NULL;
    temp->next = head;
    return sHead;
}

void removeDublicates(node *head) {
    node *temp = head;
    while (temp && temp->next) {
        if (temp->data == temp->next->data) {
            temp->next = temp->next->next;
        }
        else
            temp = temp->next;
    }
}

node * reverseRecOptimized(node *head) {
    if (head->next == NULL or head == NULL) {
        return head;
    }

    node *sHead = reverseRec(head->next);
    node *temp = head->next;
    head->next = NULL;
    temp->next = head;
    return sHead;
}

node * midpoint(node *head) {
    if (head == NULL  or head->next == NULL) {
        return head;
    }
    node *slowPtr = head;
    node *fastPtr = head->next;
    while (fastPtr != NULL && fastPtr->next != NULL) {
        fastPtr = fastPtr->next->next;
        slowPtr = slowPtr->next;
    }
    return slowPtr;
}

node *merge(node *a , node *b) {
    if (a == NULL) {
        return b;
    }

    if (b == NULL) {
        return a;
    }

    node *c;

    if (a->data <= b->data) {
        c = a;
        c->next = merge(a->next , b);
    }
    else {
        c = b;
        c->next = merge(a , b->next);
    }

    return c;
}

void insert(node *&head , node *newnode) {
    node *current = head;
    if (head == NULL or head->data >= newnode->data) {
        newnode->next = head;
        head = newnode;
    }
    else {
        while (current->next and current->next->data < newnode->data) {
            current = current->next;
        }
        newnode->next = current->next;
        current->next = newnode;
    }

}
void insertionSort(node *&head) {
    node *current = head;
    node *ans = NULL;
    while (current) {
        node *next = current->next;
        insert(ans , current);
        current = next;
    }

    head = ans;
}
node * insertionSortList(node *head) {
    if (head == NULL or head->next == NULL) {
        return head;
    }
    insertionSort(head);
    return head;
}




node *mergeSort(node *head) {
    if (head == NULL or head->next == NULL) {
        return head;
    }
    node *mid = midpoint(head);
    node *a = head;
    node *b = mid->next;
    mid->next = NULL;


    a = mergeSort(a);
    b = mergeSort(b);

    node *c = merge(a , b);

    return c;


}

node *kthNode(node *head , int k) {
    if (head == NULL or head->next == NULL) {
        return head;
    }
    node *fast = head;
    node *slow = head;
    int i = 1;
    while (i <= k) {
        fast = fast->next;
        i++;
    }
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}
node *take_input(node *&head) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        insertAtHead(head , a);
    }
    return head;
}

bool detectCycle(node *head) {
    node *slow = head;
    node *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

void makeCycle(node *head) {
    node *temp = head;
    node *ptr = head;
    int i = 1;
    while (temp->next != NULL) {
        if (i == 3) {
            ptr = temp;
        }
        i++;
        temp = temp->next;
    }
    temp->next = ptr;
}

void breakCycle(node *head) {
    node *slow = head;
    node *fast = head;
    do {
        slow = slow->next;
        fast = fast->next->next;
    }
    while (slow != fast);
    slow = head;
    while (fast->next != slow->next) {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;
}

ostream& operator<<(ostream &os , node *head) {
    display(head);
    return os;
}
istream& operator>>(istream &is , node *&head) {
    head = take_input(head);
    return is;
}


void buildLL(node *&head) {
    int n;
    cin >> n;
    while (n > 0) {
        int d;
        cin >> d;
        insertAtTail(head , d);
        n--;
    }
    return;
}
int main() {
    // node *head = NULL;
    // insertAtHead(head , 5);
    // insertAtHead(head , 2);
    // insertAtHead(head , 1);
    // insertAtHead(head , 0);
    // insertAtPosition(head , 4 , 3);
    // insertAtTail(head , 7);
    // display(head);
    // deleteAtHead(head);
    // display(head);
    // deleteAtPosition(head , 4);
    // display(head);
    // deleteAtPosition(head , 10);
    // display(head);
    // cout << searchRec(head , 7) << endl;
    // cout << head;
    // cout << endl;
    // node *head2 = reverseRecOptimized(head);
    // cout << head2;
    // node *d = midpoint(head);
    // cout << d->data << endl;
    node *head = NULL;
    cin >> head;
    cout << head << endl;
    makeCycle(head);
    cout << detectCycle(head) << endl;
    breakCycle(head);
    cout << detectCycle(head) << endl;
    cout << head;
    // node *h=mergeSort(head);
    // cout << h << endl;


}