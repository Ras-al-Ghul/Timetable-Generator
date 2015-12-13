
#include "define_classes.h"
//Everything on heap

void entercourselist(vector <Course*>* listofcourses){
    listofcourses->pb(new Course("Maths","Chandrashekar",3,4,'A'));//sem and numperweek
    /*
    vector <Course *> tempvect;
    tempvect=listofcourses[0];
    cout<<tempvect[0]->get_course_name()<<endl;
    */
    listofcourses->pb(new Course("Data Structures","Rajeshwari",3,4,'A'));
    /*
    vector <Course *> tempvect;
    tempvect=listofcourses[0];
    cout<<tempvect[1]->get_course_name()<<endl;
    */
    listofcourses->pb(new Course("Microprocessors","Gururaja",3,4,'A'));
    listofcourses->pb(new Course("Logic Design","Sreelatha",3,4,'A'));
    listofcourses->pb(new Course("Computer Organization","Sheela",3,4,'A'));

    listofcourses->pb(new Course("Maths","Anthony",3,4,'B'));
    listofcourses->pb(new Course("Data Structures","Nalina",3,4,'B'));
    listofcourses->pb(new Course("Microprocessors","Anusha",3,4,'B'));
    listofcourses->pb(new Course("Logic Design","Mamatha",3,4,'B'));
    listofcourses->pb(new Course("Computer Organization","Sindhu",3,4,'B'));


    listofcourses->pb(new Course("Operating System","Nalini",5,4,'A'));
    listofcourses->pb(new Course("Data Communications","Gururaja",5,4,'A'));
    listofcourses->pb(new Course("Database Management","Shambhavi",5,4,'A'));
    listofcourses->pb(new Course("Java Programming","Jayarekha",5,4,'A'));
    listofcourses->pb(new Course("Unix System Programming","Preetha",5,4,'A'));

    listofcourses->pb(new Course("Operating System","Mahalakshmi",5,4,'B'));
    listofcourses->pb(new Course("Data Communications","GowriShankar",5,4,'B'));
    listofcourses->pb(new Course("Database Management","Roopa",5,4,'B'));
    listofcourses->pb(new Course("Java Programming","Anitha",5,4,'B'));
    listofcourses->pb(new Course("Unix System Programming","Shubha",5,4,'B'));

    listofcourses->pb(new Course("C Sharp","Shubha",7,4,'A'));
    listofcourses->pb(new Course("Cryptography","Mahalakshmi",7,4,'A'));
    listofcourses->pb(new Course("Data Mining","Chandrakala",7,4,'A'));
    listofcourses->pb(new Course("Mobile App","Ashok",7,4,'A'));
    listofcourses->pb(new Course("Management Info Systems","Soumya",7,4,'A'));
    listofcourses->pb(new Course("Entrepreneurship","Sindhu",7,3,'A'));
    listofcourses->pb(new Course("Institutional Elective","Blank",7,4,'A'));
    listofcourses->pb(new Course("Project 1","Big blank",7,4,'A'));

    listofcourses->pb(new Course("C Sharp","Preetha",7,4,'B'));
    //listofcourses->pb(new Course("Cryptography","Mahalakshmi",7,4,'B'));
    //listofcourses->pb(new Course("Data Mining","Chandrakala",7,4,'B'));
    //listofcourses->pb(new Course("Mobile App","Ashok",7,4,'B'));
    //listofcourses->pb(new Course("Management Info Systems","Soumya",7,4,'B'));
    listofcourses->pb(new Course("Entrepreneurship","Nalina",7,3,'B'));
    listofcourses->pb(new Course("Institutional Elective","Blank",7,4,'B'));
    listofcourses->pb(new Course("Project 1","Big blank",7,4,'B'));

    /*
    vector <Course *> tempvect;
    tempvect=listofcourses[0];
    cout<<tempvect[20]->get_course_code()<<endl;
    */
    return;
}

void entersectionlist(vector <Section*> * listofsections,vector <Course*>* listofcourses){
    listofsections->pb(new Section(listofcourses,'A',3));
    listofsections->pb(new Section(listofcourses,'B',3));
    listofsections->pb(new Section(listofcourses,'A',5));
    listofsections->pb(new Section(listofcourses,'B',5));
    listofsections->pb(new Section(listofcourses,'A',7));
    listofsections->pb(new Section(listofcourses,'B',7));
    return;
}

