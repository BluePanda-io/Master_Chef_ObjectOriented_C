#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <string>

using namespace std;

class Player
{

    string name;
    string sex;
    int age;
    string occupation;


    float skill;
    float tiredLVL;
    float popLVL;


    public:
        Player();
        Player(string nam, string se,int ag,string occup);
        ~Player();


        void setNSAO(string nam, string se,int ag,string occup);
        void showPlayer();
        string getName();


        void DuringWeek();
        void talkPeople();
        void endOfWeek();
        void simetoxiSeDiagonismo();

};

#endif // PLAYER_H_INCLUDED
