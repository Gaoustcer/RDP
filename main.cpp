#include "fileread.h"
#include <string>
#include <iostream>
#include <typeinfo>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


using namespace std;
#define SIZE 1024 * 1024 * 1024
#define P 4

filestruct ** getfirstcheckblock(filestruct ***fileblocks){
    // fileblock is 4 \times 4 fileblock[i][j] refer 第一块盘上的第j个块
    // fileblock[i][0] + fileblock[i][1] + fileblock[i][2] + fileblock[i][3] -> checkin[i]
    // filestruct *checkin[4];
    filestruct ** checkin = new filestruct*[P];
    for(int i = 0;i < P;i++){
        checkin[i] = fileblocks[i][0];
        // fileblocks[i][0] ^ fileblocks[i][1] ^ fileblocks[i][2] ^ fileblocks[i][3]
        for(int j = 1;j < P;j++){
            checkin[i] = * checkin[i] ^ fileblocks[j][i];
        }
    }
    
    return checkin;
}

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
    // filestruct ** checklineblock = getfirstcheckblock(arrfiles);
    // for(int i = 0;i < P;i++){
    //     cout << "size of each block is " << checklineblock[i] -> size << endl;
    // }
    // filestruct * newfile = checklineblock[0];
    // for(int i = 1;i < P;i++){
    //     newfile = *newfile + checklineblock[1];
    // }
    for(int i = 0;i < P;i++){
        filestruct * f = arrfiles[i][0];
        for(int j = 1;j < P;j++){
            f = * f + arrfiles[i][j];
        }
        char s[20] = "./Coding/test0";
        s[strlen(s) - 1] = i + '0';
        f->outputintofile(s);
    }
    // newfile -> outputintofile("./newlinecheck");
    // for(int i = 0;i < P;i++){
    //     for(int j = 0;j < P;j++){
    //         cout << arrfiles[i][j] -> size << endl;
    //     }
    // }
    // filestruct * outfile = files[0];
    // for(int i = 1;i < P;i++){
    //     outfile = *outfile + files[i];
    // }
    // filestruct * linecheckblock = files[0];
    // for(int i = 1;i < P;i++){
    //     linecheckblock = *linecheckblock ^ files[i];
    // }
    // cout << "line check file " << linecheckblock -> size << endl;
    // linecheckblock -> outputintofile("./linecheckbaseline");
    // cout << "outfile size is " << outfile -> size << endl;
    // outfile.outputintofile("./myfiles");
    // outfile -> outputintofile("./write");
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