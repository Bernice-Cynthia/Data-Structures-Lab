//program processes the given string

#include <iostream>
#include <cstring>
#include "stack.h"
using namespace std;

string process(string);

int main()
{
    string str;
    printf("Enter the string: ");
    cin>>str;
    string ret = process(str);
    cout<<"Processed string: "<<ret<<"\n";
}

string process(string str)
{
    Stack stk;
    for(int i = 0; i<str.length(); i++)
    {
        if(str[i]=='+')
        {
            if(stk.empty())
            {
                continue;
            }
            else
            {
                stk.pop();
            }
        }
        else
        {
            stk.push(str[i]);
        }
    }
    string nstr=" ";
    while(!stk.empty())
    {
        nstr = stk.peek() + nstr;
        stk.pop();
    }
    return nstr;
}


