#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct CandidatePA {
    int paNumber;
    string cnic;
    string name;
    string party;
};

//Creating constant variables for arrays
const int maxCandidate = 50;
const int maxConstituency = 5;

//creating a 2d array of structure having instance candidatData and size is [5][50]
CandidatePA candidateData[maxConstituency][maxCandidate];

//creating a 1d array to keep a track of candidates entered per constituency
int numCandidates[maxConstituency] = {0};
//structure having instance candidate
CandidatePA candidate;


void addPData(int constituency) {
char addData;

    do { 
        cout<<"Enter PA Number(only enter digit)\n";
        cout<<"PA-";
        cin>> candidate.paNumber;

        cout<<"Enter CNIC number of the candidate\n";
        cin>>candidate.cnic;

        cout<<"Enter Name of the Contestant\n";
        cin.ignore();
        getline(cin, candidate.name);

        cout<<"Enter party name\n";
        getline(cin, candidate.party);

        //Storing data of structure having instance candidate into a 2d array having row  as constituency and column as number of candidates in that constituency
        candidateData[maxConstituency][numCandidates[maxConstituency]] = candidate;
        //incrementing the column after each  addition to avoid overwriting data in same cell
        numCandidates[maxConstituency]++;

        cout<<"Enter Y or y to add more data for the same constituency or press anyother key to exit\n";
        cin>>addData;
    } while (addData=='y' || addData=='Y');
}

void addMenu(){
    int constituency;

    do { 
        cout<<"Select your Constituency Number to add data.\n";
        cout<<"1. PA-1";
        cout<<"\n2. PA-7";
        cout<<"\n3. PA-8";
        cout<<"\n4. PA-11";
        cout<<"\n5. PA-12";
        cout<<"\n6. Exit\n";

        cin>>constituency;

        switch(constituency){
            case 1:
                addPData(0);
                break;
            case 2:
                addPData(1);
                break;
            case 3:
                addPData(2);
                break;
            case 4:
                addPData(3);
                break;
            case 5:
                addPData(4);
                break;
            case 6:
                break;
            default:
                cout<<"Invalid option\n";
                break;
        }
    } while (constituency > 6 || constituency < 1);
}

void searchData(int constituency){
    int conNum;
    cout<<"Enter the Constituency Number you want to find.\n"
    << "For example, if you are looking for information about PA-1,\n"
    << "you would enter 1 here:\n";
    cin >> conNum;
    
    for(int i=0; i<numCandidates[constituency]; i++){
        if (candidateData[constituency][i].paNumber==conNum){
            cout<<"PA Number : PA-"<<candidateData[constituency][i].paNumber<<endl;
            cout<<"CNIC : "<<candidateData[constituency][i].cnic<<endl;
            cout<<"Name : "<< candidateData[constituency][i].name<<endl;
            cout<<"Party : "<<candidateData[constituency][i].party<<endl;
            
        }
    }
    
}

void searchMenu(){

    int constituency;

    do { 
        cout<<"Select your Constituency Number to search data.";
        cout<<"1. PA-1";
        cout<<"\n2. PA-7";
        cout<<"\n3. PA-8";
        cout<<"\n4. PA-11";
        cout<<"\n5. PA-12";
        cout<<"\n6. Exit\n";

        cin>>constituency;

        switch(constituency){
            case 1:
                searchData(0);
                break;
            case 2:
                searchData(1);
                break;
            case 3:
                searchData(2);
                break;
            case 4:
                searchData(3);
                break;
            case 5:
                searchData(4);
                break;
            case 6:
                break;
            default:
                cout<<"Invalid option\n";
                break;
        }
    } while (constituency != 6);
}


