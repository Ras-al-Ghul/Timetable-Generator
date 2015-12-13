
#include "define_classes.h"
//Everything on heap

void entercourselist(vector <Course*>* listofcourses){
    listofcourses->pb(new Course("Maths","Rangaswamy",4,4,'A'));//sem and numperweek
    /*
    vector <Course *> tempvect;
    tempvect=listofcourses[0];
    cout<<tempvect[0]->get_course_name()<<endl;
    */
    listofcourses->pb(new Course("Algorithms","Gururaja",4,4,'A'));
    /*
    vector <Course *> tempvect;
    tempvect=listofcourses[0];
    cout<<tempvect[1]->get_course_name()<<endl;
    */
    listofcourses->pb(new Course("Object Oriented Programming","Shubha",4,4,'A'));
    listofcourses->pb(new Course("Unix Programming","Mamatha",4,4,'A'));
    listofcourses->pb(new Course("Theoretical Foundations of Computing","Nalini",4,4,'A'));

    listofcourses->pb(new Course("Maths","Geetha",4,4,'B'));
    listofcourses->pb(new Course("Algorithms","Roopa",4,4,'B'));
    listofcourses->pb(new Course("Object Oriented Programming","Sindhu",4,4,'B'));
    listofcourses->pb(new Course("Unix Programming","Sreelatha",4,4,'B'));
    listofcourses->pb(new Course("Theoretical Foundations of Computing","Anitha",4,4,'B'));


    listofcourses->pb(new Course("OO Modelling","Mahalakshmi",6,4,'A'));
    listofcourses->pb(new Course("Networks","Preetha",6,4,'A'));
    listofcourses->pb(new Course("Web Programming","Sreelatha",6,4,'A'));
    listofcourses->pb(new Course("Probability","Soumya",6,3,'A'));
    listofcourses->pb(new Course("Software Engineering","Rajeshwari",6,3,'A'));
    listofcourses->pb(new Course("Cloud Computing","Indra",6,4,'A'));
    listofcourses->pb(new Course("Advanced Data Structures","Shambhavi",6,4,'A'));

    listofcourses->pb(new Course("OO Modelling","Rajeshwari",6,4,'B'));
    listofcourses->pb(new Course("Networks","Chandrakala",6,4,'B'));
    listofcourses->pb(new Course("Web Programming","Shubha",6,4,'B'));
    listofcourses->pb(new Course("Probability","Nalini",6,3,'B'));
    listofcourses->pb(new Course("Software Engineering","Preetha",6,3,'B'));
    listofcourses->pb(new Course("Cloud Computing","Sindhu",6,4,'B'));
    listofcourses->pb(new Course("Advanced Data Structures","Shambhavi",6,4,'B'));

    listofcourses->pb(new Course("Cyber Law","Nalina",8,3,'A'));
    listofcourses->pb(new Course("Storage Area Networks","Jayarekha",8,4,'A'));
    listofcourses->pb(new Course("Institutional Elective","Blank",8,4,'A'));
    listofcourses->pb(new Course("Project","Big blank",8,24,'A'));

    listofcourses->pb(new Course("Cyber Law","Mahalakshmi",8,3,'B'));
    listofcourses->pb(new Course("Storage Area Networks","Sheela",8,4,'B'));
    listofcourses->pb(new Course("Institutional Elective","Blank",8,4,'B'));
    listofcourses->pb(new Course("Project","Big blank",8,24,'A'));

    /*
    vector <Course *> tempvect;
    tempvect=listofcourses[0];
    cout<<tempvect[20]->get_course_code()<<endl;
    */
    return;
}

void entersectionlist(vector <Section*> * listofsections,vector <Course*>* listofcourses){
    listofsections->pb(new Section(listofcourses,'A',4));
    listofsections->pb(new Section(listofcourses,'B',4));
    listofsections->pb(new Section(listofcourses,'A',6));
    listofsections->pb(new Section(listofcourses,'B',6));
    listofsections->pb(new Section(listofcourses,'A',8));
    listofsections->pb(new Section(listofcourses,'B',8));
    return;
}

