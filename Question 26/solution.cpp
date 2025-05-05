//Program to implement word game with 3 players 

#include <iostream>
using namespace std;

int main()
{
    int test=0;
    cout<<"Enter the number of test cases: ";
    cin>>test;
    for (int i=0;i<test;i++)
    {
        int size=0;
        cout<<"Enter the number of words: ";
        cin>>size;
        string words[3][size];
        for (int j = 0;j<3;j++)
        {
            for (int k = 0;k<size;k++)
            {
                cout<<"Enter player "<<(j+1)<<" word "<<(k+1)<< ": ";
                cin>>words[j][k];
            }
        }
        int py1=0;
        int py2=0;
        int py3=0;
        for(int j=0;j<size;j++)
        {
            string word = words[0][j];
            int flag=0;
            for (int k = 0;k<3;k++)
            {
                for (int l = 0;l<size;l++)
                {
                    if (words[k][l]==word)
                    {
                        flag++;
                    }
                }
            }
            if (flag==1)
            {
                py1+=3;
            }
            else 
            {
                py1=+1;
            }
        }
        for(int j=0;j<size;j++)
        {
            string word = words[1][j];
            int flag=0;
            for (int k = 0;k<3;k++)
            {
                for (int l = 0;l<size;l++)
                {
                    if (words[k][l]==word)
                    {
                        flag++;
                    }
                }
            }
            if (flag==1)
            {
                py2+=3;
            }
            else 
            {
                py2=+1;
            }
        }
        for(int j=0;j<size;j++)
        {
            string word = words[2][j];
            int flag=0;
            for (int k = 0;k<3;k++)
            {
                for (int l = 0;l<size;l++)
                {
                    if (words[k][l]==word)
                    {
                        flag++;
                    }
                }
            }
            if (flag==1)
            {
                py3+=3;
            }
            else 
            {
                py3=+1;
            }
        }
        cout<<py1<<"  "<<py2<<"  "<<py3<<"  "<<"\n";

        return 0;
    }
}
