#include <iostream>
#include "MMTable.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int menuSelect() {
    int choice = 0;
    while(choice == 0) {
      cout<<endl;
      cout << "======Main Menu======" << endl;
      cout << "1. List Teams by Bracket Region" << endl;
      cout << "2. List Teams Ranked in Top 25" << endl;
      cout << "3. List Teams: Games Won So Far" << endl;
      cout << "4. Insert A Team" << endl;
      cout << "5. Delete A Team" << endl;
      cout << "6. Find A Team" << endl;
      cout << "7. Compare Two Teams" << endl;
      cout << "8. Play Two Teams Against Eachother" << endl;
      cout << "9. Find Teams in Same State" << endl;
      cout << "10. Print Table Contents" <<endl;
      cout << "11. Quit" << endl;
      scanf("%d", &choice);
    }
    return choice;

} // End Menu Function


int main(int argc, char *argv[]){
	MMTable marchMadness;

    ifstream inFile;
    string data;
    string teamName;
    string state;
    string top25Rank;
    string region;
    string regionRank;

    inFile.open(argv[1]);
    if(inFile.good()){ //error check
        //cout<<"opened successfully"<<endl;
        cout<<endl;
        while(getline(inFile, data)){
            stringstream ss(data);
            getline(ss, teamName, ',');
            getline(ss, state, ',');
            getline(ss, top25Rank, ',');
            getline(ss, region, ',');
            getline(ss, regionRank, ',');
            int intTop25Rank = atoi(top25Rank.c_str());
            int intRegionRank = atoi(regionRank.c_str());
            marchMadness.insertTeam(teamName, state, intTop25Rank, region, intRegionRank);
        }
    } else{
        cout << "File unsuccessfully opened" << endl;
    }
    inFile.close(); //close the file


    string cinTeam;
    string cinState;
    string cinTop25Rank;
    string cinRegion;
    string cinRegionRank;
    string cinTeam2;

    cout << "~MARCH MADNESS SIMULATOR~"<<endl;
    int choice = menuSelect();

    while (1) {
        if (choice == 1){
            marchMadness.printTeamRegions();
        }
        else if (choice == 2){
            marchMadness.printTop25Ranking();
        }
        else if (choice == 3){
            marchMadness.printGamesWon();
        }
        else if (choice == 4){
            cout<<endl;
            cout << "Enter Team Name:" << endl;
            cin.ignore();
            getline(cin, cinTeam);
            cout << "Enter State:" << endl;
            getline(cin, cinState);
            cout << "Enter Top 25 Rank (enter 1-25, or -1 if not in Top 25):" << endl;
            getline(cin, cinTop25Rank);
            cout << "Enter Region: South, West, Midwest or East" << endl;
            getline(cin, cinRegion);
            cout << "Enter Region Rank: 1-16" << endl;
            getline(cin, cinRegionRank);
            marchMadness.insertTeam(cinTeam, cinState, stoi(cinTop25Rank), cinRegion, stoi(cinRegionRank));
        }
        else if (choice == 5){
            cout<<endl;
            cout << "Enter Team Name:" << endl;
            cin.ignore();
            getline(cin, cinTeam);
            marchMadness.deleteTeam(cinTeam);
        }
        else if (choice == 6){
            cout<<endl;
            cout << "Enter Team Name:" << endl;
            cin.ignore();
            getline(cin, cinTeam);
            marchMadness.findTeam(cinTeam);
        }
        else if (choice == 7){
          cout<<endl;
        	cout << "Enter Team 1:" << endl;
          cin.ignore();
        	getline(cin, cinTeam);
        	cout << "Enter Team 2:" << endl;
        	getline(cin, cinTeam2);
        	marchMadness.compareTeams(cinTeam, cinTeam2);
        }
        else if (choice == 8){
          cout<<endl;
          cout << "Enter Team 1:" << endl;
          cin.ignore();
        	getline(cin, cinTeam);
        	cout << "Enter Team 2:" << endl;
        	getline(cin, cinTeam2);
        	marchMadness.playTeams(cinTeam, cinTeam2);
        }
        else if (choice == 9){
          cout<<endl;
          cout << "Enter Team Name:" << endl;
          cin.ignore();
        	getline(cin, cinTeam);
          marchMadness.findCommonStates(cinTeam);
        }
        else if(choice == 10) {
        	marchMadness.printTableContents();
        }
        else if(choice == 11) {
          cout<<endl;
        	cout << "Goodbye!" << endl;
          return 0;
        } else if (choice < 0 || choice > 10) {
            cout<<"Must input a given menu number: 1 through 10 only"<<endl;
            return 0;
        }
        choice = menuSelect();

    } // End main While loop

    return 0;

} // End Main
