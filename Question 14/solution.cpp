#include <cstdlib>
#include <string>
#include <cstdio>
#include "stack.h"

int main()
{
    Stack stc;
    int chc;
    char val;
    while (1)
    {
        printf("\nMENU:\n");
        printf(" 1. Balance Check \n 2. Exit \n");
        printf("Enter you chc: ");
        scanf("%d", &chc);

        switch(chc)
        {
            case 1:
                printf("Enter string to be checked: ");
                scanf(" %s", &val);
                stc.isValid(val);
                break;
            case 2:
                exit(0);
            default:
                printf("\n Invalid Choice \n");
                break;
        }
    }
    return 0;
}

int Stack::isValid(string s)
{
    for (int i = 0; i < s.length() ; i++)
    {
        if (s[i] == '(') 
        {
            stc.push(s[i]);
        }
        if (head == NULL)
        {
            return 0;
        }
        else if (s[i] == ')')
        {
            if (stc.top() == '(')
            {
                stc.pop();
            }
            else
            {
                stc.push(s[i]);
            }
        }
    }
    return 1;
}
