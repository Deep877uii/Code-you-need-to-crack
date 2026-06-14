#include <iostream>
using namespace std;
#include <vector>

class Node
{
    public:
    int data;
    Node*next;
    Node*back;
   

    public:
    Node(int data1,Node*next1=NULL,Node*back1=NULL)
    {
        data=data1;
        next=next1;
        back=back1;
    }
};
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
void print(Node* head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main()
{
    vector<int> arr={1,2,3,4,5};
    Node* head=convertarrdll(arr);
    print(head);
    head=deletetail(head);
    print(head);
    return 0 ;
}