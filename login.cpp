#include <iostream>
#include <set>  
#include <fstream>



using namespace std;


class person{
    public : 
    int id;
    string role;
    string password;

    person (int id,string r, string pswrd) : id(id),role(r),password(pswrd){}

    bool operator<(const person &other) const {
    return this->id < other.id;
  }
};


void deserialize(multiset<person> &m, ifstream &in) {
  while (true) {

    //reading id
    int id;
    in.read((char *)(&id), sizeof(int));

    //reading role  1
    int nameLength1;
    if (!in.read((char *)(&nameLength1), sizeof(int))) {
      break;
    }
    char *role = new char[nameLength1 + 1];
    in.read(role, nameLength1);
    role[nameLength1] = '\0';

    //reading password  2
    int nameLength2;
    if (!in.read((char *)(&nameLength2), sizeof(int))) {
      break;
    }
    char *password = new char[nameLength2 + 1];
    in.read(password, nameLength2);
    password[nameLength2] = '\0';


    //inserting object (slot) into multi
    m.insert(person(id, string(role), string(password)));

    delete[] role;
    delete[] password;
  }
}



person takeInput(){
    int i; string r;string p;
    cout<<"Enter id : ";
    cin>>i;
    cout<<"Enter password : ";
    cin>>p;
    hash<string> hasher;
    auto hashCode = hasher(p);

    string hashedPass = to_string(hashCode);

    person slot1(i,r,hashedPass);
    return slot1;


}


int log_in() {
  multiset<person> loadedData;

  ifstream in("Log testing 8.bin", ios::binary);
  if (!in) {
    cerr << "Error opening file." << endl;
    return 9;
  }

  deserialize(loadedData, in);
  in.close();

  person attemp1 = takeInput();
  bool success_huh = false;
  // Print the loaded data
  for (const auto &slot : loadedData) {
    if (attemp1.id==slot.id){
      if (attemp1.password==slot.password){
        cout<<"Login Successful";
        success_huh = true;
        if(slot.role=="student"){
          return 3;
        } else if(slot.role=="teacher"){
          return 2;
        } else if(slot.role=="admin"){
          return 1;
        }
      }
      
    }
    if (success_huh){
      break;
    }
  }
  if (!success_huh){
    cout<<"Wrong ID and Password";
  }

  return 0;
}