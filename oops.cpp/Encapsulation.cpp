//wrapping up of data members(properties,state) and functions(methods,behaviour) into single unit(class) is called encapsulation.
//Fully encapsulated class-sare ke sare data members are marked as private 
//It is information hiding or data hiding
//Advantages:- 1)Data hiding thus providing more security
            // 2)we we want we can make class read only using getter and not using setter
            // 3) code reusability
            //4)it is used in unit testing.
//Implementation:-

#include<iostream>
using namespace std;
class student{
    private://data members
    string name;
    int age;
    int height;
    public://data function
    int getAge(){
        return this->age;
    }
};
int main(){
    student first;//creating object
    cout<<"sab sahi chal raha hai"<<endl;

}