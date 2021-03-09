#include <iostream>
#include <fstream>
#include <set>
//Iulia Moroti 1231A
using namespace std;

int main(){
    ifstream earthin("earth.in");
    if (!earthin){
        cerr<<"No such file found.";
        return -1;
    }
    ofstream earthout("earth.out");
    int dest, spaceships, dist, cost, range;
    set<pair<long long, int> > costs;

    earthin >> range >> dest >> spaceships;
    costs.insert({0, range});
    for (int i = 0; i < spaceships; i++){
        earthin >> dist >> cost >> range;

        while (costs.size() && (costs.begin()->second < dist) ){
            costs.erase(costs.begin());
        }
        if (costs.size()){
            costs.insert({cost + costs.begin()->first, dist + range});
        } else {
            earthout << "-1";
            return -1;
        }
    }
    while (costs.size() && (costs.begin()->second < dest) ){
        costs.erase(costs.begin() );
    }
    if (costs.size()){
        earthout << costs.begin()->first;
    } else {
        earthout << "-1";
        return -1;
    }
    return 0;
}