void enterlablist(vector <Lab*>* listoflabs){
    //Always 2 lab per week to come first and be clustered together..And always in inverted order see below..
    listoflabs->pb(new Lab("Algorithms","Gururaja","Roopa",2,4,"A1","A2"));//numperweek,semester,batch1,batch2
    listoflabs->pb(new Lab("Algorithms","Gururaja","Shweta",2,4,"A3","A4"));

    listoflabs->pb(new Lab("OO Programming","Shubha","Mahalakshmi",2,4,"A3","A4"));
    listoflabs->pb(new Lab("OO Programming","Shubha","Sindhu",2,4,"A1","A2"));

    listoflabs->pb(new Lab("Unix","Mamatha","Roopa",1,4,"A1","A2"));
    listoflabs->pb(new Lab("Unix","Mamatha","Sreelatha",1,4,"A3","A4"));
    //Bsection

    listoflabs->pb(new Lab("Algorithms","Roopa","Gururaja",2,4,"B1","B2"));
    listoflabs->pb(new Lab("Algorithms","Roopa","Rajeshwari",2,4,"B3","B4"));

    listoflabs->pb(new Lab("OO Programming","Sindhu","Indra",2,4,"B3","B4"));
    listoflabs->pb(new Lab("OO Programming","Sindhu","Nalini",2,4,"B1","B2"));

    listoflabs->pb(new Lab("Unix","Sreelatha","Mamatha",1,4,"B1","B2"));
    listoflabs->pb(new Lab("Unix","Nalini","Mamatha",1,4,"B3","B4"));
    //Asection
    listoflabs->pb(new Lab("Networks","Anitha","Chandrakala",2,6,"A1","A2"));
    listoflabs->pb(new Lab("Networks","Sindhu","Soumya",2,6,"A3","A4"));

    listoflabs->pb(new Lab("Web Programming","Sreelatha","Nalina",2,6,"A3","A4"));
    listoflabs->pb(new Lab("Web Programming","Sreelatha","AshokN",2,6,"A1","A2"));


    //Bsection
    listoflabs->pb(new Lab("Networks","Chandrakala","Sindhu",2,6,"B1","B2"));
    listoflabs->pb(new Lab("Networks","Chandrakala","Sindhu",2,6,"B3","B4"));

    listoflabs->pb(new Lab("Web Programming","Shubha","Nalina",2,6,"B3","B4"));
    listoflabs->pb(new Lab("Web Programming","Nalina","AshokN",2,6,"B1","B2"));

    /*
    vector <Lab *> tempvect=listoflabs[0];
    tr(tempvect,it){
        cout<<(*it)->get_lab_name()<<" "<<(*it)->get_batch1()<<" "<<(*it)->get_batch2()<<endl;
    }
    */
    return;
}

void enterbatchlist(vector <Batch*> * listofbatches,vector <Lab*>* listoflabs){
    listofbatches->pb(new Batch(listoflabs,"A1",4,15));//sem batchstrength
    listofbatches->pb(new Batch(listoflabs,"A2",4,15));
    listofbatches->pb(new Batch(listoflabs,"A3",4,15));
    listofbatches->pb(new Batch(listoflabs,"A4",4,15));
    listofbatches->pb(new Batch(listoflabs,"B1",4,15));
    listofbatches->pb(new Batch(listoflabs,"B2",4,15));
    listofbatches->pb(new Batch(listoflabs,"B3",4,15));
    listofbatches->pb(new Batch(listoflabs,"B4",4,15));

    listofbatches->pb(new Batch(listoflabs,"A1",6,15));
    listofbatches->pb(new Batch(listoflabs,"A2",6,15));
    listofbatches->pb(new Batch(listoflabs,"A3",6,15));
    listofbatches->pb(new Batch(listoflabs,"A4",6,15));
    listofbatches->pb(new Batch(listoflabs,"B1",6,15));
    listofbatches->pb(new Batch(listoflabs,"B2",6,15));
    listofbatches->pb(new Batch(listoflabs,"B3",6,15));
    listofbatches->pb(new Batch(listoflabs,"B4",6,15));

    return;
}

void entersemesterlist(vector <Semester*> * listofsemesters, \
                       vector <Course*> * listofcourses,vector <Section*>* listofsections,vector <Lab*> * listoflabs,vector <Batch*>* listofbatches){

    listofsemesters->pb(new Semester(listofcourses,listofsections,listoflabs,listofbatches,4));
    listofsemesters->pb(new Semester(listofcourses,listofsections,listoflabs,listofbatches,6));
    listofsemesters->pb(new Semester(listofcourses,listofsections,listoflabs,listofbatches,8));
    return;
}

