#include <iostream>
#include <vector>
#include <random>
#include <time.h>

//#define ENABLE_BETA_SETTINGS



using namespace std;

struct gameMode 
{
	bool confirmEjects;
	int emergencyMeetings;
#ifdef ENABLE_BETA_SETTINGS
	bool anonymousVoting;
#endif
	int emergencyCooldown;
	int discussionTime;
	int votingTime;
	int playerSpeed;
	int crewmateVision;
	int imposterVision;
	int killCooldown;
	int killDistance;
#ifdef ENABLE_BETA_SETTINGS
	int taskbarUpdates;
#endif
	bool visualTasks;
	int commonTasks;
	int longTasks;
	int shortTasks;
};

int emergencyMeetings[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int emergencyCooldown[] = {0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60};
int discussionTime[] = {0, 15, 30, 45, 60, 75, 90, 105, 120};
int votingTime[20]; 
double playerSpeed[11];
double crewmateVision[20];
double imposterVision[20];
double killCooldown[21];
string killDistance[] = {"short", "medium", "long"};
string taskbarUpdates[] = {"always", "meetings", "never"};
int commonTasks[] = {0, 1, 2};
int longTasks[] = {0, 1, 2, 3};
int shortTasks[] = {0, 1, 2, 3, 4, 5};

int main()
{
	srand(time(NULL));

	gameMode gm;
	int randInt;

	for(int i = 0; i < 20; i++)
	{
		votingTime[i] = 15*i;	
		crewmateVision[i] = 0.25 + i*0.25;
		imposterVision[i] = 0.25 + i*0.25;
		killCooldown[i] = 10 + 2.5*i;
	}
	killCooldown[20] = 60;

	for(int i = 0; i < 11; i++)
		playerSpeed[i] = 0.25*i + 0.5;
	

	randInt = rand();

	gm.confirmEjects = rand() % 2;
	gm.emergencyMeetings = rand() % 9;
#ifdef ENABLE_BETA_SETTINGS
	gm.anonymousVoting = rand() % 2;
#endif
	gm.emergencyCooldown = rand() % 13;
	gm.discussionTime = rand() % 9;
	gm.votingTime = rand() % 20;
	gm.playerSpeed = rand() % 11;
	gm.crewmateVision = rand() % 20;
	gm.imposterVision = rand() % 20;
	gm.killCooldown = rand() % 21;
	gm.killDistance = rand() % 3;
#ifdef ENABLE_BETA_SETTINGS
	gm.taskbarUpdates = rand() % 3;
#endif
	gm.visualTasks = rand() % 2;
	gm.commonTasks = rand() % 3;
	gm.longTasks = rand() % 4;
	gm.shortTasks = rand() % 6;

	cout << boolalpha;

	cout << "confirm ejects: " << gm.confirmEjects << endl;
	cout << "emergency meetings: " << emergencyMeetings[gm.emergencyMeetings] << endl;
#ifdef ENABLE_BETA_SETTINGS
	cout << "anonymous voting: " << gm.anonymousVoting << endl;
#endif
	cout << "emergency cooldown: " << emergencyCooldown[gm.emergencyCooldown] << endl;
	cout << "discussion time: " << discussionTime[gm.discussionTime] << endl;
	cout << "voting time: " << votingTime[gm.votingTime] << endl;
	cout << "player speed: " << playerSpeed[gm.playerSpeed] << endl;
	cout << "crewmate vision: " << crewmateVision[gm.crewmateVision] << endl;
	cout << "imposter vision: " << imposterVision[gm.imposterVision] << endl;
	cout << "kill cooldown: " << killCooldown[gm.killCooldown] << endl;
	cout << "kill distance: " << killDistance[gm.killDistance] << endl;
#ifdef ENABLE_BETA_SETTINGS
	cout << "taskbar updates: " << taskbarUpdates[gm.taskbarUpdates] << endl;
#endif
	cout << "visual tasks: " << gm.visualTasks << endl;
	cout << "common tasks: " << commonTasks[gm.commonTasks] << endl;
	cout << "long tasks: " << longTasks[gm.longTasks] << endl;
	cout << "short tasks: " << shortTasks[gm.shortTasks] << endl;
}
