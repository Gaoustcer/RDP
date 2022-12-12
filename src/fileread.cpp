#include "fileread.h"
#include <fstream>
#include <assert.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;
char * fileread(const char * filename,int sizeoffilebyte){
    ifstream file(filename,ios::binary|ios::in);
    char * filecontent = new char[sizeoffilebyte];
    cout << "read size is " << sizeoffilebyte << endl;
    file.read((char *)filecontent,sizeof(char) * sizeoffilebyte);
    file.close();
    // for(int i = 0;i < 128;i++){
    //     cout << (filecontent[i + 1024 * 1024 * 256] == 128) << " " << i << " ";
    // }
    return filecontent;
}
// bool filewrite(const char * filepath,char *)
void filestruct::outputintofile(const char* filename){
    ofstream file(filename,ios::binary|ios::out);
    for(int i = 0;i < 1024;i++){
        filepointer[i * 1024 * 1024];
    }
    file.write(filepointer,size * sizeof(char));
    // for(int i = 0;i < 1024 * 1024 * 1024;i++){
    //     filepointer[i];
    // }
    cout << "file write finish " << filename << endl;
    file.close();
    return ;
}
filestruct& filestruct::operator^(filestruct &rightop){
    assert(size == rightop.size);
    char * file = new char[size];
    for(int i = 0;i < size;i++){
        file[i] = rightop.filepointer[i] ^ filepointer[i];
    }
    const filestruct& f = filestruct(size,file);
    // return std::move(f);
    return (filestruct &)f;
}
filestruct** filestruct::filecut(int cutnum){
    assert (size % cutnum == 0);
    int eachfilesize = size/cutnum;
    // string basicfilename("Codingorigingfile");
    filestruct ** files = new filestruct*[cutnum];
    for(int i = 0;i < cutnum;i++){
        char * ptr = new char[eachfilesize];
        memcpy(ptr,filepointer + i * eachfilesize,eachfilesize);
        files[i] = new filestruct(eachfilesize,ptr);
        // memcpy(ptr,)
        // string filename = basicfilename + to_string(i);
        // cout << "cut the file" << endl;    
    }
    return files;
}
// filestruct & filestruct::operator=(filestruct & rightop){
    
// }
filestruct * filestruct::operator^(filestruct * rightop){
    assert(rightop->size == size);
    char * ptr = new char[size];
    int _size = size;
    for(int i = 0;i < _size;i++){
        ptr[i] = filepointer[i] ^ rightop->filepointer[i];
    }
    filestruct * obj = new filestruct(_size,ptr);
    return obj;
}


filestruct & filestruct::operator+(filestruct & rightop){
    // cout << "size is " << size << " right size is " << rightop.size;
    int newsize = size + rightop.size;
    // cout << " new size is " << newsize << endl;
    char * ptr = new char[newsize];
    memcpy(ptr,filepointer,size);
    // cout << "the first file concat\n";
    memcpy(ptr + size,rightop.filepointer,rightop.size);
    // cout << "the second file concar\n";
    const filestruct & f = filestruct(newsize,ptr);
    // cout << "f size is " << f.size << endl;
    filestruct& anotherf = (filestruct &) f;
    cout << " another f size " << anotherf.size << endl;
    // if(anotherf.size == 1024 * 1024 * 1024)
    //     anotherf.outputintofile("./anothertest");
    // cout << "another f size is " << anotherf.size << endl;
    // cout << "return the instance\n";
    return anotherf;
}
filestruct * filestruct::operator+(filestruct *rightop){
    // assert(size == rightop->size);
    char * pointer = new char[size + rightop->size];
    int _size = size + rightop->size;
    memcpy(pointer,this->filepointer,size);
    memcpy(pointer + size,rightop->filepointer,rightop->size);
    // return pointer;
    filestruct * obj = new filestruct(_size,pointer);
    return obj;
}