void enterprofessorlist(vector <Professor*> * listofprofessors,vector <Course*> * listofcourses,vector <Lab*> * listoflabs){
    vector <Course *>  tempvect1=listofcourses[0];
    tr(tempvect1,it){
        int flag=0;
        string tempname=(*it)->get_prof_name();
        vector <Professor *> tempprofvect=listofprofessors[0];
        tr(tempprofvect,it1){
            string temps=(*it1)->get_prof_name();
            if(tempname==temps){
                flag=1;
                break;
            }
        }
        if(flag==1){
            continue;
        }
        else{
                listofprofessors->pb(new Professor(tempname,listofcourses));
        }
    }

    vector <Lab *> tempvect2=listoflabs[0];
    tr(tempvect2,it){
        string tempname1=(*it)->get_prof_name1();string tempname2=(*it)->get_prof_name2();
        vector <Professor *> tempprofvect=listofprofessors[0];
        int flag1=0,flag2=0;
        tr(tempprofvect,it1){
            string tempstr=(*it1)->get_prof_name();
            if(tempstr==tempname1){
                flag1=1;
                (*it1)->addtolab(it);
            }
            if(tempstr==tempname2){
                flag2=1;
                (*it1)->addtolab(it);
            }
            if(flag1==1&&flag2==1)
                break;
        }
        if(flag1==0){
            listofprofessors->pb(new Professor(tempname1,it));
        }
        if(flag2==0){
            listofprofessors->pb(new Professor(tempname2,it));
        }

    }
    /*
    vector <Professor *> tempprof=listofprofessors[0];
    tr(tempprof,it){
        (*it)->printdetails();
    }
    */
    return;
}

void Maths_Constraints(vector <pair<string,pair<int,int> > * >* mathscourse){
    pair <string,pair<int,int> > * temppair=new pair<string,pair<int,int> >;
    temppair->first="A";(temppair->second).first=1;(temppair->second).second=3;//first is day of week 1-6 second is hour of day 1-7...
    mathscourse->pb(temppair);

    temppair=new pair<string,pair<int,int> >;
    temppair->first="A";(temppair->second).first=2;(temppair->second).second=6;//first is day of week 1-6 second is hour of day 1-7...
    mathscourse->pb(temppair);

    temppair=new pair<string,pair<int,int> >;
    temppair->first="A";(temppair->second).first=2;(temppair->second).second=7;//first is day of week 1-6 second is hour of day 1-7...
    mathscourse->pb(temppair);

    temppair=new pair<string,pair<int,int> >;
    temppair->first="A";(temppair->second).first=3;(temppair->second).second=5;//first is day of week 1-6 second is hour of day 1-7...
    mathscourse->pb(temppair);

    temppair=new pair<string,pair<int,int> >;
    temppair->first="A";(temppair->second).first=4;(temppair->second).second=4;//first is day of week 1-6 second is hour of day 1-7...
    mathscourse->pb(temppair);
    //section b
    temppair=new pair<string,pair<int,int> >;
    temppair->first="B";(temppair->second).first=1;(temppair->second).second=6;//first is day of week 1-6 second is hour of day 1-7...
    mathscourse->pb(temppair);

    temppair=new pair<string,pair<int,int> >;
    temppair->first="B";(temppair->second).first=1;(temppair->second).second=7;//first is day of week 1-6 second is hour of day 1-7...
    mathscourse->pb(temppair);

    temppair=new pair<string,pair<int,int> >;
    temppair->first="B";(temppair->second).first=2;(temppair->second).second=3;//first is day of week 1-6 second is hour of day 1-7...
    mathscourse->pb(temppair);

    temppair=new pair<string,pair<int,int> >;
    temppair->first="B";(temppair->second).first=3;(temppair->second).second=4;//first is day of week 1-6 second is hour of day 1-7...
    mathscourse->pb(temppair);

    temppair=new pair<string,pair<int,int> >;
    temppair->first="B";(temppair->second).first=5;(temppair->second).second=4;//first is day of week 1-6 second is hour of day 1-7...
    mathscourse->pb(temppair);

    //BASIC MATH
    temppair=new pair<string,pair<int,int> >;
    temppair->first="A";(temppair->second).first=4;(temppair->second).second=1;//first is day of week 1-6 second is hour of day 1-7...
    mathscourse->pb(temppair);

    temppair=new pair<string,pair<int,int> >;
    temppair->first="A";(temppair->second).first=5;(temppair->second).second=1;//first is day of week 1-6 second is hour of day 1-7...
    mathscourse->pb(temppair);

    temppair=new pair<string,pair<int,int> >;
    temppair->first="A";(temppair->second).first=6;(temppair->second).second=1;//first is day of week 1-6 second is hour of day 1-7...
    mathscourse->pb(temppair);

    temppair=new pair<string,pair<int,int> >;
    temppair->first="B";(temppair->second).first=4;(temppair->second).second=1;//first is day of week 1-6 second is hour of day 1-7...
    mathscourse->pb(temppair);

    temppair=new pair<string,pair<int,int> >;
    temppair->first="B";(temppair->second).first=5;(temppair->second).second=1;//first is day of week 1-6 second is hour of day 1-7...
    mathscourse->pb(temppair);

    temppair=new pair<string,pair<int,int> >;
    temppair->first="B";(temppair->second).first=6;(temppair->second).second=1;//first is day of week 1-6 second is hour of day 1-7...
    mathscourse->pb(temppair);

    return;
}

