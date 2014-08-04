//***********************************************************
//Linked List Reverser
//Programmed By: Britton Kjenner
//-This program will reverse a linked list of integers,
//it uses a recursive algorithm, so it is not to be used with
//very large lists
//***********************************************************
#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
    int data;
    node *next;
};

node* reverse(node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    node* revList = reverse(head->next);

    head->next->next = head;
    head->next = NULL;

    return revList;
}

//Non-Recursive version
node* reverse2(node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    node* remaining = head;
    node* reversed = NULL;
    
    while (remaining != NULL){
        node* temp = remaining;
        remaining = remaining->next;
        temp->next = reversed;
        reversed = temp;
    }

    return reversed;
}

int main()
{
    int numbers[5] = {7, 13, 31, 28, 66};
    node *head = NULL;
    for (int i=0; i < 5; i++){
        node *temp;
        temp = (node*)malloc(sizeof(node));
        temp->data = numbers[i];
        temp->next = head;
        head = temp; 
    }
     
    cout << "Starting List: ";
    node *current = head;
    while(current != NULL){
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    cout << "Reversed List: ";
    current = reverse(head);
    while (current != NULL){
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}
