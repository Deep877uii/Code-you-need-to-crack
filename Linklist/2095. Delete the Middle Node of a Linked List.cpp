/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
int countlist(ListNode*head){
    int count = 0 ;
    ListNode*temp=head;
    while(temp){
        count++;
        temp=temp->next;
    }
    return count;
}
    ListNode* deleteMiddle(ListNode* head) {
        ListNode*temp = head;
        int len = countlist(head);
        int mid = len/2 ;
        if(head==NULL||head->next==NULL) return NULL;

        for(int i = 1 ; i<mid ; i++){
            temp=temp->next;

        }
        ListNode*deleteNode = temp->next;
        temp->next=temp->next->next ;
        delete deleteNode;
        return head;
    }
};
