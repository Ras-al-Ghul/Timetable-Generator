class elementOfChromosome{
public:
    int labornot;//1 for lab 0 for not
    string teacher1,teacher2;
    int sem;
    string section;
    string batch1,batch2;
    string classlabname;
    int mutables;//1 if mutable 0 if not
    int crossoverrate,mutationrate;
public:
    elementOfChromosome(){}
};

int evaluate(vector<elementOfChromosome*>* chromosome){
    vector<elementOfChromosome*> tempchromosome=chromosome[0];

    for(int i=1;i<40;i+=2){
        if(i==5||i==12||i==19||i==26||i==33){
            i+=1;
            continue;
        }
        if(tempchromosome[i]->labornot==1&&tempchromosome[i+2]->labornot==1&&tempchromosome[i]->classlabname==tempchromosome[i+2]->classlabname)
            return 0;
    }//cout<<"pass1"<<endl;
    for(int i=41;i<80;i+=2){
        if(i==45||i==52||i==59||i==66||i==73){
            i+=1;
            continue;
        }
        if(tempchromosome[i]->labornot==1&&tempchromosome[i+2]->labornot==1&&tempchromosome[i]->classlabname==tempchromosome[i+2]->classlabname)
            return 0;
    }//cout<<"pass2"<<endl;
    for(int i=81;i<120;i+=2){
        if(i==85||i==92||i==99||i==106||i==113){
            i+=1;
            continue;
        }
        if(tempchromosome[i]->labornot==1&&tempchromosome[i+2]->labornot==1&&tempchromosome[i]->classlabname==tempchromosome[i+2]->classlabname)
            return 0;
    }//cout<<"pass3"<<endl;
    for(int i=121;i<160;i+=2){
        if(i==125||i==132||i==139||i==146||i==153){
            i+=1;
            continue;
        }
        if(tempchromosome[i]->labornot==1&&tempchromosome[i+2]->labornot==1&&tempchromosome[i]->classlabname==tempchromosome[i+2]->classlabname)
            return 0;
    }
    //cout<<"pass4"<<endl;
    for(int i=161;i<200;i+=2){
        if(i==165||i==172||i==179||i==186||i==193){
            i+=1;
            continue;
        }
        if(tempchromosome[i]->labornot==1&&tempchromosome[i+2]->labornot==1&&tempchromosome[i]->classlabname==tempchromosome[i+2]->classlabname)
            return 0;
    }//cout<<"pass5"<<endl;
    for(int i=201;i<240;i+=2){
        if(i==205||i==212||i==219||i==226||i==233){
            i+=1;
            continue;
        }
        if((i+2)==240)
            return 1;
        /*
        if((i+2)==240&&tempchromosome[i]->labornot==0){
            return 1;
        }
        */
        if(tempchromosome[i]->labornot==1&&tempchromosome[i+2]->labornot==1&&tempchromosome[i]->classlabname==tempchromosome[i+2]->classlabname)
            return 0;
    }cout<<"pass6"<<endl;
    return 1;
}



vector <int> randarr(2);

int findrand(int mins,int maxs){
    //doagain:
    int temp=((rand()%(maxs-mins+1))+mins);
    //if(find(randarr.begin(),randarr.end(),temp)!=randarr.end())
        //goto doagain;
    //else
        //randarr.erase(randarr.begin()+0);randarr.pb(temp);
        return temp;
}

