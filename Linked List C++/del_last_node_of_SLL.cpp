#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *insert_the_begin(Node *head, int n)
{
    Node *temp = new Node(n);
    temp->next = head;
    return temp;
}

Node *dellast(Node *head)
{
    if (head == NULL)return NULL;
    if(head->next==NULL){
        delete head;
        return NULL;
    }
    Node *curr = head;
    while(curr->next->next != NULL){
        curr = curr->next;
    }
        delete (curr->next);
        curr->next = NULL;
        return head;
    
}

void printlist(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    head = insert_the_begin(head, 10);
    head = insert_the_begin(head, 20);
    head = insert_the_begin(head, 30);
    printlist(head);
    head = dellast(head);
    printlist(head);
    return 0;
}