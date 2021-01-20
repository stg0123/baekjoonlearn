#include <iostream>
#include <vector>
using namespace std;
class find_preorder{
private:
    vector<int> inorder;
    vector<int> postorder;
    int N;
public:
    find_preorder(){
        std::cin >> N;
        inorder.resize(N+1);
        postorder.resize(N+1);
        set_val();
        preorder(1,N,1,N);
    }
    void set_val(){
        for(int i=1;i<=N;i++)
            std::cin >> inorder[i];
        for(int i=1;i<=N;i++)
            std::cin >> postorder[i];
    }
    void preorder(int start_in,int end_in,int start_post,int end_post){
        if(start_in>end_in||start_post>end_post)
            return ;
        std::cout << postorder[end_post]<< ' ';
        int i;
        for(i=start_in;i<=end_in;i++){
            if(inorder[i]==postorder[end_post])
                break;
        }
        int gap = i-1-start_in;
        preorder(start_in,i-1,start_post,start_post+gap);
        preorder(i+1,end_in,start_post+gap+1,end_post-1);
    }


};
int main(){
    find_preorder find;
    return 0;
}