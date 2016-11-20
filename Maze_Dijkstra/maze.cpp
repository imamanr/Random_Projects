//
//  main.cpp
//  Aware
//
//  Created by Imama Noor on 11/19/16.
//  Copyright © 2016 Imama. All rights reserved.
//

#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;
#define ROW 1
#define COL 1

//to store matrix cell cordinates
struct Point
{
    int x;
    int y;
};

// An Data Structure for queue used in BFS
struct queueNode
{
    Point pt;  // The cordinates of a cell
    int dist;  // cell's distance of from the source
};

// check whether given cell (row, col) is a valid
// cell or not.
bool isValid(int row, int col,int maxRow,int maxCol)
{
    // return true if row number and column number
    // is in range
    return (row < 0) || (row >= maxRow) || (col < 0) || (col >= maxCol);
    
}

// These arrays are used to get row and column
// numbers of 4 neighbours of a given cell
int rowNum[] = {-1, 0, 0, 1};
int colNum[] = {0, -1, 1, 0};

void print2D(vector<vector<char> > & arr)
{
    for(int i=0;i<arr.size();++i)
    {
        for(int j=0;j<arr[0].size();++j)
        {
            cout << (arr[i][j]) << "   ";
        }
        cout << endl;
    }
}

// function to find the shortest path between
// a given source cell to a destination cell.
int BFS(vector<vector<int> > mat, Point src, Point dest)
{

    int numEle =(int) mat.size() * mat[0].size();
    int maxRow = (int) mat.size();
    int maxCol = (int) mat[0].size();
    vector<vector<char> > temp(maxRow,vector<char>(maxCol,1));
    //temp = new char *[mat.size()];
    
    for (int i=0;i<mat.size();i++) {
        for(int j=0;j<mat[0].size();j++) {
            if(mat[i][j] == 1) temp[i][j] = 'x';
            else if(mat[i][j] == 0) temp[i][j] = '.';
        }
    }
    temp[src.x][src.y] = 'o';
    temp[dest.x][dest.y] = 'f';
    Point dist;
    dist.x = src.x - dest.x;
    dist.y = src.y - dest.y;
    
    bool visited[mat.size()][mat[0].size()];
    memset(visited, false, sizeof visited);
    
    // Mark the source cell as visited
    visited[src.x][src.y] = true;
    
    // Create a queue for BFS
    queue<queueNode> q;
    
    // distance of source cell is 0
    queueNode s = {src, 0};
    q.push(s);  // Enqueue source cell
    int sum, minSum=numEle,idx=0,row=0,col=0;
    // Do a BFS starting from source cell
    while (!q.empty())
    {
        queueNode curr = q.front();
        Point pt = curr.pt;
        
        // If we have reached the destination cell,
        // we are done
        if (pt.x == dest.x && pt.y == dest.y)
            return curr.dist;
        
        // Otherwise dequeue the front cell in the queue
        // and enqueue its adjacent cells
        q.pop();
        
        for (int i = 0; i < 4; i++)
        {
            row = pt.x + rowNum[i];
            col = pt.y + colNum[i];
            if(isValid(row, col, maxRow,maxCol)) {
                if(row < 0) row = 0;
                if(row >= mat.size()) row = mat.size()-1;
                if(col < 0) col = 0;
                if(col >= mat[0].size()) col = mat[0].size()-1;
            }
            dist.x = row - dest.x;
            dist.y = col - dest.y;
            
            sum = abs(dist.x) + abs(dist.y);
            
            if(minSum > sum && ! mat[row][col]) {
                idx = i;
                minSum = sum;
                
            }
        }
        
        row = pt.x + rowNum[idx];
        col = pt.y + colNum[idx];
        // if adjacent cell is valid, has path and
        // not visited yet, enqueue it.
        if (!isValid(row, col, maxRow,maxCol) && ! mat[row][col] &&
                !visited[row][col]) {
                // mark cell as visited and enqueue it
                visited[row][col] = true;
                queueNode Adjcell = { {row, col},
                    curr.dist + 1 };
                temp[Adjcell.pt.x][Adjcell.pt.y] = 'o';
                temp[pt.x][pt.y] = '.';
                print2D(temp);
            cout << row << "," << col << endl;
                q.push(Adjcell);
        }
        
    }
    
    //return -1 if destination cannot be reached
    return -1;
}


int main(int argc, char** argv)
{
    ++argv;
    ifstream infile;
    infile.open(*argv);
    
    if (infile.fail())
    {
        cerr << "Error opening file" << endl;
        exit(1);
    }

    Point src,dest;
   
    string s;
    vector<vector<int> > maze;
    int i=0;
    while(infile >> s)
    {
        vector<int> row;
        for(int j=0;j<s.size();++j)
        {
            if(s[j]=='o')
            {
                src.x=i;
                src.y=j;
                row.push_back(0);
            }
            else if(s[j]=='f')
            {
                dest.x=i;
                dest.y=j;
                row.push_back(0);
            }
            else
            {
                row.push_back((s[j]=='x'?1:(0)));
            }
        }
        maze.push_back(row);
        ++i;
    }
    
    int dist = BFS(maze,src,dest);
    
    if(dist == -1) {    system("clear");
                       cout << "unsolvable" << endl;}
    
    return 0;
}
