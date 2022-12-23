//Two stack is used in here.
//Traverse backwards to check node of intersection.
#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};
Node* head = new Node;
Node* second = new Node;
void create(int A[], int n){   //Linked list is created
    Node* temp;                 //Temporary variable is declared
    Node* tail;                 //tailing pointer is declared
    head->data = A[0];
    head->next = nullptr;       //Null is initialized
    tail = head;

    for (int i=1; i<n; i++){    //traversal of pointer in list
        temp = new Node;        //dynamic allocation of temporary ptr
        temp->data = A[i];
        temp->next = nullptr;
        tail->next = temp;
        tail = temp;
    }
}
void createSecond(int A[], int n, Node* p){         //new linked list is created which is to be inserted
    Node* temp;
    Node* tail;
    second->data = A[0];
    second->next = nullptr;
    tail = second;

    for (int i=1; i<n; i++){
        temp = new Node;
        temp->data = A[i];
        temp->next = nullptr;
        tail->next = temp;
        tail = temp;
    }
    tail->next = p;
}
void Intersection(Node* p, Node* q){        //using stack method to intersect both the list
    // Populate first stack
    stack<Node*> stk1;
    while (p != nullptr){
        stk1.push(p);
        p = p->next;
    }
    // Populate second stack
    stack<Node*> stk2;
    while (q != nullptr){
        stk2.push(q);
        q = q->next;
    }
    Node* r;
    while (stk1.top() == stk2.top()){       //top of the stack is compared
        r = stk1.top();
        stk1.pop();
        stk2.pop();
    }
    cout << "Intersecting Node: " << r->data << endl;
}
int main(){
    // Create First Linked List
    int A[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21};
    create(A, sizeof(A)/sizeof(A[0]));
    // Create Second Linked List
    Node* temp = head;
    int i = 5;
    while (i>0){
        temp = temp->next;
        i--;
    }
    cout << temp->data << endl;
    int B[] = {2, 4, 6, 8, 10};
    createSecond(B, sizeof(B)/sizeof(B[0]), temp);
    // Find Intersection
    Intersection(head, second);
    return 0;
}
