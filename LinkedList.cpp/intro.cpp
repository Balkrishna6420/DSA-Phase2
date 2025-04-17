//It is a type of linear data structure whic is a collection of nodes.
//A node consisits of data and address of next node
//It is a dynamic data structure which can be grown and shrink at runtime accordingly.hence we can say that memory is not wasted here.
//insertion and deletion is easy here,as we do not have to shift anything like ARRay.
//Thers are certain types of linked list are there
// 1)singly ll
// 2)doubly ll
// 3)circular ll
// 4)circular doubly ll

//implementation:-
#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;

    //constructor calling
    node(int data){
        this->data=data;
        this->next=NULL;
    }

};
int main(){
    node* node1=new node(10);//we are allocating object in heap;
    cout<<node1->data<<endl;
    cout<<node1->next<<endl;
}