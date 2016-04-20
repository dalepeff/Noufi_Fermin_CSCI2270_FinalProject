/**************************************
 * This is the declaration of the     *
 * march_madness class.   *
 *                                    *
 * Camille Noufi, Jonathan Fermin     *
 *************************************/

 #ifndef MMTABLE_H
 #define MMTABLE_H
 #include <string>
 #include <vector>

 using namespace std;

 struct TeamElem{
   std::string team;
   std::string state;
   int top25_rank;
   std::string region;
   int region_rank;
   int games_won;
   int games_lost;
   int games_tied;
 	TeamElem *next;
  TeamElem *previous;

 	TeamElem(){};
 	TeamElem(std::string in_team, std::string in_state, int in_top25_rank, std::string in_region, int in_region_rank)
 	{
 		team = in_team;
 		state = in_state;
    top25_rank = in_top25_rank;
    region = in_region;
    region_rank = in_region_rank;
    games_won = 0;
    games_lost = 0;
    games_tied = 0;
 		next = NULL;
 		previous = NULL;
 	}

 };

 class MMTable
 {
 	public:
 		MMTable();
 		~MMTable();
 		void printTableContents();
    void printTeamRegions();
    void printTop25Ranking();
    void printGamesWon();
    void insertTeam(std::string team, std::string state, int top25_ranking, std::string region, int region_rank);
 		void deleteTeam(std::string team);
 		TeamElem *findTeam(std::string team);
    void compareTeams(std::string team1, std::string team2);
    void playTeams(std::string team1, std::string team2);
    void findCommonStates(std::string team);
 	private:
 		int hashSum(std::string x, int s);
 		int tableSize = 10;
 		TeamElem *hashTable[10];

 };

 #endif // MMTABLE_H
