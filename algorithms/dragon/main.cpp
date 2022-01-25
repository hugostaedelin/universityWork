#include <iostream>
#include <vector>
#include <math.h>
#include "graphics.h"
#define Mini 0

using namespace std;

void RempliTab(vector<bool> &P,int n){

    P.reserve(pow(2,n)-1);
    int i = 0;
    P.resize(static_cast<int>(pow(2,n))-1);
    P[Mini]=false;

    for(int pli=2;pli<=n;pli++){

        i++;
        P[i]=false;
        for(int j = i-1;j>=0;j--){

            i++;
            P[i] =! P[j];

        }

    }

}

/**

1) ecrire la fonction afficher(C) qui affiche le code de C à l'écran;
2) Ecrire la fonction void trace(const vector<bool> &C , int x , int y , int direction , int lon , int couleur
*/

void AfficherV1(const vector<bool> &P){


    for(int k=0;k<P.size();k++){

        cout<<P[k];
    }
}

void Trace(const vector<bool> &C , int x , int y , int direction , int lon , int couleur)
{
        moveto(x,y);
        x=x+lon;
        setcolor(couleur);
        for(int i=0;i<=C.size();i++)
        {

                lineto(x,y);

                switch(direction)
                {
                    case 0 :

                            if(C[i]==0)
                            {
                                y=y-lon;
                                direction = 1;
                            }
                            else
                            {
                                y=y+lon;
                                direction=3;
                            }
                             break;
                    case 1 :
                            if(C[i]==0)
                            {
                                x=x-lon;
                                direction = 2;
                            }
                            else
                            {
                                x=x+lon;
                                direction=0;
                            }
                             break;
                    case 2 :
                            if(C[i]==0)
                            {
                                y=y+lon;
                                direction = 3;
                            }
                            else
                            {
                                y=y-lon;
                                direction=1;
                            }
                             break;
                    case 3 :
                            if(C[i]==0)
                            {
                                x=x+lon;
                                direction = 0;
                            }
                            else
                            {
                                x=x-lon;
                                direction=2;
                            }
                             break;
                    }

        }
}

int main()
{
    int n=20;
    int L = 2;
    vector<bool> P;

    RempliTab(P,n);
    //AfficherV1(P);

    opengraphsize(720,720);

    Trace(P,300,300,0,L,GREEN);
    Trace(P,300,300,1,L,BLUE);
    Trace(P,300,300,2,L,RED);
    Trace(P,300,300,3,L,YELLOW);
    getch();

    return 0;
}
