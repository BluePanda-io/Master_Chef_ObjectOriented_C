#include "TeamCompetition.h"
#include "FoodAward.h"
#include "Round.h"
#include "Team.h"
#include "Competition.h"
#include "Player.h"

#include<iostream>
#include <string>
#include<time.h>

using namespace std;

TeamCompetition::TeamCompetition()
{
    id = 0;
    name = "";
    winner = "";

    // Apo mono tou theti to foodAward
}

TeamCompetition::TeamCompetition(int i, string NameComp, FoodAward FD)
{
    id=i;
    name=NameComp;
    winner="";
    FdAward=FD;
}

void TeamCompetition::setIdNameFooDAw(int idt,string namet,FoodAward FD)
{
    id=idt;
    name=namet;
    FdAward=FD;
}

void TeamCompetition::getFoodAward()
{
    FdAward.status();
}

void TeamCompetition::getInformStatusFD()
{
    cout<<"id "<<id<<"\nname "<<name<<"\nwinner "<<winner<<endl;
    FdAward.status();

}

int TeamCompetition::compete(Team &team1, Team &team2)
{
    srand(time(NULL));


    int wins1,wins2,round;

    wins1=0;
    wins2=0;
    round=0;

    round++;

    Player* team1PL;
    Player* team2PL;
    Player* Play1Init;
    Player* Play2Init;

    team1PL = team1.getPlayers();
    team2PL = team2.getPlayers();
    Play1Init=team1PL;
    Play2Init=team2PL;

    int Play1,Play2;

    Play1 = team1.getNumberOfPlayers();
    Play2 = team2.getNumberOfPlayers();


    int CouPlayers;


    while (round<4)
    {
        int PlId;
        float meanTech1=0;
        float meanFatig1=0;
        float meanTech2=0;
        float meanFatig2=0;

        CouPlayers = rand()%11+1; // posoi pektes tha pexoun kathe fora


        team1PL=Play1Init;
        team2PL=Play2Init;

        Play1 = team1.getNumberOfPlayers();
        Play2 = team2.getNumberOfPlayers();

        for (int i=0;i<CouPlayers;i++)
        {
            PlId = rand()%Play1;
            team1PL[PlId].compete();
            meanFatig1=meanFatig1+team1PL[PlId].getFatigue();
            meanTech1=meanTech1+team1PL[PlId].getTechnique();

            Play1=Play1-1;
            team1PL[PlId] = team1PL[Play1];




            PlId = rand()%Play2;
            team1PL[PlId].compete();
            meanFatig2=meanFatig2+team2PL[PlId].getFatigue();
            meanTech2=meanTech2+team2PL[PlId].getTechnique();

            Play2=Play2-1;
            team2PL[PlId] = team2PL[Play2];
        }
        meanFatig1=meanFatig1/CouPlayers;
        meanFatig2=meanFatig2/CouPlayers;

        meanTech1=meanTech1/CouPlayers;
        meanTech2=meanTech2/CouPlayers;

        cout<<meanTech1<<"  "<<meanTech2<<endl;

        int Flag;
        if (meanTech1>meanTech2)
        {
            Flag=0;
        }
        else if (meanTech1<meanTech2)
        {
            Flag=1;
        }
        else // (meanTech1==meanTech2)
        {
            if (meanFatig1<meanFatig2)
            {
                Flag=0;
            }
            else
            {
                Flag=1;
            }
        }

        cout<<Flag<<endl;

        if (Flag==0)
        {
            rounds[round-1].setId(0);
            rounds[round-1].setDuration(20);
            rounds[round-1].setWinner(team1.getColor());
            wins1++;
        }
        else
        {
            rounds[round-1].setId(0);
            rounds[round-1].setDuration(20);
            rounds[round-1].setWinner(team2.getColor());
            wins2++;
        }

        rounds[round-1].status();

        round++;
    }

    cout<<wins1<<"  "<<wins2<<endl;

    if (wins1>=2)
    {
        team1.setWins(team1.getWins()+1);
        team1.setSupplies(team1.getSupplies()+FdAward.getBonusSupplies());
        return 0;
    }
    else
    {
        team2.setWins(team2.getWins()+1);
        team2.setSupplies(team2.getSupplies()+FdAward.getBonusSupplies());
        return 1;
    }




}


TeamCompetition::~TeamCompetition()
{
    cout<<"\n\n\n\n\n This object is destroyed already"<<endl;
}
