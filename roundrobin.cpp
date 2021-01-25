#include<iostream>
using namespace std;

int main()
{
    int i,n,j,qt,count=0,temp,ex=0,pid[100],at[100],bt[100],wt[100],rem[100],tat[100];
    float atat=0.0,awt=0.0;
    cout<<"Enter number of processes:";
    cin>>n;
    cout<<"\nEnter the pids:\n";
    for(i=0;i<n;i++)
    cin>>pid[i];
    cout<<"\nEnter the arrival time:\n";
    for(i=0;i<n;i++)
    cin>>at[i];
    cout<<"\nEnter the burst time:\n";
    for(i=0;i<n;i++)
   {
       cin>>bt[i];
       rem[i] = bt[i];
   }
   cout<<"\nEnter the quantum time:\n";
   cin>>qt;
   for(i=0;i<n;i++)
   {
       for(j=i+1;j<n;j++)
       {
           if(at[i]>at[j])
           {
               temp = bt[i];
               bt[i] = bt[j];
               bt[j] = temp;
               
               temp = rem[i];
               rem[i] = rem[j];
               rem[j] = temp;
               
               temp = pid[i];
               pid[i] = pid[j];
               pid[j] = temp;
               
               temp = at[i];
               at[i] = at[j];
               at[j] = temp;
           }
       }
   }
   while(true)
   {
       for(i=0,count=0;i<n;i++)
       {
           temp = qt;
           if(rem[i] == 0)
           {
               count++;
               continue;
           }
           
           if(rem[i]>qt)
           {
               rem[i] = rem[i] - qt;
           }
           else if(rem[i] >= 0)
           {
               temp = rem[i];
               rem[i]=0;
           }
           ex+=temp;
           tat[i] = ex - at[i];
       }
       if(n == count)
       break;
   }
   cout<<"\n PID\tArrival Time\tBurst Time\tTurnaround Time\tWaiting Time\n";
   for(i=0;i<n;i++)
   {
       atat += tat[i];
       wt[i] = tat[i] - bt[i];
       awt += wt[i];
       cout<<pid[i]<<'\t'<<at[i]<<'\t'<<bt[i]<<'\t'<<tat[i]<<'\t'<<wt[i]<<'\n';
       
   }
   atat = atat/n;
   awt = awt/n;
   cout<<"Average Turnaround Time:"<<atat<<'\n';
   cout<<"Average Waiting Time:"<<awt<<'\n';
   return 0;
}