void Teacher_Unavailable(vector <pair<string,pair<int,int> > * >* teacherunav){

    pair <string,pair<int,int> > * temppair=new pair<string,pair<int,int> >;

    temppair->first="Rajeshwari";(temppair->second).first=1;(temppair->second).second=4;//first is day of week 1-6 second is hour of day 1-7...
    teacherunav->pb(temppair);

    temppair=new pair<string,pair<int,int> >;
    temppair->first="Rajeshwari";(temppair->second).first=2;(temppair->second).second=5;//first is day of week 1-6 second is hour of day 1-7...
    teacherunav->pb(temppair);

    return;
}

void Course_Hardcode(vector <pair<pair<string,string>,pair<int,int> > * >* coursehardcode){
    pair <pair<string,string>,pair<int,int> > * temppair=new pair<pair<string,string>,pair<int,int> >;
    (temppair->first).first="Algorithms";(temppair->first).second="4A";(temppair->second).first=2;(temppair->second).second=4;//first is day of week 1-6 second is hour of day 1-7...
    coursehardcode->pb(temppair);

    temppair=new pair<pair<string,string>,pair<int,int> >;
    (temppair->first).first="Algorithms";(temppair->first).second="4A";(temppair->second).first=5;(temppair->second).second=5;//first is day of week 1-6 second is hour of day 1-7...
    coursehardcode->pb(temppair);

    temppair=new pair<pair<string,string>,pair<int,int> >;
    (temppair->first).first="Networks";(temppair->first).second="6A";(temppair->second).first=1;(temppair->second).second=3;//first is day of week 1-6 second is hour of day 1-7...
    coursehardcode->pb(temppair);

    temppair=new pair<pair<string,string>,pair<int,int> >;
    (temppair->first).first="blank";(temppair->first).second="6A";(temppair->second).first=2;(temppair->second).second=1;//first is day of week 1-6 second is hour of day 1-7...
    coursehardcode->pb(temppair);

    temppair=new pair<pair<string,string>,pair<int,int> >;
    (temppair->first).first="blank";(temppair->first).second="6A";(temppair->second).first=4;(temppair->second).second=1;//first is day of week 1-6 second is hour of day 1-7...
    coursehardcode->pb(temppair);

    temppair=new pair<pair<string,string>,pair<int,int> >;
    (temppair->first).first="blank";(temppair->first).second="6A";(temppair->second).first=6;(temppair->second).second=1;//first is day of week 1-6 second is hour of day 1-7...
    coursehardcode->pb(temppair);

    temppair=new pair<pair<string,string>,pair<int,int> >;
    (temppair->first).first="blank";(temppair->first).second="6B";(temppair->second).first=1;(temppair->second).second=1;//first is day of week 1-6 second is hour of day 1-7...
    coursehardcode->pb(temppair);

    temppair=new pair<pair<string,string>,pair<int,int> >;
    (temppair->first).first="blank";(temppair->first).second="6B";(temppair->second).first=3;(temppair->second).second=1;//first is day of week 1-6 second is hour of day 1-7...
    coursehardcode->pb(temppair);

    temppair=new pair<pair<string,string>,pair<int,int> >;
    (temppair->first).first="blank";(temppair->first).second="6B";(temppair->second).first=5;(temppair->second).second=1;//first is day of week 1-6 second is hour of day 1-7...
    coursehardcode->pb(temppair);

    temppair=new pair<pair<string,string>,pair<int,int> >;
    (temppair->first).first="Institutional Elective";(temppair->first).second="8A";(temppair->second).first=5;(temppair->second).second=4;//first is day of week 1-6 second is hour of day 1-7...
    coursehardcode->pb(temppair);

    temppair=new pair<pair<string,string>,pair<int,int> >;
    (temppair->first).first="Institutional Elective";(temppair->first).second="8A";(temppair->second).first=5;(temppair->second).second=5;//first is day of week 1-6 second is hour of day 1-7...
    coursehardcode->pb(temppair);

    temppair=new pair<pair<string,string>,pair<int,int> >;
    (temppair->first).first="Institutional Elective";(temppair->first).second="8A";(temppair->second).first=6;(temppair->second).second=2;//first is day of week 1-6 second is hour of day 1-7...
    coursehardcode->pb(temppair);

    temppair=new pair<pair<string,string>,pair<int,int> >;
    (temppair->first).first="Institutional Elective";(temppair->first).second="8A";(temppair->second).first=6;(temppair->second).second=3;//first is day of week 1-6 second is hour of day 1-7...
    coursehardcode->pb(temppair);

    temppair=new pair<pair<string,string>,pair<int,int> >;
    (temppair->first).first="Institutional Elective";(temppair->first).second="8B";(temppair->second).first=5;(temppair->second).second=4;//first is day of week 1-6 second is hour of day 1-7...
    coursehardcode->pb(temppair);

    temppair=new pair<pair<string,string>,pair<int,int> >;
    (temppair->first).first="Institutional Elective";(temppair->first).second="8B";(temppair->second).first=5;(temppair->second).second=5;//first is day of week 1-6 second is hour of day 1-7...
    coursehardcode->pb(temppair);

    temppair=new pair<pair<string,string>,pair<int,int> >;
    (temppair->first).first="Institutional Elective";(temppair->first).second="8B";(temppair->second).first=6;(temppair->second).second=2;//first is day of week 1-6 second is hour of day 1-7...
    coursehardcode->pb(temppair);

    temppair=new pair<pair<string,string>,pair<int,int> >;
    (temppair->first).first="Institutional Elective";(temppair->first).second="8B";(temppair->second).first=6;(temppair->second).second=3;//first is day of week 1-6 second is hour of day 1-7...
    coursehardcode->pb(temppair);

    temppair=new pair<pair<string,string>,pair<int,int> >;
    (temppair->first).first="Cyber Law";(temppair->first).second="8A";(temppair->second).first=5;(temppair->second).second=2;//first is day of week 1-6 second is hour of day 1-7...
    coursehardcode->pb(temppair);

    temppair=new pair<pair<string,string>,pair<int,int> >;
    (temppair->first).first="Cyber Law";(temppair->first).second="8A";(temppair->second).first=5;(temppair->second).second=3;//first is day of week 1-6 second is hour of day 1-7...
    coursehardcode->pb(temppair);

    temppair=new pair<pair<string,string>,pair<int,int> >;
    (temppair->first).first="Cyber Law";(temppair->first).second="8A";(temppair->second).first=6;(temppair->second).second=1;//first is day of week 1-6 second is hour of day 1-7...
    coursehardcode->pb(temppair);

    temppair=new pair<pair<string,string>,pair<int,int> >;
    (temppair->first).first="Cyber Law";(temppair->first).second="8B";(temppair->second).first=5;(temppair->second).second=2;//first is day of week 1-6 second is hour of day 1-7...
    coursehardcode->pb(temppair);

    temppair=new pair<pair<string,string>,pair<int,int> >;
    (temppair->first).first="Cyber Law";(temppair->first).second="8B";(temppair->second).first=5;(temppair->second).second=3;//first is day of week 1-6 second is hour of day 1-7...
    coursehardcode->pb(temppair);

    temppair=new pair<pair<string,string>,pair<int,int> >;
    (temppair->first).first="Cyber Law";(temppair->first).second="8B";(temppair->second).first=6;(temppair->second).second=1;//first is day of week 1-6 second is hour of day 1-7...
    coursehardcode->pb(temppair);

    temppair=new pair<pair<string,string>,pair<int,int> >;
    (temppair->first).first="Storage Area Networks";(temppair->first).second="8A";(temppair->second).first=5;(temppair->second).second=6;//first is day of week 1-6 second is hour of day 1-7...
    coursehardcode->pb(temppair);

    temppair=new pair<pair<string,string>,pair<int,int> >;
    (temppair->first).first="Storage Area Networks";(temppair->first).second="8A";(temppair->second).first=5;(temppair->second).second=7;//first is day of week 1-6 second is hour of day 1-7...
    coursehardcode->pb(temppair);

    temppair=new pair<pair<string,string>,pair<int,int> >;
    (temppair->first).first="Storage Area Networks";(temppair->first).second="8A";(temppair->second).first=6;(temppair->second).second=4;//first is day of week 1-6 second is hour of day 1-7...
    coursehardcode->pb(temppair);

    temppair=new pair<pair<string,string>,pair<int,int> >;
    (temppair->first).first="Storage Area Networks";(temppair->first).second="8B";(temppair->second).first=6;(temppair->second).second=5;//first is day of week 1-6 second is hour of day 1-7...
    coursehardcode->pb(temppair);

    temppair=new pair<pair<string,string>,pair<int,int> >;
    (temppair->first).first="Storage Area Networks";(temppair->first).second="8B";(temppair->second).first=5;(temppair->second).second=6;//first is day of week 1-6 second is hour of day 1-7...
    coursehardcode->pb(temppair);

    temppair=new pair<pair<string,string>,pair<int,int> >;
    (temppair->first).first="Storage Area Networks";(temppair->first).second="8B";(temppair->second).first=5;(temppair->second).second=7;//first is day of week 1-6 second is hour of day 1-7...
    coursehardcode->pb(temppair);

    temppair=new pair<pair<string,string>,pair<int,int> >;
    (temppair->first).first="Storage Area Networks";(temppair->first).second="8B";(temppair->second).first=6;(temppair->second).second=4;//first is day of week 1-6 second is hour of day 1-7...
    coursehardcode->pb(temppair);

    temppair=new pair<pair<string,string>,pair<int,int> >;
    (temppair->first).first="Storage Area Networks";(temppair->first).second="8B";(temppair->second).first=6;(temppair->second).second=5;//first is day of week 1-6 second is hour of day 1-7...
    coursehardcode->pb(temppair);

    return;
}

