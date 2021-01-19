#include <iostream>
#include <vector>
#include <string>
using namespace std;
class find_password{
private:
    vector<string> note;
    int N;
public:
    find_password(){
        std::cin >> N;
    }
    void set_val(){
        string str,tmp;
        for(int i=0;i<N;i++){
            std::cin >> str;
            tmp=str;
            string re_str;
            while(!str.empty()){
                re_str.push_back(str.back());
                str.pop_back();
            }
            note.push_back(re_str);
            for(int j=0;j<note.size();j++){
                if(tmp==note[j]){
                    std::cout << tmp.size()<<' '<<tmp[tmp.size()/2];
                    return ;
                }
            }
        }
    }

};
int main(){
    find_password fp;
    fp.set_val();

    return 0;
}
