#include "Team.h"
#include "Player.h"
#include "FoodAward.h"
#include "Competition.h"
#include "TeamCompetition.h"
#include "ImmunityAward.h"
#include "ImmunityCompetition.h"
#include "CreativityCompetition.h"

using namespace std;

// Index 0 = Red Team, Index 1 = Blue Team
Team teams[2] = { Team("Red"), Team("Blue")};
int Wn;
int competitionId = 0;
void menu();
void normalDay();
void teamCompetitionDay();
void immunityCompetitionDay();
void creativityCompetitionDay();

int main()
{


    menu();

    return 0;
}

void menu()
{
    int choice = -1;

    while(choice != 0)
    {
        cout << endl << "1.Normal Day." << endl;
        cout << "2.Team Competition Day." << endl;
        cout << "3.Immunity Competition Day." << endl;
        cout << "4.Creativity Competition Day." << endl;
        cout << "0.Quit" << endl;

        cin >> choice;

        switch(choice)
        {

        case 1:
            normalDay();
            break;
        case 2:
            teamCompetitionDay();
            break;
        case 3:
            immunityCompetitionDay();
            break;
        case 4:
            creativityCompetitionDay();
            break;
        case 0:
            break;
        default:
            cout << "Incorrect Input. Choose between 1 and 3. Press 0 to quit." << endl;

        }
    }
}

void normalDay()
{

    teams[0].teamWorks();
    teams[1].teamWorks();

    teams[0].teamEats();
    teams[1].teamEats();

    teams[0].teamEats();
    teams[1].teamEats();

    teams[0].teamSocializes();
    teams[1].teamSocializes();

    teams[0].teamSleeps();
    teams[1].teamSleeps();
}

void teamCompetitionDay()
{
    cout << endl << "This is a Team Competition day in the Master Chef Game." << endl << endl;

    teams[0].teamWorks();
    teams[1].teamWorks();

    teams[0].teamEats();
    teams[1].teamEats();

    FoodAward FA;

    TeamCompetition TC(competitionId,"Competition",FA);

    competitionId++;




    Wn = TC.compete(teams[0],teams[1]); // Tha xrisimopiithi stin epomeni funciton

    teams[0].teamEats();
    teams[1].teamEats();

    teams[0].teamSocializes();
    teams[1].teamSocializes();

    teams[0].teamSleeps();
    teams[1].teamSleeps();

}

void immunityCompetitionDay()
{

    cout << endl << "This is a Immunity Competition day in the Master Chef Game." << endl << endl;

    teams[0].teamWorks();
    teams[1].teamWorks();

    teams[0].teamEats();
    teams[1].teamEats();

    ImmunityAward IA;

    ImmunityCompetition IC(competitionId,"Ouiiiiii",IA);

    competitionId++;

    IC.compete(teams[Wn]);

    teams[0].teamEats();
    teams[1].teamEats();

    teams[0].teamSocializes();
    teams[1].teamSocializes();

    teams[0].teamSleeps();
    teams[1].teamSleeps();

}

void creativityCompetitionDay()
{

    cout << endl << "This is a Creativity Competition day in the Master Chef Game." << endl << endl;

    teams[0].teamWorks();
    teams[1].teamWorks();

    teams[0].teamEats();
    teams[1].teamEats();

    ExcursionAward EA;

    CreativityCompetition CC(competitionId,"Yea",EA);
    competitionId++;

    CC.compete(teams[0],teams[1]);

    teams[0].teamEats();
    teams[1].teamEats();

    teams[0].teamSocializes();
    teams[1].teamSocializes();

    teams[0].teamSleeps();
    teams[1].teamSleeps();
}
