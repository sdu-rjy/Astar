#ifndef ASTAR_H
#define ASTAR_H
#include <iostream>
#include <vector>
#include <stack>

#include <algorithm>
#include <math>

using namespace std;

typedef struct Node
{
    int x,y;
    int g;//起始点到当前点实际代价
    int h;//当前节点到目标节点最佳路径的估计代价
    int f;//估计值
    Node* father;
    //结构体也可以拥有构造函数，所以我们可以通过结构体的构造函数来初始化结构体对象
    Node(int x,int y){
        this->x = x;
        this->y = y;
        this->g = 0;
        this->f = 0;
        this->h = 0;
        this->father =NULL;
    }
    Node(int x,int y,Node* father)
    {
        this->x = x;
        this->y = y;
        this->g = 0;
        this->f = 0;
        this->h = 0;
        this->father = father;
    }

}Node;

class Astar
{
private:
    static const int row = 6;
    static const int col = 8;  
    
    /* data */
public:
    //构造函数和析构函数
    Astar();
    ~Astar();
    
    //Node End;
    //返回 上一个点到当前点实际代价 的函数 g
    void gn(Node _start,Node& next_node,const Node _end);
    //返回 当前节点到目标节点最佳路径的估计代价 的函数h
    int hn(Node _nextnode,const Node _end);


    //估计值f 返回估计值的函数


    //存储路径的vector

    //寻找路径的函数
    void searchpath(Node start,Node end);
    //展示地图
    void showmap();

    void checkPoint(int x,int y);

    //开集合
    vector<Node> OpenList;

    //闭集
    vector<Node> CloseList;



};

#endif

