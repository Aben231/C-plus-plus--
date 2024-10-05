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

void operator - ()

{

a = --a;

}

};

int main()

{

overloading op1;

op1.get();

-op1;

op1.put();

}