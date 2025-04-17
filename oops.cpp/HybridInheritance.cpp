//combination of more than one types of inheritance is acalled hybrid inheritance
#include<iostream>
using namespace std;
//parent class
class vehicle{
    public:
    vehicle(){
        cout<<"This is vehicle"<<endl;
    }
};
//parent class
class fare{
    public:
    fare(){
        cout<<"Fare of vehicle"<<endl;
    }
};
//child class1
class  car:public vehicle{

};
//child class 2
class bus:public vehicle,public fare{

};
int main(){
    bus object2;
    return 0;
}
