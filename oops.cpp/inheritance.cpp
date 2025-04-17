//If one class inherit the characteristic/properties of another class ,it is known as inheritance
//It has two class-1)sub class-the class that inherit properties from another class is called sub cladss
                //2)super class/base class-the class whose properrties are inherited by the sub class is caleed super class
//Advantages:-
      //1)code reusability
      //2) runtime polymorphism (method overriding) can be achieved by inherianve only
//private data member of any class cannot be inherited      
//protected-it is similar to private which is accessed inside the class only but in this scenario it can also be accessed by child class or derived class   .here answer will return only ias protected way.  
//if parent class is private no matter whts the inherit mode it is not accessible  

#include<iostream>
using namespace std;

class Human {

    public:
    int height;
    int weight;

    private:
    int age;

    public:
    int getAge() {
      return this->age;
    }

    void setWeight(int w) {
        this->weight = w;

    }

};

class Male: private Human {

    public:
    string color;

    void sleep() {
        cout << "Male Sleeping" << endl;
    }

    int getHeight() {
        return this->height;
    }

};



int main() {

    Male m1;
    cout << m1.getHeight() << endl;//for protected access modifiers



/*
    Male object1;
    cout << object1.age << endl;
    cout << object1.weight << endl;
    cout << object1.height << endl;

    cout << object1.color << endl;

    object1.setWeight(84);
    cout << object1.weight << endl;
    object1.sleep();
    */

    return 0;
}
