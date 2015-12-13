#include "fillrandom.h"


int evaluate1(vector<elementOfChromosome>& tempchromosome){


    for(int i=0,j=40;i<40&&j<80;i+=7,j+=7){
        int ends1,ends2;
        if(i==35)
            ends1=i+4;
        else
            ends1=i+6;
        if(j==75)
            ends2=j+4;
        else
            ends2=j+6;
        while(true){
            if(tempchromosome[ends1].classlabname!="nothing")
                break;
            ends1--;
        }
        while(true){
            if(tempchromosome[ends2].classlabname!="nothing")
                break;
            ends2--;
        }
        int starts1=i,starts2=j;
        while(true){
            if(tempchromosome[starts1].classlabname!="nothing")
                break;
            starts1++;
        }
        while(true){
            if(tempchromosome[starts2].classlabname!="nothing")
                break;
            starts2++;
        }
        for(int k=starts1;k<=ends1;k++){
            if(tempchromosome[k].classlabname=="nothing"){

                return 0;
            }
        }
        for(int k=starts2;k<=ends2;k++){
            if(tempchromosome[k].classlabname=="nothing"){

                return 0;
            }
        }
    }


    return 1;

}

int evaluate2(vector<elementOfChromosome>& tempchromosome){
    for(int i=80,j=120;i<120&&j<160;i+=7,j+=7){
        int ends1,ends2;
        if(i==115)
            ends1=i+4;
        else
            ends1=i+6;
        if(j==155)
            ends2=j+4;
        else
            ends2=j+6;
        while(true){
            if(tempchromosome[ends1].classlabname!="nothing")
                break;
            ends1--;
        }
        while(true){
            if(tempchromosome[ends2].classlabname!="nothing")
                break;
            ends2--;
        }
        int starts1=i,starts2=j;
        while(true){
            if(tempchromosome[starts1].classlabname!="nothing")
                break;
            starts1++;
        }
        while(true){
            if(tempchromosome[starts2].classlabname!="nothing")
                break;
            starts2++;
        }
        for(int k=starts1;k<=ends1;k++){
            if(tempchromosome[k].classlabname=="nothing")
                return 0;
        }
        for(int k=starts2;k<=ends2;k++){
            if(tempchromosome[k].classlabname=="nothing")
                return 0;
        }
    }

    return 1;

}

int evaluate3(vector<elementOfChromosome>& tempchromosome){
    for(int i=160,j=200;i<200&&j<240;i+=7,j+=7){
        int ends1,ends2;
        if(i==195)
            ends1=i+4;
        else
            ends1=i+6;
        if(j==235)
            ends2=j+4;
        else
            ends2=j+6;
        while(true){
            if(tempchromosome[ends1].classlabname!="nothing")
                break;
            ends1--;
        }
        while(true){
            if(tempchromosome[ends2].classlabname!="nothing")
                break;
            ends2--;
        }
        int starts1=i,starts2=j;
        while(true){
            if(tempchromosome[starts1].classlabname!="nothing")
                break;
            starts1++;
        }
        while(true){
            if(tempchromosome[starts2].classlabname!="nothing")
                break;
            starts2++;
        }
        for(int k=starts1;k<=ends1;k++){
            if(tempchromosome[k].classlabname=="nothing")
                return 0;
        }
        for(int k=starts2;k<=ends2;k++){
            if(tempchromosome[k].classlabname=="nothing")
                return 0;
        }
    }

    return 1;

}


