#!/usr/bin/python
#-*- coding:utf-8

import os
import shutil

class FileClassifier(object):
    path = 'F:/RTX files/'
    def get_file(self):
        return os.listdir(self.path)
        pass
    def MkDir(self, dir):
        os.mkdir(self.path + dir)


def main():
    fc = FileClassifier()
    xlsx = []
    data = []
    doc = []
    for file in fc.get_file():
        for elem in file.split('.'):
            if elem == 'xlsx' or elem == 'xls':
                xlsx.append(file)
            elif elem == 'doc' or elem == 'docx' or elem == 'txt' or elem == 'vsdx':
                doc.append(file)
            elif 'data' in elem:
                data.append(file)
    if not os.path.exists(u'测试用例'):
        fc.MkDir(u'测试用例')
    if not os.path.exists(u'测试数据'):
        fc.MkDir(u'测试数据')
    if not os.path.exists(u'文档'):
        fc.MkDir(u'文档')
    for file in xlsx:
        print(file)
        #shutil.copy(file, u'./测试用例')
        shutil.move(file, u'./测试用例')
    for file in data:
        #shutil.copy(file, u'./测试数据')
        shutil.move(file, u'./测试数据')
    for file in doc:
        #shutil.copy(file, u'./文档')
        shutil.move(file, u'./文档')
    print(xlsx)
    print(data)
    print(doc)

if __name__ == '__main__':
    main()