#include<iostream>

using namespace std;

class overloading

{

private:

int a;

public:

void get()

{

cout<<"enter the value"<<endl;

cin>>a;

}



void put()

{

cout<<"calculated value is = "<<a;

}

overloading operator + ( overloading op)

{

overloading op4;

op4.a = a + op.a;

return op4;

}

};

int main()

{

overloading op1,op2,op3;

op1.get();

op2.get();

op3 = op1 + op2;

op3.put();

}