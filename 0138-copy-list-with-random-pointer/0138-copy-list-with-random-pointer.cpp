/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node * temp = head ;

        if(head==NULL) return NULL ;
        while(temp!=NULL){
            Node* copynode = new Node(temp->val);
            copynode->next=temp->next;
            temp->next=copynode;
            temp=temp->next->next;
        }
        temp=head;
        while(temp!=NULL){
           Node* copynode=temp->next ;
            if(temp->random!=NULL){
            copynode->random=temp->random->next;
            }
            else{
                copynode->random = NULL;
            }
            temp=temp->next->next;
        }
        temp=head;
        Node* dummynode = new Node(-1);
        Node* res = dummynode;

        while(temp!=NULL){
            Node* copynode = temp->next;
            temp->next = copynode->next;
            res->next =copynode;
            if(copynode->next)copynode->next = copynode->next->next;
            temp=temp->next ;
            res=res->next;
        }
        return dummynode->next;
    }
};