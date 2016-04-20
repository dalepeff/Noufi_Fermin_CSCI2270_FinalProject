# Noufi_Fermin_CSCI2270_FinalProject

Project Summary:
Program simulates a March Madness bracket using Hash Tables with conflict resolution through linked lists. We are planning on creating the following functions: 

	1. List Teams by Region
	2. List Teams by Top 25 Rank
	3. List Teams by Games Won So Far
	4. Insert A Team
	5. Delete A Team
	6. Find A Team
	7. Compare Two Teams
	8. Play Two Teams Against Eachother
	9. Find Teams in Same State
	10. Print Table Contents
	11. Quit

The program displays a main menu upon launch, and reads in user input from the command line to select a menu option.  Each menu option then executes the corresponding function based on (possible) additional user inputs.  The program initially reads in a text file the user provides at the command line to build a database of teams.  The functionality of the program allows the user to input additional teams, remove teams from the bracket, obtain information about the teams in a variety of ways and simulate game predicitions based on database information.

How to Run:
To run from the command line, make sure you have all 4 necessary files in the program folder or the .exe program.  These are:

	- main.cpp
	- MMTable.cpp
	- MMTable.h
	- marchMadness.txt

OR

	-program_name.exe
	-marchMadness.txt

You must compile the program before executing if you do not have the .exe file.  Then, run the program with the following command:
	
	./program_name marchMadness.txt
	
You may pick any option from the main menu by entering the number corresponding to the function you would like to execute and then hitting enter.

EX: 	

	===Main Menu===
	...
	...
	4. Insert A Team
	5. Delete A Team
	...
	...
	You type: 4

The program will then display a new set of command line prompts specific to "Insert Team."
Follow the corresponding prompts in a similar manner.  When the specific function is finished running, you will be returned to the main menu to pick a new option or QUIT the program by typing 11.  Any invalid input will be addressed and the program will quit and must be restarted.
	
	
Dependencies:
If you do not already have the .exe file, you must have the software required to compile C++ files.
To install, you can find a number of options here: https://gcc.gnu.org/

System	Requirements:
Program can run on Windows, MAC OS X and Linux.

Group	Members:
Camille Noufi and Jonathan Fermin

Contributors:


Open issues/bugs:

