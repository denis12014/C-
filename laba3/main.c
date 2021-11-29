#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>
#define eps 0.0001

double f(double x){
  return pow(x,3)-5;
}
double method_hord(double x1,double x2, unsigned int iteration,unsigned int iterMODE,int ans)
{
    double xi;
    int n=1,q=0,nn=0;

    do{
        xi=(f(x2)*x1-f(x1)*x2)/(f(x2)-f(x1));
        if (f(xi)*f(x1)>0)
            {
            x1 = xi;
            }
       else
            {
            x2 = xi;
            }
        if(ans==1)
            {
                nn++;
                printf("\n n=%d xi=%lf  f(xi)=%lf",nn, xi, f(xi));
                getch();
            }
                if(iterMODE==1)
                {
                    n++;
                    if(n==iteration)
                    {
                    printf("\n\nAttention! iteration has reached its maximum value=%d", n);
                    printf("\n xi=%lf  f(xi)=%lf", xi, f(xi));
                    printf("\n\n 1.Exit, 2.Continue with the same value iteration=%d,", iteration);
                    printf(" 3.Continue without limitation");
                    scanf("%d",&q);
                        if(q==1){
                            break;
                            } else if(q==2){
                            iteration*=2;
                            } else if(q==3){
                            iterMODE=0;
                        }
                    }
                }

        }while(fabs(f(xi))>eps);


    return xi;
}
double method_of_half_division(double x1,double x2, unsigned int iteration,unsigned int iterMODE,int ans)
{
   double xi;
    int n=1,q=0,nn=0;

    do{
        xi=(x1+x2)/2;
        if (f(xi)*f(x1)>0)
            {
            x1 = xi;
            }
       else
            {
            x2 = xi;
            }
        if(ans==1)
            {
                nn++;
                printf("\n n=%d xi=%lf  f(xi)=%lf",nn, xi, f(xi));
                getch();
            }
                if(iterMODE==1)
                {
                    n++;
                    if(n==iteration)
                    {
                   printf("\n\nAttention! iteration has reached its maximum value=%d", n);
                    printf("\n xi=%lf  f(xi)=%lf", xi, f(xi));
                    printf("\n\n 1.Exit, 2.Continue with the same value iteration=%d,", iteration);
                    printf(" 3.Continue without limitation");
                    scanf("%d",&q);
                        if(q==1){
                            break;
                            } else if(q==2){
                            iteration*=2;
                            } else if(q==3){
                            iterMODE=0;
                        }
                    }
                }

        }while(fabs(f(xi))>eps);


    return xi;
}


int main()
{   int method,iteration=0,ans;
    unsigned int iterMODE;
    float timeCLOCK,timeSTART,timeSTOP;
    double x1,x2,vidp;
      printf("\nEnter method\n\n");
      printf("Method hord,key 1\n");
      printf("Method of half division,key 2\n");
      printf("Enter key...");
      scanf("%d",&method);

    do{
        system("cls");
        printf("\nx1=");
        scanf("%lf",&x1);
        printf("\nx2=");
        scanf("%lf",&x2);

    }while (f(x1)*f(x2)>0);
        printf("\n\nSelect mode");
        printf("\n1.Iteration mode on");
        printf("\n0.Iteration mode= off");
        scanf("%u",&iterMODE);
        if(iterMODE==1)
            {
            printf("\niteration=");
            scanf("%d",&iteration);
            }
        else
            {
            printf("\n0.Iteration mode selected= off");
            }
        printf("\nShow output data for every iteration?\n 1.yes 2.no");
        scanf("%d",&ans);
        timeSTART=clock();

    switch(method)
    {
        case 1:
            {
            vidp=method_hord(x1,x2,iteration,iterMODE,ans);
            printf("\n\nx=%lf   f(x)=%lf", vidp, f(vidp) );

            break;
            }
        case 2:
            {
            vidp=method_of_half_division(x1,x2,iteration,iterMODE,ans);
            printf("\n\nx=%lf   f(x)=%lf", vidp, f(vidp) );
            break;
            }
        default:
            {
            printf("ERROR please select key 1,2\n");
            getch();
            break;
            }
    }
        timeSTOP=clock();
        timeCLOCK=(timeSTOP-timeSTART)/CLOCKS_PER_SEC;
        printf("\n The time has passed = %f second",timeCLOCK);
        getch();
    return 0;
}
