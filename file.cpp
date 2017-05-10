//
// Created by bobichen on 2017/5/4.
//
#include "file.h"

set<string> suffix;

map<string, string> fileLayer;

extern void split(string name, File& file);
bool isExist(string file);
string to_string(int n);
void getAllFiles(string path, vector<File>& files);
void mkdir(map<string, string>file);

int main(int arg, char* args[]){
    string filePath = "C:\\Users\\bobichen\\Documents\\RTXC File List\\Accounts\\bobichen\\RTXDownload";

    vector<File> files;
    getAllFiles(filePath, files);
    cout << files.size() << endl;

    mkdir(fileLayer);

    vector<File>::iterator it = files.begin();
    string src, des;
    cout << "================================================" << endl;
    cout << suffix.size() << endl;
    for(;it != files.end(); it++){
        //cout << (*it).filename << "\t" << (*it).Suffix << "\t" << asctime((*it).create_time)<< endl;
        //cout << "path:\t" << (*it).path << endl;
        src = (*it).path;
        des = filePath + "\\" +(*it).firstlayer
              + "\\" + (*it).secondlayer +
                "\\" + (*it).filename + "." + (*it).Suffix;
        //cout << src << "\t" << des << endl;
        /*
         * 注意存储的文件名原本就相同
         */
        MoveFile(src.data(), des.data());

    }


    set<string>::iterator iter = suffix.begin();
    for(;iter != suffix.end(); iter++){
        cout << (*iter) << endl;
    }

    map<string, string>::iterator fit = fileLayer.begin();
    for(; fit != fileLayer.end(); fit ++ ){
        cout << fit->first << " " << fit->second << endl;
    }

    MoveFile("D:\\C++\\FileClassfier\\RTXFileClassfier\\2017_1\\17\\2.txt", "D:\\C++\\FileClassfier\\RTXFileClassfier\\2017_1\\16\\21.txt");




    return 0;
}


//获取后缀和文件名
void split(string name, File& file){
    file.filename = "";
    file.Suffix = "";
    int i = name.length(), j = 0;
    while(i > 0 and name[i] != '.'){
        file.Suffix += name[i];
        i--;
    }

    while(j <= i) {
        file.filename += name[i];
        j++;
    }

    cout << file.Suffix << endl;
}

//判断目录或者文件是否存在
bool isExist(string file){
    return (_access(file.data(), 0) != -1);
}

//创建目录或文件
void mkdir(map<string, string>file){
    map<string, string>::iterator it = file.begin();
    string first;
    string second;
    for(; it != file.end(); it++){
        first = it->second;
        second = it->first;
        if( isExist(first) ){
            cout << first << "已经存在" << endl;
        } else {
            _mkdir(first.data());
        }

        _mkdir( (first + "\\" + second).data() );

        set<string>::iterator iter = suffix.begin();
        for(; iter != suffix.end(); iter++){
            cout << "=================" << endl;
            cout << (first + "\\" + second + "\\" + *iter).data() << endl;
            _mkdir( (first + "\\" + second + "\\" + *iter).data() );
        }
    }
}

string to_string(int n){
    ostringstream stream;
    stream << n;  //n为int类型
    return stream.str();
}

void getAllFiles(string path, vector<File>& files){
    //文件句柄
    long hFile = 0;
    //文件信息
    struct _finddata_t fileinfo;
    string p;
    File file;

    if( (hFile = _findfirst( p.assign(path).append("\\*").c_str(), &fileinfo )) != -1L){
        do{
            split(fileinfo.name, file);
            file.create_time = gmtime(&fileinfo.time_create);//获取文件创建时间

            file.path = p.assign(path).append("\\").append(fileinfo.name);//设置文件路径

            file.firstlayer = to_string(1900 + file.create_time->tm_year) + "_" + to_string(file.create_time->tm_mon);

            file.secondlayer = to_string(file.create_time->tm_mday);

            fileLayer[file.secondlayer] = file.firstlayer;

            suffix.insert(file.Suffix);

            if( (fileinfo.attrib & _A_SUBDIR) ){//子文件夹
                if( (strcmp(fileinfo.name,".") != 0  and  strcmp(fileinfo.name,"..") != 0) ){
                    getAllFiles( p.assign(path).append("\\").append(fileinfo.name), files);
                }
            }else{
                files.push_back(file);
            }
        }while(_findnext(hFile, &fileinfo) == 0);
        _findclose(hFile);
    }
}
