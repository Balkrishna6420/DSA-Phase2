//suppose there is a class 1 and 2 with same function name .if a 3 thrd class inherit and calls both 1,2 class then ambiguiy will take place .
//hence we use scope resolution operator to remobve the error and to know which function is called out of two
#include<iostream>
using namespace std;

class A {
    public:

    void func() {
        cout << " I am A" << endl;
    }
};
class B {
    public:

    void func() {
        cout << " I am B" << endl;
    }
};

class C: public A, public B {

};

int main() {

    C obj;
    //obj.func();

    obj.A::func() ;
    obj.B::func();

    return 0;
}