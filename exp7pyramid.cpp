#include<iostream>

using namespace std;

int main(){

    for(int i=1; i<=5 ; i++){

        for(int j=1; j<=i ; j++){

            cout<<j<<" ";



        }

        cout<<"\n";

    }



    for(int i=1; i<=5 ; i++){

        for(int j=1; j<=i ; j++){

            cout<<"*"<<" ";



        }

        cout<<"\n";

    }



    int n=5;

    for (int i=1; i<=n ;i++){

        for(int j=1; j<=n-i; j++){

            cout<<" ";

            

        }

        for(int j=1; j<=i; j++){

            cout<<"* ";

            

        }

        cout<<"\n";

        

    }

    

}