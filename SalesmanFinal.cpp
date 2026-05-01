#include <iostream>
using namespace std;


int n;
int cost[20][20];
bool visited[20];
int minCost = 999999;
int path[20];
int bestPath[1000][20];
int pathCount = 0;

void tsp(int city, int count, int currentCost)
{
    if(count == n)
    {
        if(cost[city][0] != 0)
        {
            int totalCost = currentCost + cost[city][0];
            if(totalCost < minCost)
            {
                minCost = totalCost;  
                pathCount = 0;       
            }
            if(totalCost == minCost)
            {
                for(int i = 0; i < n; i++){
                    bestPath[pathCount][i] = path[i];
                }
                pathCount++;
            }
        }
        return;
    }

    for(int i = 0; i < n; i++)
    {
        if(!visited[i] && cost[city][i] != 0)
        {
            visited[i] = true;      
            path[count] = i;       
            tsp(i, count + 1, currentCost + cost[city][i]);

            visited[i] = false;    
        }
    }
}

int main()
{
    cout << "Enter number of cities: ";
    cin >> n;

    cout << "Enter cost matrix:\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }
    for(int i = 0; i < n; i++)
        visited[i] = false;

    visited[0] = true;
    path[0] = 0;

    tsp(0, 1, 0);

    cout << "\nMinimum Cost = " << minCost << endl;

    cout << "\nAll Minimum Cost Paths:\n";

    for(int i = 0; i < pathCount; i++)
    {
        for(int j = 0; j < n; j++)
        {
            // convert 0,1,2,3 -> A,B,C,D
            //cout << char('A' + bestPath[i][j]) << " -> ";
            cout << bestPath[i][j] << " -> ";
        }
        //cout << "A" << endl; // return to start city
         cout<<0<<endl;
    }

    cout << "\nTotal minimum paths = " << pathCount << endl;

    return 0;
}
