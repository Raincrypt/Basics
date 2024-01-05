#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void printLinkedList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int totalElements(Node *head)
{
    int count = 0;

    while (head != NULL)
    {
        count++;
        head = head->next;
    }

    return count;
}

void insertAtHead(int val, Node *&head)
{
    Node *new_node = new Node(val);

    if (head != NULL)
        new_node->next = head;

    head = new_node;
}

void insertAtTail(int val, Node *&head)
{
    Node *new_node = new Node(val);
    Node *temp = head;

    if (head == NULL)
    {
        head = new_node;
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = new_node;
}

void insertInBettween(int val, int pos, Node *head)
{
    Node *new_node = new Node(val);
    // If the linked list is empty or we want to add at the beginning.
    if (!head || pos == 1)
    {
        insertAtHead(val, head);
        return;
    }

    int total_elements = totalElements(head);

    if (abs(pos) > total_elements)
    {
        cout << "The given position is out of range." << endl;
        return;
    }

    pos = pos < 0 ? total_elements + pos : pos;

    Node *current = head;
    for (int i = 1; i < pos; i++)
    {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
}

void deleteHead(Node *&head)
{
    if (!head)
        return;

    Node *toDelete = head;
    head = head->next;
    delete toDelete;
}

void deleteNode(int val, Node *&head)
{
    if (head->data == val)
    {
        deleteHead(head);
        return;
    }

    Node *curr = head;

    while (curr != NULL)
    {
        Node *prev = curr;
        curr = curr->next;
        if (curr->data == val)
        {
            prev->next = curr->next;
            delete curr; // to remove the node from memory
            return;
        }
    }

    cout << "Element not Found." << endl;
}

int search(int key, Node *head)
{
    int pos = 0;

    while (head != NULL)
    {
        if (head->data == key)
        {
            return pos;
        }
        pos++;
        head = head->next;
    }

    return -1; // Key not found in the list.
}

void reverse(Node *&head)
{
    // Initialize a new reversed head, and one linked list to store reversed linked list from previous iteration.
    Node *new_head = nullptr, *store = nullptr;
    while (head)
    {
        // Get one head
        new_head = head;
        // Update the head to next node
        head = head->next;
        
        // Change the next to our stored linked list
        new_head->next = store;
        // Update the stored linked list
        store = new_head;
    }
    head = new_head;
}

Node *reverse_recursion(Node *&head)
{

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *new_head = reverse_recursion(head->next);
    head->next->next = head;
    head->next = NULL;
    return new_head;
}

int main()
{
    Node *head = NULL;

    Node *new_node = new Node(1);

    head = new_node;

    insertAtTail(20, head);
    insertAtTail(30, head);
    insertAtTail(40, head);
    insertAtHead(0, head);

    insertInBettween(35, -1, head);

    printLinkedList(head);
    cout << "Total Elements: " << totalElements(head) << endl;
    cout << "30 is in Position: " << search(30, head) << endl;

    deleteNode(35, head);
    printLinkedList(head);

    cout << "Reverse: " << endl;
    reverse(head);
    printLinkedList(head);

    cout << "Reverse Recursion: " << endl;
    printLinkedList(reverse_recursion(head));

    return 0;
}