void enterlablist(vector <Lab*>* listoflabs){
    //Always 2 lab per week to come first and be clustered together..And always in inverted order see below..
    listoflabs->pb(new Lab("Data Structures","Rajeshwari","Mahalakshmi",2,3,"A1","A2"));//numperweek,semester,batch1,batch2
    listoflabs->pb(new Lab("Data Structures","Rajeshwari","Mahalakshmi",2,3,"A3","A4"));

    listoflabs->pb(new Lab("Microprocessors","Gururaja","Soumya",2,3,"A3","A4"));
    listoflabs->pb(new Lab("Microprocessors","Gururaja","Anusha",2,3,"A1","A2"));

    listoflabs->pb(new Lab("Logic Design","Sreelatha","Mamatha",1,3,"A1","A2"));
    listoflabs->pb(new Lab("Logic Design","Sreelatha","Gururaja",1,3,"A3","A4"));
    //Bsection

    listoflabs->pb(new Lab("Data Structures","Nalina","Sindhu",2,3,"B1","B2"));
    listoflabs->pb(new Lab("Data Structures","Nalina","Sindhu",2,3,"B3","B4"));

    listoflabs->pb(new Lab("Microprocessors","Anusha","Soumya",2,3,"B3","B4"));
    listoflabs->pb(new Lab("Microprocessors","Anusha","Soumya",2,3,"B1","B2"));

    listoflabs->pb(new Lab("Logic Design","Sreelatha","Mamatha",1,3,"B1","B2"));
    listoflabs->pb(new Lab("Logic Design","Sreelatha","Mamatha",1,3,"B3","B4"));
    //Asection
    listoflabs->pb(new Lab("Database","Shambhavi","Gururaja",2,5,"A1","A2"));
    listoflabs->pb(new Lab("Database","Shambhavi","Nalina",2,5,"A3","A4"));

    listoflabs->pb(new Lab("Java","Rajeshwari","Shweta",2,5,"A3","A4"));
    listoflabs->pb(new Lab("Java","Rajeshwari","Shweta",2,5,"A1","A2"));

    listoflabs->pb(new Lab("Unix","Anitha","Preetha",1,5,"A1","A2"));
    listoflabs->pb(new Lab("Unix","Preetha","Anitha",1,5,"A3","A4"));
    //Bsection
    listoflabs->pb(new Lab("Database","Roopa","Nalini",2,5,"B1","B2"));
    listoflabs->pb(new Lab("Database","Roopa","Nalini",2,5,"B3","B4"));

    listoflabs->pb(new Lab("Java","Chandrakala","Shweta",2,5,"B3","B4"));
    listoflabs->pb(new Lab("Java","Chandrakala","Shweta",2,5,"B1","B2"));

    listoflabs->pb(new Lab("Unix","Anitha","Preetha",1,5,"B1","B2"));
    listoflabs->pb(new Lab("Unix","Anitha","Preetha",1,5,"B3","B4"));
    //Asection
    listoflabs->pb(new Lab("C Sharp","Shubha","Chandrakala",2,7,"A1","A2"));
    listoflabs->pb(new Lab("C Sharp","Shubha","Chandrakala",2,7,"A3","A4"));
    //Bsection
    listoflabs->pb(new Lab("C Sharp","Shubha","Roopa",2,7,"B1","B2"));
    listoflabs->pb(new Lab("C Sharp","Sindhu","Preetha",2,7,"B3","B4"));
    /*
    vector <Lab *> tempvect=listoflabs[0];
    tr(tempvect,it){
        cout<<(*it)->get_lab_name()<<" "<<(*it)->get_batch1()<<" "<<(*it)->get_batch2()<<endl;
    }
    */
    return;
}

