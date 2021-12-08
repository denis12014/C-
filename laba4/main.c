#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void RandomVALUE(int** Matrix,int N,int M)
{
    int a;
    srand(time(NULL));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            a=rand()%2+1;
            if(a==1)
            {
                Matrix[i][j]=rand()%20+1;
            }else
            {
                Matrix[i][j]=rand()%20-20;
            }
        }
    }
}
void Formed_Matrix(int** Matrix,int N,int M)
{
     printf("\nFormed matrix\n");
            for(int i=0;i<N;i++)
            {
                for(int j=0;j<M;j++)
                {
                    printf("%d  ",Matrix[i][j]);
                }
                printf("\n");
            }
}
void MaxMIN( int** Matrix, int N)
{
    int maxV=Matrix[0][1],minV=Matrix[0][1];
    for(int i=0;i<N;i++)
            {
                for(int j=0;j<N;j++)
                {
                    if(Matrix[i][j]>maxV)
                    {
                        maxV=Matrix[i][j];
                    }
                    if(Matrix[i][j]<minV)
                    {
                        minV=Matrix[i][j];
                    }
                }
            }
    printf(" Min value of the matrixA=%d\n Max value of the matrixA=%d\n",minV,maxV);
}
void Transpose_matrix( int** Matrix, int N,int M)
{
    printf("Transposed matrixB....\n\n");
    for(int i=0;i<M;i++)
            {
                for(int j=0;j<N;j++)
                {
                   printf("%d  ",Matrix[j][i]);
                }
                printf("\n");
            }

}
void Matrix_multiplication ( int** MatrixA,int** MatrixB, int N,int M)
{
    int mult;
    printf("Matrix multiplication...\n\n");
    for(int i=0;i<N;i++)
            {
                for(int j=0;j<M;j++)
                {
                   mult=0;
                   for(int q=0;q<N;q++)
                   {
                       mult+=MatrixA[i][q]*MatrixB[q][j];
                   }
                       printf("%d  ",mult);

                }
                printf("\n");
            }

}
void Matrix_sort(int** Matrix, int N)
{
    int q;
       printf("Line number=");
       scanf("%d",&q);
    for(int i=0;i<N-1;i++)
    {
       for(int j=0;j<N-i-1;j++)
        {
            if(Matrix[q][j]>Matrix[q][j+1])
            {
              int S = Matrix[q][j];
              Matrix[q][j]=Matrix[q][j+1];
              Matrix[q][j+1]=S;
            }
        }
    }
    Formed_Matrix(Matrix,N,N);
}
void Matrix_sumLine(int** MatrixA,int** MatrixB, int N,int Mb)
{
    int q=0;
    for(int i=0;i<N;i++)
    {
        for (int j=0;j<N;j++)
        {
            q+=MatrixA[i][j];

        }
        for(int NN=0;NN<N;NN++)
        {
            q+=MatrixB[NN][i];
        }
        printf("\n%d\n",q);
    }
}
void Freeing_mem(int** MatrixA,int** MatrixB,int Na,int Nb)
{
    for(int i=0;i<Na; i++)
    {
        free(MatrixA[i]);
    }
    free(MatrixA);

    for(int i = 0; i<Nb; i++)
    {
        free(MatrixB[i]);
    }
    free(MatrixB);
}

