/* reveseion of singlylinked list

#include<bits/stdc++.h>
using namespace std;
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    while(head==NULL|| head->next==NULL){
        return head;
    }
    LinkedListNode<int>* prev=NULL;
    LinkedListNode<int>* curr=head;
    LinkedListNode<int>* forward=NULL;

    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;

}
tc=O(n);n=number of nodes
sc=O(1); bcz it is an iterative approach
*/

//using recursion
/*void reverse(LinkedListNode* &head,LinkedListNode*curr,LinkedListNode*prev){
    //base case
    if(curr=NULL){
        head=prev;
        return;
    }
    LinkedListNode*forward=curr->next;
    reverse(head,forward,curr);
    curr->next=prev;
}
LinkedListNode *reverseLinkedList(LinkedListNode *head) 
{
    // Write your code here
    LinkedListNode*curr=head;
    LinkedListNode*prev=NULL;
    reverse(int *head,int*curr,int*prev);
    return head;
}
*/

//or
// Node*reverse1(Node*head){
//     //base cse
//     if(head==NULL||head->next=NULL){
//         return head;
//     }
//     Node*Chotahead=reverse1(head->next);
//     head->next->next=head;
//     head->next=NULL:
//     return Chotahead;
// }
// Node*reverseLinkedList(Node*head){
//     return reverse1(head);
// }
//tc and sc=O(n)