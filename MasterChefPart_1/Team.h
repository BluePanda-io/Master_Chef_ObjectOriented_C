#ifndef TEAM_H_INCLUDED
#define TEAM_H_INCLUDED

class Team
{
    int numPlayers;
    int ilika;
    int meridesFagito;
    int IDPlayersTeam[11]; // To pragmatiko ID ton player se aftin tin omada // I thesou tou player ston basiko pinaka (pou aniki se aftin tin omada)


    public:
        Team();
        void setTeam(int ilik,int mer);
        void addNewPlayer(int ID);
        void showInfTeam();
        int getIDPlayer(int IDinTeamArray);

        ~Team();
};

#endif // TEAM_H_INCLUDED


