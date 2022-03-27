
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> &phone_numbers, vector<string> &phone_owners, string &number) {
    // write your code in C++14 (g++ 6.2.0)
    string answer = number;
    for(int i=0;i<phone_numbers.size();i++){
        if(phone_numbers[i] == number)
            answer = phone_owners[i];
    }
    return answer;

}