void enterbatchlist(vector <Batch*> * listofbatches,vector <Lab*>* listoflabs){
    listofbatches->pb(new Batch(listoflabs,"A1",3,15));//sem batchstrength
    listofbatches->pb(new Batch(listoflabs,"A2",3,15));
    listofbatches->pb(new Batch(listoflabs,"A3",3,15));
    listofbatches->pb(new Batch(listoflabs,"A4",3,15));
    listofbatches->pb(new Batch(listoflabs,"B1",3,15));
    listofbatches->pb(new Batch(listoflabs,"B2",3,15));
    listofbatches->pb(new Batch(listoflabs,"B3",3,15));
    listofbatches->pb(new Batch(listoflabs,"B4",3,15));

    listofbatches->pb(new Batch(listoflabs,"A1",5,15));
    listofbatches->pb(new Batch(listoflabs,"A2",5,15));
    listofbatches->pb(new Batch(listoflabs,"A3",5,15));
    listofbatches->pb(new Batch(listoflabs,"A4",5,15));
    listofbatches->pb(new Batch(listoflabs,"B1",5,15));
    listofbatches->pb(new Batch(listoflabs,"B2",5,15));
    listofbatches->pb(new Batch(listoflabs,"B3",5,15));
    listofbatches->pb(new Batch(listoflabs,"B4",5,15));

    listofbatches->pb(new Batch(listoflabs,"A1",7,15));
    listofbatches->pb(new Batch(listoflabs,"A2",7,15));
    listofbatches->pb(new Batch(listoflabs,"A3",7,15));
    listofbatches->pb(new Batch(listoflabs,"A4",7,15));
    listofbatches->pb(new Batch(listoflabs,"B1",7,15));
    listofbatches->pb(new Batch(listoflabs,"B2",7,15));
    listofbatches->pb(new Batch(listoflabs,"B3",7,15));
    listofbatches->pb(new Batch(listoflabs,"B4",7,15));

    return;
}

