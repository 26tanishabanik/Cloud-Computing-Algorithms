#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
bool sortcol( const vector<int>& v1,const vector<int>& v2 ) 
{ 
 return v1[1] < v2[1]; 
} 
int main()
{
    vector<vector<int>> process
    {
        {1,1,2},
        {2,0,2},
        {3,6,4},
        {4,5,3}
    };
    sort(process.begin(), process.end(),sortcol);
    //unordered_map<int,int> time_time;
    //cout<<"hi";
    //vector<vector<int>> time_time;
    int time_time[4][2];
    int tat[process.size()];
    int wt[process.size()];
    for(int i=0;i<process.size();i++)
    {
        if(i == 0)
        {
            time_time[i][0] = process[i][1];
            time_time[i][1] = process[i][1]+process[i][2];
            //cout<<"hi";
        }
        //time_time[process[i][1]] = process[i][1]+process[i][2];
        
        else
        {
            if(process[i][1] <= time_time[i-1][1])
            {
                time_time[i][0] = time_time[i-1][1];
                time_time[i][1] = time_time[i][0]+process[i][2];
                //cout<<"hi";
            }
            else
            {
                time_time[i][0] = process[i][1];
                time_time[i][1] = process[i][1]+process[i][2];
                
            }
            //cout<<"hi";
            //time_time[process[i-1][1]] = process[i][1]+process[i][2];
            
            //time_time[process[i][1]] = process[i][1]+process[i][2];
        }
    }
    for(int i = 0;i<process.size();i++)
    {
        for(int j=0;j<2;j++)
        cout<<time_time[i][j]<<" ";
        cout<<endl;
    }
    int sum=0;
    for(int i=0;i<process.size();i++)
    {
        tat[i] = time_time[i][1] - process[i][1];
        sum+=tat[i];
    }
    cout<<"Average Turnaorund Time: "<<(float)sum/process.size()<<endl; 
    sum=0;
    for(int i=0;i<process.size();i++)
    {
        wt[i] = tat[i] - process[i][2];
        sum+=wt[i];
    }
    cout<<"Average TWaiting Time: "<<(float)sum/process.size()<<endl;
    
    
    return 0;
}