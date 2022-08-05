#include<bits/stdc++.h> 
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
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }
    Node *curr = head;
    while (curr->next->next != NULL)
    {
        curr = curr->next;
    }
    delete (curr->next);
    curr->next = NULL;
    return head;
}

Node *insertpos(Node *head,int pos,int data){
    Node *temp = new Node(data);
    if(pos==1){
        temp->next = head;
        return temp;
    }

    Node *curr = head;
    for(int i = 1;i<=pos-2 && curr!=NULL;i++){
        curr = curr->next;
    }
    if(curr==NULL)return head;
     temp->next = curr->next;
     curr->next = temp;
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
    head = insertpos(head,3,50);
    printlist(head);
    return 0;
}