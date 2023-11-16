#include <iostream>
#include <set>  
#include <fstream>

using namespace std;


class Class{
    public : 
    int slot_Num;
    string room_No;
    string course_Code;
    string professor;
    string batch;
    string year;
    string group;
    string time_Slot;
    string day;
    string type;

    Class (int s,string r, string cc,string p,string b,string y,string g,string t,string d,string typ) : slot_Num(s),room_No(r),course_Code(cc),professor(p),batch(b),year(y),group(g),time_Slot(t),day(d),type(typ){}

    bool operator<(const Class &other) const {
    return this->slot_Num < other.slot_Num;
  }
};


Class take_Input(int s,string batch){
    string r; string cc;string p;string b;string y;string g;string t;string d;int slot;string type;
    slot = s;
    cout<<"Enter room_no : ";
    cin>>r;
    cout<<"Enter course_code : ";
    cin>>cc;
    cout<<"Enter professor : ";
    cin>>p;
    cout<<"Enter type of class : ";
    cin>>type;
    cout<<"Enter year : "; // remeber to write only number in accordance to which year this tt belongs to (eg - 1,2,3,4 or 1st,2nd,etc.)
    cin>>y;
    cout<<"Enter group : ";
    cin>>g;
    cout<<"Enter time_slot : ";
    cin>>t;
    cout<<"Enter day : ";
    cin>>d;

    Class slot1(s,r,cc,p,batch,y,g,t,d,type);
    return slot1;


}


class time_Table{
    public:
    multiset<Class> ms;

    void insert_Slot(Class slot1){
        ms.insert(slot1);
    }

};

void serialize(time_Table &m, ofstream &out) {
  for (const auto &clas : m.ms) {


    //writing slot_no in bin file
    out.write((char *)(&clas.slot_Num), sizeof(int));

    //writing room_No   1
    int nameLength1 = clas.room_No.length();
    out.write((char *)(&nameLength1), sizeof(int));
    out.write(clas.room_No.c_str(), nameLength1);

    //writing Course code   2
    int nameLength2 = clas.course_Code.length();
    out.write((char *)(&nameLength2), sizeof(int));
    out.write(clas.course_Code.c_str(), nameLength2);

    //writing professor   3
    int nameLength3 = clas.professor.length();
    out.write((char *)(&nameLength3), sizeof(int));
    out.write(clas.professor.c_str(), nameLength3);



    //writing year   5
    int nameLength5 = clas.year.length();
    out.write((char *)(&nameLength5), sizeof(int));
    out.write(clas.year.c_str(), nameLength5);


    //writing group   6
    int nameLength6 = clas.group.length();
    out.write((char *)(&nameLength6), sizeof(int));
    out.write(clas.group.c_str(), nameLength6);

    //writing time slot   7
    int nameLength7 = clas.time_Slot.length();
    out.write((char *)(&nameLength7), sizeof(int));
    out.write(clas.time_Slot.c_str(), nameLength7);

    //writing day   8
    int nameLength8 = clas.day.length();
    out.write((char *)(&nameLength8), sizeof(int));
    out.write(clas.day.c_str(), nameLength8);

    //writing Batch  9
    int nameLength9 = clas.type.length();
    out.write((char *)(&nameLength9), sizeof(int));
    out.write(clas.type.c_str(), nameLength9);
  }
}

int input(string batch){
    cout<<"No of class you wanna add in time table of"<<batch;
    int a;
    cin>>a;

    time_Table Batch40;
    int i=0;
    while (i<a){
        auto slot = take_Input(i+1,batch);
        Batch40.insert_Slot(slot);
        i++;
    }

    string TimeTableName = batch+".bin";
    //making a bin file and writing in it
    ofstream out(TimeTableName, ios::binary);
    if (!out) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    serialize(Batch40, out);
    out.close();




    return 0;

}


int input_update(string batch){
  cout<<"Add new class to this batch";
    int a;
    cin>>a;

    time_Table Batch40;
    int i=0;
    while (i<a){
        auto slot = take_Input(i+1,batch);
        Batch40.insert_Slot(slot);
        i++;
    }

  //making a bin file and writing in it
  ofstream out("testing 1.bin", ios::binary | ios::app);
  if (!out) {
    cerr << "Error opening file." << endl;
    return 1;
  }

  serialize(Batch40, out);
  out.close();




    return 0;

}