#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>
using namespace std;
struct node{
    int x,y,z;  
};
struct compare{
    bool operator()(node& a,node& b){
        return a.x>b.x;
    
    };
};
bool compare2(node& a,node& b){
    return a.x<b.x;
};
int gcd(int a,int b){
    return b==0 ? a :gcd(b,a%b);
};
int main(){
    priority_queue<node,vector<node>,compare> pq;
    pq.push({1,2,3});
    pq.push({5,4,2});
    pq.push({2,4,2});
    pq.push({4,4,2});
    pq.push({3,4,2});
    while(!pq.empty()){
        std::cout << pq.top().x <<','<<pq.top().y<<','<<pq.top().z << '\n';
        pq.pop();
    }
    std::cout << '\n';
    vector<node> v;
    v.push_back({1,2,3});
    v.push_back({5,4,2});
    v.push_back({2,4,2});
    v.push_back({4,4,2});
    v.push_back({3,4,2});
    sort(v.begin(),v.end(),compare2);
    for(node t : v){
        std::cout << t.x << ',' <<t.y<<','<<t.z<<'\n';
    }
    std::cout << '\n';
    set<pair<int,int>> s;
    s.insert({5,1});
    s.insert({1,2});
    s.insert({4,2});
    s.insert({6,2});
    s.insert({5,1});
    for(auto i : s)
        std::cout << i.first <<',' << i.second << ' ';
    std::cout << '\n';

    unordered_set<int> us;
    // unordered_set<pair<int,int>> us;
    us.insert(5);
    us.insert(1);
    us.insert(4);
    us.insert(6);
    us.insert(5);
    for(auto t : us)
        std::cout << t << ' ';
    std::cout << '\n';
    
    map<char,node> m;
    m['a']={1,2,3};
    m['c']={3,4,3};
    m['b']={1,2,3};
    m['d']={5,2,3};
    for(auto t : m )
        std::cout << t.first << ' ';
    std::cout << '\n';

    unordered_map<char,node> um;
    um['a']={1,2,3};
    um['c']={3,4,3};
    um['b']={1,2,3};
    um['d']={5,2,3};
    um.insert({'b',{4,2,3}});
    for(auto t : um )
        std::cout << t.first << ' ';
    std::cout << '\n';
    std::cout << '\n';
    std::cout << gcd(12,1)<<'\n';
    return 0;
}