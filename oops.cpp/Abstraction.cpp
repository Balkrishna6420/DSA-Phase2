//It is implementation hiding.jo required cheese hai use hi dikhao no need to shoe all
//only u can change the code
//code reusablity
//avoids duplication of code
//Encapsulation:-- Information hiding.
//Abstraction:-- Implementation hiding.
// C++ Program to Demonstrate the working of Abstraction

#include <iostream>
using namespace std;
 
class implementAbstraction {
private:     //The class implementAbstraction has two private data members: a and b.Because they are marked as private, they cannot be accessed directly from outside the class.
    int a, b;
 
public:
    // method to set values of
    // private members
    void set(int x, int y) //These are public methods that provide controlled access to the private variables:
    {
        a = x;
        b = y;
    }
 
    void display()
    {
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
    }
};
 
int main()
{
    implementAbstraction obj;
    obj.set(10, 20);
    obj.display();
    return 0;
}