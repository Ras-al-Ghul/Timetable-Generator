#include "fillcourse.h"



void print_chromosome(vector<elementOfChromosome*>* chromosome){
    vector<elementOfChromosome*> tempchromo=chromosome[0];
        for(int j=0;j<6;j++){
            for(int k=0;k<40;k++){
                if(tempchromo[j*40+k]->labornot==1){
                    cout<<tempchromo[j*40+k]->classlabname<<" "<<tempchromo[j*40+k]->batch1<<tempchromo[j*40+k]->batch2<<" ";//<<" "<<tempchromo[j*40+k]->teacher1<<" ";
                    k++;
                    cout<<tempchromo[j*40+k]->classlabname<<" "<<tempchromo[j*40+k]->batch1<<tempchromo[j*40+k]->batch2<<" ";//<<" "<<tempchromo[j*40+k]->teacher2<<" ";
                }
                else
                {
                    cout<<tempchromo[j*40+k]->classlabname<<" ";//<<tempchromo[j*40+k]->teacher1<<" "<<tempchromo[j*40+k]->teacher2<<" ";
                }

                if(k==6||k==13||k==20||k==27||k==34)
                    cout<<endl;
            }
            cout<<endl<<endl<<endl;
        }

}


void fillInHardcode(vector<int> &LabDS,vector<elementOfChromosome*>* chromosome,vector <Course*>* listofcourses,vector <Lab*>* listoflabs,\
                    vector <pair<string,pair<int,int> > * >* mathscourse,\
                    vector <pair<pair<string,string>,pair<int,int> > * >* coursehardcode,\
                  vector <pair<pair<string,string>,pair<pair<string,string>,pair<int,int> > >* >* labhardcode){

    vector<elementOfChromosome*> tempchromosome=chromosome[0];
    //filling in maths first
    vector <Course*> tempcourse=listofcourses[0];

    vector <pair<string,pair<int,int> > * > tempmathvect=mathscourse[0];
    tr(tempmathvect,it){
        int tempnum;
        if((*it)->first=="A")
            tempnum=((((*it)->second).first-1)*7)+(((*it)->second).second)-1;
        else if((*it)->first=="B")
            tempnum=((((*it)->second).first-1)*7)+((((*it)->second).second)-1)+40;
        else{
            //Have to add code for Probability course of sixth sem..
        }
        tempchromosome[tempnum]->section=(*it)->first;
        tempchromosome[tempnum]->classlabname="Maths";
        tempchromosome[tempnum]->mutables=0;
        tempchromosome[tempnum]->sem=3;
        tempchromosome[tempnum]->labornot=0;

        string tempstr=(*it)->first;
        tr(tempcourse,iter){
            char tempchar=(*iter)->get_char_section();
            string temps="";temps=temps+tempchar;
            if((*iter)->get_course_name()=="Maths"&&temps==tempstr){
                (*iter)->set_allocated(4);
                tempchromosome[tempnum]->teacher1=(*iter)->get_prof_name();
                break;
            }
        }
    }
    //filling in coursehardcode
    vector <pair<pair<string,string>,pair<int,int> > * > tempcourses=coursehardcode[0];
    tr(tempcourses,it){
        string semsec=((*it)->first).second;
        int tempnum,tn;
        int subnum;
        switch(int(semsec[0]-48)){
            case 3:subnum=3;break;
            case 5:subnum=4;break;
            case 7:subnum=5;break;
            case 4:
            case 6:
            case 8:break;
        }
        tn=int(semsec[0]-48-subnum);//Have to change for evensem..
        if(semsec[1]=='A')
            tempnum=((((*it)->second).first-1)*7)+((((*it)->second).second)-1)+(80*tn);
        else
            tempnum=((((*it)->second).first-1)*7)+((((*it)->second).second)-1)+(80*tn)+40;
        tempchromosome[tempnum]->section+=semsec[1];
        tempchromosome[tempnum]->classlabname=((*it)->first).first;
        tempchromosome[tempnum]->mutables=0;
        tempchromosome[tempnum]->sem+=semsec[0];
        tempchromosome[tempnum]->labornot=0;

        string tempstrcourse=((*it)->first).first;
        string tempstrsec="";tempstrsec+=semsec[1];
        tr(tempcourse,iter){
            char tempchar=(*iter)->get_char_section();
            string temps="";temps=temps+tempchar;
            if((*iter)->get_course_name()==tempstrcourse&&temps==tempstrsec){
                tempchromosome[tempnum]->teacher1=(*iter)->get_prof_name();
                (*iter)->set_allocated(((*iter)->get_allocated())+1);
                break;
            }
        }

    }
    //filling in labhardcode
    vector <Lab*> templabs=listoflabs[0];
    //if anything other than LD added then have to update batchcount..
    vector <pair<pair<string,string>,pair<pair<string,string>,pair<int,int> > >* > templabhard=labhardcode[0];
    tr(templabhard,it){
        string semsec=((*it)->first).second;
        int tempnum,tn;int tempnum2;
        int subnum;
        switch(int(semsec[0]-48)){
            case 3:subnum=3;break;
            case 5:subnum=4;break;
            case 7:subnum=5;break;
            case 4:
            case 6:
            case 8:break;
        }
        tn=int(semsec[0]-48-subnum);//Have to change for evensem..
        if(semsec[1]=='A')
            tempnum=((((*it)->second).second.first-1)*7)+((((*it)->second).second.second)-1)+(80*tn);
        else
            tempnum=((((*it)->second).second.first-1)*7)+((((*it)->second).second.second)-1)+(80*tn)+40;
        tempnum2=tempnum+1;
        tempchromosome[tempnum]->section+=semsec[1];tempchromosome[tempnum2]->section+=semsec[1];
        tempchromosome[tempnum]->classlabname=((*it)->first).first;tempchromosome[tempnum2]->classlabname=((*it)->first).first;
        tempchromosome[tempnum]->mutables=0;tempchromosome[tempnum2]->mutables=0;
        tempchromosome[tempnum]->sem+=semsec[0];tempchromosome[tempnum2]->sem+=semsec[0];
        tempchromosome[tempnum]->labornot=1;tempchromosome[tempnum2]->labornot=1;
        tempchromosome[tempnum]->batch1=(*it)->second.first.first;tempchromosome[tempnum2]->batch1=(*it)->second.first.first;
        tempchromosome[tempnum]->batch2=(*it)->second.first.second;tempchromosome[tempnum2]->batch2=(*it)->second.first.second;

        if(tempchromosome[tempnum]->classlabname!="Logic Design"){
            cout<<"doing here"<<endl;
            int temponum=((((*it)->second).second.first-1)*3)+(((((*it)->second).second.second)/2)-1);
            LabDS[temponum]+=2;//or +4
        }

        string tempstrlab=((*it)->first).first;
        tr(templabs,iter){
            string tempb1=(*iter)->get_batch1();string tempb2=(*iter)->get_batch2();
            if((*iter)->get_lab_name()==tempstrlab&&tempchromosome[tempnum]->batch1==tempb1&&tempchromosome[tempnum]->batch2==tempb2){
                tempchromosome[tempnum]->teacher1=(*iter)->get_prof_name1();tempchromosome[tempnum2]->teacher1=(*iter)->get_prof_name1();
                tempchromosome[tempnum]->teacher2=(*iter)->get_prof_name2();tempchromosome[tempnum2]->teacher2=(*iter)->get_prof_name2();
                (*iter)->set_allocated(1);
                break;
            }
        }
    }

    return;
}

