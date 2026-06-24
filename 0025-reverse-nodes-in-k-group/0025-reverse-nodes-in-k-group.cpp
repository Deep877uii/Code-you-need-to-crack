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

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr) {
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        return prev;
    }

    ListNode* find_k_node(ListNode* head, int k) {

        ListNode* temp = head;
        k--;

        while(temp != NULL && k > 0){
            temp = temp->next;
            k--;
        }

        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp = head;
        ListNode* prevnode = NULL;

        while(temp != NULL){

            ListNode* kNode = find_k_node(temp, k);

            if(kNode == NULL){
                if(prevnode){
                    prevnode->next = temp;
                }
                break;
            }

            ListNode* nextNode = kNode->next;

            kNode->next = NULL;

            ListNode* newHead = reverseList(temp);

            if(temp == head){
                head = newHead;
            }
            else{
                prevnode->next = newHead;
            }

            prevnode = temp;
            temp = nextNode;
        }

        return head;
    }
};