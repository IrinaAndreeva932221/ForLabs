#include <iostream>
#include <time.h>

void Swap(int *x, int *y)
{
    int tmp=*x; *x=*y; *y=tmp;
}

void BubbleSortUp (int *a, int n, int g)
{
    for(int k=n-1; k>g; k--)
    {for(int i=g; i<k; i++)
        if(a[i]>a[i+1])
        Swap(&a[i], &a[i+1]);
    }
}

void RandInput(int **matr, int n, int left = 1, int right = 20)
{
    int i, j;
    matr[0][0] = 0;
    for (i = 1; i <= n; i++)
        matr[0][i]= i;
    for (i = 1; i <= n; i++)
        matr[i][0] = i;
    srand(time(0));
    for(i=1; i<=n; i++)
    for(j=1; j<=n; j++)
    {   if (i==j) matr[i][j] = 0;
        else
        matr[i][j]=rand()%right+left;}
}

void OutputMatr(int **matr, int n)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j=0; j <= n; j++)
            std::cout << matr[i][j] << ' ';
        std::cout << std::endl;
    }
}

void OutputPath(int *path, int n)
{
    for (int i = 0; i<n; i++)
        std::cout << path[i] << ' ';
    std::cout<<std::endl;
}

void getNewPath(int *path, int n, int *answ)
{
   int i, j, p=1, l,temp;
    for (l=1; l<n; l++) p*=l;
    for (l = 0; l<p-1; l++)
    {
    for(i=n-2; i>0; i--)
    {if (path[i]<path[i+1])
    {
        for(j=n-1; j>i; j--)
        {
            if(path[i]<path[j])
            {temp=path[i];
            path[i]=path[j];
            path[j]=temp;
            break;}
        }
        break;
    }}
    BubbleSortUp(path, n, i+1);
    OutputPath(path, n);
    }
}


int main()
{
    int N, startTown, i, j;
    std::cout << "Введите количество городов, которые необходимо посетить :";
    std::cin >> N;
    do {
    std::cout << "Введите номер начального города (он не может быть больше их количества):";
    std::cin >> startTown;} while (startTown>N || startTown<1);
    int *path = new int[N];
    int *final_path = new int [N];
    path[0] = startTown;
    final_path[0] = startTown;
    for (i = 1, j=1; i<N; i++, j++)
    {
        if (i == startTown) j++;
        path[i] = j;
    }
    int **cost = new int* [N];
        for (i = 0; i <= N; i++)
            cost[i] = new int [N];
    RandInput(cost, N);
    OutputPath(path, N);
    std::cout << std::endl;
    getNewPath(path, N, path);
    OutputMatr(cost, N);
    for (i = 0; i <= N; i++)
        delete [] cost[N];
    delete [] path;
    delete [] final_path;
    return 0;
}
