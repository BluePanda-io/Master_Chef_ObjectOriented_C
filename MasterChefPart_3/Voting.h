#ifndef VOTING_H_INCLUDED
#define VOTING_H_INCLUDED
#include <iostream>
#include <vector>
#include <map>
#include "Vote.h"
#include "Team.h"

using namespace std;

class Voting
{


public:

    static void departureProcess(int x,Team &team);
    static vector <Vote> votes;
    static map <string,int> res;
    static void votingProcess(Team &team);
};

#endif // VOTING_H_INCLUDED