void entersemesterlist(vector <Semester*> * listofsemesters, \
                       vector <Course*> * listofcourses,vector <Section*>* listofsections,vector <Lab*> * listoflabs,vector <Batch*>* listofbatches){

    listofsemesters->pb(new Semester(listofcourses,listofsections,listoflabs,listofbatches,3));
    listofsemesters->pb(new Semester(listofcourses,listofsections,listoflabs,listofbatches,5));
    listofsemesters->pb(new Semester(listofcourses,listofsections,listoflabs,listofbatches,7));
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
    temppair->first="A";(temppair->second).first=1;(temppair->second).second=1;//first is day of week 1-6 second is hour of day 1-7...
    mathscourse->pb(temppair);

    temppair=new pair<string,pair<int,int> >;
    temppair->first="A";(temppair->second).first=2;(temppair->second).second=6;//first is day of week 1-6 second is hour of day 1-7...
    mathscourse->pb(temppair);

    temppair=new pair<string,pair<int,int> >;
    temppair->first="A";(temppair->second).first=2;(temppair->second).second=7;//first is day of week 1-6 second is hour of day 1-7...
    mathscourse->pb(temppair);

    temppair=new pair<string,pair<int,int> >;
    temppair->first="A";(temppair->second).first=5;(temppair->second).second=4;//first is day of week 1-6 second is hour of day 1-7...
    mathscourse->pb(temppair);

    temppair=new pair<string,pair<int,int> >;
    temppair->first="A";(temppair->second).first=6;(temppair->second).second=5;//first is day of week 1-6 second is hour of day 1-7...
    mathscourse->pb(temppair);
    //section b
    temppair=new pair<string,pair<int,int> >;
    temppair->first="B";(temppair->second).first=1;(temppair->second).second=3;//first is day of week 1-6 second is hour of day 1-7...
    mathscourse->pb(temppair);

    temppair=new pair<string,pair<int,int> >;
    temppair->first="B";(temppair->second).first=2;(temppair->second).second=5;//first is day of week 1-6 second is hour of day 1-7...
    mathscourse->pb(temppair);

    temppair=new pair<string,pair<int,int> >;
    temppair->first="B";(temppair->second).first=3;(temppair->second).second=6;//first is day of week 1-6 second is hour of day 1-7...
    mathscourse->pb(temppair);

    temppair=new pair<string,pair<int,int> >;
    temppair->first="B";(temppair->second).first=3;(temppair->second).second=7;//first is day of week 1-6 second is hour of day 1-7...
    mathscourse->pb(temppair);

    temppair=new pair<string,pair<int,int> >;
    temppair->first="B";(temppair->second).first=4;(temppair->second).second=4;//first is day of week 1-6 second is hour of day 1-7...
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

    temppair->first="Rajeshwari";(temppair->second).first=3;(temppair->second).second=2;//first is day of week 1-6 second is hour of day 1-7...
    teacherunav->pb(temppair);

    temppair=new pair<string,pair<int,int> >;
    temppair->first="Rajeshwari";(temppair->second).first=3;(temppair->second).second=3;//first is day of week 1-6 second is hour of day 1-7...
    teacherunav->pb(temppair);

    temppair=new pair<string,pair<int,int> >;
    temppair->first="Mamatha";(temppair->second).first=1;(temppair->second).second=4;//first is day of week 1-6 second is hour of day 1-7...
    teacherunav->pb(temppair);

    temppair=new pair<string,pair<int,int> >;
    temppair->first="Chandrakala";(temppair->second).first=1;(temppair->second).second=4;//first is day of week 1-6 second is hour of day 1-7...
    teacherunav->pb(temppair);

    temppair=new pair<string,pair<int,int> >;
    temppair->first="Mamatha";(temppair->second).first=1;(temppair->second).second=5;//first is day of week 1-6 second is hour of day 1-7...
    teacherunav->pb(temppair);

    temppair=new pair<string,pair<int,int> >;
    temppair->first="Chandrakala";(temppair->second).first=1;(temppair->second).second=5;//first is day of week 1-6 second is hour of day 1-7...
    teacherunav->pb(temppair);

    temppair=new pair<string,pair<int,int> >;
    temppair->first="Shweta";(temppair->second).first=1;(temppair->second).second=4;//first is day of week 1-6 second is hour of day 1-7...
    teacherunav->pb(temppair);

    temppair=new pair<string,pair<int,int> >;
    temppair->first="Sreelatha";(temppair->second).first=1;(temppair->second).second=4;//first is day of week 1-6 second is hour of day 1-7...
    teacherunav->pb(temppair);

    temppair=new pair<string,pair<int,int> >;
    temppair->first="Shweta";(temppair->second).first=1;(temppair->second).second=5;//first is day of week 1-6 second is hour of day 1-7...
    teacherunav->pb(temppair);

    temppair=new pair<string,pair<int,int> >;
    temppair->first="Sreelatha";(temppair->second).first=1;(temppair->second).second=5;//first is day of week 1-6 second is hour of day 1-7...
    teacherunav->pb(temppair);

    temppair=new pair<string,pair<int,int> >;
    temppair->first="Mamatha";(temppair->second).first=2;(temppair->second).second=2;//first is day of week 1-6 second is hour of day 1-7...
    teacherunav->pb(temppair);

    temppair=new pair<string,pair<int,int> >;
    temppair->first="Roopa";(temppair->second).first=2;(temppair->second).second=2;//first is day of week 1-6 second is hour of day 1-7...
    teacherunav->pb(temppair);

    temppair=new pair<string,pair<int,int> >;
    temppair->first="Mamatha";(temppair->second).first=2;(temppair->second).second=3;//first is day of week 1-6 second is hour of day 1-7...
    teacherunav->pb(temppair);

    temppair=new pair<string,pair<int,int> >;
    temppair->first="Roopa";(temppair->second).first=2;(temppair->second).second=3;//first is day of week 1-6 second is hour of day 1-7...
    teacherunav->pb(temppair);

    temppair=new pair<string,pair<int,int> >;
    temppair->first="Mamatha";(temppair->second).first=3;(temppair->second).second=4;//first is day of week 1-6 second is hour of day 1-7...
    teacherunav->pb(temppair);

    temppair=new pair<string,pair<int,int> >;
    temppair->first="Mamatha";(temppair->second).first=3;(temppair->second).second=5;//first is day of week 1-6 second is hour of day 1-7...
    teacherunav->pb(temppair);

    temppair=new pair<string,pair<int,int> >;
    temppair->first="Mamatha";(temppair->second).first=4;(temppair->second).second=2;//first is day of week 1-6 second is hour of day 1-7...
    teacherunav->pb(temppair);

    temppair=new pair<string,pair<int,int> >;
    temppair->first="Mamatha";(temppair->second).first=4;(temppair->second).second=3;//first is day of week 1-6 second is hour of day 1-7...
    teacherunav->pb(temppair);

    temppair=new pair<string,pair<int,int> >;
    temppair->first="Mamatha";(temppair->second).first=6;(temppair->second).second=3;//first is day of week 1-6 second is hour of day 1-7...
    teacherunav->pb(temppair);

    temppair=new pair<string,pair<int,int> >;
    temppair->first="Mamatha";(temppair->second).first=6;(temppair->second).second=4;//first is day of week 1-6 second is hour of day 1-7...
    teacherunav->pb(temppair);

    return;
}

