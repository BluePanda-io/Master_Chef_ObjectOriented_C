#include "Voting.h"
#include "time.h"
#include <map>
#include "Team.h"

using namespace std;

void Voting::votingProcess(Team &team)
{
	// ================= Initialization ================
    srand(time(NULL)); % Gia na boro na dialego tixea
    int chs;
    int counter=0;
	int j;
    vector <int> imVotes;
	// ================= Initialization ================
	
    for(int i=0; i<11; i++) // doulebo gia olous tous pektes
    {
        if(team.getPlayers()[i].getAge()!=0)//an den exei figi o i paikths tote pshfisei
        {

			chs=rand() %11;
			while(team.getPlayers()[chs].getAge()==0 || team.getPlayers()[chs].getImmunity()!=false || chs==i) // kanonika aftos den einai beltistos tropos alla litourgi idika gia 11 pektes
                chs=rand() %11;


            Voting::votes.push_back(Vote(team.getPlayers()[chs].getName()));
            counter=counter+1;


            if(team.getPlayers()[i].getImmunity())
            {

                imVotes.push_back(chs);


                for(j=1 ; j<team.getPlayers()[i].getVotes() ; j++)
                {

                    bool fg=true;

                    while(fg)
                    {

                        while(team.getPlayers()[chs].getAge()==0 || team.getPlayers()[chs].getImmunity()!=false || chs==i)
                            chs=rand() %11;


                        if(j==1 && chs!=imVotes[0] )
                        {
                            imVotes.push_back(chs);
                            fg=false;

                        }
                        if(j==2)
                        {
                            if(chs!=imVotes[0] && chs!=imVotes[1])
                                fg=false;
                        }
                    }

                    Voting::votes.push_back(Vote(team.getPlayers()[chs].getName()));
                    counter++;




                }
            }
        }

    }

    for(int i=0; i<counter; i++)
        Voting::votes[i].status();
	
    Voting::depProc(counter, team);
}

void Voting::depProc(int x, Team &team)
{

    Voting::res.insert(pair<string,int>(Voting::votes[0].getVoted(),1));

    map<string, int>::iterator p;

    for(int i=1 ; i<x ; i++)
    {
        p = Voting::res.find(Voting::votes[i].getVoted());

        if(p != Voting::res.end())
            p->second = p->second +1;
        else
            Voting::res.insert(pair<string,int>(Voting::votes[i].getVoted(),1));
    }

    p=Voting::res.begin();
    for(p ; p!=Voting::res.end() ;++p)
        cout << "Name: \"" << p->first << "\" "<< "Votes: " << p->second << endl;
	
    cout<<"\n\n"<<endl;
    p=Voting::res.begin()++;
    int maxVotes=p->second;
    string candidate1=p->first;
    p++;
    int MaxVts1=p->second;
    string candidate2=p->first;

    if(MaxVts1>maxVotes)
    {
        int temp;
        string temp1;

        temp=maxVotes;
        temp1=candidate1;
        maxVotes=MaxVts1;
        candidate1=candidate2;
        MaxVts1=temp;
        candidate2=temp1;
    }

    p++;

    for(p ; p != Voting::res.end() ; ++p)
    {

        if(p->second > maxVotes)
        {
            MaxVts1=maxVotes;
            candidate2=candidate1;

            maxVotes = p->second;
            candidate1=p->first;
        }
        else if(p->second > MaxVts1)
        {
            MaxVts1=p->second;
            candidate2=p->first;
        }
    }

	// ================= Initialization ================
    int idx1=-1;int idx2=-1;
    int skl1;int skl2;
    bool fg=true;
	// ================= Initialization ================


    for(int i=0;i<11;i++)
    {
        if(team.getPlayers()[i].getName()==candidate1 || team.getPlayers()[i].getName() == candidate2)
        {
            team.getPlayers()[i].setCandidate(true);
            team.getPlayers()[i].status();
        }
    }



    for (int i=0; i<11; i++)
    {

        if(team.getPlayers()[i].getCandidate())

        {



            if(fg)
            {
                fg=false;
                idx1=i;
                skl1=team.getPlayers()[i].getTechnique();
            }
            else
            {
                idx2=i;
                skl2=team.getPlayers()[i].getTechnique();
            }


        }
    }

	// ================= Initialization ================
    int index=idx1;
	// ================= Initialization ================
	
	cout<<"\nidx1 :"<<idx1<<"     idx2 : "<<idx2<<endl;

    if(skl1>=skl2) // Elenxo ta skils1 kai 2
    {
        team.getPlayers()[idx1].setCandidate(false);

        team.getPlayers()[idx1].setWins(team.getPlayers()[idx1].getWins()+1);
        index=idx2;


    }
    else
    {
        team.getPlayers()[idx2].setWins(team.getPlayers()[idx2].getWins()+1);
        team.getPlayers()[idx2].setCandidate(false);

    }
    string adio=team.getPlayers()[index].getName();
    cout<<"\n Telefteos pektis o/h  :  "<<adio<<endl;

    team.removePlayer(index);


    Voting::res.clear();
    Voting::votes.clear();

}


