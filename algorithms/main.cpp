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
}



int main()
{
    int N, first_town, i, j;
    std::cout << "Введите количество городов, которые необходимо посетить :";
    std::cin >> N;
    do {
    std::cout << "Введите номер начального города (он не может быть больше их количества):";
    std::cin >> first_town;} while (first_town>N || first_town<1);
    int *path = new int[N];
    path[0] = first_town;
    for (i = 1, j=1; i<N; i++, j++)
    {
        if (i == first_town) j++;
        path[i] = j;
    }
    int **cost = new int* [N];
        for (i = 0; i <= N; i++)
            cost[i] = new int [N];
    RandInput(cost, N);
    OutputPath(path, N);
    std::cout << std::endl;
    OutputMatr(cost, N);
    for (i = 0; i <= N; i++)
        delete [] cost[N];
    delete [] path;
    return 0;
}
