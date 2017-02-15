//
// Created by christoffer on 2/15/17.
//

#include "FileUtils.h"

string FileUtils::getRuntimeFileName(const string &fileName, const string &algoName) {
    return fileName + "/" + fileName + "_" + algoName + ".txt";
}

string FileUtils::getPapiFileName(const string &papi_label, const string &fileName, const string &algoName) {
    return fileName + "/" + fileName + "_" + algoName + "_" + papi_label + ".txt";
}

string FileUtils::getOutputName(const string &fileName, const string &algoName) {
    return fileName + "/" + fileName + "_" + algoName + ".png";

}

string FileUtils::getOutputName(const string &papi_label, const string &fileName, const string &algoName) {
    return fileName + "/" + fileName + "_" + algoName + "_" + papi_label + ".png";
}