void Lab_Hardcode(vector <pair<pair<string,string>,pair<pair<string,string>,pair<int,int> > >* >* labhardcode){
    pair<pair<string,string>,pair<pair<string,string>,pair<int,int> > >* temppair=new pair<pair<string,string>,pair<pair<string,string>,pair<int,int> > >;

    /*
    (temppair->first).first="Logic Design";(temppair->first).second="3A";
    (temppair->second).first.first="A1";(temppair->second).first.second="A2";(temppair->second).second.first=1;(temppair->second).second.second=6;
    labhardcode->pb(temppair);
    */

    return;
}

void getallinputs(vector <Course*>* listofcourses,vector <Section*>* listofsections,vector <Lab*>* listoflabs,vector <Batch*>* listofbatches,\
                  vector <Semester*>* listofsemesters,vector <Professor*>* listofprofessors,vector <pair<string,pair<int,int> > * >* mathscourse,\
                  vector <pair<string,pair<int,int> > * >* teacherunav,vector <pair<pair<string,string>,pair<int,int> > * >* coursehardcode,\
                  vector <pair<pair<string,string>,pair<pair<string,string>,pair<int,int> > >* >* labhardcode){
    oddeve=false;//Doing for odd sem..



    entercourselist(listofcourses);
    //Section field of Course is yet to be defined at this stage..



    entersectionlist(listofsections,listofcourses);



    enterlablist(listoflabs);



    enterbatchlist(listofbatches,listoflabs);



    entersemesterlist(listofsemesters,listofcourses,listofsections,listoflabs,listofbatches);


    enterprofessorlist(listofprofessors,listofcourses,listoflabs);


    Maths_Constraints(mathscourse);


    Teacher_Unavailable(teacherunav);


    Course_Hardcode(coursehardcode);


    Lab_Hardcode(labhardcode);

    return;
}
