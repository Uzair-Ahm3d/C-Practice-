#include<iostream>
#include<ctime>
#include<string>
#include<cstring>
#include<fstream>
#include<cstdlib>
#include<iomanip>
#include<conio.h>

//#include "scoreboard.h"
using namespace std;

// function to show the scorecard of all the batsmen

void scoreboard(string name[], int runs[], int balls_faced[], float strk_rate[])
{
    system("CLS");
    // clearing screen after every inning

    cout << "----------------------------------------------------------------------" << endl;
    cout << "----------------------------------------------------------------------" << endl;

    cout << "--------------------------SCOREBOARD-------------------------------------" << endl;
    cout << "-------------------------BATTING SIDE-----------------------------------" << endl;
    cout << "----------------------------------------------------------------------" << endl << endl;

    cout << "BATSMAN\t\t\t" << "RUNS\t\t" << "BOWL FACED\t\t" << "Strike Rate" << endl << endl;

    for (int i = 0; i < 11; i++)
    {
        //cout<<"BATSMAN |"<<setw(20)<<"RUNS |"<<setw(20)<<"BOWL FACED |"<<endl<<endl;

        cout << name[i] << "|\t\t\t" << runs[i] << "|\t\t" << balls_faced[i] << "|\t\t" << strk_rate[i] << endl << endl;
    }
}
// function to show the scoreboard of all the bowlers

void scoreboard2(string bowl_name[], int wickets_taken[])
{

    cout << "----------------------------------------------------------------------" << endl;
    cout << "----------------------------------------------------------------------" << endl;

    cout << "--------------------------SCOREBOARD-------------------------------------" << endl;
    cout << "-------------------------BOWLING SIDE-----------------------------------" << endl;
    cout << "----------------------------------------------------------------------" << endl << endl;

    cout << "BOWLER NAME\t\t\t" << "WICKETS TAKEN" << endl << endl;

    for (int i = 5; i <= 10; i++)
    {

        cout << bowl_name[i] << "\t\t\t" << wickets_taken[i] << endl << endl;
    }
}
// function for the innings of both teams(bowling and batsmen)

