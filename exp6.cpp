#include<iostream>

using namespace std;



class a {

    private:

        int b = 5;

        int x;



    public:

        a() {

            x = b;

        }



        a(int b) {

            x = b;

        }



        a(a &i) {

            x = i.x;

        }



        void get() {

            cout << x << endl;

        }

};



int main() {

    a obj1;

    obj1.get();



    a obj2(10);

    obj2.get();



    a obj3(obj2);

    obj3.get();

}
