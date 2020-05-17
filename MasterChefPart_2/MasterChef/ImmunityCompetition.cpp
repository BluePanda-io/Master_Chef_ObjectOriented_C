
#include "ImmunityCompetition.h"
#include "ImmunityAward.h"
#include "Player.h"

#include <iostream>

using namespace std;

ImmunityCompetition::ImmunityCompetition()
{
    id = 0;
    name = "";
    winner = "";
    // Everything is already been created because I use only objects
}

ImmunityCompetition::ImmunityCompetition(int ID, string names, ImmunityAward IA)
{
    id = ID;
    name = names;
    winner = "";
    ImmAw=IA;
}

void ImmunityCompetition::setIdNameImmAw(int idt,string namet,ImmunityAward IA)
{
    id = idt;
    name = namet;
    ImmAw=IA;
}

ImmunityAward ImmunityCompetition::getImmunityAward()
{
    return(ImmAw);
}

void ImmunityCompetition::setImmunityAward(ImmunityAward IA)
{
    ImmAw=IA;
}

void ImmunityCompetition::statusImmComp()
{
    cout<<"id "<<id<<"\nname "<<name<<"\nwinner "<<winner<<endl;
    ImmAw.status();
}

void ImmunityCompetition::compete(Team &team)
{
    Player *plT;
    plT = team.getPlayers();

    float MaxPlayer,temp;
    int MaxPlayerID;
    MaxPlayer=0;
    for (int i=0;i<11;i++)
    {
        temp = 0.75*(plT[i].getTechnique())+0.25*(100-plT[i].getFatigue());


        if (MaxPlayer<temp) // Find maximum number
        {
            MaxPlayer=temp;
            MaxPlayerID=i;
        }
    }
    int t = plT[MaxPlayerID].getWins();
    plT[MaxPlayerID].setWins(t+1);

    cout<<"NIKITIS"<<endl;
    plT[MaxPlayerID].status();

}

ImmunityCompetition::~ImmunityCompetition()
{
    cout<<"\n\n\n\n\n This object is destroyed already"<<endl;
}










