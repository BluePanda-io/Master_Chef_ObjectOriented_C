#include <iostream>
#include "Team.h"

using namespace std;

Team::Team()
{
    numPlayers=0;
    ilika=0;
    meridesFagito=14; // Xeroume apo prin oti tha einai 14
    for (int i=0;i<11;i++)
    {
        IDPlayersTeam[i]=-1; // Ta kanoume ola -1 gia na min berdeftoume me kapio ID
    }
}

Team::~Team()
{

    cout<<"This object is destroyed already"<<endl;

}


void Team::setTeam(int ilik,int mer) // Arxikopiume ta ilika kai tis merides
{
    ilika=ilik;
    meridesFagito=mer;

}

void Team::addNewPlayer(int ID) // To ID einai i thesi ston basiko pinaka
{

    IDPlayersTeam[numPlayers]=ID; // I proti timi pou tha exei einai 0 ara tha bali ton pekti sto 0 kai meta tha dixi to 1 gia ton epomeno pekti
    numPlayers+=1; // Dixno ton epomeno pekti

}

void Team::showInfTeam() // Print ola ta stixia tis omadas kai tous pektes pou simetexoun
{

    cout<<"numPlayers "<<numPlayers<<"\nilika "<<ilika<<"\nmeridesFagito "<<meridesFagito<<endl;

    for (int i=0;i<numPlayers;i++)
    {
        cout<<"Player "<<IDPlayersTeam[i]<<endl;
    }

    cout<<endl;

}


int Team::getIDPlayer(int IDinTeamArray) //IDinTeamArray = I thesi tou pekti ston pinaka tis omadas
{
    return(IDPlayersTeam[IDinTeamArray]); // T id tou pinaka antikimenon player (to ID tou pekti ston geniko pinaka)

}














