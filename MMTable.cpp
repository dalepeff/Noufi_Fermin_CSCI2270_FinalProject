#include "MMTable.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <istream>
#include <sstream>

using namespace std;

MMTable::MMTable()
{
    //ctor
    for(int i = 0; i<tableSize; i++) {          //empty record initialize
        hashTable[i] = NULL;
    }
}

MMTable::~MMTable()
{
    //dtor
}


void MMTable::printTableContents() {
    TeamElem *temp;
    int counter = 0;
    int num = 0;
    cout<<"Teams Eligible for March Madness, by hash index:"<<endl;
    for(int i = 0; i<tableSize; i++) {
        temp = hashTable[i];
        while (temp != NULL) {
            num++;
            cout<<num<<": "<<temp->team<<", "<<temp->state<<endl;
            temp = temp->next;
            counter++;
        }
    }
    if(!counter) cout<<"Bracket empty"<<endl;
    return;
}

void MMTable::printTeamRegions() {
  TeamElem *temp;
  int counter = 0;
  cout<<"Teams Playing in March Madness, by Region:"<<endl;
  for(int i = 0; i<tableSize; i++) {
      temp = hashTable[i];
      while (temp != NULL) {
        if(temp->region == "South")
            cout<<temp->region<<": "<<temp->team<<endl;
        temp = temp->next;
        counter++;
      }
  } for(int i = 0; i<tableSize; i++) {
      temp = hashTable[i];
      while (temp != NULL) {
        if(temp->region == "West")
            cout<<temp->region<<": "<<temp->team<<endl;
        temp = temp->next;
        counter++;
      }
  } for(int i = 0; i<tableSize; i++) {
      temp = hashTable[i];
      while (temp != NULL) {
        if(temp->region == "East")
            cout<<temp->region<<": "<<temp->team<<endl;
        temp = temp->next;
        counter++;
      }
  } for(int i = 0; i<tableSize; i++) {
      temp = hashTable[i];
      while (temp != NULL) {
        if(temp->region == "Midwest")
            cout<<temp->region<<": "<<temp->team<<endl;
        temp = temp->next;
        counter++;
      }
  }
  if(!counter) cout<<"Bracket empty"<<endl;
  return;
}


void MMTable::printTop25Ranking() {
  TeamElem *temp;
  bool bracketExists = 0;
  cout << "Teams' Top 25 Ranking, by hash index: " << endl;
  for (int i = 0; i < tableSize; i++){
    if (hashTable[i]!=NULL){
      temp = hashTable[i];
      while(temp != NULL){
        if (temp -> top25_rank == -1) {
          //
        }else
          cout << temp -> team << ", "<< temp -> state << ", Top 25 Ranking: " << temp -> top25_rank << endl;
        temp = temp -> next;
      }
      bracketExists = 1;
    }
  }
  if (bracketExists == 0){
    cout << "The March Madness Hash Table is Empty." << endl;
  }
}


void MMTable::printGamesWon() {
  TeamElem *temp;
  bool bracketExists = 0;
  bool teamsHavePlayed = 0;
  cout << "Teams' Games Won, by hash index: " << endl;
  for (int i = 0; i < tableSize; i++){
    if (hashTable[i]!=NULL){
      temp = hashTable[i];
      while(temp != NULL){
        if (temp -> games_won != 0){
          cout << temp -> team << ", "<< temp -> state << ": Games Won " << temp -> games_won << endl;
          teamsHavePlayed = 1;
        }
        temp = temp -> next;
      }
      bracketExists = 1;

    }
  }
  if (bracketExists == 0){
    cout << "The March Madness Hash Table is Empty." << endl;
  }
  else if (teamsHavePlayed == 0){
    cout << "No Team Has Played Yet" << endl;
  }
}


void MMTable::insertTeam(string team, string state, int top25_ranking, string region, int region_rank) {
    int index = hashSum(team, tableSize);
    if(hashTable[index] == NULL) {
        hashTable[index] = new TeamElem(team, state, top25_ranking, region, region_rank);
    } else {
        TeamElem *temp = hashTable[index];
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new TeamElem(team, state, top25_ranking, region, region_rank);
        temp->next->previous = temp;
    }
    return;
}


void MMTable::deleteTeam(string team) {
    int index = hashSum(team, tableSize);
    TeamElem *temp = hashTable[index];
    while (temp != NULL) {
        if (temp->team == team) {
            if(temp->previous != NULL) {                //if not the 1st element in an index row
                temp->previous->next = temp->next;
                if(temp->next != NULL)                  //if not the last element in an index row
                    temp->next->previous = temp->previous;
            }
            // First element in index row
            else {
                if (temp->next == NULL) {               // the first and last element in an index row
                    hashTable[index] = temp->next;
                } else {
                    hashTable[index] = temp->next;
                    temp->next->previous = NULL;
                }
            }
            return;
        }
        temp = temp->next;
    }
    delete temp;
    cout << "Team not found in March Madness Database" <<endl;
    cout<<endl;
    return;
}

