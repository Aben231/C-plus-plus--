#include<iostream>
#include<iomanip>
#include<cstring>  // For strcpy
using namespace std;

struct student {
    char name[50];
    int age;
    int ma, ss, dsd;  // ma = maths, ss = social science, dsd = another subject
};
void display(Person):
int main() {
    student s1;

    // Correct way to assign a string to a char array
    strcpy(s1.name, "Aben");
    s1.age = 18;  // Correct integer assignment
    s1.ma = 98;  // ma = maths mark
    s1.ss = 99;  // ss = social science mark
    s1.dsd = 96;  // dsd = some other subject mark
}
void display(student s1):
{
    // Output the student details
    cout << "Name: " << s1.name << endl;
    cout << "Age: " << s1.age << endl;
    cout << "Maths Marks: " << s1.ma << endl;
    cout << "Social Science Marks: " << s1.ss << endl;
    cout << "DSD Marks: " << s1.dsd << endl;

    return 0;
}