void Course_Hardcode(vector <pair<pair<string,string>,pair<int,int> > * >* coursehardcode){
    pair <pair<string,string>,pair<int,int> > * temppair=new pair<pair<string,string>,pair<int,int> >;
    (temppair->first).first="Data Structures";(temppair->first).second="3A";(temppair->second).first=2;(temppair->second).second=4;//first is day of week 1-6 second is hour of day 1-7...
    coursehardcode->pb(temppair);

    temppair=new pair<pair<string,string>,pair<int,int> >;
    (temppair->first).first="Data Structures";(temppair->first).second="3A";(temppair->second).first=3;(temppair->second).second=6;//first is day of week 1-6 second is hour of day 1-7...
    coursehardcode->pb(temppair);

    temppair=new pair<pair<string,string>,pair<int,int> >;
    (temppair->first).first="Java Programming";(temppair->first).second="5B";(temppair->second).first=3;(temppair->second).second=3;//first is day of week 1-6 second is hour of day 1-7...
    coursehardcode->pb(temppair);

    temppair=new pair<pair<string,string>,pair<int,int> >;
    (temppair->first).first="Blank";(temppair->first).second="5A";(temppair->second).first=1;(temppair->second).second=1;//first is day of week 1-6 second is hour of day 1-7...
    coursehardcode->pb(temppair);
    temppair=new pair<pair<string,string>,pair<int,int> >;
    (temppair->first).first="Blank";(temppair->first).second="5A";(temppair->second).first=3;(temppair->second).second=1;//first is day of week 1-6 second is hour of day 1-7...
    coursehardcode->pb(temppair);
    temppair=new pair<pair<string,string>,pair<int,int> >;
    (temppair->first).first="Blank";(temppair->first).second="5A";(temppair->second).first=5;(temppair->second).second=1;//first is day of week 1-6 second is hour of day 1-7...
    coursehardcode->pb(temppair);

    temppair=new pair<pair<string,string>,pair<int,int> >;
    (temppair->first).first="Blank";(temppair->first).second="5B";(temppair->second).first=2;(temppair->second).second=1;//first is day of week 1-6 second is hour of day 1-7...
    coursehardcode->pb(temppair);
    temppair=new pair<pair<string,string>,pair<int,int> >;
    (temppair->first).first="Blank";(temppair->first).second="5B";(temppair->second).first=4;(temppair->second).second=1;//first is day of week 1-6 second is hour of day 1-7...
    coursehardcode->pb(temppair);
    temppair=new pair<pair<string,string>,pair<int,int> >;
    (temppair->first).first="Blank";(temppair->first).second="5B";(temppair->second).first=6;(temppair->second).second=1;//first is day of week 1-6 second is hour of day 1-7...
    coursehardcode->pb(temppair);

    temppair=new pair<pair<string,string>,pair<int,int> >;
    (temppair->first).first="Institutional Elective";(temppair->first).second="7A";(temppair->second).first=1;(temppair->second).second=4;//first is day of week 1-6 second is hour of day 1-7...
    coursehardcode->pb(temppair);

    temppair=new pair<pair<string,string>,pair<int,int> >;
    (temppair->first).first="Institutional Elective";(temppair->first).second="7A";(temppair->second).first=1;(temppair->second).second=5;//first is day of week 1-6 second is hour of day 1-7...
    coursehardcode->pb(temppair);

    temppair=new pair<pair<string,string>,pair<int,int> >;
    (temppair->first).first="Institutional Elective";(temppair->first).second="7A";(temppair->second).first=3;(temppair->second).second=4;//first is day of week 1-6 second is hour of day 1-7...
    coursehardcode->pb(temppair);

    temppair=new pair<pair<string,string>,pair<int,int> >;
    (temppair->first).first="Institutional Elective";(temppair->first).second="7A";(temppair->second).first=6;(temppair->second).second=3;//first is day of week 1-6 second is hour of day 1-7...
    coursehardcode->pb(temppair);

    temppair=new pair<pair<string,string>,pair<int,int> >;
    (temppair->first).first="Institutional Elective";(temppair->first).second="7B";(temppair->second).first=1;(temppair->second).second=4;//first is day of week 1-6 second is hour of day 1-7...
    coursehardcode->pb(temppair);

    temppair=new pair<pair<string,string>,pair<int,int> >;
    (temppair->first).first="Institutional Elective";(temppair->first).second="7B";(temppair->second).first=1;(temppair->second).second=5;//first is day of week 1-6 second is hour of day 1-7...
    coursehardcode->pb(temppair);

    temppair=new pair<pair<string,string>,pair<int,int> >;
    (temppair->first).first="Institutional Elective";(temppair->first).second="7B";(temppair->second).first=3;(temppair->second).second=4;//first is day of week 1-6 second is hour of day 1-7...
    coursehardcode->pb(temppair);

    temppair=new pair<pair<string,string>,pair<int,int> >;
    (temppair->first).first="Institutional Elective";(temppair->first).second="7B";(temppair->second).first=6;(temppair->second).second=3;//first is day of week 1-6 second is hour of day 1-7...
    coursehardcode->pb(temppair);

    return;
}

