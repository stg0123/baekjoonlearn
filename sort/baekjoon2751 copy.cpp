#include <iostream>
#include <vector>
using namespace std;
class sorting{
private:
    vector<int> val;
    int N;
public:
    sorting(){
        std::cin >> N;
        val.resize(N);
        for(int i=0;i<N;i++)
            std::cin >> val[i];
    }

    void SelectionSort(){
        for(int i=0;i<N-1;i++){
            int idx = i;
            for(int j=i+1;j<N;j++){
                if(val[idx]>val[j])
                    idx= j;
            }
            swap(val[i],val[idx]);
        }
    }
    void InsertionSort(){
        for(int i=1;i<N;i++){
            int key = val[i];
            for(int j=i-1;j>=0;j--){
                if(val[j+1]>=val[j]){
                    val[j+1]=key;
                    break;
                }
                swap(val[j+1],val[j]);
            }
        }
    }
    void BubbleSort(){
        for(int i=0;i<N-1;i++){
            for(int j=1;j<N-i;j++){
                if(val[j-1]>val[j])
                    swap(val[j-1],val[j]);
            }
        }

    }


    void print_val(){
        for(int i=0;i<val.size();i++)
            std::cout << val[i] << '\n';
    }

};
int main(){
    sorting st;
    st.BubbleSort();
    st.print_val();

    return 0;
}