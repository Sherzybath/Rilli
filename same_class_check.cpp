//#include <iostream>
#include "input.cpp"
#include "loader.cpp"
using namespace std;

bool same_class_check(string room_no){

    multiset<Class> loadedData;

    ifstream in("Log testing 8.bin", ios::binary );
    if (!in) {
        cerr << "Error opening file." << endl;
        return 0;
    }

    deserialize(loadedData, in);
    in.close();

    for(const Class attempt: loadedData){
        if(attempt.room_No==room_no){
            return 1;
        }
    }

    return 0;    
    
}