//There are various types of inheritance
// 1)single level inheritance
// 2)Multi Level inheritance
// 3)Multiple
// 4)Hybrid
// 5)Hierarchial


//Example of single inheritance
#include<iostream>
using namespace std;
class Animal {

    public:
    int age;
    int weight;


    public:
    void speak() {
        cout << "Speaking " << endl;
    }
};

class Dog: public Animal {

};


int main() {

    Dog d;
    d.speak();
    cout << d.age << endl;
    return 0;
}