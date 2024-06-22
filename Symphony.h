#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

#ifndef SYMPHONY_H
#define SYMPHONY_H
#define N 100

class Music{
    protected:
    string cList;
    string urlcList;
    
    public:
    Music(string _cList,string _url){
        cList=_cList;
        urlcList=_url;
    }
    
    string getcList() {return cList;}
    string geturlcList() {return urlcList;}

    void setcList(string _music) {cList=_music;}
    void seturlcList(string _url) {urlcList=_url;}

    virtual void dispClist(int i) {
        if (!cList.empty() && !urlcList.empty()) {
            cout << setw(3) << left << i+1 << ": " << "\033]8;;" << urlcList << "\033\\" 
                 << setw(50)<< left << cList << "\033]8;;\033\\";
            cout << setw(2) << " ";
        }
    } 
};

class ClassicM:public Music{
    string composer;

    public:
    ClassicM(string _list, string _url, string _composer):Music(_list,_url){
        composer=_composer;
    }

    string getComposer() {return composer;}
    void setComposer(string name) {composer=name;}

    void dispClist(int i){
        if(i==0)
            cout << "Classical Music: \n";

        Music::dispClist(i);
            cout << "Composer: " << composer << endl;
    }
};

class WhiteNoise: public Music{
    string typeW;

    public:
    WhiteNoise(string _clist, string _urlList,string _typeW):Music(_clist,_urlList){
        typeW=_typeW;
    }

    void setType(string _type) {typeW=_type;}
    string getType() {return typeW;}

    void dispClist(int i){
        if(i==0)
            cout << "\nWhite Noise: \n";

        Music::dispClist(i);
        cout << "Type: " << typeW << endl;
    }
};

class FavM: public Music{
    string typeF;

    public:
    FavM(string _list, string _urlList,string _typeF): Music(_list, _urlList){
        typeF=_typeF;
    }

    void setType(string _type) {typeF=_type;}
    string getType(int i) {return typeF;}

    void dispClist(int i){
        if(i==0)
            cout << "\nUser Defined Music: \n";

        if(!typeF.empty()){
            Music::dispClist(i);
            cout << "Type: " << typeF << endl;
        }

        else
        if(i==0)
            cout << "!!Doesn't have User Defined Music!!\n\n";
    }
};

#endif 
