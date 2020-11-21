#include <iostream>
#include <vector>

using namespace std;
typedef struct node{
    int data;
}node;

class quicksort{
private:
    vector<node> map;
    int N;
public :
    quicksort(int n):N(n){};

    void set_map(){
        node tmp;
        for(int i=0;i<N;i++){
            std::cin >> tmp.data;
            map.push_back(tmp);
        }
    };

    void print_map(){
        for(int i=0;i<N;i++)
            std::cout << map[i].data<< ' ';
        std::cout <<'\n';
    };
    
    void sorting(int start,int end){
        if(start>=end)
            return ;
        std::cout << "start ,end = "<<start << ','<<end<<'\n'; 
        print_map();
        int pivot,x,y;
        pivot=start;
        x=start+1;
        y=end;
        while(x<y){
            while(map[x].data<=map[pivot].data&&x<=end)
                x++;
            while(map[y].data>=map[pivot].data&&y>start)
                y--;

            if(x<y){
                swap(x,y);
                continue;
            }
            swap(pivot,y);
            sorting(start,y-1);
            sorting(y+1,end);

        }

    };

    void swap(int x,int y){
        node tmp;
        tmp=map[x];
        map[x]=map[y];
        map[y]=tmp;
    };


};
int main(){
    int n;
    std::cin >>n;
    quicksort qs(n);
    qs.set_map();
    qs.sorting(0,n-1);
    qs.print_map();

    return 0;
}