#include <iostream>
using namespace std;

class node{
  public:
    int data;
    node* next;
    
    node(int val){
        data = val;
        next = NULL;
    }
};

node* reverse(node* head){
  node* prevptr = NULL;
  node* currentptr = head;
  node* nextptr;
  
  while(currentptr!=NULL){
    nextptr = currentptr->next;
    currentptr->next = prevptr;
    
    prevptr = currentptr;
    currentptr = nextptr;
  }
  return prevptr;
}

void display(node* head){
    node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    n->next = head;
    head = n;
}

void insertAtTail(node* &head, int val){
    node* n = new node(val);
    node* temp = head;
    
    if(head == NULL){
        head = n;
        return;
    }
    
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}

int main()
{
    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtHead(head, 0);
    display(head);
    node* rev = reverse(head);
    display(rev);
    return 0;
}
