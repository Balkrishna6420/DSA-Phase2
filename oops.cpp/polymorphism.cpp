//poly means many,morph means forms.Inshort existing in many forms.
//your pitaji can be a son,father,brother and cab be a husband
//It is of two types: Run time and compile time/static polymorphism.
//compile time is of two types and is acieved through 1) function overloading 2)operator overloading
//function overloading-same function ko multiple forms me likhna hai.
//Function overloading is a feature of object-oriented programming where two or more functions can have the same name but different parameters.
//function overloading
#include<iostream>
using namespace std;

class A {

    public:
    void sayHello() {
        cout << "Hello Love Babbar" << endl;
    }
    
    int sayHello(char name) {
        cout << "Hello Love Babbar" << endl;
        return 1;
    }

    void sayHello(string name) {
        cout << "Hello " << name  << endl;
    }

};
int main(){
    A obj;
    obj.sayHello("Krishna");
}

//operator overloading-kisi ek operatoe se multiple kaam k,arwa sakta hoo  
#include<iostream>
using namespace std;

class B {
    public:
    int a;
    int b;

    public: 
    int add() {
        return a+b;
    }

    void operator+ (B &obj) {
/*      int value1 = this -> a;
        int value2 = obj.a;
        cout << "output " << value2 - value1 << endl; 
        */
       cout << "Hello Babbar" << endl;
    }

    void operator() () {
        cout << "main Bracket hu " << this->a << endl;
    }

};
int main(){
    B obj1, obj2;

    obj1.a = 4;
    obj2.a = 7;

    obj1 + obj2;
    obj1();
}

//Runtime polymorphism-Dynamic Polymorphism-method overriding/function overriding
//method of the parent class and child class is same name and parameters.
//it is possible through inheritamce only
#include<iostream>
using namespace std;
class Animal {
    public:
    void speak() {
        cout << "Speaking "<< endl;
    }
};

class Dog: public Animal {

    public:
    void speak() {
        cout << "Barking " << endl;
    }


};
int main(){
    Dog object;
    object.speak();
}
