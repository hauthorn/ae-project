//
// Created by christoffer on 2/15/17.
//

#include<string>
using namespace std;

#ifndef AE_PROJECT_FILEUTILS_H
#define AE_PROJECT_FILEUTILS_H


class FileUtils {
public:
    static string getPapiFileName(const string &papi_label, const string &fileName, const string &algoName);
    static string getRuntimeFileName(const string &fileName, const string &algoName);
    static string getOutputName(const string &fileName, const string &algoName);
    static string getOutputName(const string &papi_label, const string &fileName, const string &algoName);
};


#endif //AE_PROJECT_FILEUTILS_H
