#include "Astar.h"
#include <iostream>

using namespace std;

int main(){
    Astar astar;
    cout<<"this is map"<<endl;
    

    //astar.showmap();


/*     int x,y;
    cout<<"please enter your start:"<<endl;
    cin>>x>>y; */
    Node start = Node(5,1);
/*     cout<<"please enter your end:"<<endl;
    cin>>x>>y; */
    Node End = Node(3,8);

    astar.searchpath(start,End);

    return 0;


}