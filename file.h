//
// Created by bobichen on 2017/5/4.
//
#include <string>
#include <stdio.h>
#include <io.h>
#include <sys/stat.h>
#include <time.h>
#include <vector>
#include <string.h>
#include <Windows.h>
#include <iostream>
using namespace std;
#ifndef RTXFILECLASSFIER_FILE_H
#define RTXFILECLASSFIER_FILE_H
class File{
private:
    string path;
    string create_time;
};

void getAllFiles(string path, vector<string>& files);

#endif //RTXFILECLASSFIER_FILE_H
