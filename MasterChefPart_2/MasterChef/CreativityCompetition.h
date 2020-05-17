#ifndef CREATIVITYCOMPETITION_H_INCLUDED
#define CREATIVITYCOMPETITION_H_INCLUDED

#include <string>

#include "Competition.h"
#include "ExcursionAward.h"
#include "Team.h"

class CreativityCompetition: public Competition
{
    ExcursionAward ExA; // Epathlo ekdromis

    string ingredient[10];

    public:
        CreativityCompetition();
        CreativityCompetition(int idt,string namet, string ingr[10]);
        CreativityCompetition(int idt,string namet, ExcursionAward Exa2);
        ~CreativityCompetition();

        void setIngr(string ingr[10]);

        string* getIngr();
        void getInformStatusCrCo();

        void compete(Team &team1, Team &team2);

};

#endif // CREATIVITYCOMPETITION_H_INCLUDED