int fillin4thyear(vector<elementOfChromosome>& tempchromosome,vector <Course>& tempcourses,vector <Batch*>* listofbatches\
                ,vector <pair<string,pair<int,int> > * >* teacherunav){
    vector <pair<string,pair<int,int> > * > tempteacher=teacherunav[0];
    //7th sem

    int retrycount=0;
    typeof(tempcourses.begin()) sub1,sub2;
    tr(tempcourses,it){
        if((*it).get_allocated()<4&&(*it).get_numperweek()==4&&((*it).get_sem()==7)&&(*it).get_course_name()=="Cryptography"){
            sub1=it;
        }
        if((*it).get_allocated()<4&&(*it).get_numperweek()==4&&((*it).get_sem()==7)&&(*it).get_course_name()=="Data Mining"){
            sub2=it;
        }
    }


        while((*sub1).get_allocated()<4){
            string prof1,prof2;
            prof1=(*sub1).get_prof_name();string tempprof1="";prof2=(*sub2).get_prof_name();string tempprof2="";
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

            int sem=(*sub1).get_sem(),subnum;
        switch(sem){
            case 3:subnum=3;break;
            case 5:subnum=4;break;
            case 7:subnum=5;break;
            case 4:
            case 6:
            case 8:break;
        }
        int tn=(sem-subnum);int dayofweek,hourofday=0;

        labelss:

                    dayofweek=findrand(1,6);


                    if(dayofweek==6){
                            hourofday=(findrand(1,5));
                    }
                    else{
                            hourofday=(findrand(1,7));
                    }

                    char sec=(*sub1).get_char_section();int tempnum1,tempnum2;
                    if(sec=='A'){
                        tempnum1=((dayofweek-1)*7)+(hourofday-1)+(80*tn);
                        tempnum2=((dayofweek-1)*7)+(hourofday-1)+(80*tn)+40;
                    }

                    if(hourofday!=1){
                        int starts=tempnum1-hourofday+1;
                        while(starts<tempnum1){
                            if(tempchromosome[starts].labornot==0&&tempchromosome[starts].classlabname==(*sub1).get_course_name()){
                                goto labelss;
                            }
                            starts++;
                        }
                    }
                    if(dayofweek!=6){
                        int starts;
                        if(hourofday!=7){
                            starts=tempnum1+1;
                            while(starts<=(tempnum1+7-hourofday)){
                                if(tempchromosome[starts].labornot==0&&tempchromosome[starts].classlabname==(*sub1).get_course_name()){
                                    goto labelss;
                                }
                                starts++;
                            }
                        }
                    }
                    else{
                        int starts;
                        if(hourofday!=5){
                            starts=tempnum1+1;
                            while(starts<=(tempnum1+5-hourofday)){
                                if(tempchromosome[starts].labornot==0&&tempchromosome[starts].classlabname==(*sub1).get_course_name()){
                                    goto labelss;
                                }
                                starts++;
                            }
                        }
                    }

                    for(int i=((dayofweek-1)*7)+(hourofday-1);i<240;i+=40){
                        if(i!=tempnum1){
                            if(tempchromosome[i].teacher1==prof1||tempchromosome[i].teacher2==prof1\
                               ||tempchromosome[i].teacher1==prof2||tempchromosome[i].teacher2==prof2){
                                goto labelss;
                            }
                        }
                    }

                    //cout<<"pass first";
                    if(hourofday==1&&(tempchromosome[tempnum1+1].classlabname!="nothing"||tempchromosome[tempnum2+1].classlabname!="nothing")){
                        if(tempchromosome[tempnum1+1].labornot==1||tempchromosome[tempnum2+1].labornot==1){
                            goto labelss;
                        }
                    }
                    else if(hourofday==1&&(tempchromosome[tempnum1+1].classlabname=="nothing"||tempchromosome[tempnum2+1].classlabname=="nothing")){
                        goto labelss;
                    }
                    /*
                    //cout<<"pass second";
                    if((dayofweek!=6&&hourofday!=7&&hourofday!=1)||(dayofweek==6&&hourofday!=5&&hourofday!=1)){
                        if((tempchromosome[tempnum1+1].classlabname=="nothing"&&tempchromosome[tempnum1-1].classlabname=="nothing")\
                        ||(tempchromosome[tempnum2+1].classlabname=="nothing"&&tempchromosome[tempnum2-1].classlabname=="nothing")){
                            goto labelss;
                        }
                    }
                    //cout<<"pass third";
                    if((dayofweek!=6&&hourofday==7)||(dayofweek==6&&hourofday==5)){
                        if((tempchromosome[tempnum1-1].classlabname=="nothing")\
                        ||(tempchromosome[tempnum2-1].classlabname=="nothing")){
                            goto labelss;
                        }
                    }
                    //cout<<"pass fourth";
                    */
                    if(tempchromosome[tempnum1].classlabname=="nothing"&&tempchromosome[tempnum2].classlabname=="nothing"){
                        if(!tempprof1list.empty()){
                            tr(tempprof1list,tempi){
                                if(((*tempi)[0]==dayofweek&&(*tempi)[1]==hourofday)/*||((*tempi)[0]==dayofweek&&(*tempi)[1]==(hourofday+1))*/){
                                    goto labelss;
                                }
                            }
                        }
                        if(!tempprof2list.empty()){
                                tr(tempprof2list,tempi){
                                    if(((*tempi)[0]==dayofweek&&(*tempi)[1]==hourofday)/*||((*tempi)[0]==dayofweek&&(*tempi)[1]==(hourofday+1))*/){
                                        goto labelss;
                                    }
                                }
                        }

                    }
                    else{
                        goto labelss;
                    }
                    //cout<<"pass fifth";
                    tempchromosome[tempnum1].section+=sec;tempchromosome[tempnum2].section+=sec;
                    tempchromosome[tempnum1].classlabname=(*sub1).get_course_name();tempchromosome[tempnum2].classlabname=(*sub2).get_course_name();
                    tempchromosome[tempnum1].mutables=1;tempchromosome[tempnum2].mutables=1;
                    tempchromosome[tempnum1].sem+=char(sem+48);tempchromosome[tempnum2].sem+=char(sem+48);
                    tempchromosome[tempnum1].labornot=0;tempchromosome[tempnum2].labornot=0;
                    tempchromosome[tempnum1].teacher1=(*sub1).get_prof_name();tempchromosome[tempnum2].teacher1=(*sub2).get_prof_name();

                    (*sub1).set_allocated(((*sub1).get_allocated())+1);(*sub2).set_allocated(((*sub2).get_allocated())+1);
                    //cout<<(*sub1).get_allocated();
        }
    //cout<<"Here";
    //Next pair
    tr(tempcourses,it){
        if((*it).get_allocated()<4&&(*it).get_numperweek()==4&&((*it).get_sem()==7)&&(*it).get_course_name()=="Mobile App"){
            sub1=it;
        }
        if((*it).get_allocated()<4&&(*it).get_numperweek()==4&&((*it).get_sem()==7)&&(*it).get_course_name()=="Management Info Systems"){
            sub2=it;
        }
    }


        while((*sub1).get_allocated()<4){
            string prof1,prof2;
            prof1=(*sub1).get_prof_name();string tempprof1="";prof2=(*sub2).get_prof_name();string tempprof2="";
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

            int sem=(*sub1).get_sem(),subnum;
        switch(sem){
            case 3:subnum=3;break;
            case 5:subnum=4;break;
            case 7:subnum=5;break;
            case 4:
            case 6:
            case 8:break;
        }
        int tn=(sem-subnum);int dayofweek,hourofday=0;

        labelsss:

                    dayofweek=findrand(1,6);


                    if(dayofweek==6){
                            hourofday=(findrand(1,5));
                    }
                    else{
                            hourofday=(findrand(1,7));
                    }

                    char sec=(*sub1).get_char_section();int tempnum1,tempnum2;
                    if(sec=='A'){
                        tempnum1=((dayofweek-1)*7)+(hourofday-1)+(80*tn);
                        tempnum2=((dayofweek-1)*7)+(hourofday-1)+(80*tn)+40;
                    }

                    if(hourofday!=1){
                        int starts=tempnum1-hourofday+1;
                        while(starts<tempnum1){
                            if(tempchromosome[starts].labornot==0&&tempchromosome[starts].classlabname==(*sub1).get_course_name()){
                                goto labelsss;
                            }
                            starts++;
                        }
                    }
                    if(dayofweek!=6){
                        int starts;
                        if(hourofday!=7){
                            starts=tempnum1+1;
                            while(starts<=(tempnum1+7-hourofday)){
                                if(tempchromosome[starts].labornot==0&&tempchromosome[starts].classlabname==(*sub1).get_course_name()){
                                    goto labelsss;
                                }
                                starts++;
                            }
                        }
                    }
                    else{
                        int starts;
                        if(hourofday!=5){
                            starts=tempnum1+1;
                            while(starts<=(tempnum1+5-hourofday)){
                                if(tempchromosome[starts].labornot==0&&tempchromosome[starts].classlabname==(*sub1).get_course_name()){
                                    goto labelsss;
                                }
                                starts++;
                            }
                        }
                    }

                    for(int i=((dayofweek-1)*7)+(hourofday-1);i<240;i+=40){
                        if(i!=tempnum1){
                            if(tempchromosome[i].teacher1==prof1||tempchromosome[i].teacher2==prof1\
                               ||tempchromosome[i].teacher1==prof2||tempchromosome[i].teacher2==prof2){
                                goto labelsss;
                            }
                        }
                    }

                    //cout<<"pass first";
                    if(hourofday==1&&(tempchromosome[tempnum1+1].classlabname!="nothing"||tempchromosome[tempnum2+1].classlabname!="nothing")){
                        if(tempchromosome[tempnum1+1].labornot==1||tempchromosome[tempnum2+1].labornot==1){
                            goto labelsss;
                        }
                    }
                    else if(hourofday==1&&(tempchromosome[tempnum1+1].classlabname=="nothing"||tempchromosome[tempnum2+1].classlabname=="nothing")){
                        goto labelsss;
                    }

                    //cout<<"pass second";
                    if((dayofweek!=6&&hourofday!=7&&hourofday!=1)||(dayofweek==6&&hourofday!=5&&hourofday!=1)){
                        if((tempchromosome[tempnum1+1].classlabname=="nothing"&&tempchromosome[tempnum1-1].classlabname=="nothing")\
                        ||(tempchromosome[tempnum2+1].classlabname=="nothing"&&tempchromosome[tempnum2-1].classlabname=="nothing")){
                            goto labelsss;
                        }
                    }
                    //cout<<"pass third";
                    if((dayofweek!=6&&hourofday==7)||(dayofweek==6&&hourofday==5)){
                        if((tempchromosome[tempnum1-1].classlabname=="nothing")\
                        ||(tempchromosome[tempnum2-1].classlabname=="nothing")){
                            goto labelsss;
                        }
                    }
                    //cout<<"pass fourth";

                    if(tempchromosome[tempnum1].classlabname=="nothing"&&tempchromosome[tempnum2].classlabname=="nothing"){
                        if(!tempprof1list.empty()){
                            tr(tempprof1list,tempi){
                                if(((*tempi)[0]==dayofweek&&(*tempi)[1]==hourofday)/*||((*tempi)[0]==dayofweek&&(*tempi)[1]==(hourofday+1))*/){
                                    goto labelsss;
                                }
                            }
                        }
                        if(!tempprof2list.empty()){
                                tr(tempprof2list,tempi){
                                    if(((*tempi)[0]==dayofweek&&(*tempi)[1]==hourofday)/*||((*tempi)[0]==dayofweek&&(*tempi)[1]==(hourofday+1))*/){
                                        goto labelsss;
                                    }
                                }
                        }

                    }
                    else{
                        goto labelsss;
                    }
                    //cout<<"pass fifth";
                    tempchromosome[tempnum1].section+=sec;tempchromosome[tempnum2].section+=sec;
                    tempchromosome[tempnum1].classlabname=(*sub1).get_course_name();tempchromosome[tempnum2].classlabname=(*sub2).get_course_name();
                    tempchromosome[tempnum1].mutables=1;tempchromosome[tempnum2].mutables=1;
                    tempchromosome[tempnum1].sem+=char(sem+48);tempchromosome[tempnum2].sem+=char(sem+48);
                    tempchromosome[tempnum1].labornot=0;tempchromosome[tempnum2].labornot=0;
                    tempchromosome[tempnum1].teacher1=(*sub1).get_prof_name();tempchromosome[tempnum2].teacher1=(*sub2).get_prof_name();

                    (*sub1).set_allocated(((*sub1).get_allocated())+1);(*sub2).set_allocated(((*sub2).get_allocated())+1);
                    //cout<<(*sub1).get_allocated();
        }
    retrycount=0;
    tr(tempcourses,it){
        while((*it).get_allocated()<4&&(*it).get_numperweek()==4&&((*it).get_sem()==7)&&(*it).get_course_name()!="Project 1"){
            int counts=0;
            while(counts<(4-((*it).get_allocated()))){
                    string prof;
                    prof=(*it).get_prof_name();string tempprof="";
                    vvi tempproflist;
                    tr(tempteacher,iters){
                        if(prof==(*iters)->first){
                            tempprof+=prof;vi tempvec;tempvec.pb((*iters)->second.first);tempvec.pb((*iters)->second.second);
                            tempproflist.pb(tempvec);
                        }
                    }

                    int sem=(*it).get_sem(),subnum;
                    switch(sem){
                        case 3:subnum=3;break;
                        case 5:subnum=4;break;
                        case 7:subnum=5;break;
                        case 4:
                        case 6:
                        case 8:break;
                    }
                    int tn=(sem-subnum);int dayofweek,hourofday=0;

                    labels:

                    dayofweek=findrand(1,6);


                    if(dayofweek==6){
                            hourofday=(findrand(1,5));
                    }
                    else{
                            hourofday=(findrand(1,7));
                    }

                    char sec=(*it).get_char_section();int tempnum;
                    if(sec=='A')
                        tempnum=((dayofweek-1)*7)+(hourofday-1)+(80*tn);
                    else
                        tempnum=((dayofweek-1)*7)+(hourofday-1)+(80*tn)+40;

                    if(hourofday!=1){
                        int starts=tempnum-hourofday+1;
                        while(starts<tempnum){
                            if(tempchromosome[starts].labornot==0&&tempchromosome[starts].classlabname==(*it).get_course_name()){
                                retrycount++;if(retrycount>1000)return 0;goto labels;
                            }
                            starts++;
                        }
                    }
                    if(dayofweek!=6){
                        int starts;
                        if(hourofday!=7){
                            starts=tempnum+1;
                            while(starts<=(tempnum+7-hourofday)){
                                if(tempchromosome[starts].labornot==0&&tempchromosome[starts].classlabname==(*it).get_course_name()){
                                    retrycount++;if(retrycount>1000)return 0;goto labels;
                                }
                                starts++;
                            }
                        }
                    }
                    else{
                        int starts;
                        if(hourofday!=5){
                            starts=tempnum+1;
                            while(starts<=(tempnum+5-hourofday)){
                                if(tempchromosome[starts].labornot==0&&tempchromosome[starts].classlabname==(*it).get_course_name()){
                                    retrycount++;if(retrycount>1000)return 0;goto labels;
                                }
                                starts++;
                            }
                        }
                    }

                    for(int i=((dayofweek-1)*7)+(hourofday-1);i<240;i+=40){
                        if(i!=tempnum){
                            if(tempchromosome[i].teacher1==prof||tempchromosome[i].teacher2==prof){
                                retrycount++;if(retrycount>500)return 0;goto labels;
                            }
                        }
                    }

                    if(hourofday==1&&(tempchromosome[tempnum+1].classlabname!="nothing")){
                        if(tempchromosome[tempnum+1].labornot==1){
                            goto labels;
                        }
                    }
                    else if(hourofday==1&&(tempchromosome[tempnum+1].classlabname=="nothing")){
                        goto labels;
                    }

                    if((dayofweek!=6&&hourofday!=7&&hourofday!=1)||(dayofweek==6&&hourofday!=5&&hourofday!=1)){
                        if(tempchromosome[tempnum+1].classlabname=="nothing"&&tempchromosome[tempnum-1].classlabname=="nothing"){
                            goto labels;
                        }
                    }

                    if((dayofweek!=6&&hourofday==7)||(dayofweek==6&&hourofday==5)){
                        if((tempchromosome[tempnum-1].classlabname=="nothing")){
                            goto labels;
                        }
                    }

                    if(tempchromosome[tempnum].classlabname=="nothing"){
                        if(!tempproflist.empty()){
                            tr(tempproflist,tempi){
                                if(((*tempi)[0]==dayofweek&&(*tempi)[1]==hourofday)||((*tempi)[0]==dayofweek&&(*tempi)[1]==(hourofday+1))){
                                    retrycount++;if(retrycount>1000)return 0;goto labels;
                                }
                            }
                        }
                    }
                    else{
                        retrycount++;if(retrycount>1000)return 0;goto labels;
                    }

                    //olddayofweek[odwcount++]=dayofweek;

                    tempchromosome[tempnum].section+=sec;
                    tempchromosome[tempnum].classlabname=(*it).get_course_name();
                    tempchromosome[tempnum].mutables=1;
                    tempchromosome[tempnum].sem+=char(sem+48);
                    tempchromosome[tempnum].labornot=0;
                    tempchromosome[tempnum].teacher1=(*it).get_prof_name();


                        (*it).set_allocated(((*it).get_allocated())+1);
                    counts++;
            }
        }
    }

    retrycount=0;
    tr(tempcourses,it){
        while((*it).get_allocated()<3&&(*it).get_numperweek()==3&&((*it).get_sem()==7)){
            int counts=0;
            while(counts<(3-((*it).get_allocated()))){
                    string prof;
                    prof=(*it).get_prof_name();string tempprof="";
                    vvi tempproflist;
                    tr(tempteacher,iters){
                        if(prof==(*iters)->first){
                            tempprof+=prof;vi tempvec;tempvec.pb((*iters)->second.first);tempvec.pb((*iters)->second.second);
                            tempproflist.pb(tempvec);
                        }
                    }

                    int sem=(*it).get_sem(),subnum;
                    switch(sem){
                        case 3:subnum=3;break;
                        case 5:subnum=4;break;
                        case 7:subnum=5;break;
                        case 4:
                        case 6:
                        case 8:break;
                    }
                    int tn=(sem-subnum);int dayofweek,hourofday=0;

                    labe:

                    dayofweek=findrand(1,6);


                    if(dayofweek==6){
                            hourofday=(findrand(1,5));
                    }
                    else{
                            hourofday=(findrand(1,7));
                    }

                    char sec=(*it).get_char_section();int tempnum;
                    if(sec=='A')
                        tempnum=((dayofweek-1)*7)+(hourofday-1)+(80*tn);
                    else
                        tempnum=((dayofweek-1)*7)+(hourofday-1)+(80*tn)+40;

                    if(hourofday!=1){
                        int starts=tempnum-hourofday+1;
                        while(starts<tempnum){
                            if(tempchromosome[starts].labornot==0&&tempchromosome[starts].classlabname==(*it).get_course_name()){
                                retrycount++;if(retrycount>1000)return 0;goto labe;
                            }
                            starts++;
                        }
                    }
                    if(dayofweek!=6){
                        int starts;
                        if(hourofday!=7){
                            starts=tempnum+1;
                            while(starts<=(tempnum+7-hourofday)){
                                if(tempchromosome[starts].labornot==0&&tempchromosome[starts].classlabname==(*it).get_course_name()){
                                    retrycount++;if(retrycount>1000)return 0;goto labe;
                                }
                                starts++;
                            }
                        }
                    }
                    else{
                        int starts;
                        if(hourofday!=5){
                            starts=tempnum+1;
                            while(starts<=(tempnum+5-hourofday)){
                                if(tempchromosome[starts].labornot==0&&tempchromosome[starts].classlabname==(*it).get_course_name()){
                                    retrycount++;if(retrycount>1000)return 0;goto labe;
                                }
                                starts++;
                            }
                        }
                    }

                    for(int i=((dayofweek-1)*7)+(hourofday-1);i<240;i+=40){
                        if(i!=tempnum){
                            if(tempchromosome[i].teacher1==prof||tempchromosome[i].teacher2==prof){
                                retrycount++;if(retrycount>500)return 0;goto labe;
                            }
                        }
                    }

                    if(hourofday==1&&(tempchromosome[tempnum+1].classlabname!="nothing")){
                        if(tempchromosome[tempnum+1].labornot==1){
                            retrycount++;if(retrycount>1000)return 0;goto labe;
                        }
                    }
                    else if(hourofday==1&&(tempchromosome[tempnum+1].classlabname=="nothing")){
                        retrycount++;if(retrycount>1000)return 0;goto labe;
                    }

                    if((dayofweek!=6&&hourofday!=7&&hourofday!=1)||(dayofweek==6&&hourofday!=5&&hourofday!=1)){
                        if(tempchromosome[tempnum+1].classlabname=="nothing"&&tempchromosome[tempnum-1].classlabname=="nothing"){
                            retrycount++;if(retrycount>1000)return 0;goto labe;
                        }
                    }

                    if((dayofweek!=6&&hourofday==7)||(dayofweek==6&&hourofday==5)){
                        if((tempchromosome[tempnum-1].classlabname=="nothing")){
                            retrycount++;if(retrycount>1000)return 0;goto labe;
                        }
                    }

                    if(tempchromosome[tempnum].classlabname=="nothing"){
                        if(!tempproflist.empty()){
                            tr(tempproflist,tempi){
                                if(((*tempi)[0]==dayofweek&&(*tempi)[1]==hourofday)||((*tempi)[0]==dayofweek&&(*tempi)[1]==(hourofday+1))){
                                    retrycount++;if(retrycount>1000)return 0;goto labe;
                                }
                            }
                        }
                    }
                    else{
                        retrycount++;if(retrycount>1000)return 0;goto labe;
                    }

                    //olddayofweek[odwcount++]=dayofweek;

                    tempchromosome[tempnum].section+=sec;
                    tempchromosome[tempnum].classlabname=(*it).get_course_name();
                    tempchromosome[tempnum].mutables=1;
                    tempchromosome[tempnum].sem+=char(sem+48);
                    tempchromosome[tempnum].labornot=0;
                    tempchromosome[tempnum].teacher1=(*it).get_prof_name();


                        (*it).set_allocated(((*it).get_allocated())+1);
                    counts++;
            }
        }
    }

    if(evaluate3(tempchromosome)!=1)
        return 0;

    return 1;
}