void initializeToBlank(vector<elementOfChromosome*>* chromosome,vector<int> &LabDS){
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
    for(int i=0;i<17;i++)
        LabDS[i]=0;
    return;
}

void settozero(vector <Course*>* listofcourses,vector <Lab*>* listoflabs){
    vector <Course*> tempcourselist=listofcourses[0];
    tr(tempcourselist,it){
        (*it)->set_allocated(0);
    }
    vector <Lab*> templablist=listoflabs[0];
    tr(templablist,it){
        (*it)->set_allocated(0);
    }

    return;
}

int fillInChromosome(vector<int> &LabDS,vector<elementOfChromosome*>* chromosome,vector <Course*>* listofcourses,vector <Section*>* listofsections,vector <Lab*>* listoflabs,vector <Batch*>* listofbatches,\
                  vector <Semester*>* listofsemesters,vector <Professor*>* listofprofessors,vector <pair<string,pair<int,int> > * >* mathscourse,\
                  vector <pair<string,pair<int,int> > * >* teacherunav,vector <pair<pair<string,string>,pair<int,int> > * >* coursehardcode,\
                  vector <pair<pair<string,string>,pair<pair<string,string>,pair<int,int> > >* >* labhardcode){


        settozero(listofcourses,listoflabs);
        initializeToBlank(chromosome,LabDS);
        fillInHardcode(LabDS,chromosome,listofcourses,listoflabs,mathscourse,coursehardcode,labhardcode);
        int val=fillinlabs(LabDS,chromosome,listoflabs,listofbatches,teacherunav);

        return val;
}


int createChromosome(vector<elementOfChromosome*>* chromosome,vector<int> &LabDS,vector <Course*>* listofcourses,vector <Section*>* listofsections,vector <Lab*>* listoflabs,vector <Batch*>* listofbatches,\
                  vector <Semester*>* listofsemesters,vector <Professor*>* listofprofessors,vector <pair<string,pair<int,int> > * >* mathscourse,\
                  vector <pair<string,pair<int,int> > * >* teacherunav,vector <pair<pair<string,string>,pair<int,int> > * >* coursehardcode,\
                  vector <pair<pair<string,string>,pair<pair<string,string>,pair<int,int> > >* >* labhardcode){
    /*
    for(int i=0;i<2000;i++){

        vector<elementOfChromosome*>* chromosome=new vector<elementOfChromosome*>[240];
        vector<int> LabDS(17);
        int val=fillInChromosome(LabDS,chromosome,listofcourses,listofsections,listoflabs,listofbatches,listofsemesters,listofprofessors,mathscourse,teacherunav,coursehardcode,labhardcode);
        if(val!=1){
            delete []chromosome;
            continue;
        }
        else{
            print_chromosome(chromosome);
            return 1;
        }

    }
    */
    int val=fillInChromosome(LabDS,chromosome,listofcourses,listofsections,listoflabs,listofbatches,listofsemesters,listofprofessors,mathscourse,teacherunav,coursehardcode,labhardcode);
    return val;
}


