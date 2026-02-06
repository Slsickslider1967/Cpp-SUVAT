#ifndef SUVAT_PROJ_H
#define SUVAT_PROJ_H

#include <string>

double calculateS(std::string u, std::string v, std::string a, std::string t);
double calculateU(std::string s, std::string v, std::string a, std::string t);
double calculateV(std::string s, std::string u, std::string a, std::string t);
double calculateA(std::string s, std::string u, std::string v, std::string t);
double calculateT(std::string s, std::string u, std::string v, std::string a);

#endif
