#include <iostream>
#include <string>


#include "Team.h"
#include "Player.h"


using namespace std;

int main()
{
    //-------------------Players Initialization------------------
    Player Pl[22];
    int numPl;

    //Paradigma gia 5 pektes
    Pl[0].setNSAO("Miltos","Men",18,"programmer");
    Pl[1].setNSAO("Fotis","Men",20,"Volley");
    Pl[2].setNSAO("Danai","Yoman",17,"programmer");
    Pl[3].setNSAO("Kapten","Men",13,"lay");
    Pl[4].setNSAO("Mays","Men",11,"superman");

    numPl=5;
    //-------------------END Players Initialization------------------


    //-------------------Team Initialization------------------
    Team Tm[2];

    Tm[0].setTeam(5,13);
    Tm[1].setTeam(12,14);


    //-------------------END Team Initialization------------------


    int Flagi=3;
    int IDPlayer,Team0or1;
    int NameOrArray,positionInTeam,RealIDplayer;
    string NamePlayer;

    /*NamePlayer="helo";

    int s;
    s=NamePlayer.compare("hello");

    cout<<s<<endl;*/

    while(Flagi!=4)
    {
        cout<<"If you want to Add a New Player in a Team press 1"<<endl;
        cout<<"If you want to Watch the Information for a team press 2"<<endl;
        cout<<"If you want to Watch the Information for a Player in a Team press 3"<<endl;
        cout<<"If you want to stop the program press 4"<<endl;
        cin>>Flagi;

        if (Flagi==1) // Prosthetoume atomo stin omada
        {
            cout<<"In which team you want to add a player Red=0, Blue=1, and what is the ID of the player (0,21)"<<endl;
            cin>>Team0or1>>IDPlayer;
            Tm[Team0or1].addNewPlayer(IDPlayer);
        }
        if (Flagi==2)// Show the results and the player that is added to the team
        {
            cout<<"Which team you want to show the  Red=0, Blue=1"<<endl;
            cin>>Team0or1;
            Tm[Team0or1].showInfTeam();
        }
        if (Flagi==3)
        {
            cout<<"what team you want to see the player Red=0, Blue=1, You want to find the player from name = 0 or ID in the Team Array = 1"<<endl;
            cin>>Team0or1>>NameOrArray;

            if (NameOrArray==0) // You want to find the player with the Name
            {
                cout<<"What is the Name of the Player"<<endl;
                //NamePlaye="Msfltos";
                //cout<<NamePlayer<<endl;
                cin>>NamePlayer;

                for (int i=0;i<numPl;i++)
                {
                    if (NamePlayer.compare(Pl[i].getName())==0) // This is the player that we are looking for
                    {
                        Pl[i].showPlayer();
                    }
                }


            }
            else if (NameOrArray==1) // You want to find the player with the ID in the array
            {
                cout<<"What is the ID - position in the team"<<endl;
                cin>>positionInTeam;

                RealIDplayer=Tm[Team0or1].getIDPlayer(positionInTeam); // Meso tou pinaka brisko tin pragmatiki thesi

                //cout<<RealIDplayer<<endl;

                Pl[RealIDplayer].showPlayer(); // Meso tis pragmatikis thesis dixno ta stixia tou pekti

            }


        }

    }

    cout<<"endl"<<endl;


    return 0;
}











