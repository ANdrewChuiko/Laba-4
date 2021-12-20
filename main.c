#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int i,j,temp,N=3,M=4,choise;
int maximal=0,sort,sum=0,vvod,end;

int Maximum(int **A)
{
    for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                if (A[i][j]>maximal)
                maximal=A[i][j];
            }
        }
        printf("Максимальне значення матрицi А: %d\n",maximal);
}
int Transponate (int **B,int **T)
{
    for (i=0;i<N;i++)
        {
            for (j=0;j<M;j++)
            {
                T[j][i]=B[i][j];
            }
        }
        printf("\n Транспонована матриця :  is:\n");
    for (i=0;i<M;i++)
    {
        for (j=0;j<N;j++)
        {
            printf("%3d ", T[i][j]);
        }
        printf("\n");
    }
}
int Multiply(int **A,int **B,int **Dob)
{
     for(i=0;i<N;i++)
        {
            for(j=0;j<M;j++)
            {
                Dob[i][j]=0;
                for(int p=0;p<N;p++)
                {
                    Dob[i][j]+=A[i][p]*B[p][j];
                }
            }
        }

        for (i=0;i<N;i++)
        {
            for (j=0;j<M;j++)
            {
                printf("%3d ", Dob[i][j]);
            }
            printf("\n");
        }
}
int Sort(int **A,int sort)
{
    for(i=0;i<N-1;i++)
    {


    for(j=0;j<N-i-1;j++)
{
        if(A[sort][j]>A[sort][j+1])
                {
                   swap(&A[sort][j],&A[sort][j+1]);
                }
}
    }
for(j=0;j<N;j++)
{
    printf("%3d ",A[sort][j]);
}
}
int Summ(int **A,int **B,int sum)
{
    for(i=0;i<N;i++)
    {
        sum=0;
        for(j=0;j<N;j++)
        {
            sum+=A[i][j];
        }
        printf("\n%d Сума елементiв рядкiв матрицi А =%d",i,sum);
        }
    for(j=0;j<M;j++)
    {
        sum=0;
        for(i=0;i<N;i++)
        {
            sum+=B[i][j];
        }
        printf("\n%d Сума елементiв столбцiв матрицi В =%d",j,sum);
    }
}
int main()

{  setlocale(LC_ALL, "Rus");

    printf("Оберiть метод створення матрицi:\n1. Метод виставлення оцiнок в кампус*рандомайзер*\n2. З клавiатури\n");
    scanf("%d",&vvod);
    if (vvod==2)
    {
    printf("\nВведiть розмiр квадратної матрицi: ");
    scanf("%d",&N);
    printf("\nВведiть розмiр прямокутної матрицi: ");
    scanf("%d",&M);
    }


    int **A=NULL;
    A=(int**)calloc(N,sizeof(int));
    for(int i=0;i<N;i++)
    {
        A[i]=(int*)calloc(N,sizeof(int));
    }

    int **B=NULL;
    B=(int**)calloc(M,sizeof(int));

    int **Dob=NULL;
    Dob=(int**)calloc(M,sizeof(int));

    int **T=NULL;
    T=(int**)calloc(N,sizeof(int));

    for(int i=0;i<M;i++)
    {
        B[i]=(int*)calloc(N,sizeof(int));
        Dob[i]=(int*)calloc(N,sizeof(int));
        T[i]=(int*)calloc(M,sizeof(int));
    }

    if(vvod==2)
    {
    printf("Введiть елементи квадратної матрицi:\n");
    for (i=0;i<N;i++)
    {
        for (j=0;j<N;j++)
        {
            printf("A[%d][%d]=",i,j);
            scanf("%d",&A[i][j]);
        }
    }


    printf("Введiть елементи прямокутної матрицi:\n");
    for (i=0;i<N;i++)
    {
        for (j=0;j<M;j++)
        {
            printf("B[%d][%d]=",i,j);
            scanf("%d",&B[i][j]);
        }
    }
    }
    else
    {
        for (i=0;i<N;i++)
        {
            for (j=0;j<N;j++)
            {
                A[i][j]=rand() %20;
            }
        }
        for (i=0;i<N;i++)
        {
            for (j=0;j<M;j++)
            {
                B[i][j]=rand() %15;
            }
        }
    }

    printf("\nПочаткова матриця A та B:\n");
        for (i=0;i<N;i++)
    {
        for (j=0;j<N;j++)
        {
            printf("%3d ", A[i][j]);
        }
        printf("\n");
    }
        printf("\n");

    for (i=0;i<N;i++)
    {
        for (j=0;j<M;j++)
        {
            printf("%3d ", B[i][j]);
        }
        printf("\n");
    }

    printf("\nМеню користування:\n1. Максимальне значення А \n2. Транспонувати B\n3. Помножити AxB\n4. Сортувати рядок матрицi A\n5. Показати суму в рядочках та стовбчиках\n");
    scanf("%d",&choise);
    switch (choise)
    {
    case 1:
    Maximum(A);
        break;
    case 2:
    Transponate(B,T);
    break;
    case 3:
        printf("AxB:\n");
       Multiply(A,B,Dob);
        break;
        case 4:
        printf("\nВведiть номер рядочка для сортування: ");
        scanf("%d",&sort);
        Sort(A,sort);
        break;
        case 5:
        Summ(A,B,sum);
        break;
    }
    printf("\nЯкi подальшi дiї?\n1. Restart\n2. Exit\n");
    scanf("%d",&end);
    if(end==1){
        system("cls");
        return main(); }
        else
        return 0;
        }
        void swap(int *A,int *B)
        {
            int temp;
            temp=*A;
           *A=*B;
           *B=temp;
        }
