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

Node *delhead(Node *head){
    if(head==NULL)return NULL;
    else{
        Node *temp = head->next;
        delete(head);
        return temp;
    }

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
    head = delhead(head);
    printlist(head);
    return 0;
}