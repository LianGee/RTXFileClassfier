//
// Created by bobichen on 2017/5/4.
//
#include <string>
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <vector>
#include <set>
#include <map>
#include <string.h>
#include <Windows.h>
#include <iostream>
#include <io.h>
#include <direct.h> //_mkdir函数的头文件
#include <fstream>
#include <sstream>
using namespace std;
#ifndef RTXFILECLASSFIER_FILE_H
#define RTXFILECLASSFIER_FILE_H
class File{
public:
    string path;
    tm* create_time;
    string filename;
    string Suffix;
    string firstlayer;
    string secondlayer;
};

void getAllFiles(string path, vector<string>& files);

#endif //RTXFILECLASSFIER_FILE_H
