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
int find_mini(vector<vector<int>> etl,int machines,int tasks,int r=-1)
{
    //vector<int> temp;
    int mini;
    for (int i = 0; i < tasks; i++) 
    { 
  
        if(i == r)
        {
            mini = etl[0][i]; 
            for (int j = 1; j < machines; j++) 
            { 
                if (etl[j][i] < mini) 
                mini = etl[j][i]; 
            } 
            //temp.push_back(minm);
        }
    } 
    return mini;
}
vector<int> find_sec_min(vector<vector<int>> etl,int machines,int tasks,int r=-1)
{
    vector<int> temp;
    int sec = INT_MAX;
    for (int i = 0; i < tasks; i++) 
    { 
  
        if(i != r)
        {
            int first = etl[0][i]; 
            for (int j = 1; j < machines; j++) 
            { 
                if (etl[j][i] < first) 
                {
                    sec = first;
                    first = etl[j][i];
                }
                else if (etl[j][i] < sec) 
                {
                    sec = etl[j][i];
                }
                
            } 
            temp.push_back(abs(sec-first));
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
    int minm,row,column,sec_minm,index;
    vector<int> gantt;
    vector<int> columns;
    for(int k=0;k<tasks-1;k++)
    {
        if(k==0)
        {
            vector<int> temp = find_min(etl,machines,tasks);
            vector<int> temp1 = find_sec_min(etl,machines,tasks);
            int maxm = *max_element(temp1.begin(),temp1.end());
            //int index = find(temp1.begin(),temp1.end(),maxm);
            
            index;
            for(int i=0;i<temp1.size();i++)
            {
                if(temp1[i] == maxm)
                {
                    index = i;
                    break;
                }
            }
            columns.push_back(index);
            int mini = find_mini(etl,machines,tasks,index);
            gantt.push_back(mini);
            row = find_row(mini,etl,machines,tasks);
            //column = find_column(minm,etl,machines,tasks);
            //cout<<maxm<<" "<<index<<" "<<mini<<endl;
            for(int j=0;j<tasks;j++)
            {
                if(find(columns.begin(), columns.end(), j) ==  columns.end())
                {
                    etl[row][j] = etl[row][j] + mini;
                    //cout<<j<<" ";
                }
                //cout<<etl[row][j]<<" ";
            }
        }
        else
        {
            vector<int> temp = find_min(etl,machines,tasks,index);
            vector<int> temp1 = find_sec_min(etl,machines,tasks,index);
            int maxm = *max_element(temp1.begin(),temp1.end());
            //int index = find(temp1.begin(),temp1.end(),maxm);
            
            index;
            for(int i=0;i<temp1.size();i++)
            {
                if(temp1[i] == maxm)
                {
                    index = i;
                    break;
                }
            }
            columns.push_back(index);
            int mini = find_mini(etl,machines,tasks,index);
            gantt.push_back(mini);
            row = find_row(mini,etl,machines,tasks);
            //column = find_column(minm,etl,machines,tasks);
            //cout<<maxm<<" "<<index<<" "<<mini<<endl;
            for(int j=0;j<tasks;j++)
            {
                if(find(columns.begin(), columns.end(), j) ==  columns.end())
                {
                    etl[row][j] = etl[row][j] + mini;
                    //cout<<j<<" ";
                }
                //cout<<etl[row][j]<<" ";
            }
        }
          
          
    }
    vector<int> temp = find_min(etl,machines,tasks,column);
    cout<<"Makespan: "<<*max_element(temp.begin(),temp.end());
    //for(int i=0;i<columns.size();i++)
    //cout<<columns[i]<<" ";
    
    
    
    return 0;
}