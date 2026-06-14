#include <iostream>
using namespace std;
#include <vector>

class Node
{
    public:
    int data;
    Node*next;
    Node*back;
   
 //constructor
    public:
    Node(int data1,Node*next1=NULL,Node*back1=NULL)
    {
        data=data1;
        next=next1;
        back=back1;
    }
    // public:
    // Node(int data1)
    // {
    //     data =data1;
    //     next=NULL;
    //     back=NULL;
    // }
};

// function to convert array to doubly linked list
    Node* convertarrdll(vector<int> arr)
    {
      Node* head = new Node(arr[0]);
      Node*prev = head ; 
      for(int i = 1 ; i<arr.size();i++){
        Node*temp = new Node(arr[i],NULL,prev);
        prev->next = temp;
        temp->back = prev;
        prev = temp;
      }
      return head;
    }
// function to delete the tail of the doubly linked list
Node * deletetail(Node*head){
    if(head==NULL){
        return NULL;
    }

    Node*temp = head ;

    while(temp){
        temp=temp->next;
    }
    Node*prev = temp->back;
    prev->next = NULL;
    delete temp;
    return head;
}
void print(Node* head)// function to print the doubly linked list
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

// function to delete the kth node of the doubly linked list
Node *delete_kth (Node*head,int k ){

    if(head==NULL){
        return NULL;
    }
    int count = 0 ;
    Node*temp = head ;
    while(temp){
        count++;
        if(count==k) break;
        temp=temp->next;
    }
    Node*prev = temp->back;
    Node*front = temp->next;
    
    if(prev==NULL && front ==NULL){
        delete temp;
        return NULL;
    }
    else if(prev==NULL){
        front->back = NULL;
        head = front ;
        delete temp;
        return head;
    }
    else if(front == NULL){
        prev->next = NULL;
        delete temp;
        return head;
    }
    else{
        prev->next = front ;
        front->back = prev ;
        delete temp;
        return head;

    }
}

// function to delete a given node of the doubly linked list
Node* delete_Node(Node*temp){
    Node*prev =temp->back;
    Node*front=temp->next;
    if(front==NULL){
        prev->next = nullptr;        
        temp->back =nullptr;
        delete temp;
        return temp;
    }

    prev->next=front;
    front->back=prev;
    temp->next = nullptr;
    temp->back = nullptr;
    free(temp); 
}
// main function
int main()
{
    vector<int> arr={1,2,3,4,5};
    Node* head=convertarrdll(arr);
    head=deletetail(head);
    head=delete_kth(head,3);
    head =delete_Node(head->next);
    print(head);
    return 0 ;
}
