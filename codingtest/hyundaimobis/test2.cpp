#include <iostream>
#include <vector>
using namespace std;
class test2{
private:
    string RID;
public:
    test2(string str):RID(str){


    }
    string find_sol(){
        string year;
        string sex;
        if(RID[7]=='1'){
            year="19";
            sex="M";
        }
        else if(RID[7]=='2'){
            year="19";
            sex="F";
        }
        else if(RID[7]=='3'){
            year="20";
            sex="M";
        }
        else if(RID[7]=='4'){
            year="20";
            sex="F";
        }
        return year+RID.substr(0,2)+"/"+sex;
    }


};