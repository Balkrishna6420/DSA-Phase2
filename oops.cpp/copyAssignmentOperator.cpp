#include<bits/stdc++.h>
using namespace std;

class Hero {
    
    //properties
    private:
    int health;

    public:
    char *name;
    char level;

    Hero() {
        cout << "Simple constructor called" << endl;
        name = new char[100];//allocated dynamically
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

        char *ch = new char[strlen(temp.name) + 1];//new character array made
        strcpy(ch, temp.name);//and temp ka name is copiedin ch
        this->name = ch;//in short due to deep copy now , if we change name of one object newly copied object will not be changed now.

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


};
int main(){
    
    Hero hero1;

    hero1.setHealth(12);
    hero1.setLevel('D');
    char name[7] = "Babbar";
    hero1.setName(name);

    //hero1.print();

    //use default copy constructor

    Hero hero2(hero1);
    //hero2.print();
//    Hero hero2 = hero1;

    hero1.name[0] = 'G';
    hero1.print();

    hero2.print();//here due to shallow copy which is caled during default copy constructor even if im changing the valu e of hero1,hero 2 value will also be updated.
    hero1 = hero2;//copy assignment operator

    hero1.print();

    hero2.print();


}

//shallow copy is using same memory as shared by previous object
//in case of deep copy default copy constructor is not called,we have to make our own.