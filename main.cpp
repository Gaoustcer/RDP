#include "fileread.h"
#include <string>
#include <iostream>
using namespace std;


int main(){
    char * filecontent;
    filecontent = fileread("./test");
    filestruct file(1024 * 1024 * 1024,filecontent);
    // file.outputintofile("./reconstruct");
    filestruct * files = file.filecut(4);
    for(int i = 0;i < 4;i++){
        cout << files[i].size << endl;        
    }
    filestruct f(files[0] + files[1] + files[2] + files[3]);
    cout << "new object\n";
    f.outputintofile("./reconstruct");
    // filestruct =
    // filestruct
}