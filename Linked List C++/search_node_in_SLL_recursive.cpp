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

Node *insert_the_end(Node *head, int n)
{
    Node *temp = new Node(n);
    if (head == NULL)
        return temp;

    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}

int search(Node *head, int x)
{
    if(head == NULL)return -1;
    if(head->data == x){
        return 1;
    }
    else{
        int res = search(head->next,x);
        if(res==-1)return -1;
        else return (res+1);
    }
}

void printlist(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    Node *head = NULL;
    head = insert_the_end(head, 10);
    head = insert_the_end(head, 20);
    head = insert_the_end(head, 30);
    printlist(head);
    cout << endl;
    cout << search(head, 20);
    return 0;
}