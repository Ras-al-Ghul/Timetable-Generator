#include "C:\Users\admin\Desktop\Timetable Gen\Oddsem\Inputs\get_inputs.h"
#include "genetic.h"
#include "CODE.h"

void print_chromosomes(vector<elementOfChromosome> tempchromo){

   ofstream outputfile;
   outputfile.open("TimeTableOddSem.txt");

        for(int j=0;j<6;j++){
                string ppttrr="";
            for(int k=0;k<40;k++){
                if(tempchromo[j*40+k].labornot==1){

                     string ppttrr=get_code(tempchromo[j*40+k].classlabname)+"/"+tempchromo[j*40+k].batch1+tempchromo[j*40+k].batch2;
                     outputfile<<ppttrr;

                    for(int kk=0;kk<(11-ppttrr.size());kk++){
                      outputfile<<" ";
                    }
                    if(get_code(tempchromo[j*40+k].classlabname)==get_code(tempchromo[j*40+(k+1)].classlabname)){k++;}
                }
                else
                {    string ppttrr=get_code(tempchromo[j*40+k].classlabname);
                     outputfile<<ppttrr;
                     for(int kk=0;kk<(11-ppttrr.size());kk++){
                         outputfile<<" ";
                    }
                }

                if(k==6||k==13||k==20||k==27||k==34)
                    outputfile<<"\n";
            }
           outputfile<<"\n\n\n";

        }
}

void initializerToBlank(vector<elementOfChromosome*>* chromosome){
    for(int i=0;i<240;i++){
        elementOfChromosome* tempobj=new elementOfChromosome;
        tempobj->labornot=-1;
        tempobj->teacher1="";tempobj->teacher2="";
        tempobj->sem=0;tempobj->section="";
        tempobj->batch1="";tempobj->batch2="";
        tempobj->classlabname="nothing";
        tempobj->mutables=1;
        tempobj->crossoverrate=10;tempobj->mutationrate=10;
        chromosome->pb(tempobj);
    }
    return;
}



