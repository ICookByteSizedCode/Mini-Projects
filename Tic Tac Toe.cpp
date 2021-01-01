#include<iostream>
#include<string>

using namespace std;

int main()
{
    int p1, p2, counta=0, countb=0, countc=0, i, j, p1r, p1c, p2r, p2c, temp=0;
    char a[3][3], chartemp;

    cout<<"_0_|_1_|_2_"<<endl; /*Original positions*/
    cout<<"_3_|_4_|_5_"<<endl;
    cout<<" 6 | 7 | 8 "<<endl;

    for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                chartemp = temp + 48; /*filling grid*/
                a[i][j] = chartemp;
                temp++;
            }
        }

    cout<<endl;

    while(countc==0)
    {
        cout<<"p1: "; /*taking input from users*/
        cin>>p1;
        cout<<"p2: ";
        cin>>p2;
        cout<<endl;
        p1r=p1/3; /*calculating row and column number from input*/
        p1c=p1%3;
        p2r=p2/3;
        p2c=p2%3;
        for(i=0;i<3;i++) /*All check conditions. count a b c to keep track
                         of winner*/
        {
            for(j=0;j<3;j++)
            {
                if(i==p1r && j==p1c)
                {
                    a[i][j]='x';
                }
            }
        }
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(i==p2r && j==p2c)
                {
                    a[i][j]='o';
                }
            }
        }

        for(i=0;i<3;i++)
        {
            j=0;
            if(a[i][j]=='x' && a[i][j+1]=='x' && a[i][j+2]=='x')
            {
                cout<<"Player 1 has won the game"<<endl<<endl;
                counta++;
                countc++;
            }
        }

        if(counta==0)
        {
          cout<<"Row check complete"<<endl;
          i=0;
          for(j=0;j<3;j++)
            {
                if(a[i][j]=='x' && a[i+1][j]=='x' && a[i+2][j]=='x')
                {
                    cout<<"Player 1 has won the game"<<endl<<endl;
                    countb++;
                    countc++;
                }
            }
        }

        if(countb==0)
        {
            cout<<"Row and Column check complete"<<endl;
            i=0, j=0;
            if(a[i][j]=='x' && a[i+1][j+1]=='x' && a[i+2][j+2]=='x')
            {
                cout<<"Player 1 has won the game"<<endl<<endl;
                countc++;
            }
            else if(a[i+2][j]=='x' && a[i+1][j+1]=='x' && a[i][j+2]=='x')
            {
                cout<<"Player 1 has won the game"<<endl<<endl;
                countc++;
            }
            else
            {
                cout<<"All checks complete and the game continues"<<endl<<endl;
            }

        }
        if(countc==0)
        {
            for(i=0;i<3;i++)
            {
                j=0;
                if(a[i][j]=='o' && a[i][j+1]=='o' && a[i][j+2]=='o')
                {
                    cout<<"Player 2 has won the game"<<endl<<endl;
                    counta++;
                    countc++;
                }
            }
            if(counta==0)
            {
                cout<<"Row check complete"<<endl;
                i=0;
                for(j=0;j<3;j++)
                {
                    if(a[i][j]=='o' && a[i+1][j]=='o' && a[i+2][j]=='o')
                    {
                        cout<<"Player 2 has won the game"<<endl<<endl;
                        countb++;
                        countc++;
                    }
                }
            }
            if(countb==0)
            {
                cout<<"Row and Column check complete"<<endl;
                i=0, j=0;
                if(a[i][j]=='o' && a[i+1][j+1]=='o' && a[i+2][j+2]=='o')
                {
                    cout<<"Player 2 has won the game"<<endl<<endl;
                    countc++;
                }
                else if(a[i+2][j]=='o' && a[i+1][j+1]=='o' && a[i][j+2]=='o')
                {
                    cout<<"Player 2 has won the game"<<endl<<endl;
                    countc++;
                }
                else
                {
                    cout<<"All checks complete and the game continues"<<endl<<endl;
                }
            }


        }
        /*final output grid after each round*/

        cout<<"_"<<a[i][j]<<"_|_"<<a[i][j+1]<<"_|_"<<a[i][j+2]<<"_"<<endl;
        cout<<"_"<<a[i+1][j]<<"_|_"<<a[i+1][j+1]<<"_|_"<<a[i+1][j+2]<<"_"<<endl;
        cout<<" "<<a[i+2][j]<<" | "<<a[i+2][j+1]<<" | "<<a[i+2][j+2]<<" "<<endl;
        cout<<endl;
    }
    return 0;
}
