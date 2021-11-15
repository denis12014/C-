#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>ллл
#include <stdbool.h>
float integFUN(float c){
    return (c*c)+2*c;
}

float Method_left_rectangles(float a,float b,int n)
{   float vidp=0,h;
    int i;
    h=(b-a)/n;
    for(i=0;i<n-1;i++)
    {
        vidp+=h*integFUN(i*h+a);
    }
   return vidp;
}

float Method_right_rectangles(float a,float b,int n)
{   float vidp=0,h;
    int i;
    h=(b-a)/n;
    for(i=0;i<n;i++)
    {
        vidp+=h*integFUN(i*h+a);
    }
   return vidp;
}

float Trapezoidal_method(float a,float b,int n)
{   float vidp=integFUN(a)+integFUN(b),h;
    int i;
    h=(b-a)/n;
    for(i=0;i<n-1;i++)
    {
        vidp+=2*integFUN(i*h+a);
    }
    vidp*=h/2;
   return vidp;
}

float Parabolic_method(float a,float b,int n)
{   float vidp=integFUN(a)+integFUN(b),h;
    int i,a1;
    h=(b-a)/n;
    for(i=0;i<n-1;i++)
    {
        a1=2+2*(i%2);
        vidp+=a1*integFUN(i*h+a);
    }
    vidp*=h/3;
   return vidp;
}


int main()
{   float x,a,b,h,integ,p;
    int n;

    unsigned int g;
    int Method=0,i;

    if(Method==0)
    {
     printf("\nEnter method\n\n");
     printf("Method left rectangles,key 1\n");
     printf("Method right rectangles,key 2\n");
     printf("Trapezoidal method,key 3\n");
     printf("Parabolic method,key 4\n");
     printf("Enter key...");
     scanf("%u", &Method);
        if(Method==1 || Method==2 || Method==3 || Method==4)
        {
            printf("Enter upper limit of the integral:");
            scanf("%f",&b);
            printf("Enter lower limit of the integral:");
            scanf("%f",&a);
            printf("Enter error:");
            scanf("%f",&p);
            printf("Enter number of intervals:");
            scanf("%d",&n);
        }

     }
 switch(Method)
 {
 case 1:
       {
        printf("Method left rectangles selected\n\n");
            do{
                g+=2;
                integ=fabs(Method_left_rectangles(a,b,g)- Method_left_rectangles(a,b,g+2));
            } while(integ>p);
        hat();
        stick();
        printf("|  1|%8.4f|%10.4f|%10.4f|%10.4f|%10.4f|%u|\n", Method_left_rectangles(a,b,n), Method_left_rectangles(a,b,10),
               Method_left_rectangles(a,b,100), Method_left_rectangles(a,b,1000), Method_left_rectangles(a,b,10000), g);
        stick();

        break;
       }
 case 2:
       {
        printf("Method right rectangles selected\n\n");
            do{
                g+=2;
                integ=fabs(Method_right_rectangles(a,b,g)- Method_right_rectangles(a,b,g+2));
                } while(integ>p);
        hat();
        stick();
        printf("|   2|%8.4f|%10.4f|%10.4f|%10.4f|%10.4f|%u|\n", Method_right_rectangles(a,b,n),Method_right_rectangles(a,b,10),
                Method_right_rectangles(a,b,100), Method_right_rectangles(a,b,1000), Method_right_rectangles(a,b,10000), g);
        stick();
        Method=0;
        break;
        }
 case 3:
        {
        printf("Trapezoidal method selected\n\n");
         do{
                g+=2;
                integ=fabs(Trapezoidal_method(a,b,g)- Trapezoidal_method(a,b,g+2));
           } while(integ>p);
        hat();
        stick();
        printf("|   3|%8.4f|%10.4f|%10.4f|%10.4f|%10.4f|%u|\n", Trapezoidal_method(a,b,n),Trapezoidal_method(a,b,10),
               Trapezoidal_method(a,b,100), Trapezoidal_method(a,b,1000), Trapezoidal_method(a,b,10000), g);
        stick();
        Method=0;
        break;
        }

 case 4:
        {
        printf("Parabolic method selected\n\n");
        do{
                g+=2;
                integ=fabs(Parabolic_method(a,b,g)- Parabolic_method(a,b,g+2));
           } while(integ>p);
        hat();
        stick();
        printf("|   4|%8.4f|%10.4f|%10.4f|%10.4f|%10.4f|%u|\n", Parabolic_method(a,b,n),Parabolic_method(a,b,10),
               Parabolic_method(a,b,100), Parabolic_method(a,b,1000), Parabolic_method(a,b,10000), g);
        stick();
        Method=0;
        break;
        }
 default:
     {
     printf("ERROR please select key 1,2,3 and 4\n");
     Method=0;
     getch();
     break;
     }
 }

 return 0;
}


int stick()
{
  printf("+---+--------+----------+----------+----------+----------+----+\n");
}
int hat()
{
   printf("+---+--------+----------+----------+----------+----------+----+\n");
   printf("+-M-+-USER n-+---n=10---+---n=100--+--n=1000--+-n=10000--+--N-+\n");
}