void editData(int constituency){
    string editname;
    cout<<"Enter name of the candidate you want to edit\n";
    cin.ignore();
    getline(cin, editname);
    bool found=false;
    for (int i=0; i<numCandidates[constituency]; i++){
        if (candidateData[constituency][i].name == editname) {
            found==true;
            cout<<"Enter new PA Number\n";
            cin>>candidateData[constituency][i].paNumber;
            cout<<"New PA number is " << candidateData[constituency][i].paNumber<<endl;
            cout<<"Enter new name\n";
            cin.ignore();
            getline(cin, candidateData[constituency][i].name);
            cout<<"Name has been changed to "<<candidateData[constituency][i].name<<endl;
            cout<<"Enter new CNIC";
            cin>>candidateData[constituency][i].cnic;
            cout<<"CNIC has been changed to "<<candidateData[constituency][i].cnic<<endl;
            cout<<"Enter new Political Party";
            cin.ignore();
            getline(cin, candidateData[constituency][i].party);
            cout<<"Political party has been changed to "<<candidateData[constituency][i].party<<endl;
            cout<<"Data Updated Successfully! ";

    }
    else if (!found){
        cout<<"Name not found in database!";
        }
    }
}

void editMenu(){
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
                editData(0);
                break;
            case 2:
                editData(1);
                break;
            case 3:
                editData(2);
                break;
            case 4:
                editData(3);
                break;
            case 5:
                editData(4);
                break;
            case 6:
                break;
            default:
                cout<<"Invalid option\n";
                break;
        }
    } while (constituency!=6);

}


void viewData(){
    for (int i = 0; i < maxConstituency; i++) {
        cout<<"\nConstituency "<<i+1<<":"<<endl;
        for (int j = 0; j < numCandidates[i]; j++) {
            cout<<"\n  PA Number: PA-"<<candidateData[i][j].paNumber<<endl;
            cout<<"  CNIC: "<<candidateData[i][j].cnic<<endl;
            cout<<"  Name: "<<candidateData[i][j].name<<endl;
            cout<<"  Party: "<<candidateData[i][j].party<<endl;
        }
    }

}


void deleteData(){
    string delName;
    int delPaNum;
    cout<<"Enter the Name of candidate you want to delete";
    cin.ignore();
    getline(cin,delName);
    cout<<"Enter the Provincial Assembly number of the candidate you want to edit. (only enter Digit)";
    cout<<"PA-";
    cin>>delPaNum;
    bool found=false;
    for (int i=0; i<maxConstituency; i++){
        for (int j=0; j<numCandidates[i]; j++ ){
            if (candidateData[i][j].name == delName && candidateData[i][j].paNumber == delPaNum){
                found=true;
                numCandidates[i]--;
                for (int k=j;k<numCandidates[i];k++){
                    candidateData[i][k]=candidateData[i][k+1];
                    }
                }
            else if (!found);{
            cout<<"Data not found!";

            }
        }

    }

}


void savePAtoFile(){
    fstream fout;
    fout.open("PAData.txt", ios::app);
    if (!fout){
        cout<<"Error! File not opening\n";
        return;
    }
    else {
    for (int i = 0; i < maxConstituency; i++) {
        fout<<"\nConstituency "<<i+1<<":"<<endl;
        for (int j = 0; j < numCandidates[i]; j++) {
            fout<<"\n  PA Number: PA-"<<candidateData[i][j].paNumber<<endl;
            fout<<"  CNIC: "<<candidateData[i][j].cnic<<endl;
            fout<<"  Name: "<<candidateData[i][j].name<<endl;
            fout<<"  Party: "<<candidateData[i][j].party<<endl;
        }
        fout<<endl;
        }   
    }
}


void PaSystem(){
    int mainMenuOption;
    do{
        cout<<"Select which function do you want to perform.\n";
        cout<<"1. Add Data";
        cout<<"\n2. View Data";
        cout<<"\n3. Search Data";
        cout<<"\n4. Edit Data";
        cout<<"\n5. Delete Data";
        cout<<"\n6. Save Data to file";
        cout<<"\n7. Exit\n";

        cin>>mainMenuOption;
        switch (mainMenuOption) {
            case 1:
            addMenu();
            break;

            case 2:
            viewData();
            break;

            case 3:
            searchMenu();
            break;

            case 4:
            editMenu();
            break;

            case 5:
            deleteData();
            break;

            case 6:
            savePAtoFile();
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