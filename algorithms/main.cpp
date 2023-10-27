#include <iostream>
#include <vector>
#include <string>

struct Table
{
    char alph[256];
    int values[256];
};

int GetValueForTable(std::string s, int index)
{
    for(int i=s.size()-2; i>=index+1; i--)
    if (s[i]==s[index]) return s.size()-i-1;
    return s.size()-index-1;
}

Table SetTable(std::string sample)
{
    Table a;
    int i, j;
    for (i=0; i<256; i++)
    {
        a.alph[i]=i;
        a.values[i]=sample.size();
    }
    for(j=sample.size()-2; j>=0; j--)
    {

        i=int(sample[j]);
        a.values[i]=GetValueForTable(sample, j);
    }
    return a;
}

void OutputTable(Table a)
{
    for(int i=97; i<123; i++)
    std::cout<<a.alph[i]<<' ';
    std::cout<<'\n';
    for(int i=97; i<123; i++)
    std::cout<<a.values[i]<<' ';
}

void OutputVector(std::vector<int> v)
{
    for(int i; i<v.size(); i++)
    std::cout<<v[i]<<" ";
}

int GetFirstIndexOfSubstr(Table table, std::string s, std::string sample)
{
    int sampleSize=sample.size();
    int i=sampleSize-1, j=sampleSize-1, k;
    while (i<s.size() && j>=0)
    {
        for (k=i, j=sampleSize-1; j>=0; j--, k--)
        {
            if (s[k]!=sample[j])
            {i+=table.values[s[i]];
             j=sampleSize-1;
             break;}
        }
    }
    if(j<0) return i+1-sampleSize;
    return -1;
}

void GetAllIndexesInAB(Table table, std::string s, std::string sample, std::vector<int>& indexes, int left, int right)
{
    int sampleSize=sample.size();
    int i=sampleSize-1+left, j=sampleSize-1, k;
    while (i<=right)
    {
        for (k=i, j=sampleSize-1; j>=0; j--, k--)
        {
            if (s[k]!=sample[j])
            {i+=table.values[s[i]];
             j=sampleSize-1;
             break;}
        }
        if (j<0)
        {indexes.push_back(i+1-sampleSize); i+=table.values[s[i]];}
    }
}

int main()
{
    std::string str, sample;
    Table table;
    int firstIndex, left, right;
    std::vector<int> indexes;
    std::cout<<"Введите строку для поиска в ней подстроки: ";
    getline(std::cin, str);
    std::cout<<"Введите искомую подстроку: ";
    getline(std::cin, sample);
    table=SetTable(sample);
    //OutputTable(table);
    //firstIndex=GetFirstIndexOfSubstr(table, str, sample);
    //if (firstIndex>=0) std::cout<<"Индекс первого вхождения подстроки: "<<firstIndex<<'\n';
    //else std::cout<<"Подстрока не найдена";
    std::cout<<"Введите левую и правую границы: ";
    std::cin>>left>>right;
    if(left>=right || left<0 || right>str.size()-1)
    {
        std::cout<<"Вы неверно ввели границы, поиска будет производиться по всей строке\n";
        left=0; right=str.size()-1;
    }
    GetAllIndexesInAB(table, str, sample, indexes, left, right);
    if (!indexes.empty()) {std::cout<<"Список индексов вхождений подстроки: "; OutputVector(indexes);}
    else std::cout<<"Подстрока не найдена";
    return 0;
}