TeamElem *MMTable::findTeam(string name) {
    int index = hashSum(name, tableSize);
    TeamElem *temp = hashTable[index];
    while (temp != NULL) {
        if (temp->team == name) {
            cout<<"Rank: "<<temp->region<<" #"<<temp->region_rank <<": " << temp->team <<", "<< temp->state <<endl;
            cout<<"Games won so far: "<<temp->games_won<<", "<<"Games lost so far: "<<temp->games_lost<<", "<<"Games tied so far: "<<temp->games_tied<<endl;
            if(temp->top25_rank > 0) {
              cout<<"Overall Rank: "<<temp->top25_rank<<endl;
            } else {
              cout<<"Not ranked in Top 25"<<endl;
            }
            cout<<endl;
            return temp;
        }
        temp = temp->next;
    }
    cout << "Team not found in March Madness Database" <<endl;
    return temp;
}


void MMTable::compareTeams(string name1, string name2) {
    cout<<endl;
    cout<<"TEAM 1: "<<endl;
    TeamElem *team1 = findTeam(name1);
    cout<<"vs. TEAM 2: "<<endl;
    TeamElem *team2 = findTeam(name2);

    if (team1 == NULL || team2 == NULL) {
        return;
    } else {
      if(((team1->top25_rank < team2->top25_rank) && team1->top25_rank > 0) || (team1->region_rank < team2->region_rank)) {
        cout<<team1->team<<" likely to beat "<<team2->team<<endl;
      } else if( ((team2->top25_rank < team1->top25_rank && team2->top25_rank > 0)) || (team2->region_rank < team1->region_rank)) {
        cout<<team1->team<<" likely to beat "<<team2->team<<endl;
      } else {
        cout<<team1->team<<" and "<<team2->team<<" likely to tie."<<endl;
      }
    }
    return;
}


void MMTable::playTeams(string name1, string name2) {
    cout<<endl;
    cout<<"TEAM 1: "<<endl;
    TeamElem *team1 = findTeam(name1);
    cout<<"vs. TEAM 2: "<<endl;
    TeamElem *team2 = findTeam(name2);

    if(team1 == NULL || team2 == NULL) {
        return;
    } else {
        if((team1->top25_rank > 0 && team2->top25_rank > 0) || team1->region == team2->region) {
            if(((team1->top25_rank < team2->top25_rank) && team1->top25_rank > 0) || (team1->region_rank < team2->region_rank)) {
              cout<<team1->team<<" beats "<<team2->team<<"!"<<endl;
              team1->games_won++;
              team2->games_lost++;
            } else if( ((team2->top25_rank < team1->top25_rank && team2->top25_rank > 0)) || (team2->region_rank < team1->region_rank)) {
              cout<<team2->team<<" beats "<<team1->team<<"!"<<endl;
              team2->games_won++;
              team1->games_lost++;
            } else {
              cout<<team1->team<<" and "<<team2->team<<" tie!"<<endl;
              team2->games_tied++;
              team1->games_tied++;
            }
      } else {
        cout<<"Teams must be in Top 25 or in same bracket region to play each other."<<endl;
      }
    }
    return;
}



void MMTable::findCommonStates(string name) {
    //Traverse hash table until finding a match to input team name
    int index = hashSum(name, tableSize);
    TeamElem *team1 = hashTable[index];
    while (team1 != NULL) {
        if (team1->team == name)
            break;
        team1 = team1->next;
    }
    if(team1 == NULL) {
        cout << "Team not found in March Madness Database" <<endl;
        return;

    } else {
        // Find matching teams with common state
        TeamElem *team2;
        int counter = 0;
        cout<<endl<<team1->state<<":"<<endl;

        for(int i = 0; i<tableSize; i++) {
            team2 = hashTable[i];
            while (team2 != NULL) {
                if(team2->state == team1->state) {
                  cout<<team2->team<<endl;
                  counter++;
                }
                team2 = team2->next;
            }
        }
        cout<<team1->state<<" has "<<counter<<" teams in March Madness!"<<endl;
        return;
  }
}


int MMTable::hashSum(string key, int table_size) {
    int sum = 0;
    for(int i = 0; i<key.size(); i++)
        sum += key[i];
    sum %= table_size;
    return sum;
}
