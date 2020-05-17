#include "CreativityCompetition.h"
#include "Team.h"

#include<iostream>
using namespace std;

CreativityCompetition::CreativityCompetition()
{
    id = 0;
    name = "";
    winner = "";

    ingredient[0]="apple";
    ingredient[1]="bannana";

}

CreativityCompetition::CreativityCompetition(int idt,string namet, string ingr[10])
{
    id=idt;
    name=namet;
    winner = "";

    for (int i=0;i<10;i++)
    {
        ingredient[i]=ingr[i];
    }


}

CreativityCompetition::CreativityCompetition(int idt,string namet, ExcursionAward Exa2)
{
    id=idt;
    name=namet;
    winner = "";

    ExA = Exa2;


}

void CreativityCompetition::setIngr(string ingr[10])
{
    for (int i=0;i<10;i++)
    {
        ingredient[i]=ingr[i];
    }
}

string* CreativityCompetition::getIngr()
{
    return(ingredient);
}

void CreativityCompetition::getInformStatusCrCo()
{
    cout<<"id "<<id<<"\nname "<<name<<"\nwinner "<<winner<<endl;
    for (int i=0;i<10;i++)
    {
        cout<<ingredient[i]<<endl;
    }
    ExA.status();
}

void CreativityCompetition::compete(Team &team1, Team &team2)
{

    float maxTechnique = -1;
    int maxIndex = -1;
    int playerIndex = 0;

    Player AllPlayers[22];
    Player *Team1Pl;
    Player *Team2Pl;

    Team1Pl=team1.getPlayers(); // oi pektes is omadas ena
    Team2Pl=team2.getPlayers();

	int numPl1 = team1.getNumberOfPlayers();

	int count=0;
	for (int i=0;i<numPl1;i++)
    {
	   count++;
       AllPlayers[i]=Team1Pl[i];
    }


	for (int i=0;i<team2.getNumberOfPlayers();i++)
    {
	   count++;
       AllPlayers[i+numPl1]=Team2Pl[i];
    }

    /*for (int i=0;i<22;i++) // For Debug
    {
        cout<<i<<endl;
        AllPlayers[i].status();
    }*/


    float technique;
    for (int i=0;i<count;i++) // For Debug
    {
        technique = AllPlayers[i].getTechnique();

        if (maxTechnique<technique)
        {
            maxTechnique=technique;
            maxIndex=i;
        }
    }
    cout<<"Nikitis"<<endl;

    cout<<maxTechnique<<" "<<maxIndex<<endl;

    AllPlayers[maxIndex].status();

    AllPlayers[maxIndex].setTechnique(AllPlayers[maxIndex].getTechnique()+ExA.getTechniqueBonus());

    AllPlayers[maxIndex].setPopularity(AllPlayers[maxIndex].getPopularity()-ExA.getPopularityPenalty());



}

CreativityCompetition::~CreativityCompetition()
{
    cout<<"\n\n\n\n\n This object is destroyed already"<<endl;
}
