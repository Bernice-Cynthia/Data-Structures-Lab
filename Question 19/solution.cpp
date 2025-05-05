//to find the max value that the first tower can have
#include <queue>
#include <iostream>
using namespace std;
class towers
{
    queue<long> que;
    public:
        long max(long);
        void clearqueue();
};

int main()
{
    towers obj;
    int test;
    cout<<"Enter the number of test cases: ";
    cin>>test;
    long ntow;
    while(test--)
    {
        cout<<"Enter the number of towers: ";
        cin>>ntow;
        long ret = obj.max(ntow);
        cout<<"The maximum value of tower one is: "<<ret<<"\n";
        obj.clearqueue();
    }
}

long towers::max(long ntow)
{
    int temp;
    for(int i = 0;i<ntow;i++)
    {
        cout<<"Enter the number of blocks in "<<i+1<<": ";
        cin>>temp;
        que.push(temp);
        while(que.back()>0&&que.back()>que.front())
        {
            que.back()=que.back()-1;
            que.front()=que.front()+1;
        }
    }
    return que.front();
}

void towers::clearqueue()
{
    while(!que.empty())
    {
        que.pop();
    }
}
