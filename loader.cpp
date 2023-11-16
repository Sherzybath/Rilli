#include <iostream>
#include <set>  
#include <fstream>



using namespace std;


// class Class{
//     public :
//     int slot_Num;
//     string room_No;
//     string course_Code;
//     string professor;
//     string batch;
//     string year;
//     string group;
//     string time_Slot;
//     string day;
//
//     Class (int s,string r, string cc,string p,string b,string y,string g,string t,string d) : slot_Num(s),room_No(r),course_Code(cc),professor(p),batch(b),year(y),group(g),time_Slot(t),day(d){}
//
//     bool operator<(const Class &other) const {
//     return this->slot_Num < other.slot_Num;
//   }
// };
//
// class time_Table{
//     public:
//     multiset<Class> ms;
//
// };



void deserialize(multiset<Class> &m, ifstream &in,string batch) {
  while (true) {

    //reading slot_Num
    int slot_Num;
    in.read((char *)(&slot_Num), sizeof(int));

    //reading room_no  1
    int nameLength1;
    if (!in.read((char *)(&nameLength1), sizeof(int))) {
      break;
    }
    char *room_No = new char[nameLength1 + 1];
    in.read(room_No, nameLength1);
    room_No[nameLength1] = '\0';

    

    //reading course code  2
    int nameLength2;
    if (!in.read((char *)(&nameLength2), sizeof(int))) {
      break;
    }
    char *course_Code = new char[nameLength2 + 1];
    in.read(course_Code, nameLength2);
    course_Code[nameLength2] = '\0';



    //reading professor  3
    int nameLength3;
    if (!in.read((char *)(&nameLength3), sizeof(int))) {
      break;
    }
    char *professor = new char[nameLength3 + 1];
    in.read(professor, nameLength3);
    professor[nameLength3] = '\0';







    //reading year  5
    int nameLength5;
    if (!in.read((char *)(&nameLength5), sizeof(int))) {
      break;
    }
    char *year = new char[nameLength5 + 1];
    in.read(year, nameLength5);
    year[nameLength5] = '\0';


    //reading group  6
    int nameLength6;
    if (!in.read((char *)(&nameLength6), sizeof(int))) {
      break;
    }
    char *group = new char[nameLength6 + 1];
    in.read(group, nameLength6);
    group[nameLength6] = '\0';



    //reading time slot  7
    int nameLength7;
    if (!in.read((char *)(&nameLength7), sizeof(int))) {
      break;
    }
    char *time_Slot = new char[nameLength7 + 1];
    in.read(time_Slot, nameLength7);
    time_Slot[nameLength7] = '\0';


    //reading day  8
    int nameLength8;
    if (!in.read((char *)(&nameLength8), sizeof(int))) {
      break;
    }
    char *day = new char[nameLength8 + 1];
    in.read(day, nameLength8);
    day[nameLength8] = '\0';

      //reading type 9
      int nameLength9;
      if (!in.read((char *)(&nameLength9), sizeof(int))) {
          break;
      }
      char *type = new char[nameLength9 + 1];
      in.read(type, nameLength9);
      type[nameLength9] = '\0';



    //inserting object (slot) into multi
    m.insert(Class(slot_Num, string(room_No), string(course_Code),string(professor),string(batch),string(year),string(group),string(time_Slot),string(day),string(type)));

    delete[] room_No;
    delete[] professor;
    delete[] course_Code;
    delete[] year;
    delete[] group;
    delete[] time_Slot;
    delete[] day;
    delete[] type;
  }
}

int loader(string batch) {
  cout<<"here lol";
  multiset<Class> loadedData;
  string filename;
  filename = batch+".bin";

  ifstream in(filename, ios::binary);
  if (!in) {
    cerr << "Error opening file." << endl;
    return 1;
  }

  deserialize(loadedData, in,batch);
  in.close();

  // Print the loaded data
  for (const auto &slot : loadedData) {
    cout << "Room no : " << slot.room_No << endl;
    cout << "Course Code : " << slot.course_Code << endl;
    cout << "Professor : " << slot.professor << endl;
    cout << "Group: " << slot.group << endl;
    cout << "Year: " << slot.year << endl;
    cout << "Time Slot: " << slot.time_Slot << endl;
    cout << "Day : " << slot.day << endl;
    cout << "Type of class : " << slot.type<<endl;

      cout << "Type : " << slot.type << endl;
    cout<<"\n\n\n\n\n";
  }

  return 0;
}