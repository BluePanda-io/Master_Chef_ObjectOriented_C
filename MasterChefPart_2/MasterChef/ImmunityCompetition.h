#ifndef IMMUNITYCOMPETITION_H_INCLUDED
#define IMMUNITYCOMPETITION_H_INCLUDED

#include "ImmunityAward.h"
#include "Competition.h"
#include "Team.h"

#include <string>

class ImmunityCompetition: public Competition
{
    ImmunityAward ImmAw;

    public:
        ImmunityCompetition();
        ImmunityCompetition(int ID, string names, ImmunityAward IA);
        ~ImmunityCompetition();

        void setIdNameImmAw(int idt,string namet,ImmunityAward IA);

        ImmunityAward getImmunityAward();

        void setImmunityAward(ImmunityAward IA);

        void statusImmComp();

        void compete(Team &team);
};

#endif // IMMUNITYCOMPETITION_H_INCLUDED
