#include <iostream>
using namespace std;

class overloading
{
    private:
        int a;
        int b;

    public:
        void get()
        {
            cout << "Enter the value: ";
            cin >> a;

            cout << "Enter the value: ";
            cin >> b;
        }

        void put()
        {
            cout << "The calculated value is = " << a << endl;
             cout << "The calculated value is = " << b << endl;
        }

        void operator+()  // Overload the unary minus operator
        {
            a = +a;
            b = -b;
        }
};

int main()
{
    overloading op1;
    op1.get();
     +op1;  // This will call the overloaded operator-
    op1.put();

    return 0;
}
