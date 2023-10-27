#include <iostream>
#include <time.h>

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
    {   if (i==j) matr[i][j] = -1;
        else
        matr[i][j]=rand()%right+left;}
}

void RowsBack(int **matr, int n)
{
    int i;
    for (i = 1; i <= n; i++)
        matr[0][i]= i;
    for (i = 1; i <= n; i++)
        matr[i][0] = i;
}

void OutputMatr(int **matr, int n)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j=0; j <= n; j++)
            std::cout << matr[i][j] << '\t';
        std::cout << std::endl;
    }
}

void OutputPath(int *path, int n)
{
    for (int i = 0; i<n; i++)
        std::cout << path[i] << ' ';
    std::cout<<std::endl;
}

bool InCycle(int *path, int k, int index)
{
    for (int i=0; i<k; i++) if(path[i]==index) return 0;
    return 1;
}

int GetMinElement(int *row, int *path, int n)
{
    int minInd=0;
    row[0]=1000;
    for (int i=1; i<=n ; i++)
    {
        if (row[minInd]>row[i] && row[i]!=-1 && InCycle(path, n, i)) minInd=i;
    }
    return minInd;
}

int GetCostOfFinalPath(int **matCost, int *path, int n)
{
    int i, cost=0, town=path[0];
    for (i=1; i<n; i++)
    {
        town=GetMinElement(matCost[town], path, n);
        path[i]=town;
        cost+=matCost[path[i-1]][town];
    }
    RowsBack(matCost, n);
    return cost;
}

int main()
{
    int N, startTown, i, cost=0;
    std::cout << "Введите количество городов, которые необходимо посетить :";
    std::cin >> N;
    do {
    std::cout << "Введите номер начального города (он не может быть больше их количества):";
    std::cin >> startTown;} while (startTown>N || startTown<1);
    int *final_path = new int [N];
    final_path[0] = startTown;
    int **matCost = new int* [N];
        for (i = 0; i <= N; i++)
            matCost[i] = new int [N];
    RandInput(matCost, N);
    OutputMatr(matCost, N);
    cost=GetCostOfFinalPath(matCost, final_path, N);
    std::cout<<cost<<'\n';
    OutputPath(final_path, N);
    for (i = 0; i <= N; i++)
        delete [] matCost[N];
    delete [] final_path;
    return 0;
}
