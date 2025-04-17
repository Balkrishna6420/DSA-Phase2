//using getter and setter we can access the privte content of the class by the outsider main function also
#include<iostream>
using namespace std;
class Hero{
    private:
    int health;
    public:
    char level;
    

    int getHealth(){
        return health;
    }
    char getlevel(){
        return level;
    }
    void setHealth(int h){
        health=h;
    }
    char setlevel(char ch ){
        level=ch;
    }
    
};
int main(){
    Hero h1;//staticalyy allocated
    h1.setHealth(80);
    h1.setlevel('B');

    cout<<"Health will be"<<h1.getHealth()<<endl;
    cout<<"level will be"<<h1.level<<endl;
    //dynamically allocation will be
    Hero *h2=new Hero; 
    h2->setHealth(90);
    h2->setlevel('c');
    cout<<"Health will be"<<(*h2).getHealth()<<endl;
    cout<<"level will be"<<(*h2).level<<endl;
    //or
    cout<<"Health will be"<<h2->getHealth()<<endl;
    cout<<"level will be"<<h2->level<<endl;
//     cout<<"h1 Health is"<<h1.getHealth()<<endl;
//     cout<<"h1 level"<<h1.getlevel()<<endl;
}
//use case of setter-it can restrict only certaim user to modify something  in case . 
//what is padding -its adding of extra byte so that our os will work smoothly. if our os is of 64 bits tgen 8 byte is reserved for each operation of data type