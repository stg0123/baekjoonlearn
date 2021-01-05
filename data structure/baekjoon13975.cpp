#include <iostream>
#include <vector>
using namespace std;
template<typename T>
class min_heap{
private:
    vector<T> heap;
public:
    min_heap(){
        heap.push_back((T)0);
    };
    bool compare(T a,T b){
        return a>b;
    }
    void swap(int a,int b){
        T temp =heap[a];
        heap[a]=heap[b];
        heap[b]=temp;
    }

    void push(T a){
        heap.push_back(a);
        int i=heap.size()-1;
        while(i>1){
            if(compare(heap[i/2],heap[i])){
                swap(i/2,i);
                i/=2;
            }
            else
                break;
        }
    }
    void print_heap(){
        for(int i=1;i<heap.size();i++)
            std::cout <<heap[i]<<' ';
        std::cout <<'\n';
    }
    int size(){
       return heap.size()-1; 
    }

    T pop(){
        if(heap.size()<=1){
            std::cout <<"error\n";
            return 0;
        }
        T sol=heap[1];
        swap(1,heap.size()-1);
        heap.pop_back();
        int tmp=1;
        while(tmp*2<=heap.size()-1){
            if(tmp*2==heap.size()-1){
                if(compare(heap[tmp],heap[tmp*2]))
                    swap(tmp,tmp*2);
                break;
            }
            else if(compare(heap[tmp],min(heap[tmp*2],heap[tmp*2+1]))){
                if(compare(heap[tmp*2],heap[tmp*2+1])){
                    swap(tmp,tmp*2+1);
                    tmp=tmp*2+1;
                }
                else{
                    swap(tmp,tmp*2);
                    tmp=tmp*2;
                }
            }
            else
                break;            
        }
        return sol;
    }
};
class file_add{
private:
    min_heap<long long> heap;
    int N;
public:
    file_add(int n):N(n){  
    };
    void set_val(){
        int n;
        for(int i=0;i<N;i++){
            std::cin >> n;
            heap.push(n);
        }
    }

    void find(){
        long long sum,sol=0;
        while(heap.size()>1){
            sum=heap.pop()+heap.pop();
            sol+=sum;
            heap.push(sum);
        }
        std::cout << sol<<'\n';
    };


};
int main(){
    int n,tmp;
    std::cin >>n;
    for(int i=0;i<n;i++){
        std::cin >> tmp;
        file_add f(tmp);
        f.set_val();
        f.find();
    }
 

    return 0;
}