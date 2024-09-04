#include <iostream>
using namespace std;

class overloading
{
    private:
        int a;
        int b;

    public:
        // Function to get values for a and b
        void get()
        {
            cout << "Enter the value for a: ";
            cin >> a;

            cout << "Enter the value for b: ";
            cin >> b;
        }

        // Function to display the values of a and b
        void put()
        {
            cout << "The calculated value of a is = " << a << endl;
            cout << "The calculated value of b is = " << b << endl;
        }

        // Overloading the + operator to add two overloading objects
        overloading operator +(overloading op) 
        {
            overloading op4;
            op4.a = a + op.a;
            op4.b = b + op.b;
            return op4;
        }
};

int main()
{
    overloading op1, op2, op3;

    // Getting values for op1 and op2
    op1.get();
    op2.get();

    // Adding op1 and op2 using the overloaded + operator
    op3 = op1 + op2;

    // Displaying the result
    op3.put();

    return 0;
}
