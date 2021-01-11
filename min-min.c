#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
vector<int> find_min(vector<vector<int>> etl,int machines,int tasks,int r=-1)
{
    vector<int> temp;
    for (int i = 0; i < tasks; i++) 
    { 
  
        if(i != r)
        {
            int minm = etl[0][i]; 
            for (int j = 1; j < machines; j++) 
            { 
                if (etl[j][i] < minm) 
                minm = etl[j][i]; 
            } 
            temp.push_back(minm);
        }
    } 
    return temp;
}
int find_row(int minm,vector<vector<int>> etl,int machines,int tasks)
{
    for(int i=0;i<machines;i++)
    {
        for(int j=0;j<tasks;j++)
        {
            if(etl[i][j] == minm)
            {
                int row = i;
                return row;;
            }
        }
                
    }
    
}
int find_column(int minm,vector<vector<int>> etl,int machines,int tasks)
{
    for(int i=0;i<machines;i++)
    {
        for(int j=0;j<tasks;j++)
        {
            if(etl[i][j] == minm)
            {
                int column = j;
                return column;
            }
        }
                
    }
    
}
int main()
{
    vector<vector<int>> etl{
        {140,20,60},
        {100,100,70}
    };
    int tasks = 3;
    int machines = 2;
    int minm,row,column;
    vector<int> gantt;
    vector<int> columns;
    for(int k=0;k<tasks-1;k++)
    {
        if(k==0)
        {
            vector<int> temp = find_min(etl,machines,tasks);
            minm = *min_element(temp.begin(), temp.end());
            gantt.push_back(minm);
            row = find_row(minm,etl,machines,tasks);
            column = find_column(minm,etl,machines,tasks);
            columns.push_back(column);
            for(int j=0;j<tasks;j++)
            {
                if(j!=column)
                etl[row][j] = etl[row][j] + minm;
                //cout<<etl[row][j]<<" ";
            }
        }
        else
        {
            vector<int> temp = find_min(etl,machines,tasks,column);
            minm = *min_element(temp.begin(), temp.end());
            gantt.push_back(minm);
            row = find_row(minm,etl,machines,tasks);
            column = find_column(minm,etl,machines,tasks);
            columns.push_back(column);
            for(int j=0;j<tasks;j++)
            {
                if(find(columns.begin(), columns.end(), j) ==  columns.end())
                {
                    etl[row][j] = etl[row][j] + minm;
                    //cout<<j<<" ";
                }
                //cout<<etl[row][j]<<" ";
            }
        }
          
          
    }
    vector<int> temp = find_min(etl,machines,tasks,column);
    cout<<"Makespan: "<<*max_element(temp.begin(),temp.end());
    
    
    
    
    return 0;
}