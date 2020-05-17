#ifndef TEAMCOMPETITION_H_INCLUDED
#define TEAMCOMPETITION_H_INCLUDED

#include "FoodAward.h"
#include "Round.h"
#include "Competition.h"
#include "Team.h"
#include <string>

class TeamCompetition: public Competition
{
    FoodAward FdAward;
    Round rounds[3];

    public:
        TeamCompetition();
        TeamCompetition(int i, string NameComp, FoodAward FD);
        ~TeamCompetition();

        void setIdNameFooDAw(int idt,string namet,FoodAward FD);

        void getFoodAward();

        void getInformStatusFD();


        int compete(Team &team1, Team &team2);

};

#endif // TEAMCOMPETITION_H_INCLUDED
