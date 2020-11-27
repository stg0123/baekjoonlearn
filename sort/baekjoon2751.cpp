#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class sorting{
private:
    vector<int> num;
    int N;
public :
    sorting(int n):N(n){
        num.resize(n);
      
    };    

    void set_data(){
        for(int i=0;i<N;i++)
            std::cin >> num[i];
    };
    void bubble_sort(){
        int tmp;
        for(int i=0;i<N-1;i++){
            for(int j=0;j<N-1-i;j++)
                if(num[j]>num[j+1]){
                    tmp=num[j+1];
                    num[j+1]=num[j];
                    num[j]=tmp;
                }
        }
    };
    void sort(){
        std::sort(&num[0],&num[num.size()]);

    }
    void print_num(){
        for(int i=0;i<N;i++)
            std::cout << num[i]<<'\n';

    };
};

int main(){
    int n;
    std::cin >>n;
    sorting arr(n);
    arr.set_data();
    arr.sort();
    arr.print_num();
    
    
    return 0;
}