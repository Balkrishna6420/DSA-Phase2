
// Remove unsorted LL using map
// Node *removeDuplicates(Node *head)
// {    
//     Node* curr = head;
//     Node* prev = NULL;
//     unordered_map<int, bool> visited;
    
//     while(curr != NULL){
//         if(!visited[curr->data]){
//             visited[curr->data] = true;
//             prev = curr;
//             curr = curr -> next;
//         }
//         else{
//             prev -> next = curr -> next;
//             delete curr;
//         }
//         curr = prev -> next;
//     }
//     return head;
// }
// tc will be O(n);
// sc=O(n)

//we can also solve it using sorting//tc and sc will be O(nlogn),O(1) and double loop method(0(n^2))


// using two loops 
// Node *removeDuplicates(Node *head)
// {
//     // Write your code 
//     Node *p, *q;
//     p = head;

//     // Outer loop to pick element.
//     while (p != NULL)
//     {
//         // Initialize the inner loop pointer.
//         q = p->next;

//         // Keep track of previous node.
//         Node *prev = p;

//         while (q != NULL)
//         {
//             if (p->data == q->data)
//             {
//                 // Found a duplicate of node 'p'. Now, we need to remove it.
//                 // Firstly update the next pointer of the previous node.
//                 prev->next = q->next;

//                 // Delete the duplicate node.
//                 delete q;

//                 // Move the inner loop pointer to the next node.
//                 q = prev->next;
//             }
//             else
//             {
//                 // Node 'q' is not a duplicate. So, move to the next node.
//                 prev = q;
//                 q = q->next;
//             }
//         }

//         // Move the outer loop pointer to the next node.
//         p = p->next;
//     }

//     return head;
// }