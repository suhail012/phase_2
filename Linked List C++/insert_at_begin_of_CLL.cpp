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

Node *insertBegin(Node *head, int x)//naive approach
{
    Node *temp = new Node(x);
    if (head == NULL)
        temp->next = temp;
    else
    {
        Node *curr = head;
        while (curr->next != head)
            curr = curr->next;
        curr->next = temp;
        temp->next = head;
    }
    return temp;
}

Node *insertbegin_eff(Node *head,int x){//efficient approach
    Node *temp = new Node(x);
    if(head==NULL){
        temp->next = temp;
        return temp;
    }
    else{
        temp->next = head->next;
        head->next = temp;
        int t = head->data;
        head->data = temp->data;
        temp->data = t;
        return head;
    }
}

int main()
{
    Node *head = insertBegin(head,10);
    head = insertBegin(head, 15);
    printlist(head);
    cout << endl;
    head = insertbegin_eff(head,69);
    head = insertbegin_eff(head,96);
    printlist(head);
    return 0;
}
