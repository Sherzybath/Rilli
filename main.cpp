#include <iostream>
#include "login.cpp"
#include "signup.cpp"
#include "input.cpp"
#include "loader.cpp"
using namespace std;

int main(){
    cout<<"Welcome";
    int ch;
    int logged_in;

    while(true){
        cout<<"\n\n1.Log in\n2.Sign up\n3.Exit\n";
        cin>>ch;
        if(ch==1){
            logged_in=0;
            logged_in = log_in();

            if(logged_in==1){
                // int n;
                cout<<"Enter batch : ";
                string batch;
                cin>>batch;
                input(batch);
            } else if(logged_in==2){
                cout<<"Enter batch : ";
                string batch;
                cin>>batch;
                loader(batch);
            } else if(logged_in==3){
                cout<<"Enter batch : ";
                string batch;
                cin>>batch;
                loader(batch);
            }


        } else if (ch==2) {
            sign_up();

        } else{
            break;
        }
    }
    // cout<<"\n"<<logged_in;
    cout<<"\n\n\n";


}