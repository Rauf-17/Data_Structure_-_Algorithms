
#include <iostream>
#include <climits>
using namespace std;


struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};


struct Node* head = NULL;


void insertAtBeginning(int new_data)
{

    struct Node* new_node = new Node;


    new_node->data = new_data;


    new_node->next = head;
    new_node->prev = NULL;


    if (head != NULL)
        head->prev = new_node;


    head = new_node;
}


void insertAtEnd(int new_data)
{

    struct Node* new_node = new Node;

    struct Node* last = head;


    new_node->data = new_data;


    new_node->next = NULL;


    if (head == NULL)
    {
        new_node->prev = NULL;
        head = new_node;
        return;
    }


    while (last->next != NULL)
        last = last->next;


    last->next = new_node;


    new_node->prev = last;

    return;
}


void printList(struct Node* node)
{
    struct Node* last;
    cout << "In Order : "<<" ";
    while (node != NULL)
    {
        cout << " " << node->data << " ";
        last = node;
        node = node->next;
    }
    cout<<endl;
    cout << "Reverse Order :"<<" ";
    while (last != NULL)
    {
        cout << " " << last->data << " ";
        last = last->prev;
    }
}


void deleteNode(struct Node* del)
{

    if (head == NULL || del == NULL)
        return;


    if (head == del)
        head = del->next;


    if (del->next != NULL)
        del->next->prev = del->prev;


    if (del->prev != NULL)
        del->prev->next = del->next;

    free(del);
    return;
}


int findMax()
{
    int max = INT_MIN;
    struct Node* temp = head;

    while (temp != NULL)
    {
        if (temp->data > max)
            max = temp->data;
        temp = temp->next;
    }
    return max;
}


int findMin()
{
    int min = INT_MAX;
    struct Node* temp = head;

    while (temp != NULL)
    {
        if (temp->data < min)
            min = temp->data;
        temp = temp->next;
    }
    return min;
}


int main()
{

    insertAtEnd(6);


    insertAtBeginning(7);


    insertAtBeginning(1);


    insertAtEnd(4);

    insertAtEnd(8);


    printList(head);

   cout<<endl;

    cout << "\nMax Node is : " << findMax();


    cout << "\nMin Node is : " << findMin();

    return 0;
}
