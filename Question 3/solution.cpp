//Menu-driven program to find armstrong, perfect and palindorm numbers

#include <cstdio>
#include <stdlib.h>
#include <math.h>

int* digits(int*);
int* reverse(int*);
int palindrome(int*);
int* sum_digits(int*, int*);
int* sum_fact(int*);
int armstrong(int*);
int perfect(int*);

int main()
{
    int* chc;
    chc=(int*)(malloc(sizeof(int)));
    do
    {
        printf("enter 1. armstrong, 2. for palindrome, 3. for perfect, 4. for exit: \n");
        scanf("%d", chc);

            switch(*chc)
            {
                case 1:
                    int* num;
                    num=(int*)(malloc(sizeof(int)));
                    printf("enter the number: \n");
                    scanf("%d", num); 

                    int* ret;
                    ret=(int*)(malloc(sizeof(int)));
                    *ret=armstrong(num);
                    if(*ret == 1)
                    {
                        printf("it is an armstrong number\n");
                    }
                    else
                    {
                        printf("it is not a armstrong number\n");
                    }
                    break;
                
                case 2:
                    int* num1;
                    num1=(int*)(malloc(sizeof(int)));
                    printf("enter the number: \n");
                    scanf("%d", num1); 
                    int* ret1;
                    ret1=(int*)(malloc(sizeof(int)));
                    *ret1=palindrome(num1);
                    if(*ret1 == 1)
                    {
                        printf("it is a palindrome\n");
                    }
                    else
                    {
                        printf("it is not a palindrome\n");
                    }
                    break;

                case 3:
                    int* num2;
                    num2=(int*)(malloc(sizeof(int)));
                    printf("enter the number: \n");
                    scanf("%d", num2); 
                    int* rval;
                    rval=(int*)(malloc(sizeof(int)));
                    *rval=perfect(num2);
                    if(*rval==1)
                    {
                        printf("it is a perfect number\n");
                    }
                    else
                    {
                        printf("it is not a perfect number\n");
                    }
                    break;
                
                case 4:
                    return 0;

                default:
                    printf("invalid input");
                    return 0;

        }
    }while((*chc)<4);
}

int* sum_digits(int* num, int* dig)
{
    int* sum;
    sum=(int*)(malloc(sizeof(int)));
    *sum=0;
    while ((*num)>0)
    {
        *sum = *sum + (int)(pow(((*num)%10), (*dig)));
        *num=(*num)/10;
    }
    return sum;
}

int* digits(int* num)
{
    int* digit;
    digit=(int*)(malloc(sizeof(int)));
    *digit=0;
    while((*num)>0)
    {
        (*digit)++;
        *num=(*num)/10;
    }
    return digit;
}

int armstrong(int* num)
{
    int* copy;
    copy=(int*)(malloc(sizeof(int)));
    *copy=*num;
    int* copy1;
    copy1=(int*)(malloc(sizeof(int)));
    *copy1=*num;
    int* digit;
    digit=(int*)(malloc(sizeof(int)));
    *digit=*digits(num);
    int* rsum;
    rsum=(int*)(malloc(sizeof(int)));

    *rsum=*sum_digits(copy1, digit);
    
    if(*copy==*rsum)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}


int* reverse(int* num)
{
    int* rnum;
    rnum=(int*)(malloc(sizeof(int)));
    *rnum=0;
    while((*num)>0)
    {
        *rnum=(*rnum)*10 + (*num)%10;
        *num=(*num)/10;
    }
    return rnum;
}

int palindrome(int* num)
{
    int* copy;
    copy=(int*)(malloc(sizeof(int)));
    *copy=*num;
    int* rnum;
    rnum=(int*)(malloc(sizeof(int)));
    *rnum= *reverse(num);

    if((*copy)==(*rnum))
    {
        return 1;
    }

    else{
        return 0;
    }
}

int* sum_fact(int* num)
{
    int* i;
    i=(int*)(malloc(sizeof(int)));
    *i=0;
    int* sum;
    sum=(int*)(malloc(sizeof(int)));
    *sum=0;
    for((*i)=(*num)-1; (*i)>0; (*i)--)
    {
        if((*num)%(*i)==0)
        {
            *sum+=*i;
        }
    }
    return sum;
}

int perfect(int* num)
{
    int* copy;
    copy=(int*)(malloc(sizeof(int)));
    *copy=*num;
    int* rsum;
    rsum=(int*)(malloc(sizeof(int)));
    *rsum=*sum_fact(num);
    if(*rsum==*num)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
