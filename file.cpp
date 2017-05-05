//
// Created by bobichen on 2017/5/4.
//
#include "file.h"
void getAllFiles(string path, vector<string>& files){
    //文件句柄
    long hFile = 0;
    //文件信息
    struct _finddata_t fileinfo;
    string p;


    //cout << p.assign(path).append("\\*.xlsx") << endl;
    if( (hFile = _findfirst( p.assign(path).append("\\*").c_str(), &fileinfo )) != -1L){
        cout << "file name " << fileinfo.name << endl;
        do{
            cout << asctime(gmtime(&fileinfo.time_create))  << endl;
            if( (fileinfo.attrib & _A_SUBDIR) ){//子文件夹
                if( (strcmp(fileinfo.name,".") != 0  and  strcmp(fileinfo.name,"..") != 0) ){
                    files.push_back(p.assign(path).append("\\").append(fileinfo.name) );
                    getAllFiles( p.assign(path).append("\\").append(fileinfo.name), files );
                }
            }else{
                files.push_back(p.assign(path).append("\\").append(fileinfo.name) );
            }
        }while(_findnext(hFile, &fileinfo) == 0);
        _findclose(hFile);
    }
}

int main(int arg, char* args[]){
    string filePath = "C:\\Users\\bobichen\\Documents\\RTXC File List\\Accounts\\bobichen\\RTXDownload";
    vector<string> files;
    getAllFiles(filePath, files);
    cout << files.size() << endl;
    vector<string>::iterator it = files.begin();
    for(;it != files.end(); it++){
        //cout << *it << endl;
    }
    return 0;
}
