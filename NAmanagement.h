#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct CandidateNA {
    int conNumber;
    string cnic;
    string name;
    string party;
};


const int maxCandidates = 70;
const int maxConstituencies = 6;

CandidateNA candidateDataN[maxConstituencies][maxCandidates];

int numCandidate[maxConstituencies] = {0};
CandidateNA NAcandidate;


void addNData(int constituency) {
char addData;

    
    do { 
        cout<<"Enter NA Number(only enter digit)\n";
        cout<<"NA-";
        cin>> NAcandidate.conNumber;

        cout<<"Enter CNIC number of the candidate\n";
        cin>>NAcandidate.cnic;

        cout<<"Enter Name of the Contestant\n";
        cin.ignore();
        getline(cin, NAcandidate.name);

        cout<<"Enter party name\n";
        getline(cin, NAcandidate.party);

        candidateDataN[constituency][numCandidate[constituency]] = NAcandidate;
        numCandidate[constituency]++;

        cout<<"Enter Y or y to add more data for the same constituency or press anyother key to exit\n";
        cin>>addData;
    } while (addData=='y' || addData=='Y');
}

void NaddMenu(){
    int counter = 0;
    int constituency;

    do { 
        cout<<"Select your Constituency Number to add data.\n";
        cout<<"1. NA-1";
        cout<<"\n2. NA-7";
        cout<<"\n3. NA-8";
        cout<<"\n4. NA-11";
        cout<<"\n5. NA-12";
        cout<<"\n6. Exit\n";

        cin>>constituency;

        switch(constituency){
            case 1:
                addNData(0);
                break;
            case 2:
                addNData(1);
                break;
            case 3:
                addNData(2);
                break;
            case 4:
                addNData(3);
                break;
            case 5:
                addNData(4);
                break;
            case 6:
                break;
            default:
                cout<<"Invalid option\n";
                break;
        }
    } while (constituency > 6 || constituency < 1);
}

void searchNData(int constituency){
    int consNum;
    cout<<"Enter the Constituency Number you want to find.\n"
    << "For example, if you are looking for information about NA-1,\n"
    << "you would enter 1 here:\n";
    cin >> consNum;
    
    for(int i=0; i<numCandidate[constituency]; i++){
        if (candidateDataN[constituency][i].conNumber==consNum){
            cout<<"NA Number : NA-"<<candidateDataN[constituency][i].conNumber<<endl;
            cout<<"CNIC : "<<candidateDataN[constituency][i].cnic<<endl;
            cout<<"Name : "<< candidateDataN[constituency][i].name<<endl;
            cout<<"Party : "<<candidateDataN[constituency][i].party<<endl;
            
        }
    }
    
}

void searchNMenu(){
    int counter = 0;
    int constituency;

    do { 
        cout<<"Select your Constituency Number to search data.";
        cout<<"1. NA-1";
        cout<<"\n2. NA-7";
        cout<<"\n3. NA-8";
        cout<<"\n4. NA-11";
        cout<<"\n5. NA-12";
        cout<<"\n6. Exit\n";

        cin>>constituency;

        switch(constituency){
            case 1:
                searchNData(0);
                break;
            case 2:
                searchNData(1);
                break;
            case 3:
                searchNData(2);
                break;
            case 4:
                searchNData(3);
                break;
            case 5:
                searchNData(4);
                break;
            case 6:
                break;
            default:
                cout<<"Invalid option\n";
                break;
        }
    } while (constituency != 6);
}


void editNData(int constituency){
    string editname;
    cout<<"Enter name of the candidate you want to edit\n";
    cin.ignore();
    getline(cin, editname);
    bool found=false;
    for (int i=0; i<numCandidate[constituency]; i++){
        if (candidateDataN[constituency][i].name == editname) {
            found==true;
            cout<<"Enter new NA Number\n";
            cin>>candidateDataN[constituency][i].conNumber;
            cout<<"New NA number is " << candidateDataN[constituency][i].conNumber<<endl;
            cout<<"Enter new name\n";
            cin.ignore();
            getline(cin, candidateDataN[constituency][i].name);
            cout<<"Name has been changed to "<<candidateDataN[constituency][i].name<<endl;
            cout<<"Enter new CNIC";
            cin>>candidateDataN[constituency][i].cnic;
            cout<<"CNIC has been changed to "<<candidateDataN[constituency][i].cnic<<endl;
            cout<<"Enter new Political Party";
            cin.ignore();
            getline(cin, candidateDataN[constituency][i].party);
            cout<<"Political party has been changed to "<<candidateDataN[constituency][i].party<<endl;
            cout<<"Data Updated Successfully! ";

    }
    else if (!found){
        cout<<"Name not found in database!";
        }
    }
}