int main()
{
    int operation,Na,Nb=0,Mb,Val,ans,W=1;
    while(W)
    {
    //system("cls");
    printf("Select operation\n\n");
    printf("1.Max and min MATRIX A value\n");
    printf("2.Transpose matrix B\n");
    printf("3.Matrix multiplication (MatrixA*MatrixB)\n");
    printf("4.Sorting the matrix A line by magnification\n");
    printf("5.Sum of the elements of rows of matrix A and columns of matrix B\n");
    printf("0.Exit B\n");

    scanf("%d",&operation);


     switch(operation)
    {


        case 1:
            {
                printf("Enter size matrix A(square)\n\n");
                scanf("%d",&Na);
                printf("Generate a random matrix? 1-yes 0-no\n\n");
                scanf("%d",&ans);
                int** MatrixA =(int**)malloc(Na*sizeof(int*));

                for(int i=0;i<Na;i++)
                {
                    MatrixA[i]=(int*)malloc(Na*sizeof(int));
                }
                if(ans==0)
                {
                printf("Enter %d matrixA values\n",Na*Na);

                for(int i=0;i<Na;i++)
                {
                    for(int j=0;j<Na;j++)
                    {
                        scanf("%d",&Val);
                        MatrixA[i][j]=Val;
                    }
                }
                }else
                {
                    RandomVALUE(MatrixA,Na,Na);
                }

                Formed_Matrix(MatrixA,Na,Na);
                MaxMIN(MatrixA,Na);
                getch();
            break;
            }
        case 2:
            {
                printf("Enter size matrix B(rectangle)\n\n");
                scanf("%d",&Nb);
                scanf("%d",&Mb);
                printf("Generate a random matrix? 1-yes 0-no\n\n");
                scanf("%d",&ans);
                int** MatrixB =(int**)malloc(Nb*sizeof(int*));

                for(int i=0;i<Nb;i++)
                {
                    MatrixB[i]=(int*)malloc(Nb*sizeof(int));
                }
                if(ans==0)
                {
                    printf("Enter %d matrixB values\n",Nb*Mb);

                    for(int i=0;i<Mb;i++)
                    {
                        for(int j=0;j<Nb;j++)
                        {
                            scanf("%d",&Val);
                            MatrixB[i][j]=Val;
                        }
                    }
                }else
                {
                RandomVALUE(MatrixB,Nb,Mb);
                }

                Formed_Matrix(MatrixB,Nb,Mb);
                printf("\n");
                Transpose_matrix(MatrixB,Nb,Mb);
                getch();
                break;
                }
        case 3:
            {
                printf("Enter size matrix A(square)\n\n");
                scanf("%d",&Na);
                printf("Generate a random matrix? 1-yes 0-no\n\n");
                scanf("%d",&ans);
                int** MatrixA =(int**)malloc(Na*sizeof(int*));

                for(int i=0;i<Na;i++)
                {
                    MatrixA[i]=(int*)malloc(Na*sizeof(int));
                }
                if(ans==0)
                {
                printf("Enter %d matrixA values\n",Na*Na);

                for(int i=0;i<Na;i++)
                {
                    for(int j=0;j<Na;j++)
                    {
                        scanf("%d",&Val);
                        MatrixA[i][j]=Val;
                    }
                }
                }else
                {
                    RandomVALUE(MatrixA,Na,Na);
                }
                Formed_Matrix(MatrixA,Na,Na);

                printf("Enter size matrix B(rectangle)\n\n");
                scanf("%d",&Mb);
                printf("Generate a random matrix? 1-yes 0-no\n\n");
                scanf("%d",&ans);
                int** MatrixB =(int**)malloc(Na*sizeof(int*));

                for(int i=0;i<Na;i++)
                {
                    MatrixB[i]=(int*)malloc(Na*sizeof(int));
                }
                if(ans==0)
                {
                    printf("Enter %d matrixB values\n",Na*Mb);

                    for(int i=0;i<Mb;i++)
                    {
                        for(int j=0;j<Na;j++)
                        {
                            scanf("%d",&Val);
                            MatrixB[i][j]=Val;
                        }
                    }
                }else{
                RandomVALUE(MatrixB,Na,Mb);
                }

                Formed_Matrix(MatrixB,Na,Mb);
                printf("\n");

                Matrix_multiplication(MatrixA,MatrixB,Na,Mb);
                getch();
                break;
                }

        case 4:
            {
                printf("Enter size matrix A(square)\n\n");
                scanf("%d",&Na);
                printf("Generate a random matrix? 1-yes 0-no\n\n");
                scanf("%d",&ans);
                int** MatrixA =(int**)malloc(Na*sizeof(int*));

                for(int i=0;i<Na;i++)
                {
                    MatrixA[i]=(int*)malloc(Na*sizeof(int));
                }
                if(ans==0)
                {
                printf("Enter %d matrixA values\n",Na*Na);

                for(int i=0;i<Na;i++)
                {
                    for(int j=0;j<Na;j++)
                    {
                        scanf("%d",&Val);
                        MatrixA[i][j]=Val;
                    }
                }
                }else
                {
                    RandomVALUE(MatrixA,Na,Na);
                }
                Formed_Matrix(MatrixA,Na,Na);
                printf("\n");
                Matrix_sort(MatrixA,Na);
                getch();

            break;
            }
        case 5:
            {

                printf("Enter size matrix A(square)\n\n");
                scanf("%d",&Na);
                printf("Generate a random matrix? 1-yes 0-no\n\n");
                scanf("%d",&ans);
                int** MatrixA =(int**)malloc(Na*sizeof(int*));

                for(int i=0;i<Na;i++)
                {
                    MatrixA[i]=(int*)malloc(Na*sizeof(int));
                }
                if(ans==0)
                {
                printf("Enter %d matrixA values\n",Na*Na);

                for(int i=0;i<Na;i++)
                {
                    for(int j=0;j<Na;j++)
                    {
                        scanf("%d",&Val);
                        MatrixA[i][j]=Val;
                    }
                }
                }else
                {
                    RandomVALUE(MatrixA,Na,Na);
                }
                Formed_Matrix(MatrixA,Na,Na);

                printf("Enter size matrix B(rectangle)\n\n");
                scanf("%d",&Mb);
                printf("Generate a random matrix? 1-yes 0-no\n\n");
                scanf("%d",&ans);
                int** MatrixB =(int**)malloc(Na*sizeof(int*));

                for(int i=0;i<Na;i++)
                {
                    MatrixB[i]=(int*)malloc(Na*sizeof(int));
                }
                if(ans==0)
                {
                    printf("Enter %d matrixB values\n",Na*Mb);

                    for(int i=0;i<Na;i++)
                    {
                        for(int j=0;j<Mb;j++)
                        {
                            scanf("%d",&Val);
                            MatrixB[i][j]=Val;
                        }
                    }
                }else
                {
                RandomVALUE(MatrixB,Na,Mb);
                }

                Formed_Matrix(MatrixB,Na,Mb);
                printf("\n");
                Matrix_sumLine(MatrixA,MatrixB,Na,Mb);
                getch();
                break;
            }
        default:
            {
                system("cls");
                if(Nb==0)
                {
                    Nb=Na;
                }
                int** MatrixA =(int**)malloc(Na*sizeof(int*));
                int** MatrixB =(int**)malloc(Na*sizeof(int*));
                W=0;
                printf("\n\nFreeing up memory....");
                getch();
                Freeing_mem(MatrixA,MatrixB,Na,Nb);

                break;
            }

    }
    }
    return 0;
}