int fillin3rdyear(vector<elementOfChromosome>& tempchromosome,vector <Course>& tempcourses,vector <Batch*>* listofbatches\
                ,vector <pair<string,pair<int,int> > * >* teacherunav){
    vector <pair<string,pair<int,int> > * > tempteacher=teacherunav[0];
    //5th sem

    int retrycount=0;
    tr(tempcourses,it){
        while((*it).get_allocated()<4&&(*it).get_numperweek()==4&&((*it).get_sem()==5)){
            int counts=0;
            while(counts<(4-((*it).get_allocated()))){
                    string prof;
                    prof=(*it).get_prof_name();string tempprof="";
                    vvi tempproflist;
                    tr(tempteacher,iters){
                        if(prof==(*iters)->first){
                            tempprof+=prof;vi tempvec;tempvec.pb((*iters)->second.first);tempvec.pb((*iters)->second.second);
                            tempproflist.pb(tempvec);
                        }
                    }

                    int sem=(*it).get_sem(),subnum;
                    switch(sem){
                        case 3:subnum=3;break;
                        case 5:subnum=4;break;
                        case 7:subnum=5;break;
                        case 4:
                        case 6:
                        case 8:break;
                    }
                    int tn=(sem-subnum);int dayofweek,hourofday=0;

                    labels:

                    dayofweek=findrand(1,6);


                    if(dayofweek==6){
                            hourofday=(findrand(1,5));
                    }
                    else{
                            hourofday=(findrand(1,7));
                    }

                    char sec=(*it).get_char_section();int tempnum;
                    if(sec=='A')
                        tempnum=((dayofweek-1)*7)+(hourofday-1)+(80*tn);
                    else
                        tempnum=((dayofweek-1)*7)+(hourofday-1)+(80*tn)+40;

                    if(hourofday!=1){
                        int starts=tempnum-hourofday+1;
                        while(starts<tempnum){
                            if(tempchromosome[starts].labornot==0&&tempchromosome[starts].classlabname==(*it).get_course_name()){
                                retrycount++;if(retrycount>1000)return 0;goto labels;
                            }
                            starts++;
                        }
                    }
                    if(dayofweek!=6){
                        int starts;
                        if(hourofday!=7){
                            starts=tempnum+1;
                            while(starts<=(tempnum+7-hourofday)){
                                if(tempchromosome[starts].labornot==0&&tempchromosome[starts].classlabname==(*it).get_course_name()){
                                    retrycount++;if(retrycount>1000)return 0;goto labels;
                                }
                                starts++;
                            }
                        }
                    }
                    else{
                        int starts;
                        if(hourofday!=5){
                            starts=tempnum+1;
                            while(starts<=(tempnum+5-hourofday)){
                                if(tempchromosome[starts].labornot==0&&tempchromosome[starts].classlabname==(*it).get_course_name()){
                                    retrycount++;if(retrycount>1000)return 0;goto labels;
                                }
                                starts++;
                            }
                        }
                    }


                    if(hourofday==1&&(tempchromosome[tempnum+1].classlabname=="nothing")){
                        goto labels;
                    }


                    if((dayofweek!=6&&hourofday!=7&&hourofday!=1)||(dayofweek==6&&hourofday!=5&&hourofday!=1)){
                        if(tempchromosome[tempnum+1].classlabname=="nothing"&&tempchromosome[tempnum-1].classlabname=="nothing"){
                            goto labels;
                        }
                    }
                    /*
                    if((dayofweek!=6&&hourofday==7)||(dayofweek==6&&hourofday==5)){
                        if((tempchromosome[tempnum-1].classlabname=="nothing")){
                            goto labels;
                        }
                    }
                    */


                    for(int i=((dayofweek-1)*7)+(hourofday-1);i<240;i+=40){
                        if(i!=tempnum){
                            if(tempchromosome[i].teacher1==prof||tempchromosome[i].teacher2==prof){
                                retrycount++;if(retrycount>500)return 0;goto labels;
                            }
                        }
                    }

                    if(tempchromosome[tempnum].classlabname=="nothing"){
                        if(!tempproflist.empty()){
                            tr(tempproflist,tempi){
                                if(((*tempi)[0]==dayofweek&&(*tempi)[1]==hourofday)||((*tempi)[0]==dayofweek&&(*tempi)[1]==(hourofday+1))){
                                    retrycount++;if(retrycount>1000)return 0;goto labels;
                                }
                            }
                        }
                    }
                    else{
                        retrycount++;if(retrycount>1000)return 0;goto labels;
                    }

                    //olddayofweek[odwcount++]=dayofweek;

                    tempchromosome[tempnum].section+=sec;
                    tempchromosome[tempnum].classlabname=(*it).get_course_name();
                    tempchromosome[tempnum].mutables=1;
                    tempchromosome[tempnum].sem+=char(sem+48);
                    tempchromosome[tempnum].labornot=0;
                    tempchromosome[tempnum].teacher1=(*it).get_prof_name();


                        (*it).set_allocated(((*it).get_allocated())+1);
                    counts++;
            }
        }
    }

    if(evaluate2(tempchromosome)!=1)
        return 0;

    return 1;
}


