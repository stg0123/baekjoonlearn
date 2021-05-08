#include <iostream>
#include <vector>
using namespace std;
class easymax{
private:
    vector<int> m_sum;
    int N,M;
public:
    easymax(){
        std::cin >> N >> M;
        m_sum.resize(N,0);
        set_val();
    }
    void set_val(){
        int last,tmp;
        std::cin >> last;
        for(int i=1;i<N;i++){
            std::cin >>tmp;
            m_sum[i]=m_sum[i-1]+abs(tmp-last);
            last=tmp;
        }
    }
    void find_sol(){
        int s,e;
        for(int i=0;i<M;i++){
            std::cin >> s >> e;
            if(s>=e)
                std::cout << 0 << '\n';
            else
                std::cout << m_sum[e-1]-m_sum[s-1]<<'\n';
        }
    }

};
int main(){
    easymax em;
    em.find_sol();
    return 0;
}