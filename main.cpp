#include <iostream>
#include "MMTable.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]){
	MMTable marchMadness;
    
    ifstream inFile;
    string data;

    inFile.open(argv[1]);
    if(inFile.good()){ //error check
        cout<<"opened successfully"<<endl;
        while(getline(inFile, data)){ 
            stringstream ss(data); 
            
            string teamName;
            string state;
            string top25Rank;
            string region;
            string regionRank

            getline(ss, teamName, ',');
            getline(ss, state, ',');
            getline(ss, top25Rank, ',');
            getline(ss, region, ',');
            getline(ss, regionRank, ',');          
            // cout << teamName << endl;
            // cout << state << endl;
            // cout << top25Rank << endl;
            // cout << region << endl;
            // cout << regionRank << endl;
            int intTop25Rank = atoi(imdbRanking.c_str());
            int intRegionRank = atoi(yearMade.c_str());
            imdb.insertMovie(teamName, state, intTop25Rank, region, intRegionRank);
        }
    }else{
        cout << "File unsuccessfully opened" << endl;
    }
    inFile.close(); //close the file
    cout << "======Main Menu======" << endl;
    cout << "1. Print Team Names" << endl;
    cout << "2. Print Top 25 Ranking" << endl;
    cout << "3. Print Regional Ranking" << endl;
    cout << "4. Insert A Team" << endl;
    cout << "5. Delete A Team" << endl;
    cout << "6. Find Team" << endl;
    cout << "7. Play Teams" << endl;
    cout << "8. Compare Teams" << endl;
    cout << "9. Find Common States" << endl;
    cout << "10. Quit" << endl;

    string choice;

    string cinTeam;
    string cinState;
    string cinTop25Rank;
    string cinRegion;
    string cinRegionRank;

    string cinTeam2;

    getline(cin,choice);

    while (choice != "9"){
        if (choice == "1"){
            marchMadness.printTeamNames();
        }
        else if (choice == "2"){
            marchMadness.printTop25Ranking();
        }
        else if (choice == "3"){
            marchMadness.printRegionalRanking();
        }
        else if (choice == "4"){
        	cout << "Enter Team Name:" << endl;
            getline(cin, cinTeam);
            cout << "Enter State:" << endl;
            getline(cin, cinState);
            cout << "Enter Top 25 Rank:" << endl;
            getline(cin, cinTop25Rank);
            cout << "Enter Region:" << endl;
            getline(cin, cinRegion);
            cout << "Enter Region Rank:" << endl;
            getline(cin, cinRegionRank);
            marchMadness.insertTeam(cinTeam, cinState, stoi(cinTop25Rank), cinRegion, stoi(cinRegionRank));
        }
        else if (choice == "5"){
        	cout << "Enter Team Name:" << endl;
            getline(cin, cinTeam);
            marchMadness.deleteTeam(cinTeam);
        }
        else if (choice == "6"){
        	cout << "Enter Team Name:" << endl;
            getline(cin, cinTeam);
            marchMadness.findTeam(cinTeam);
        }
        else if (choice == "7"){
        	cout << "Enter Team 1:" << endl;
        	getline(cin, cinTeam);
        	cout << "Enter Team 2:" << endl;
        	getline(cin, cinTeam2);
        	marchMadness.compareTeams(cinTeam, cinTeam2);
        }
        else if (choice == "8"){
        	cout << "Enter Team 1:" << endl;
        	getline(cin, cinTeam);
        	cout << "Enter Team 2:" << endl;
        	getline(cin, cinTeam2);
        	marchMadness.playTeams(cinTeam, cinTeam2);
        }
        else if (choice == "9"){
        	marchMadness.findCommonStates();
        }
        else{
            cout << "Not A Valid Option" << endl;
        }

        cout << "======Main Menu======" << endl;
	    cout << "1. Print Team Names" << endl;
	    cout << "2. Print Top 25 Ranking" << endl;
	    cout << "3. Print Regional Ranking" << endl;
	    cout << "4. Print table contents" << endl;
	    cout << "5. Insert A Team" << endl;
	    cout << "6. Delete A Team" << endl;
	    cout << "7. Find Team" << endl;
	    cout << "8. Play Teams" << endl;
	    cout << "9. Find Common States" << endl;
	    cout << "10. Quit" << endl;
        getline(cin, choice);
    }
    cout << "Goodbye!" << endl;

    return 0;
}












v