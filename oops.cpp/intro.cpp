// object-It is an entity which has state/properties and behaviour
// class-Hero ram:-It is user defined data type like int a.char ch,etc
//in case of empty class the memory allocated to the object is of 1 byte for identification/keeping tracks of records
//by default in class access modifiers is private
//to acess the content we use dot operator 
/*
#include<iostream>
using namespace std;
class Hero{
    //no properties given
    
};
int main(){
    Hero h1;//it is an object ie,instance of a class
    cout<<"size"<<sizeof(h1)<<endl;
    return 0;
}
*/

//Example 2:-
#include<iostream>
using namespace std;
class Hero{
    // properties given
    public:
    int health;
    char level;
    void print(){
        cout<<level<<endl;
    }

    
};
int main(){
    
    Hero h1;//it is an object ie,instance of a class
    h1.health=70;
    h1.level='A';
    cout<<"size"<<sizeof(h1)<<endl;
    cout<<"Health"<<h1.health<<endl;
    cout<<"Level is "<<h1.level<<endl;
    return 0;
}
