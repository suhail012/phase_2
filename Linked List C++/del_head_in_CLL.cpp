#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

void printlist(Node *head)
{
    if (head == NULL)
        return;
    Node *p = head;
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != head);
}

Node *insertEnd(Node *head, int x) // naive approach
{
    Node *temp = new Node(x);
    if (head == NULL)
    {
        temp->next = temp;
        return temp;
    }
    else
    {
        Node *curr = head;
        while (curr->next != head)
            curr = curr->next;
        curr->next = temp;
        temp->next = head;
        return head;
    }
}

Node *insertEnd_eff(Node *head, int x)
{
    Node *temp = new Node(x);
    if (head == NULL)
    {
        temp->next = temp;
        return temp;
    }
    else
    {
        temp->next = head->next;
        head->next = temp;
        int t = temp->data;
        temp->data = head->data;
        head->data = t;
        return temp;
    }
}

Node *delhead(Node *head){
    if(head==NULL)return NULL;
    if(head->next == head){
        delete head;
        return NULL;
    }

    Node *curr = head;
    while(curr->next != head){
        curr = curr->next;
    }
    curr->next = head->next;
    delete head;
    return curr->next;
}

Node *delhead_eff(Node *head){
    if(head==NULL)return NULL;
    if(head->next == head){
        delete head;
        return NULL;
    }

    head->data = head->next->data;
    Node *temp = head->next;
    head->next = head->next->next;
    delete temp;
    return head;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = head;
    head = insertEnd(head, 15);
    head = insertEnd_eff(head, 25);
    head = insertEnd_eff(head, 30);
    printlist(head);
    cout<<endl;
    head = delhead(head);
    head = delhead_eff(head);
    printlist(head);
    return 0;
}
