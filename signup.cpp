#include <iostream>
#include <set>
#include <fstream>

using namespace std;

// class person {
// public:
//     int id;
//     string role;
//     string password;
//
//     person(int id, string r, string pswrd) : id(id), role(r), password(pswrd) {}
//
//     bool operator<(const person &other) const {
//         return this->id < other.id;
//     }
// };

person take_Input() {
    int i;
    string r;
    string p;
    cout << "Enter id : ";
    cin >> i;
    cout << "Enter role : ";
    cin >> r;
    cout << "Enter password : ";
    cin >> p;

    hash<string> hasher;
    auto hashCode = hasher(p);

    string hashedPass = to_string(hashCode);

    person slot1(i, r, hashedPass);
    return slot1;
}

class signUp {
public:
    multiset<person> ms;

    void insert_Slot(person slot1) {
        ms.insert(slot1);
    }
};

//void deserialize(multiset<person> &m, ifstream &in) {
//    while (true) {
//
//        //reading id
//        int id;
//        in.read((char *)(&id), sizeof(int));
//
//        //reading role  1
//        int nameLength1;
//        if (!in.read((char *)(&nameLength1), sizeof(int))) {
//            break;
//        }
//        char *role = new char[nameLength1 + 1];
//        in.read(role, nameLength1);
//        role[nameLength1] = '\0';
//
//        //reading password  2
//        int nameLength2;
//        if (!in.read((char *)(&nameLength2), sizeof(int))) {
//            break;
//        }
//        char *password = new char[nameLength2 + 1];
//        in.read(password, nameLength2);
//        password[nameLength2] = '\0';
//
//
//        //inserting object (slot) into multi
//        m.insert(person(id, string(role), string(password)));
//
//        delete[] role;
//        delete[] password;
//    }
//}


bool pre_exist_check(int id) {
  multiset<person> loadedData;

  ifstream in("Log testing 8.bin", ios::binary );
  if (!in) {
    cerr << "Error opening file." << endl;
    return 0;
  }

  deserialize(loadedData, in);
  in.close();

  for(const person attempt: loadedData){
    if(attempt.id==id){
        return 1;
    }
  }

  return 0;
}

void serialize(signUp &m, ofstream &out) {
    for (const auto &clas : m.ms) {
        // writing slot_no in bin file
        out.write((char *)(&clas.id), sizeof(int));

        // writing role   1
        int nameLength1 = clas.role.length();
        out.write((char *)(&nameLength1), sizeof(int));
        out.write(clas.role.c_str(), nameLength1);

        // writing Course code   2
        int nameLength2 = clas.password.length();
        out.write((char *)(&nameLength2), sizeof(int));
        out.write(clas.password.c_str(), nameLength2);
    }
}

int sign_up() {
    signUp user1;

    // Open the file in append mode to avoid overwriting
    ofstream out("Log testing 8.bin", ios::binary | ios::app);
    if (!out) {
        cerr << "Error opening file." << endl;
        return 0;
    }

    auto slot = take_Input();
    if(pre_exist_check(slot.id)){
        cout<<"This ID already exsists.";
    }else{
        cout<<"saving";
        user1.insert_Slot(slot);
        serialize(user1, out);
    }


    out.close();

    return 0;
}


//admin not permitted wala code