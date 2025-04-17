//It is that datatype that belongs to a class and it does not need object to be accessed.
//in short it does not belong to object but belong to class
#include<bits/stdc++.h>
using namespace std;

class Hero {
    
    //properties
    private:
    int health;

    public:
    char *name;
    char level;
    static int timeToComplete;//static data member

    Hero() {
        cout << "Simple constructor called" << endl;
        name = new char[100];
    }

    //Paramerterised Constructor
    Hero(int health) {
        this -> health = health;
    }

    Hero(int health, char level) {
        this -> level = level;
        this -> health = health;
    }

    //copy constructor
    Hero(Hero& temp) {

        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);
        this->name = ch;

        cout << "Copy constructor called" << endl;
        this->health = temp.health;
        this->level = temp.level;
    }

    void print(){
        cout << endl;
        cout << "[ Name: " << this->name<< " ,";
        cout << "health: " << this->health << " ,";
        cout <<"level: " << this->level << " ]";
        cout << endl << endl;
    }

    int getHealth() {
        return health;
    }

    char getLevel() {
        return level;
    }

    void setHealth(int h) {
        health = h;
    }

    void setLevel(char ch) {
        level = ch;
    }

    void setName(char name[]) {
        strcpy(this->name, name);
    }
    //static data function-it does not use this keyword as it only acess to functions of static member not class 
    static int random(){
        return timeToComplete;//static function only access static implemented data members,here no helth,name erc
    }
    //destructor
    ~Hero(){
        cout<<"Destructor bro called"<<" "<<endl;
    }


};
int Hero::timeToComplete = 5;//for initialisation of static keyword ,:: this is scope resolution operator
int main(){
   // cout<<Hero::timeToComplete<<endl;
    cout<<Hero::random()<<endl;

}