//At a time max num of batches in lab is 5..
//Num of labs of a particular subject is one per day..
//Num of labs
int fillinlabs(vector<int> &LabDS,vector<elementOfChromosome*>* chromosome,vector <Lab*>* listoflabs,vector <Batch*>* listofbatches\
                ,vector <pair<string,pair<int,int> > * >* teacherunav){
    vector<elementOfChromosome*> tempchromosome=chromosome[0];
    vector <Lab*> templabs=listoflabs[0];
    vector <pair<string,pair<int,int> > * > tempteacher=teacherunav[0];

    int retrycount=0;

    tr(templabs,it){

        //for 4th and 6th sem

        while((*it)->get_allocated()==0&&(*it)->get_numperweek()==2&&((*it)->get_sem()==4||(*it)->get_sem()==6)){
            int counts=0;
            int olddayofweek=-1;
            while(counts<2){

                string prof1,prof2,prof3,prof4;
                prof1=(*it)->get_prof_name1();prof2=(*it)->get_prof_name2();
                prof3=(*(it+2))->get_prof_name1();prof4=(*(it+2))->get_prof_name2();
                string tempprof1="",tempprof2="",tempprof3="",tempprof4="";

                vvi tempprof1list,tempprof2list,tempprof3list,tempprof4list;

                tr(tempteacher,iters){
                    if(prof1==(*iters)->first){
                        tempprof1+=prof1;vi tempvec;tempvec.pb((*iters)->second.first);tempvec.pb((*iters)->second.second);
                        tempprof1list.pb(tempvec);
                    }
                    if(prof2==(*iters)->first){
                        tempprof2+=prof2;vi tempvec;tempvec.pb((*iters)->second.first);tempvec.pb((*iters)->second.second);
                        tempprof2list.pb(tempvec);
                    }
                    if(prof3==(*iters)->first){
                        tempprof3+=prof3;vi tempvec;tempvec.pb((*iters)->second.first);tempvec.pb((*iters)->second.second);
                        tempprof2list.pb(tempvec);
                    }
                    if(prof4==(*iters)->first){
                        tempprof4+=prof4;vi tempvec;tempvec.pb((*iters)->second.first);tempvec.pb((*iters)->second.second);
                        tempprof2list.pb(tempvec);
                    }
                }



                int sem=(*it)->get_sem(),subnum;
                switch(sem){
                    case 3:subnum=3;break;
                    case 5:subnum=4;break;
                    case 7:subnum=5;break;
                    case 4:subnum=4;break;
                    case 6:subnum=5;break;
                    case 8:subnum=6;break;
                }
                int tn=(sem-subnum);int dayofweek,hourofday=0;
                label:

                    dayofweek=findrand(1,6);
                    while(olddayofweek==dayofweek){
                        dayofweek=findrand(1,6);
                    }

                    if(dayofweek==6){
                        while((hourofday!=2&&hourofday!=4)){
                            hourofday=(findrand(2,4));
                        }
                    }
                    else{
                        while(hourofday!=2&&hourofday!=4&&hourofday!=6){
                            hourofday=(findrand(2,6));
                        }
                    }

                string temp=(*it)->get_batch1();int tempnum1,tempnum2;
                if(temp[0]=='A')
                    tempnum1=((dayofweek-1)*7)+(hourofday-1)+(80*tn);
                else
                    tempnum1=((dayofweek-1)*7)+(hourofday-1)+(80*tn)+40;
                tempnum2=tempnum1+1;

                if(tempchromosome[tempnum1]->classlabname=="nothing"&&tempchromosome[tempnum2]->classlabname=="nothing"){
                    if(LabDS[(((dayofweek-1)*3)+((hourofday/2)-1))]+4<6){

                        if(!tempprof1list.empty()){
                            tr(tempprof1list,tempi){
                                if(((*tempi)[0]==dayofweek&&(*tempi)[1]==hourofday)||((*tempi)[0]==dayofweek&&(*tempi)[1]==(hourofday+1))){
                                    retrycount++;if(retrycount>1000)return 0;goto label;
                                }
                            }
                        }
                        if(!tempprof2list.empty()){
                            tr(tempprof2list,tempi){
                                if(((*tempi)[0]==dayofweek&&(*tempi)[1]==hourofday)||((*tempi)[0]==dayofweek&&(*tempi)[1]==(hourofday+1))){
                                    retrycount++;if(retrycount>1000)return 0;goto label;
                                }
                            }
                        }
                        if(!tempprof3list.empty()){
                            tr(tempprof3list,tempi){
                                if(((*tempi)[0]==dayofweek&&(*tempi)[1]==hourofday)||((*tempi)[0]==dayofweek&&(*tempi)[1]==(hourofday+1))){
                                    retrycount++;if(retrycount>1000)return 0;goto label;
                                }
                            }
                        }
                        if(!tempprof4list.empty()){
                            tr(tempprof4list,tempi){
                                if(((*tempi)[0]==dayofweek&&(*tempi)[1]==hourofday)||((*tempi)[0]==dayofweek&&(*tempi)[1]==(hourofday+1))){
                                    retrycount++;if(retrycount>1000)return 0;goto label;
                                }
                            }
                        }
                        goto alright;

                       }
                    else
                        retrycount++;if(retrycount>1000)return 0;goto label;
                }
                else{
                    retrycount++;if(retrycount>1000)return 0;goto label;
                }

                alright:
                olddayofweek=dayofweek;

                tempchromosome[tempnum1]->section+=temp[0];tempchromosome[tempnum2]->section+=temp[0];
                tempchromosome[tempnum1]->classlabname=(*it)->get_lab_name();tempchromosome[tempnum2]->classlabname=(*(it+2))->get_lab_name();
                tempchromosome[tempnum1]->mutables=1;tempchromosome[tempnum2]->mutables=1;
                tempchromosome[tempnum1]->sem+=char(sem+48);tempchromosome[tempnum2]->sem+=char(sem+48);
                tempchromosome[tempnum1]->labornot=1;tempchromosome[tempnum2]->labornot=1;
                tempchromosome[tempnum1]->batch1=(*it)->get_batch1();tempchromosome[tempnum2]->batch1=(*(it+2))->get_batch1();
                tempchromosome[tempnum1]->batch2=(*it)->get_batch2();tempchromosome[tempnum2]->batch2=(*(it+2))->get_batch2();
                tempchromosome[tempnum1]->teacher1=(*it)->get_prof_name1();tempchromosome[tempnum2]->teacher1=(*(it+2))->get_prof_name1();
                tempchromosome[tempnum1]->teacher2=(*it)->get_prof_name2();tempchromosome[tempnum2]->teacher2=(*(it+2))->get_prof_name2();
                LabDS[(((dayofweek-1)*3)+((hourofday/2)-1))]+=4;
                //cout<<"LabDS is set by "<<(((dayofweek-1)*3)+((hourofday/2)-1))<<tempchromosome[tempnum1]->classlabname<<" "<<tempchromosome[tempnum1]->batch1\
                <<" "<<tempchromosome[tempnum2]->classlabname<<tempchromosome[tempnum2]->batch2<<endl;
                if(counts==1){
                    (*it)->set_allocated(1);
                    (*(it+2))->set_allocated(1);
                }
                counts++;
            }
        }
    }
        //for 4th sem


    retrycount=0;
    int olddayofweek=-1;
    tr(templabs,it){

        while((*it)->get_allocated()==0&&(*it)->get_numperweek()==1&&((*it)->get_sem()==4)){
            string prof1,prof2;
            prof1=(*it)->get_prof_name1();prof2=(*it)->get_prof_name2();
            string tempprof1="",tempprof2="";
            vvi tempprof1list,tempprof2list;

            tr(tempteacher,iters){
                if(prof1==(*iters)->first){
                    tempprof1+=prof1;vi tempvec;tempvec.pb((*iters)->second.first);tempvec.pb((*iters)->second.second);
                    tempprof1list.pb(tempvec);
                }
                if(prof2==(*iters)->first){
                    tempprof2+=prof2;vi tempvec;tempvec.pb((*iters)->second.first);tempvec.pb((*iters)->second.second);
                    tempprof2list.pb(tempvec);
                }
            }

            int sem=(*it)->get_sem(),subnum;
                switch(sem){
                    case 3:subnum=3;break;
                    case 5:subnum=4;break;
                    case 7:subnum=5;break;
                    case 4:subnum=4;break;
                    case 6:subnum=5;break;
                    case 8:subnum=6;break;
                }
                int tn=(sem-subnum);int dayofweek,hourofday=0;
                labels:

                    dayofweek=findrand(1,6);

                    if(dayofweek==6){
                        while((/*hourofday!=2&&*/hourofday!=4)){
                            hourofday=(findrand(2,4));
                        }
                    }
                    else{
                        while(/*hourofday!=2&&hourofday!=4&&*/hourofday!=6){
                            hourofday=(findrand(2,6));
                        }
                    }

                string temp=(*it)->get_batch1();int tempnum1,tempnum2;
                if(temp[0]=='A')
                    tempnum1=((dayofweek-1)*7)+(hourofday-1)+(80*tn);
                else
                    tempnum1=((dayofweek-1)*7)+(hourofday-1)+(80*tn)+40;
                tempnum2=tempnum1+1;

                for(int i=((dayofweek-1)*7)+(hourofday-1);i<240;i+=40){
                    if(i!=tempnum1){
                        if(tempchromosome[i]->teacher1==prof1||tempchromosome[i]->teacher2==prof1||\
                           tempchromosome[i]->teacher1==prof2||tempchromosome[i]->teacher2==prof2){
                            retrycount++;if(retrycount>500)return 0;goto labels;
                        }
                        if(tempchromosome[i+1]->teacher1==prof1||tempchromosome[i+1]->teacher2==prof1||\
                           tempchromosome[i+1]->teacher1==prof2||tempchromosome[i+1]->teacher2==prof2){
                            retrycount++;if(retrycount>500)return 0;goto labels;
                        }
                    }
                }


                    if(LabDS[(((dayofweek-1)*3)+((hourofday/2)-1))]+2<7&&tempchromosome[tempnum1]->batch1!=(*it)->get_batch1()&&tempchromosome[tempnum1]->batch1!=(*it)->get_batch2()\
                       &&tempchromosome[tempnum1]->labornot!=0&&tempchromosome[tempnum2]->labornot!=0\
                       &&tempchromosome[tempnum2]->batch1!=(*it)->get_batch1()&&tempchromosome[tempnum2]->batch1!=(*it)->get_batch2()){

                        if(!tempprof1list.empty()){
                            tr(tempprof1list,tempi){
                                if(((*tempi)[0]==dayofweek&&(*tempi)[1]==hourofday)||((*tempi)[0]==dayofweek&&(*tempi)[1]==(hourofday+1))){
                                    retrycount++;if(retrycount>500)return 0;goto labels;
                                }
                            }
                        }
                        if(!tempprof2list.empty()){
                            tr(tempprof2list,tempi){
                                if(((*tempi)[0]==dayofweek&&(*tempi)[1]==hourofday)||((*tempi)[0]==dayofweek&&(*tempi)[1]==(hourofday+1))){
                                    retrycount++;if(retrycount>500)return 0;goto labels;
                                }
                            }
                        }
                        goto alrights;

                       }
                    else{
                        retrycount++;if(retrycount>500)return 0;goto labels;
                    }

                alrights:
                    if(temp[1]==1){
                    olddayofweek==dayofweek;
                }
                else
                    if(olddayofweek==dayofweek){
                        retrycount++;if(retrycount>500)return 0;goto labels;
                    }
                tempchromosome[tempnum1]->section+=temp[0];tempchromosome[tempnum2]->section+=temp[0];
                tempchromosome[tempnum1]->classlabname=(*it)->get_lab_name();tempchromosome[tempnum2]->classlabname=(*it)->get_lab_name();
                tempchromosome[tempnum1]->mutables=1;tempchromosome[tempnum2]->mutables=1;
                tempchromosome[tempnum1]->sem+=char(sem+48);tempchromosome[tempnum2]->sem+=char(sem+48);
                tempchromosome[tempnum1]->labornot=1;tempchromosome[tempnum2]->labornot=1;
                tempchromosome[tempnum1]->batch1=(*it)->get_batch1();tempchromosome[tempnum2]->batch1=(*it)->get_batch1();
                tempchromosome[tempnum1]->batch2=(*it)->get_batch2();tempchromosome[tempnum2]->batch2=(*it)->get_batch2();
                tempchromosome[tempnum1]->teacher1=(*it)->get_prof_name1();tempchromosome[tempnum2]->teacher1=(*it)->get_prof_name1();
                tempchromosome[tempnum1]->teacher2=(*it)->get_prof_name2();tempchromosome[tempnum2]->teacher2=(*it)->get_prof_name2();
                LabDS[(((dayofweek-1)*3)+((hourofday/2)-1))]+=2;
                (*it)->set_allocated(1);
        }


    }

    int twocount=0;
    for(int i=0;i<17;i++){
        if(LabDS[i]==0)
            return 0;
        if(LabDS[i]==2)//&&LabDS[5]==4&&LabDS[8]==6&&LabDS[2]==6&&LabDS[14]==4)
            twocount++;
    }
    if(twocount==0)
        return 0;

    if(evaluate(chromosome)!=1)
        return 0;

    cout<<endl<<"The lab batch strength is"<<endl;
    for(int i=0;i<17;i++){
        if(i%3==0)
            cout<<endl<<LabDS[i];
        else
            cout<<" "<<LabDS[i];
    }
    cout<<endl<<endl;
    //cout<<"The retry count is "<<retrycount<<endl;
    return 1;
}
