#include "all_headers.h"

class Course;
class Lab;

bool oddeve;//true for odd sem false for even sem



class Batch;
class Course;

class Section;
//Each section will have its own course copy
class Course{
    string course_name;
    string course_code;
    string prof_name;
    char sec;
    int sem;
    int numperweek;
    int allocated;
public:
    Course(){}
    Course(string cname,string pname,int sems,int num,char secs):course_name(cname),prof_name(pname),sem(sems),numperweek(num),sec(secs),allocated(0){
        course_code="";course_code.insert(0,course_name.substr(0,4));
    }
    Course(string cname,string pname,int sems,int num,char secs,int alloc):course_name(cname),prof_name(pname),sem(sems),numperweek(num),sec(secs),allocated(alloc){
        course_code="";course_code.insert(0,course_name.substr(0,4));
    }
    string get_course_name(){return course_name;}
    string get_course_code(){return course_code;}
    string get_prof_name(){return prof_name;}
    int get_sem(){return sem;}
    int get_numperweek(){return numperweek;}
    char get_char_section(){return sec;}
    int get_allocated(){return allocated;}
    int set_allocated(int val){allocated=val;}
};

class Section{
    vector <Batch> batch_list;
    string section_code;
    vector <Course*> course_list;
    int semester;
public:
    Section(){}
    Section(vector <Course*>* listofcourses,char secs,int num):semester(num){
        char temp[3];temp[0]=char((int)'0'+num);temp[1]=secs;temp[2]='\0';section_code=temp;
        vector <Course *> tempvect=listofcourses[0];
        int tempnum;char tempsecs;
        tr(tempvect,it){
                tempnum=(*it)->get_sem();
                tempsecs=(*it)->get_char_section();
                if(tempnum==num&&tempsecs==secs){
                    course_list.pb((*it));
                    //cout<<(*it)->get_course_name();
                }
        }
    }
};

class Batch;
class Lab{
    string lab_name;
    string prof_name1;
    string prof_name2;
    string lab_code;
    string batch1;
    string batch2;
    int numperweek;
    int sem;
    int allocated;
public:
    Lab(){}
    Lab(string labname,string prof1,string prof2,int num,int sems,string bat1,string bat2):lab_name(labname),\
    prof_name1(prof1),prof_name2(prof2),numperweek(num),sem(sems),batch1(bat1),batch2(bat2),allocated(0){
        lab_code="";lab_code.insert(0,lab_name.substr(0,4));
    }
    string get_lab_name(){return lab_name;}
    string get_prof_name1(){return prof_name1;}
    string get_prof_name2(){return prof_name2;}
    string get_lab_code(){return lab_code;}
    string get_batch1(){return batch1;}
    string get_batch2(){return batch2;}
    int get_numperweek(){return numperweek;}
    int get_sem(){return sem;}
    int get_allocated(){return allocated;}
    int set_allocated(int val){allocated=val;}
};


class Professor{
    string prof_name;
    string prof_code;
    vector <Course*> course_list;
    vector <Lab*> lab_list;
public:
    Professor(){}
    Professor(string nam,vector <Course*> *listofcourses):prof_name(nam){
        prof_code="";prof_code.insert(0,prof_name.substr(0,4));
        vector <Course *> tempvect=listofcourses[0];
        tr(tempvect,it){
            string temp=(*it)->get_prof_name();
            if(temp==prof_name){
                course_list.pb(*it);
            }
        }
    }
    Professor(string nam,vector<Lab*>::iterator it):prof_name(nam){
        prof_code="";prof_code.insert(0,prof_name.substr(0,4));
        lab_list.pb(*it);

    }
    void addtolab(vector<Lab*>::iterator it){
        lab_list.pb(*it);
    }
    string get_prof_name(){return prof_name;}
    string get_prof_code(){return prof_code;}
    void printdetails(){
        cout<<prof_name<<" "<<prof_code<<endl;
        cout<<"list of courses ";
        tr(course_list,it){
            cout<<(*it)->get_course_name()<<" ";
        }
        cout<<endl<<"list of labs ";
        tr(lab_list,it){
            cout<<(*it)->get_lab_name()<<" ";
        }
        cout<<endl;
    }
};

class Batch{
    int sem;
    string batch_code;
    vector <Lab*> lab_list;
    int batch_strength;
public:
    Batch(){}
    Batch(vector <Lab*>* listoflabs,string batchs,int sems,int strength):sem(sems),batch_code(batchs),batch_strength(strength){
        vector <Lab *> tempvect=listoflabs[0];
        int tempsem;string tempbatch1,tempbatch2;
        tr(tempvect,it){
                tempsem=(*it)->get_sem();
                tempbatch1=(*it)->get_batch1();tempbatch2=(*it)->get_batch2();

                if((tempsem==sem)&&(batch_code==tempbatch1)){
                    lab_list.pb((*it));
                    //cout<<(*it)->get_lab_name();
                    continue;
                }
                if((tempsem==sem)&&(batch_code==tempbatch2)){
                    lab_list.pb((*it));
                    //cout<<(*it)->get_lab_name();
                    continue;
                }

        }
        //cout<<endl;
    }
};


class Semester{
    vector <Section*> section_list;
    vector <Course*> course_list;
    vector <Lab*> lab_list;
    vector <Batch*> batch_list;
    int semester_code;
public:
    Semester(){}
    Semester(vector <Course*> * listofcourses,vector <Section*>* listofsections,vector <Lab*> * listoflabs,vector <Batch*>* listofbatches,int sems):\
    semester_code(sems){
        vector <Course *> tempvect1=listofcourses[0];
        tr(tempvect1,it){
            int tempsem=(*it)->get_sem();
            if(tempsem==semester_code){
                course_list.pb((*it));
                //cout<<(*it)->get_course_name()<<" ";
            }
        }
        //cout<<endl<<"courses done"<<endl;
        vector <Lab*> tempvect2=listoflabs[0];
        tr(tempvect2,it){

            int tempsem=(*it)->get_sem();
            if(tempsem==semester_code){
                lab_list.pb(*it);
                //cout<<(*it)->get_lab_code()<<" ";
            }
        }
        //cout<<endl<<"labs done"<<endl;
    }
};


