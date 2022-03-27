#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
struct node{
    int time=-1;
    int all_time=0;
};
class test3{
private:
    map<string,node> m;
    vector<int> fees;
public:
    test3(vector<int>& fees):fees(fees){
        
    };

    vector<int> find_sol(vector<string>& records){
        for(int i=0;i<records.size();i++){
            string str = records[i];
            int time = stoi(str.substr(0,2))*60+stoi(str.substr(3,5));
            string number=str.substr(6,4);
            string q=str.substr(11);
            
            if(q=="IN")
                m[number].time=time;
            else if(q=="OUT"){
                m[number].all_time+=time-m[number].time;
                m[number].time=-1;
            }
        }
        vector<int> sol;
        int end = 23*60+59;
        for(auto t : m){
            if(t.second.time>=0)
                t.second.all_time+=end-t.second.time;
            if(t.second.all_time<=fees[0])
                sol.push_back(fees[1]);
            else{
                int mod= (t.second.all_time-fees[0])%fees[2];
                if(mod)
                    sol.push_back(fees[1]+((t.second.all_time-fees[0])/fees[2]+1)*fees[3]);
                else
                    sol.push_back(fees[1]+(t.second.all_time-fees[0])/fees[2]*fees[3]);
            }
        }
        return sol;
    };
};
vector<int> solution(vector<int> fees, vector<string> records) {
    test3 t3(fees);
    return t3.find_sol(records);
}
int main(){
    solution({180, 5000, 10, 600},{"05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"});
    return 0;
}