int fillincourses(vector<elementOfChromosome> &tempchromosome,vector <Course> &tempcourses,vector <Batch*>* listofbatches\
                ,vector <pair<string,pair<int,int> > * >* teacherunav){

    vector <pair<string,pair<int,int> > * > tempteacher=teacherunav[0];

    //3rd sem||((*it).get_sem()==5)
    int retrycount=0;
    tr(tempcourses,it){
        while((*it).get_allocated()<4&&(*it).get_numperweek()==4&&(((*it).get_sem()==3))){
            int counts=0;
            while(counts<(4-((*it).get_allocated()))){
                    string prof;
                    prof=(*it).get_prof_name();string tempprof="";
                    vvi tempproflist;
                    tr(tempteacher,iters){
                        if(prof==(*iters)->first){
                            tempprof+=prof;vi tempvec;tempvec.pb((*iters)->second.first);tempvec.pb((*iters)->second.second);
                            tempproflist.pb(tempvec);
                        }
                    }

                    int sem=(*it).get_sem(),subnum;
                    switch(sem){
                        case 3:subnum=3;break;
                        case 5:subnum=4;break;
                        case 7:subnum=5;break;
                        case 4:
                        case 6:
                        case 8:break;
                    }
                    int tn=(sem-subnum);int dayofweek,hourofday=0;

                    label:

                    dayofweek=findrand(1,6);


                    if(dayofweek==6){
                            hourofday=(findrand(1,5));
                    }
                    else{
                            hourofday=(findrand(1,7));
                    }

                    char sec=(*it).get_char_section();int tempnum;
                    if(sec=='A')
                        tempnum=((dayofweek-1)*7)+(hourofday-1)+(80*tn);
                    else
                        tempnum=((dayofweek-1)*7)+(hourofday-1)+(80*tn)+40;

                    if(hourofday!=1){
                        int starts=tempnum-hourofday+1;
                        while(starts<tempnum){
                            if(tempchromosome[starts].labornot==0&&tempchromosome[starts].classlabname==(*it).get_course_name()){
                                retrycount++;if(retrycount>1000)return 0;goto label;
                            }
                            starts++;
                        }
                    }
                    if(dayofweek!=6){
                        int starts;
                        if(hourofday!=7){
                            starts=tempnum+1;
                            while(starts<=(tempnum+7-hourofday)){
                                if(tempchromosome[starts].labornot==0&&tempchromosome[starts].classlabname==(*it).get_course_name()){
                                    retrycount++;if(retrycount>1000)return 0;goto label;
                                }
                                starts++;
                            }
                        }
                    }
                    else{
                        int starts;
                        if(hourofday!=5){
                            starts=tempnum+1;
                            while(starts<=(tempnum+5-hourofday)){
                                if(tempchromosome[starts].labornot==0&&tempchromosome[starts].classlabname==(*it).get_course_name()){
                                    retrycount++;if(retrycount>1000)return 0;goto label;
                                }
                                starts++;
                            }
                        }
                    }

                    if(hourofday==1&&(tempchromosome[tempnum+1].classlabname=="nothing")){
                        goto label;
                    }

                    if((dayofweek!=6&&hourofday!=7&&hourofday!=1)||(dayofweek==6&&hourofday!=5&&hourofday!=1)){
                        if(tempchromosome[tempnum+1].classlabname=="nothing"&&tempchromosome[tempnum-1].classlabname=="nothing"){
                            goto label;
                        }
                    }

                    if((dayofweek!=6&&hourofday==7)||(dayofweek==6&&hourofday==5)){
                        if((tempchromosome[tempnum-1].classlabname=="nothing")){
                            goto label;
                        }
                    }

                    for(int i=((dayofweek-1)*7)+(hourofday-1);i<240;i+=40){
                        if(i!=tempnum){
                            if(tempchromosome[i].teacher1==prof||tempchromosome[i].teacher2==prof){
                                retrycount++;if(retrycount>500)return 0;goto label;
                            }
                        }
                    }

                    if(tempchromosome[tempnum].classlabname=="nothing"){
                        if(!tempproflist.empty()){
                            tr(tempproflist,tempi){
                                if(((*tempi)[0]==dayofweek&&(*tempi)[1]==hourofday)||((*tempi)[0]==dayofweek&&(*tempi)[1]==(hourofday+1))){
                                    retrycount++;if(retrycount>1000)return 0;goto label;
                                }
                            }
                        }
                    }
                    else{
                        retrycount++;if(retrycount>1000)return 0;goto label;
                    }

                    //olddayofweek[odwcount++]=dayofweek;

                    tempchromosome[tempnum].section+=sec;
                    tempchromosome[tempnum].classlabname=(*it).get_course_name();
                    tempchromosome[tempnum].mutables=1;
                    tempchromosome[tempnum].sem+=char(sem+48);
                    tempchromosome[tempnum].labornot=0;
                    tempchromosome[tempnum].teacher1=(*it).get_prof_name();


                        (*it).set_allocated(((*it).get_allocated())+1);
                    counts++;
            }
        }
    }

    //cout<<"out"<<endl;
    if(evaluate1(tempchromosome)!=1)
        return 0;


    return 1;
}
