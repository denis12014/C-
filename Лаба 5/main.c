#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float MyFun(float x)
{
    return sqrt(x)+sin(x);
}
void hat_txt(FILE *out)
{
   fprintf(out,"*******************************\n");
   fprintf(out,"*   N    *    X    *   F(X)   *\n");
   fprintf(out,"*******************************\n");
}


void TableFILE_txt(float x1, float x2, float delta, unsigned int N,FILE *out)
{
  for (int i=1;i<=N;i++,x1+=delta)
    {
        fprintf(out,"+---------+---------+---------+\n");
        fprintf(out,"|");
        fprintf(out,"%9d|", i);
        fprintf(out,"%9.2f|", x1);
        fprintf(out,"%9.3f|", MyFun(x1));
        fprintf(out,"\n");
    }
  fprintf(out,"+---------+---------+---------+\n");
}
void WriteBIN(char symb,int iter,FILE *outBIN)
{

    int num=0;

    for(int i=0;i<=iter;i++)
    {
        char buffer[100];
        if(num==iter)
    {
        fwrite(buffer,1,num,outBIN);
        num=0;
    }
    buffer[num]=symb;
    num++;
    }
}
void hat_bin(FILE *outBIN)
{
    WriteBIN('*',31,outBIN);
    WriteBIN('\n',1,outBIN);
    WriteBIN('*',1,outBIN);
    WriteBIN(' ',4,outBIN);
    WriteBIN('N',1,outBIN);
    WriteBIN(' ',4,outBIN);
    WriteBIN('*',1,outBIN);
    WriteBIN(' ',3,outBIN);
    WriteBIN('X',1,outBIN);
    WriteBIN(' ',5,outBIN);
    WriteBIN('*',1,outBIN);
    WriteBIN(' ',2,outBIN);
    WriteBIN('F',1,outBIN);
    WriteBIN('(',1,outBIN);
    WriteBIN('X',1,outBIN);
    WriteBIN(')',1,outBIN);
    WriteBIN(' ',3,outBIN);
    WriteBIN('*',1,outBIN);
    WriteBIN('\n',1,outBIN);
    WriteBIN('*',31,outBIN);
}
void stick(FILE *outBIN)
{
for(int i=0;i<3;i++)
    {
        WriteBIN('+',1,outBIN);
        WriteBIN('-',9,outBIN);
    }
    WriteBIN('+',1,outBIN);
}
int Leng(float v)
{
    int n=0;
    int c;
    if(v<0)
    {
        n++;
    }
    while(1)
    {
        c=v;
        if(c==0)
        {
            return n;
        }
        v/=10;
        n++;

    }
}
void convertINT(float v,FILE *outBIN)
{
  char a,b;
  int q=Leng(v);
  v/=pow(10,q);
  for(int n=0;n<q;n++)
  {
      v*=10.001;
      a=(int)v%10+'0';
      WriteBIN(a,1,outBIN);
  }
}
void convertFLOAT(float v,FILE *outBIN)
{
    char a;
    if(v<0)
    {
       WriteBIN('-',1,outBIN);
    }
    if(v<1)
    {
        WriteBIN('0',1,outBIN);
    }
    v=fabs(v);
    int q=Leng(v);
    v/=pow(10,q);
    v+=0.000001;
    for(int n=0;n<q;n++)
    {
        v*=10;
        a=(int)v%10+'0';
        WriteBIN(a,1,outBIN);
    }
    WriteBIN('.',1,outBIN);
    for(int i=0;i<3;i++)
    {
        v*=10;
        a=(int)v%10+'0';
        WriteBIN(a,1,outBIN);
    }

}
void TableFILE_bin(float x1, float x2, float delta, unsigned int N,FILE *outBIN)
{
    for (int i=1;i<=N;i++,x1+=delta)
    {
        WriteBIN('\n',1,outBIN);
        stick(outBIN);
        WriteBIN('\n',1,outBIN);
        WriteBIN('|',1,outBIN);
        if(i<10)
        {
            WriteBIN(' ',8,outBIN);
        }
        else
        {
            WriteBIN(' ',7,outBIN);
        }
        convertINT(i,outBIN);
        WriteBIN('|',1,outBIN);
        if(x1<10)
        {
            WriteBIN(' ',4,outBIN);
        }
        else
        {
            WriteBIN(' ',3,outBIN);
        }
        convertFLOAT(x1,outBIN);
        WriteBIN('|',1,outBIN);
        if(MyFun(x1)<10)
        {
            WriteBIN(' ',4,outBIN);
        }
        else
        {
            WriteBIN(' ',3,outBIN);
        }
        convertFLOAT(MyFun(x1),outBIN);
        WriteBIN('|',1,outBIN);
    }
    WriteBIN('\n',1,outBIN);
    stick(outBIN);
}

int main()
{
    float x1,x2,N,delta;
    FILE *in;
    in=fopen("input.dat.txt", "r");
    char input[40];
    fgets(input,40,in);
    printf("\nInput data saved in file\n");
    fscanf(in, "%f", &x1);
    printf("x1=%.2f  ",x1);
    fscanf(in, "%f", &x2);
    printf("x2=%.2f  ",x2);
    fscanf(in, "%f", &N);
    printf("N=%.2f  ",N);
    fscanf(in, "%f", &delta);
    printf("delta=%.2f\n",delta);
    fclose(in);

    FILE *outBIN;
    outBIN=fopen("result.bin", "w");
    hat_bin(outBIN);
    TableFILE_bin(x1,x2,delta,N,outBIN);
    fclose(outBIN);
    printf("\n File result.bin ready \n");
    printf("\n Displaying the table on the screen...\n");
    getch();
    outBIN=fopen("result.bin", "r");
    while(fscanf(outBIN,"%[^\n]\n",input)==1)
    {
        printf("%s\n",input);
    }
    fclose(outBIN);


    FILE *out;
    out=fopen("result.txt", "w");
    fprintf(out,"N=%.2f\n",N);
    hat_txt(out);
    TableFILE_txt(x1,x2,delta,N,out);
    printf("\n File result.txt ready \n");
    fclose(out);
    return 0;
}
