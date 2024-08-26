#include<iostream>
#include<iomanip>
using namespace std;

struct student {
    char name[50];
    int age;
    int ma, ss, dsd;
};

int main() {
    student s1;
    cout << "Enter your name: ";
    cin.get(s1.name, 50);
    cout << "Enter your Age: ";
    cin >> s1.age;
    cout << "Enter your maths marks: ";
    cin >> s1.ma;
    cout << "Enter your ss marks: ";
    cin >> s1.ss;
    cout << "Enter your dsd marks: ";
    cin >> s1.dsd;
    
    cout << "\nDisplay Information" << endl;
    cout << "Name: " << s1.name << endl;
    cout << "Age: " << s1.age << endl;
    cout << "Maths marks: " << s1.ma << endl;
    cout << "SS marks: " << s1.ss << endl;
    cout << "DSD marks: " << s1.dsd << endl;

    return 0;
}
