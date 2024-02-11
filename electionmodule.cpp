#include <iostream>
#include "PAmanagement.h"
#include "NAmanagement.h"
#include "votermanagement.h"
using namespace std;

int main(){

int choice;
do{
    cout<<"        WELCOME TO ELECTION MODULE 2024\n";
    cout<<" *********************************************\n";

cout<<"Select which management system you want to use\n";
cout<<"1: National Assembly Management System\n";
cout<<"2: Provincial Assembly Management System\n";
cout<<"3: Voters Management System\n";
cin>>choice;

switch (choice){
    case 1:
    NaSystem();
    break;

    case 2:
    PaSystem();
    break;

    case 3:
    voterSystem();
    break;

    case 4:
    break;
    default:
    cout << "Invalid Choice! Please enter a number between 1 and 4.";
        }

    }
    while(choice=!4);
    return 0;
}