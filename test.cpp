#include<stdio.h>
int  main()
{
    int num,r,c,sp;
    scanf("%d",&num);
    for(r=1; r<=num; r++)
        {
            for(sp=num-r; sp>=1; sp--)
                printf(" ");
            for(c=1; c<=r; c++)
                printf("%d",c);
            for(c=r-1; c>=1; c--)
                printf("%d",c);
            printf("\n");
        }
    for(r=1; r<=num; r++)
        {
            for(sp=r; sp>=1; sp--)
                printf(" ");
            for(c=1; c<=(num-r); c++)
                printf("%d",c);
            for(c=num-r-1; c>=1; c--)
                printf("%d",c);
            printf("\n");
        }
}