int main(){
    srand(time(NULL));
    const int numofallcourses=36;
    const int numofallsections=6;
    const int numofalllabs=24;
    const int numofallbatches=24;
    const int numofallsemesters=3;

    vector <Course*>* listofcourses=new vector<Course*>;
    vector <Section*>* listofsections=new vector<Section*>;
    vector <Lab*>* listoflabs=new vector<Lab*>;
    vector <Batch*>* listofbatches=new vector<Batch*>;
    vector <Semester*>* listofsemesters=new vector<Semester*>;
    vector <Professor*>* listofprofessors=new vector<Professor*>;
    vector <pair<string,pair<int,int> > * >* mathscourse=new vector<pair<string,pair<int,int> > * >;
    vector <pair<string,pair<int,int> > * >* teacherunav=new vector<pair<string,pair<int,int> > * >;
    vector <pair<pair<string,string>,pair<int,int> > * >* coursehardcode=new vector<pair<pair<string,string>,pair<int,int> > * >;
    vector <pair<pair<string,string>,pair<pair<string,string>,pair<int,int> > >* >* labhardcode=new vector<pair<pair<string,string>,pair<pair<string,string>,pair<int,int> > >* >;

    getallinputs(listofcourses,listofsections,listoflabs,listofbatches,listofsemesters,listofprofessors,mathscourse,teacherunav,coursehardcode,labhardcode);

    vector<elementOfChromosome*>* chromosome,*chromosome1,*chromosome2,*chromosome3;
    string ans;

    beginagain:
    ans="N";

    while(ans=="N"||ans=="n"){
        int tempnum=0;
        while(tempnum!=1){

            for(int i=0;i<2000;i++){
                chromosome=new vector<elementOfChromosome*>[240];
                vector<int> LabDS(17);
                tempnum=createChromosome(chromosome,LabDS,listofcourses,listofsections,listoflabs,listofbatches,listofsemesters,listofprofessors,mathscourse,teacherunav,coursehardcode,labhardcode);
                if(tempnum!=1){
                    delete []chromosome;
                    continue;
                }
                else{
                    print_chromosome(chromosome);
                    break;
                }
            }
        }
        cout<<endl<<"Are you satisfied with lab time table? (Y/N)"<<endl;
        cin>>ans;
    }

    chromosome1=new vector<elementOfChromosome*>[240];chromosome2=new vector<elementOfChromosome*>[240];chromosome3=new vector<elementOfChromosome*>[240];

    vector<elementOfChromosome*> tempchromosome=chromosome[0];
    for(int i=0;i<240;i++){
        elementOfChromosome* tempobj1=new elementOfChromosome;elementOfChromosome* tempobj2=new elementOfChromosome;elementOfChromosome* tempobj3=new elementOfChromosome;
        tempobj1->labornot=tempchromosome[i]->labornot;tempobj2->labornot=tempchromosome[i]->labornot;tempobj3->labornot=tempchromosome[i]->labornot;
        tempobj1->teacher1=tempchromosome[i]->teacher1;tempobj1->teacher2=tempchromosome[i]->teacher2;
        tempobj2->teacher1=tempchromosome[i]->teacher1;tempobj2->teacher2=tempchromosome[i]->teacher2;
        tempobj3->teacher1=tempchromosome[i]->teacher1;tempobj3->teacher2=tempchromosome[i]->teacher2;
        tempobj1->sem=tempchromosome[i]->sem;tempobj1->section=tempchromosome[i]->section;
        tempobj2->sem=tempchromosome[i]->sem;tempobj2->section=tempchromosome[i]->section;
        tempobj3->sem=tempchromosome[i]->sem;tempobj3->section=tempchromosome[i]->section;
        tempobj1->batch1=tempchromosome[i]->batch1;tempobj1->batch2=tempchromosome[i]->batch2;
        tempobj2->batch1=tempchromosome[i]->batch1;tempobj2->batch2=tempchromosome[i]->batch2;
        tempobj3->batch1=tempchromosome[i]->batch1;tempobj3->batch2=tempchromosome[i]->batch2;
        tempobj1->classlabname=tempchromosome[i]->classlabname;tempobj2->classlabname=tempchromosome[i]->classlabname;tempobj3->classlabname=tempchromosome[i]->classlabname;
        tempobj1->mutables=tempchromosome[i]->mutables;tempobj2->mutables=tempchromosome[i]->mutables;tempobj3->mutables=tempchromosome[i]->mutables;
        tempobj1->crossoverrate=10;tempobj1->mutationrate=10;tempobj2->crossoverrate=10;tempobj2->mutationrate=10;tempobj3->crossoverrate=10;tempobj3->mutationrate=10;
        chromosome1->pb(tempobj1);chromosome2->pb(tempobj2);chromosome3->pb(tempobj3);
    }

    ans="2";
    while(ans=="2"){


        int tempnum=0;

        while(tempnum!=1){
            vector<elementOfChromosome*> tempchromosome=chromosome[0];
            for(int i=0;i<2000;i++){

                vector<elementOfChromosome> dupchromosome(240);
                for(int j=0;j<240;j++){

                    elementOfChromosome tempobj;
                    tempobj.section=tempchromosome[j]->section;
                    tempobj.classlabname=tempchromosome[j]->classlabname;
                    tempobj.mutables=tempchromosome[j]->mutables;
                    tempobj.sem=tempchromosome[j]->sem;
                    tempobj.labornot=tempchromosome[j]->labornot;
                    tempobj.teacher1=tempchromosome[j]->teacher1;
                    tempobj.teacher2=tempchromosome[j]->teacher1;
                    tempobj.batch1=tempchromosome[j]->batch1;
                    tempobj.batch2=tempchromosome[j]->batch2;
                    dupchromosome[j]=(tempobj);
                    //cout<<tempobj.classlabname<<dupchromosome[j].classlabname<<endl;
                    //dupchromosome[j]();
                }

                vector <Course> templistofcourses;
                vector <Course*> oldtempvec=listofcourses[0];
                tr(oldtempvec,iters){
                    string courses=(*iters)->get_course_name();string profs=(*iters)->get_prof_name();
                    int sems=(*iters)->get_sem();int nums=(*iters)->get_numperweek();char secs=(*iters)->get_char_section();
                    Course tempobj(courses,profs,sems,nums,secs,(*iters)->get_allocated());
                    templistofcourses.pb(tempobj);
                }
                tempnum=fillincourses(dupchromosome,templistofcourses,listofbatches,teacherunav);
                if(tempnum!=1){
                    dupchromosome.erase(dupchromosome.begin(),dupchromosome.end());
                    templistofcourses.erase(templistofcourses.begin(),templistofcourses.end());
                    oldtempvec.erase(oldtempvec.begin(),oldtempvec.end());
                    //cout<<"done";
                    continue;
                }
                else{
                    //cout<<"Here"<<endl;
                    print_chromosomes(dupchromosome);vector<elementOfChromosome*> tempchromosome1=chromosome1[0];
                    for(int cc=0;cc<240;cc++){
                        tempchromosome1[cc]->section=dupchromosome[cc].section;
                        tempchromosome1[cc]->classlabname=dupchromosome[cc].classlabname;
                        tempchromosome1[cc]->mutables=dupchromosome[cc].mutables;
                        tempchromosome1[cc]->sem=dupchromosome[cc].sem;
                        tempchromosome1[cc]->labornot=dupchromosome[cc].labornot;
                        tempchromosome1[cc]->teacher1=dupchromosome[cc].teacher1;
                        tempchromosome1[cc]->teacher2=dupchromosome[cc].teacher1;
                        tempchromosome1[cc]->batch1=dupchromosome[cc].batch1;
                        tempchromosome1[cc]->batch2=dupchromosome[cc].batch2;
                    }
                    break;
                }
            }
        }
        cout<<endl<<"Second year done"<<endl<<endl;

        thirdyear:
        tempnum=0;
        while(tempnum!=1){
            vector<elementOfChromosome*> tempchromosome=chromosome1[0];
            for(int i=0;i<2000;i++){
                vector<elementOfChromosome> dupchromosome(240);
                for(int j=0;j<240;j++){
                    elementOfChromosome tempobj;
                    tempobj.section=tempchromosome[j]->section;
                    tempobj.classlabname=tempchromosome[j]->classlabname;
                    tempobj.mutables=tempchromosome[j]->mutables;
                    tempobj.sem=tempchromosome[j]->sem;
                    tempobj.labornot=tempchromosome[j]->labornot;
                    tempobj.teacher1=tempchromosome[j]->teacher1;
                    tempobj.teacher2=tempchromosome[j]->teacher1;
                    tempobj.batch1=tempchromosome[j]->batch1;
                    tempobj.batch2=tempchromosome[j]->batch2;
                    dupchromosome[j]=tempobj;
                }

                vector <Course> templistofcourses;
                vector <Course*> oldtempvec=listofcourses[0];
                tr(oldtempvec,iters){
                    string courses=(*iters)->get_course_name();string profs=(*iters)->get_prof_name();
                    int sems=(*iters)->get_sem();int nums=(*iters)->get_numperweek();char secs=(*iters)->get_char_section();
                    Course tempobj(courses,profs,sems,nums,secs,(*iters)->get_allocated());
                    templistofcourses.pb(tempobj);
                }
                tempnum=fillin3rdyear(dupchromosome,templistofcourses,listofbatches,teacherunav);
                if(tempnum!=1){
                    dupchromosome.erase(dupchromosome.begin(),dupchromosome.end());
                    templistofcourses.erase(templistofcourses.begin(),templistofcourses.end());
                    oldtempvec.erase(oldtempvec.begin(),oldtempvec.end());

                    continue;
                }
                else{
                    print_chromosomes(dupchromosome);vector<elementOfChromosome*> tempchromosome2=chromosome2[0];
                    for(int cc=0;cc<240;cc++){
                        tempchromosome2[cc]->section=dupchromosome[cc].section;
                        tempchromosome2[cc]->classlabname=dupchromosome[cc].classlabname;
                        tempchromosome2[cc]->mutables=dupchromosome[cc].mutables;
                        tempchromosome2[cc]->sem=dupchromosome[cc].sem;
                        tempchromosome2[cc]->labornot=dupchromosome[cc].labornot;
                        tempchromosome2[cc]->teacher1=dupchromosome[cc].teacher1;
                        tempchromosome2[cc]->teacher2=dupchromosome[cc].teacher1;
                        tempchromosome2[cc]->batch1=dupchromosome[cc].batch1;
                        tempchromosome2[cc]->batch2=dupchromosome[cc].batch2;
                    }
                    break;
                }
            }
        }

        cout<<endl<<"Third Year is done"<<endl<<endl;


        fourthyear:
        tempnum=0;
        while(tempnum!=1){
            vector<elementOfChromosome*> tempchromosome=chromosome2[0];
            for(int i=0;i<2000;i++){
                vector<elementOfChromosome> dupchromosome(240);
                for(int j=0;j<240;j++){
                    elementOfChromosome tempobj;
                    tempobj.section=tempchromosome[j]->section;
                    tempobj.classlabname=tempchromosome[j]->classlabname;
                    tempobj.mutables=tempchromosome[j]->mutables;
                    tempobj.sem=tempchromosome[j]->sem;
                    tempobj.labornot=tempchromosome[j]->labornot;
                    tempobj.teacher1=tempchromosome[j]->teacher1;
                    tempobj.teacher2=tempchromosome[j]->teacher1;
                    tempobj.batch1=tempchromosome[j]->batch1;
                    tempobj.batch2=tempchromosome[j]->batch2;
                    dupchromosome[j]=tempobj;
                }

                vector <Course> templistofcourses;
                vector <Course*> oldtempvec=listofcourses[0];
                tr(oldtempvec,iters){
                    string courses=(*iters)->get_course_name();string profs=(*iters)->get_prof_name();
                    int sems=(*iters)->get_sem();int nums=(*iters)->get_numperweek();char secs=(*iters)->get_char_section();
                    Course tempobj(courses,profs,sems,nums,secs,(*iters)->get_allocated());
                    templistofcourses.pb(tempobj);
                }
                tempnum=fillin4thyear(dupchromosome,templistofcourses,listofbatches,teacherunav);
                if(tempnum!=1){
                    dupchromosome.erase(dupchromosome.begin(),dupchromosome.end());
                    templistofcourses.erase(templistofcourses.begin(),templistofcourses.end());
                    oldtempvec.erase(oldtempvec.begin(),oldtempvec.end());
                    //cout<<"0";
                    continue;
                }
                else{
                    print_chromosomes(dupchromosome);
                    vector<elementOfChromosome*> tempchromosome3=chromosome3[0];
                    for(int cc=0;cc<240;cc++){
                        tempchromosome3[cc]->section=dupchromosome[cc].section;
                        tempchromosome3[cc]->classlabname=dupchromosome[cc].classlabname;
                        tempchromosome3[cc]->mutables=dupchromosome[cc].mutables;
                        tempchromosome3[cc]->sem=dupchromosome[cc].sem;
                        tempchromosome3[cc]->labornot=dupchromosome[cc].labornot;
                        tempchromosome3[cc]->teacher1=dupchromosome[cc].teacher1;
                        tempchromosome3[cc]->teacher2=dupchromosome[cc].teacher1;
                        tempchromosome3[cc]->batch1=dupchromosome[cc].batch1;
                        tempchromosome3[cc]->batch2=dupchromosome[cc].batch2;
                    }
                    cout<<endl<<"Fourth Year is done"<<endl<<endl;
                    cout<<"The final time table is"<<endl<<endl;
                    print_chromosome(chromosome3);
                    break;
                }
            }
        }

        cout<<endl<<"Are you satisfied with the timetable? Key in \n1 for Yes,\n2 for redoing course filling from second year,\
        \n3 for redoing course filling from third year, \n4 for redoing course filling from fourth year, \
        \n5 for starting all over again, \n6 for quitting.."<<endl;
        cin>>ans;
        int tempint=int(ans[0]-48);
        switch(tempint){
        case 1:
        case 6:
            break;
        case 2:
            continue;
        case 3:
            goto thirdyear;
        case 4:
            goto fourthyear;
        case 5:
            delete []chromosome;
            goto beginagain;
        default:
            break;
        }
    }

    return 0;
}
