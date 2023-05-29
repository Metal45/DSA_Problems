#include <iostream>
#include <unordered_map>
using namespace std;


int main(){
    // declaration
    unordered_map<string, int> map;

    // insertion
    pair<string, int> p1 = make_pair("scorpio", 9);
    pair<string, int> p2("alto", 7);
    map.insert(p1);
    map.insert(p2);
    map["fortuner"] = 10;

    // access
    cout << map.at("scorpio") << endl;
    cout << map.at("alto") << endl;

    // when you access using this syntax it creates and entry if the key is already not present with a value 0
    cout << map["fortuner"]  << endl;

    // isPresent
    cout << map.count("innova") << endl;
    cout << map.count("scorpio") << endl;

    // find
    if(map.find("fortuner") != map.end()){
        cout << "Found" << endl;
    }else{
        cout << "Not Present" << endl;
    }


    // iteration on map

    for(auto i : map){
        cout << i.first << " " << i.second << endl;
    }

    // how to iterate on map in different ways? 
    // last to up up to down form a specific pos using iterators

    
}