int score(string name[], string bowl_name[], int n = 2)// float str_rate[],int no_fours[], int no_sixes[], int bowls_faced[])
{
    int runs[11] = { 0 }, balls_faced[] = { 0 }, wickets_taken[11] = { 0 }, runs_given[11] = { 0 };

    float strk_rate[11] = { 0 };

    int player1 = 0, score_p1 = 0;

    int player2 = 0, score_p2 = 0;

    int ip1 = 0, ip2 = 1;           // indexes for name array

    int bowl_index = 10, wickets = 0, bolwer = 0; // wickets for number of wickets and bowler for index of bowlers

    int runs1 = 0, runs2 = 0, scores1 = 0, scores2 = 0;

    int input;

    int p1 = 1, p2 = 2;

    int temp1 = 0, temp2 = 0, total_scores = 0, shift = p1;

    int bowls_1 = 0, bowls_2 = 0;

    cout << endl << endl;

    // player is facing the ball

    cout << name[ip1] << " is facing the ball" << endl;

    cout << bowl_name[bowl_index] << " is bowling " << endl;

    // index is for the bowlers

    cout << name[ip1] << " score = " << scores1 << endl;

    for (int i = 0; i < n; i++)
    {
        // bowl index is for bowlers from 5 to 10 in a team

        if (bowl_index == 5)
        {
            bowl_index = 10;
        }
        for (int j = 0; j < 6; j++)
        {
            cout << "Press Enter to Bowl" << endl;

            if (cin.get())
            {
                if (shift == p1)       // shift is for turn of player
                {
                    player1 = rand() % 7 - 1;   // implementing condition of runs which are already given
                }
                else if (shift == p2)
                {
                    player2 = rand() % 7 - 1;
                }
                // if run is 1 then the next player comes on strike to bat

                if (shift == p1)
                {
                    if (player1 != -1)
                    {
                        if (player1 % 2 != 0)
                        {
                            bowls_1++;

                            cout << bowl_name[bowl_index] << " is bowling " << j + 1 << " bowl" << endl;

                            cout << "Score hit on the bowl is = " << player1 << endl;

                            scores1 += player1;

                            cout << name[ip2] << " is facing the ball" << endl;

                            cout << name[ip2] << " score = " << scores2 << endl;

                            p2 += 2;  // incrementing so that value of p1 and p2 can never be same

                            shift = p2;

                            runs[runs2] = scores1;

                            balls_faced[runs2] = bowls_1;

                            // calculating strike rate of the bowler

                            strk_rate[ip1] = float((runs[runs2] * 100)) / balls_faced[runs2];

                            cout << endl;
                        }
                        else
                        {
                            bowls_1++;

                            cout << bowl_name[bowl_index] << " is bowling " << j + 1 << " bowl" << endl;

                            cout << "Score hit on the bowl is = " << player1 << endl;

                            // calculating score of the player 1

                            scores1 += player1;

                            cout << name[ip1] << " is facing the ball" << endl;

                            cout << name[ip1] << " score = " << scores1 << endl;

                            p1 += 1;

                            shift = p1;

                            runs[runs2] = scores1;

                            balls_faced[runs2] = bowls_1;

                            strk_rate[ip1] = float((runs[runs2] * 100)) / balls_faced[runs2];
                        }
                    }
                }
                else if (shift == p2)
                {
                    if (player2 != -1)
                    {
                        if (player2 % 2 != 0)
                        {
                            bowls_2++;

                            cout << bowl_name[bowl_index] << " is bowling " << j + 1 << " bowl" << endl;

                            cout << "Score hit on the bowl is = " << player2 << endl;

                            // calculating the score of player 2

                            scores2 += player2;

                            cout << name[ip1] << " is facing the ball" << endl;

                            cout << name[ip1] << " score = " << scores1 << endl;

                            p1 += 1;

                            shift = p1;

                            runs[runs2] = scores2;

                            balls_faced[runs2] = bowls_2;

                            strk_rate[ip2] = float((runs[runs2] * 100)) / balls_faced[runs2];

                            //scoreboard(name,runs,balls_faced);
                        }
                        else
                        {
                            bowls_2++;

                            cout << bowl_name[bowl_index] << " is bowling " << j + 1 << " bowl" << endl;

                            cout << "Score hit on the bowl is = " << player2 << endl;

                            scores2 += player2;

                            cout << name[ip2] << " is facing the ball" << endl;

                            cout << name[ip2] << " score = " << scores2 << endl;

                            p2 += 2;

                            shift = p2;

                            runs[runs2] = scores2;

                            balls_faced[runs2] = bowls_2;

                            strk_rate[ip2] = float((runs[runs2] * 100)) / balls_faced[runs2];
                        }
                    }
                }
                if (shift == p1)             // working out(-1)
                {
                    if (player1 == -1)
                    {
                        bowls_1++;

                        cout << bowl_name[bowl_index] << " is bowling " << j + 1 << " bowl" << endl;

                        cout << "Score hit on bowl is = " << player1 << endl;

                        cout << name[ip1] << " is out" << endl;

                        cout << "Score of " << name[ip1] << " is = " << scores1 << endl << "\tBalls faced = " << bowls_1 << endl;

                        runs[runs1] = scores1;

                        balls_faced[runs1] = bowls_1;

                        scores1 = 0;

                        bowls_1 = 0;

                        runs1 += 2;  // incrementing index for next player

                        ip1 += 2;    // for names array

                        wickets_taken[bowl_index] += 1;

                        cout << "Wickets taken by " << bowl_name[bowl_index] << "are = " << wickets_taken[bowl_index] << endl;
                    }
                }
                else if (shift == p2)
                {
                    if (player2 == -1)
                    {
                        bowls_2++;

                        cout << bowl_name[bowl_index] << " is bowling " << j + 1 << " bowl" << endl;

                        cout << "Score hit on bowl is = " << player2 << endl;

                        cout << name[ip2] << " is out" << endl;

                        cout << "Score of " << name[ip2] << " is = " << scores2 << "/tBalls faced = " << bowls_2 << endl;

                        runs[runs2] = scores2;

                        balls_faced[runs2] = bowls_2;

                        runs2 += 2;

                        scores2 = 0;

                        ip2 += 2;

                        bowls_2 = 0;

                        wickets_taken[bowl_index] += 1;

                        cout << "Wickets taken by " << bowl_name[bowl_index] << "are = " << wickets_taken[bowl_index] << endl;
                    }
                }
            }
            if (player1 != -1 || player2 != -1)
            {
                temp1 += player1; // storing scores

                temp2 += player2;
            }
        }
        bowl_index -= 1;

        scoreboard(name, runs, balls_faced, strk_rate);

        scoreboard2(bowl_name, wickets_taken);
    }
    total_scores = temp1 + temp2;

    cout << "Total score of team is = " << total_scores << endl << endl;

    return total_scores;
}
//below is a function for a toss that generates random numbers 0 and 1 if toss is equal to zero team Pakistan will bat first else england bat first
int coin_toss()
{
    int random_number = 0;

    srand((time(0)));

    random_number = rand() % 2;

    return random_number;
}
int main()
{
    int team1 = 0, team2 = 0;

    string pakistani_team[11] = { "Waim_Akram","Inzamam","Amer_Sohail","Ramiz_Raja","Imran_Khan","Javed_Miandad","Ijaz_Ahmed","Moin_Khan","Aqib_Javed","Mushtaq_Ahmed","Saleem_Malik" };

    string england_team[11] = { "Gharam_Gooch","Ian_Botham","Alec_Stewart","Graeme_Hick","NeilFair","Allan_lamb","Dermot_Reeve","Derek_Pringle","Phil_Defritas","Richard_Ill","Joy Root" };

    cout << "----------------------------WELCOME TO A CRICKET GAME------------------------------" << endl << endl;
    cout << "|========Team-PAKISTAN========\t\t|========Team-ENGLAND=========|" << endl;
    cout << "--------------------------\t\t-----------------------------" << endl;



    cout << "--------------------------\t\t-----------------------------" << endl;

    for (int i = 0; i < 11; i++)
    {
        cout << "|\t" << pakistani_team[i] << "\t |" << "\t\t" << " |\t" << setw(20) << england_team[i] << "\t |" << "|\t" << endl << endl;
    }
    cout << endl << endl;

    int random_number = coin_toss();

    if (random_number == 1)
    {
        cout << "Pakistan has won the toss and elected to bat first" << endl << endl;

        cout << "Pakistan cricket team " << endl << endl;

        //cout<<"Batting"<<setw(25)<<"R"<<setw(10)<<"B"<<setw(10)<<"M"<<setw(10)<<"4s"<<setw(10)<<"6s"<<setw(10)<<"SR"<<endl<<endl;

        for (int i = 0; i < 11; i++)
        {
            //cout<<"|\t"<<pakistani_team[i]<<"\t |"<<"\t\t"<<endl;

            cout << pakistani_team[i] << endl;
        }
        team1 = score(pakistani_team, england_team);
    }
    else
    {
        cout << "England has won the toss and elected to bat first " << endl << endl;

        cout << "England inning" << endl << endl;

        //cout<<"Batting"<<setw(25)<<"R"<<setw(10)<<"B"<<setw(10)<<"M"<<setw(10)<<"4s"<<setw(10)<<"6s"<<setw(10)<<"SR"<<endl<<endl;

        for (int j = 0; j < 11; j++)
        {
            //cout <<"|\t"<<england_team[j]<<"\t |"<<endl;

            cout << england_team[j] << endl;
        }
        team2 = score(england_team, pakistani_team);
    }
    cout << endl << endl;

    // creating a file
 //scoreboard(name,runs,balls_faced);

    fstream new_file;

    new_file.open("configuration.txt", ios::out);

    if (!new_file)
    {
        cout << "this file doesn't exits" << endl;
    }
    else
    {
        new_file << "2";                   // reading overs from a file

        new_file.close();
    }
    new_file.open("configuration.txt", ios::in);

    if (!new_file)
    {
        cout << "file not created";
    }
    else
    {
        int overs;

        while (1)
        {
            new_file >> overs;

            if (new_file.eof())

                break;
        }
        cout << "Total number of overs are " << overs << endl << endl << endl;
    }
    new_file.close();

    if (random_number == 1)
    {
        team2 = score(england_team, pakistani_team);
    }
    else
    {
        team1 = score(pakistani_team, england_team);
    }
    if (team1 > team2)
    {
        cout << "Pakistan Won!!" << endl;
    }
    else if (team1 < team2)
    {
        cout << "England Won!!" << endl;
    }
    else
    {
        cout << "Game Draw" << endl;
    }
    return 0;
}