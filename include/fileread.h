// #include <fstream>
// #include <iostream>
// using namespace std;

class filestruct{
public:
    int size;
    char * filepointer;
    filestruct(int _size,char * _filepointer):size(_size),filepointer(_filepointer){}
    filestruct():size(0),filepointer(nullptr){};
    filestruct * operator^(filestruct *);
    ~filestruct(){
        if(size != 0){
            delete [] filepointer;
        }
    }
    void outputintofile(const char *);
};

// filestruct * 
char * fileread(const char * filepath,int sizeoffilebyte = 1024 * 1024 * 1024);
// bool filewrite(const char * filepath,char * filecontent,int sizeoffilebype = 1024 * 1024 * 1024);