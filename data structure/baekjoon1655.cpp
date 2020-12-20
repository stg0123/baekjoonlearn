#include <iostream>
#include <vector>
#include <queue>

using namespace std;
template<typename T>
class max_heap{
private :
    vector<T> heap;

public:
    max_heap(){
        heap.push_back((T)0);
    };
    bool compare(T a,T b){
        return a>b;
    }
    void swap(int a,int b){
        T temp=heap[b];
        heap[b]=heap[a];
        heap[a]=temp;
    }
    void pop(){
        swap(1,heap.size()-1);
        heap.pop_back();
        int i=1;
        while(i*2<heap.size()){
            if(i*2==heap.size()-1){
                if(compare(heap[i*2],heap[i]))
                    swap(i*2,i);
                break;
            }
            if(compare(heap[i],heap[i*2])&&compare(heap[i],heap[(i*2)+1]))
                break;
            else if(compare(heap[i*2],heap[(i*2)+1])){
                swap(i*2,i);
                i*=2;
            }
            else{
                swap((i*2)+1,i);
                i=(i*2)+1;
            }
        }
    }

    void push(T a){
        heap.push_back(a);
        int i=heap.size()-1;
        while(i>1){
            if(compare(heap[i],heap[i/2])){
                swap(i,i/2);
                i/=2;
            }
            else            
                break;            
        }
    };
    int size(){
        return heap.size()-1;
    }

    T top(){
        return heap[1];
    };

    void print_heap(){
        for(int i=1;i<heap.size();i++)
            std::cout << heap[i]<<' ';
        std::cout << '\n';
    };
    
};

template<typename T>
class min_heap{
private :
    vector<T> heap;

public:
    min_heap(){
        heap.push_back((T)0);
    };
    bool compare(T a,T b){
        return a<b;
    }
    void swap(int a,int b){
        T temp=heap[b];
        heap[b]=heap[a];
        heap[a]=temp;
    }
    void pop(){
        swap(1,heap.size()-1);
        heap.pop_back();
        int i=1;
        while(i*2<heap.size()){
            if(i*2==heap.size()-1){
                if(compare(heap[i*2],heap[i]))
                    swap(i*2,i);
                break;
            }
            if(compare(heap[i],heap[i*2])&&compare(heap[i],heap[(i*2)+1]))
                break;
            else if(compare(heap[i*2],heap[(i*2)+1])){
                swap(i*2,i);
                i*=2;
            }
            else{
                swap((i*2)+1,i);
                i=(i*2)+1;
            }
        }
    }

    void push(T a){
        heap.push_back(a);
        int i=heap.size()-1;
        while(i>1){
            if(compare(heap[i],heap[i/2])){
                swap(i,i/2);
                i/=2;
            }
            else            
                break;            
        }
    };
    int size(){
        return heap.size()-1;
    }

    T top(){
        return heap[1];
    };

    void print_heap(){
        for(int i=1;i<heap.size();i++)
            std::cout << heap[i]<<' ';
        std::cout << '\n';
    };
    
};

class mid_val{
private:
    int mid;
    max_heap<int> maxh;
    min_heap<int> minh;
    int N;
public:
    mid_val(int n):N(n){
        std::cin >> mid;
        std::cout << mid <<'\n';
    };

    void input(){
        int a;
        for(int i=0;i<N-1;i++){
            std::cin >> a;
            if(a<mid)
                maxh.push(a);
            else
                minh.push(a);

            //std::cout << "mid:"<<mid<<"a:"<<a << ' '<< maxh.size()<<' '<<minh.size()<<'\n';
            
            if(maxh.size()>minh.size()){
                minh.push(mid);
                mid=maxh.top();
                maxh.pop();
            }
            else if(maxh.size()+1<minh.size()){
                maxh.push(mid);
                mid=minh.top();
                minh.pop();
            }
            std::cout << mid << '\n';
        }
    };

};


int main(){
    int n;
    std::cin >>n;
    mid_val mv(n);
    mv.input();

    return 0;
}