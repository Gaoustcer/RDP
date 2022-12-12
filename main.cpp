#include "fileread.h"
#include <string>
#include <iostream>
#include <typeinfo>


using namespace std;
#define SIZE 1024 * 1024 * 1024
#define P 4

int main(){
    char * filecontent;
    filecontent = fileread("./test");
    filestruct file(SIZE,filecontent);
    cout << "file content size " << file.size << endl;
    // file.outputintofile("./reconstruct");
    filestruct ** files = file.filecut(P);
    filestruct ** arrfiles[P];
    for(int i = 0;i < P;i++){
        arrfiles[i] = files[i]->filecut(P);
    }
    for(int i = 0;i < P;i++){
        for(int j = 0;j < P;j++){
            cout << arrfiles[i][j] -> size << endl;
        }
    }
    filestruct outfile (*files[0] + *files[1] + *files[2] + *files[3]);
    cout << "outfile size is " << outfile.size << endl;
    outfile.outputintofile("./myfiles");
    // for(int i = 0;i < 4;i++){
    //     cout << files[i]->size << endl;        
    // }
    // filestruct* f = files[0];
    // for(int i = 1;i < 4;i++){
    //     f = *f + files[i];
    // }
    // cout << "new object\n";
    // cout << "f size is " << f->size << endl;
    // f -> outputintofile("./reconstruct");
}