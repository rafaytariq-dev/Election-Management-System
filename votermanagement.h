#include<iostream>
#include<fstream>
using namespace std;


struct voterBiodata{
    string CNIC;
    string Name;
    int Age;
    string city;
};

struct voterInfo{
    int constituencyNoN;
    int constituencyNoP;
    string pollingbooth;
    struct voterBiodata voter;
};
const int maxVoter = 500;
voterInfo VoterData[maxVoter];
int counter;


//int voterData[maxVoter]; 
char addData;
void addVoter(){
    
    cout<<"**********Enter the details of new Voters**********\n";
    for(int i=0; i<maxVoter; i++){
    cout<<"Enter Name of the Voter\n";
    cin.ignore();
    getline(cin,VoterData[i].voter.Name);
    cout<<"Enter CNIC Number of the Voter: \n";
    cin>>VoterData[i].voter.CNIC;
    cout<<"Enter Age of the voter: \n";
    cin>>VoterData[i].voter.Age;
    cout<<"Enter City of the voter: \n";
    cin.ignore();
    getline(cin, VoterData[i].voter.city);
    cout<<"Enter National Assembly Constituency Number\n";
    cout<<"NA-";
    cin>>VoterData[i].constituencyNoN;
    cout<<"Enter Provincial Assembly constituency Number\n";
    cout<<"PA-";
    cin>>VoterData[i].constituencyNoP;
    cout<<"Enter Polling Booth Address :\n";
    cin.ignore();
    getline(cin,VoterData[i].pollingbooth);
    counter++;
    cout<<"Enter Y or y to add more data for the same constituency or press anyother key to exit\n";
    cin>>addData;
    if ((addData=='Y')||(addData=='y')){
        continue;
    }
    else
        break;
    }

}

void viewVoter(){
    for (int i=0; i<counter; i++){
        cout<<"Voter number "<<i+1<<endl;
        cout<<"Voter Name: "<<VoterData[i].voter.Name<<endl;
        cout<<"Voter CNIC: "<<VoterData[i].voter.CNIC<<endl;
        cout<<"Voter Age: "<<VoterData[i].voter.Age<<endl;
        cout<<"Voter City: "<<VoterData[i].voter.city<<endl;
        cout<<"National Assembly Constituency Number: NA-"<<VoterData->constituencyNoN<<endl;
        cout<<"Provincial Assembly Constituency Number: PA-"<<VoterData->constituencyNoP<<endl;
        cout<<"Polling Booth Address: "<<VoterData[i].pollingbooth<<endl;
        cout<<endl;
        
    }

}

void editVoter(){
    string editcnic;
    cout<<"Enter the CNIC of the voter you want to edit\n";
    cin>>editcnic;
    for(int i=0; i<counter;i++){
        if(VoterData[i].voter.CNIC == editcnic) {
            cout<<"**Enter New Data**\n";
            cout<<"Enter New Name: \n";
            cin.ignore();
            getline(cin, VoterData[i].voter.Name);
            cout<<"Enter new CNIC Number of the Voter: \n";
            cin>>VoterData[i].voter.CNIC;
            cout<<"Enter new Age of the voter: \n";
            cin>>VoterData[i].voter.Age;
            cout<<"Enter new City of the voter: \n";
            cin.ignore();
            getline(cin, VoterData[i].voter.city);
            cout<<"Enter updated National Assembly Constituency Number\n";
            cout<<"NA-";
            cin>>VoterData[i].constituencyNoN;
            cout<<"Enter updated Provincial Assembly constituency Number\n";
            cout<<"PA-";
            cin>>VoterData[i].constituencyNoP;
            cout<<"Enter new Polling Booth Address :\n";
            cin.ignore();
            getline(cin,VoterData[i].pollingbooth);

        }
        else 
        cout<<"Error! Data not found!\n";
    }
}

void searchVoter(){
    string Cnic;
    cout<<"Enter the CNIC of the voter to get Details\n";
    cin>>Cnic;
    for(int i=0; i<counter; i++){
    if(VoterData[i].voter.CNIC==Cnic){
        cout<<"Name: "<<VoterData[i].voter.Name<<endl;
        cout<<"CNIC: "<<VoterData[i].voter.CNIC<<endl;
        cout<<"Age: "<<VoterData[i].voter.Age<<endl;
        cout<<"City: "<<VoterData[i].voter.city<<endl;
        cout<<"NA Constituency Number: "<<VoterData[i].constituencyNoN<<endl;
        cout<<"PA Constituency Number: "<<VoterData[i].constituencyNoP<<endl;
        cout<<"Polling Booth Address: "<<VoterData[i].pollingbooth<<endl;
        
        }
    }
}

void deleteVoter() {
    string Cnic;
    cout << "Enter CNIC of the Voter you want to delete: ";
    cin >> Cnic;
    for (int i = 0; i < counter; i++) {
        if (VoterData[i].voter.CNIC == Cnic) {
            for (int j = i; j < counter - 1; j++) {
                VoterData[j] = VoterData[j+1];
            }
            counter--;
            cout << "Voter deleted successfully." << endl;
            return;
        }
    }

    cout << "Voter not found." << endl;
}

void saveVotertoFile(){
    fstream fout;
    fout.open("voterData.txt", ios::app);
    if (!fout){
        cout<<"Error! File not opening\n";
        return;
    }
    else {
        for (int i=0; i<counter; i++){
        fout<<"Voter number "<<i+1<<endl;
        fout<<"Voter Name: "<<VoterData[i].voter.Name<<endl;
        fout<<"Voter CNIC: "<<VoterData[i].voter.CNIC<<endl;
        fout<<"Voter Age: "<<VoterData[i].voter.Age<<endl;
        fout<<"Voter City: "<<VoterData[i].voter.city<<endl;
        fout<<"National Assembly Constituency Number: NA-"<<VoterData->constituencyNoN<<endl;
        fout<<"Provincial Assembly Constituency Number: PA-"<<VoterData->constituencyNoP<<endl;
        fout<<"Polling Booth Address: "<<VoterData[i].pollingbooth<<endl;
        fout<<endl;
        }   
    }
}

void voterSystem(){
    int option;

    do { 
        cout<<"********* VOTER MANAGEMENT SYSTEM *********\n";
        cout<<"Select which function you want to perform!\n";
        cout<<"1. Add Voter Information";
        cout<<"\n2. View Voter Information";
        cout<<"\n3. Search Voter Information";
        cout<<"\n4. Edit Voter Information";
        cout<<"\n5. Delete Voter Information";
        cout<<"\n6 Save data to file";
        cout<<"\n7. Exit\n";

        cin>>option;

        switch(option){
            case 1:
                addVoter();
                break;
            case 2:
                viewVoter();
                break;
            case 3:
                searchVoter();
                break;
            case 4:
                editVoter();
                break;
            case 5:
                deleteVoter();
                break;
            case 6:
                saveVotertoFile();
                break;
            case 7:
                cout<<"Exiting program! Make sure  all changes are saved in file.\n";
                break;
            default:
                cout<<"Invalid option\n";
                break;
        }
    } while (option != 7);
}
