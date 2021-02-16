#include <stdio.h> 
#include <iostream> 
#include <vector>
using namespace std;


class Date{

//Methods
public:
  Date(const int day,const int month,const int year){
    this-> day = day;
    this-> month = month;
    this-> year = year;
  }

  int Get_Day(){
    return this -> day; 
  }
  
  int Get_Month(){
    return this -> month;
  }

  int Get_Year(){
    return this -> year;
  }

  void Print_Date(){
    cout << day << "/" << month << "/" << year;
  }

//Attributes
protected:
  int day;
  int month;
  int year;

};


class Blood{

public:
  Blood(const int systolic, const int diastolic, const Date date):date(date){
    this-> systolic = systolic;
    this-> diastolic = diastolic;
  }
  
  int Get_Syst(){
    return this -> systolic; 
  }
  int Get_Dias(){
    return this -> diastolic; 
  }
  Date Get_Date(){
    return this -> date; 
  }
  void Print_Blood(){
    cout << "systolic: " << systolic << " diastolic: " << diastolic << " " << date.Get_Day()<<"/"<< date.Get_Month()<<"/"<<date.Get_Year()<<endl;
  }

protected:
  int systolic;
  int diastolic;
  Date date;
};


class Patient{

public:
  Patient(string name){
  this -> name = name;
  this -> table= vector<Blood>();
  }

  void addRecord(Blood record){
    this->table.push_back(record);
  }

  void printPatient(){
    cout<<"−−−−− Patient: "<< this->name<<" −−−−−−"<<endl;
    for (int j=0; j<this->table.size();j++){
      this -> table[j].Print_Blood();
    }
  }

  void printReport(){
    vector<Blood> highestAbnormal =vector<Blood>();
    int max = 140;
    double avgDiastolic = 0.0;

    for(int i=0;i< this-> table.size();i++){
      avgDiastolic+=table[i].Get_Dias();
      if ( table[i].Get_Syst()>max){
      highestAbnormal.clear(); 
      highestAbnormal.push_back(table[i]); 
      max=table[i].Get_Syst(); 
      }
      else if ( table [ i ]. Get_Syst()== max){ highestAbnormal.push_back(table[i]);
      } 
    }
    
    cout<<"−−−−− Patient: "<< this->name<<" report  −−−−−−"<<endl;
    if (highestAbnormal.size()==0)
      cout << "All measurements are normal " << endl; 
    else {
      cout << "Abnormal systolic blood pressures measured: " << endl; 
      for(int i=0;i<highestAbnormal.size();i++){
        cout << "\t";
        highestAbnormal[i].Print_Blood (); 
      }
    }
    cout << "Average diastolic pressure: " <<avgDiastolic/table.size() << endl;
    cout << " " << endl;

  }

protected:
  string name;
  vector <Blood> table;
};



int main() {
Patient mary("Mary"); 
Patient john = Patient("John");

mary.addRecord(Blood(94,61, Date(2,5,2013))); 
mary.addRecord(Blood(97,65, Date(3,5,2013))); 
mary.addRecord(Blood(144,99, Date(4,5,2013))); 
mary.addRecord(Blood(123,88, Date(5,5,2013)));
mary.addRecord(Blood(177,110, Date(6,5,2013))); mary.addRecord(Blood(145,89, Date(7,5,2013)));

john.addRecord(Blood(88,57, Date(15,5,2013)));
john.addRecord(Blood(95,61, Date(16,5,2013)));
john.addRecord(Blood(114,80, Date(17,5,2013)));
john.addRecord(Blood(151,96, Date(18,5,2013)));
john.addRecord(Blood(176,104, Date(19,5,2013)));
john.addRecord(Blood(176,110, Date(20,5,2013)));

mary.printReport();
john.printReport();

return 0;
}