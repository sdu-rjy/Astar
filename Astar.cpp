#include "Astar.h"
#include <math.h>


using namespace std;

int map[101][101] =
{
    {0,0,0,1,0,1,0,0,0},
    {0,0,0,1,0,1,0,0,0},
    {0,0,0,0,0,1,0,0,0},
    {0,0,0,1,0,1,0,1,0},
    {0,0,0,1,0,1,0,1,0},
    {0,0,0,1,0,0,0,1,0},
    {0,0,0,1,0,0,0,1,0}
};

void Astar::showmap(){

for(int i=0;i<=row;i++){
        for(int j=0;j<=col;j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }  

}

Astar::Astar()
{

}
Astar::~Astar()
{

}

void Astar::searchpath(Node start,const Node end){
    cout<<"this is map"<<endl;
    showmap();
    Node nextnode = start;

    
    
    for(int i = 20;i > 0;i--){
        //cout<<"hello3"<<endl;
        gn(start,nextnode,end);
        start = nextnode;
        if(nextnode.x == end.x && nextnode.y == end.y)
        break;
                
    }

    for (int i = 0; i < CloseList.size(); i++)
    {
       cout<<"next point is "<<CloseList[i].x<<" "<<CloseList[i].y<<endl;
    }
    
    return;
}

void Astar::gn(Node _start,Node& next_node,const Node _end){
    int colId[8] = {-1,0,1,1,1,0,-1,-1};
    int rowId[8] = {-1,-1,-1,0,1,1,1,0};
    next_node.f = 999999999; 
    cout<<"hello1"<<endl;
    for (int i = 0; i < 8; i++)
    {
        Node temp = next_node;
        
        if( _start.x + colId[i] >= col || _start.x + colId[i] < 0 ||
            _start.y + rowId[i] >= row || _start.y + rowId[i] < 0 )
        continue;
        if(map[_start.x + colId[i]][_start.y + rowId[i]] == 1)
        continue;
        
        temp.x = _start.x + colId[i];
        temp.y = _start.y + rowId[i];

        if(temp.x == _end.x && temp.y == _end.y)
        {
            cout<<"find path"<<endl;
            return;
        }
        

        if(abs(colId[i])+abs(rowId[i]) == 2)
        temp.g = 1.414;
        else
        temp.g = 1;
        
        if(next_node.f > temp.g + hn(temp, _end)){
             next_node.x = _start.x + colId[i];
             next_node.y = _start.y + rowId[i];
             next_node.g = temp.g;
             next_node.f = next_node.g + hn(next_node, _end);
        }   
    } 
    next_node.father = &_start;
    CloseList.push_back(next_node);
    return;
}

int Astar::hn(Node _nextnode,const Node _end){
    return sqrt((_nextnode.x-_end.x)*(_nextnode.x-_end.x) + (_nextnode.y-_end.y)*(_nextnode.y-_end.y));

}
