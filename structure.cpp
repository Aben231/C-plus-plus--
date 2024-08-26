#include<iostream>
#include<iomanip>
using namespace std;
struct Person{
    char name[50];
    int age;
};
int main()
{
    Person p1;
    cout<<"Enter your Name:";
    cin.get(p1.name,50);
    cout<<"Enter your Age:";
    cin>>p1.age;
    cout<<"Displaying the information"<<endl;
    cout<<"Name:"<<p1.name<<endl;
    cout<<"Age:"<<p1.age<<endl;


}