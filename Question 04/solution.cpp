//Menu-driven program to calculate area 

#include <cstdio>
#include <cstdlib>

class area 
{
    int len, bre, hei;
    public:
        area()
        {
            len = 1;
            bre = 1;
            hei = 1;
        }
        void slen(int);
        void sbre(int);
        void shei(int);
        int squa(int);
        int cube(int);
        int cuboid(int, int, int);
        int rect(int,int);
};

int main()
{
    int len, bre, hei, are, chc;
    area obj;
    while (1)
    {
        printf("\nMENU\n");
        printf("1. Square  \n2. Rectangle  \n3. Cube  \n4. Cuboid \n5. Exit  \n");
        printf("Enter your choice (1/2/3/4/5): ");
        scanf("%d", &chc);

        switch (chc)
        {
            case 1:
                printf("Enter the length: ");
                scanf("%d", &len);
                obj.slen(len);
                are = obj.squa(len);
                printf("The area of the square is %d \n", are);
                break;
            case 2:
                printf("Enter the length: ");
                scanf("%d", &len);
                printf("Enter the breadth: ");
                scanf("%d", &bre);
                obj.slen(len);
                obj.sbre(bre);
                are = obj.rect(len,bre);
                printf("The area of the rectangle is %d \n", are);
                break;
            case 3:
                printf("Enter the length: ");
                scanf("%d", &len);
                obj.slen(len);
                are = obj.cube(len);
                printf("The area of the cube is %d \n", are);
                break;
            case 4:
                printf("Enter the length: ");
                scanf("%d", &len);
                printf("Enter the breadth: ");
                scanf("%d", &bre);
                printf("Enter the height: ");
                scanf("%d", &hei);
                obj.slen(len);
                obj.sbre(bre);
                obj.shei(hei);
                are = obj.cuboid(len, bre, hei);
                printf("The area of the cuboid is %d \n", are);
                break;
            case 5:
                exit(0);
        }
    }
}

void area::slen(int temp)
{
    len = temp;
}

void area::sbre(int temp)
{
    bre = temp;
}

void area::shei(int temp)
{
    hei = temp;
}

int area::squa(int len)
{
    return len*len;
}

int area::cube(int len)
{
    return 6*len*len;
}

int area::cuboid(int len, int bre, int hei)
{
    return 2*(len*bre + bre*hei + hei*len);
}

int area::rect(int len, int bre)
{
    return len*bre;
}
