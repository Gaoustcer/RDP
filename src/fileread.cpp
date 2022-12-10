#include "fileread.h"
#include <fstream>
#include <assert.h>
#include <iostream>
#include <string>
using namespace std;
char * fileread(const char * filename,int sizeoffilebyte){
    ifstream file(filename,ios::binary|ios::in);
    char * filecontent = new char[sizeoffilebyte];
    file.read((char *)filecontent,sizeof(char) * sizeoffilebyte);
    file.close();
    return filecontent;
}
// bool filewrite(const char * filepath,char *)
void filestruct::outputintofile(const char* filename){
    ofstream file(filename,ios::binary|ios::out);
    file.write(filepointer,size * sizeof(char));
    file.close();
    return ;
}
filestruct* filestruct::operator^(filestruct *rightop){
    assert(size == rightop->size);
    char * file = new char[size];
    for(int i = 0;i < size;i++){
        file[i] = rightop->filepointer[i] ^ filepointer[i];
    }
    filestruct * f = new filestruct(size,file);
    return f;
}
filestruct* filestruct::filecut(int cutnum){
    assert (size % cutnum == 0);
    int eachfilesize = size/cutnum;
    string basicfilename("Codingorigingfile");
    filestruct * files;
    for(int i = 0;i < cutnum;i++){

    }
}