void Lab_Hardcode(vector <pair<pair<string,string>,pair<pair<string,string>,pair<int,int> > >* >* labhardcode){
    pair<pair<string,string>,pair<pair<string,string>,pair<int,int> > >* temppair=new pair<pair<string,string>,pair<pair<string,string>,pair<int,int> > >;
    (temppair->first).first="Logic Design";(temppair->first).second="3A";
    (temppair->second).first.first="A1";(temppair->second).first.second="A2";(temppair->second).second.first=1;(temppair->second).second.second=6;
    labhardcode->pb(temppair);

    temppair=new pair<pair<string,string>,pair<pair<string,string>,pair<int,int> > >;
    (temppair->first).first="Logic Design";(temppair->first).second="3A";
    (temppair->second).first.first="A3";(temppair->second).first.second="A4";(temppair->second).second.first=6;(temppair->second).second.second=2;
    labhardcode->pb(temppair);

    temppair=new pair<pair<string,string>,pair<pair<string,string>,pair<int,int> > >;
    (temppair->first).first="Logic Design";(temppair->first).second="3B";
    (temppair->second).first.first="B1";(temppair->second).first.second="B2";(temppair->second).second.first=2;(temppair->second).second.second=6;
    labhardcode->pb(temppair);

    temppair=new pair<pair<string,string>,pair<pair<string,string>,pair<int,int> > >;
    (temppair->first).first="Logic Design";(temppair->first).second="3B";
    (temppair->second).first.first="B3";(temppair->second).first.second="B4";(temppair->second).second.first=5;(temppair->second).second.second=6;
    labhardcode->pb(temppair);

    return;
}

void getallinputs(vector <Course*>* listofcourses,vector <Section*>* listofsections,vector <Lab*>* listoflabs,vector <Batch*>* listofbatches,\
                  vector <Semester*>* listofsemesters,vector <Professor*>* listofprofessors,vector <pair<string,pair<int,int> > * >* mathscourse,\
                  vector <pair<string,pair<int,int> > * >* teacherunav,vector <pair<pair<string,string>,pair<int,int> > * >* coursehardcode,\
                  vector <pair<pair<string,string>,pair<pair<string,string>,pair<int,int> > >* >* labhardcode){
    oddeve=true;//Doing for odd sem..



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