void NeditMenu(){
    int counter = 0;
    int constituency;

    do { 
        cout<<"Select your Constituency Number to edit data.\n";
        cout<<"1. PA-1";
        cout<<"\n2. PA-7";
        cout<<"\n3. PA-8";
        cout<<"\n4. PA-11";
        cout<<"\n5. PA-12";
        cout<<"\n6. Exit\n";

        cin>>constituency;

        switch(constituency){
            case 1:
                editNData(0);
                break;
            case 2:
                editNData(1);
                break;
            case 3:
                editNData(2);
                break;
            case 4:
                editNData(3);
                break;
            case 5:
                editNData(4);
                break;
            case 6:
                break;
            default:
                cout<<"Invalid option\n";
                break;
        }
    } while (constituency <= 6 || constituency>1);

}


void viewNData(){
    for (int i = 0; i < maxConstituencies; i++) {
        cout<<"\nConstituency "<<i+1<<":"<<endl;
        for (int j = 0; j < numCandidate[i]; j++) {
            cout<<"\n  NA Number: NA-"<<candidateDataN[i][j].conNumber<<endl;
            cout<<"  CNIC: "<<candidateDataN[i][j].cnic<<endl;
            cout<<"  Name: "<<candidateDataN[i][j].name<<endl;
            cout<<"  Party: "<<candidateDataN[i][j].party<<endl;
        }
    }

}


void deleteNData(){
    string delName;
    int delNaNum;
    cout<<"Enter the Name of candidate you want to delete";
    cin.ignore();
    getline(cin,delName);
    cout<<"Enter the National Assembly number of the candidate you want to edit. (only enter Digit)";
    cout<<"NA-";
    cin>>delNaNum;
    bool found=false;
    for (int i=0; i<maxConstituencies; i++){
        for (int j=0; j<numCandidate[i]; j++ ){
            if (candidateDataN[i][j].name == delName && candidateDataN[i][j].conNumber == delNaNum){
                found=true;
                numCandidate[i]--;
                for (int k=j;k<numCandidate[i];k++){
                    candidateDataN[i][k]=candidateDataN[i][k+1];
                    }
                }
            else if (!found);{
            cout<<"Data not found!";

            }
        }

    }

}

void saveNAtoFile(){
    fstream fout;
    fout.open("NAData.txt", ios::app);
    if (!fout){
        cout<<"Error! File not opening\n";
        return;
    }
    else {
        for (int i = 0; i < maxConstituencies; i++) {
        fout<<"\nConstituency "<<i+1<<":"<<endl;
        for (int j = 0; j < numCandidate[i]; j++) {
            fout<<"\n  NA Number: NA-"<<candidateDataN[i][j].conNumber<<endl;
            fout<<"  CNIC: "<<candidateDataN[i][j].cnic<<endl;
            fout<<"  Name: "<<candidateDataN[i][j].name<<endl;
            fout<<"  Party: "<<candidateDataN[i][j].party<<endl;
            fout<<endl;
            }   
        }
    }
}

void NaSystem(){
    int mainMenuOption;
    do{
        cout<<"Select which function do you want to perform.\n";
        cout<<"1. Add Data";
        cout<<"\n2. View Data";
        cout<<"\n3. Search Data";
        cout<<"\n4. Edit Data";
        cout<<"\n5. Delete Data";
        cout<<"\n6. Save data to file";
        cout<<"\n7. Exit\n";

        cin>>mainMenuOption;
        switch (mainMenuOption) {
            case 1:
            NaddMenu();
            break;

            case 2:
            viewNData();
            break;

            case 3:
            searchNMenu();
            break;

            case 4:
            NeditMenu();
            break;

            case 5:
            deleteNData();
            break;

            case 6:
            saveNAtoFile();
            break; 

            case 7:
            cout<<"Exiting program! Make sure  all changes are saved in file.\n";
            break;

            default:
            cout<<"Invalid option\n";
            break;
            }

        }
    while(mainMenuOption!=6);
}