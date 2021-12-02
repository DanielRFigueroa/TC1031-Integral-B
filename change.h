
#include <string>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;


string validation(int code){
    stringstream aux;

    if(code == 0){
        aux << "ALAMEDA";
        return aux.str();

    } else if (code == 1){
        aux << "ARCOS";
        return aux.str();

    } else if (code == 2){
        aux << "ANTEA";
        return aux.str();

    } else if (code == 3){
        aux << "REFUGIO";
        return aux.str();

    } else if (code == 4){
        aux << "JURIQUI";
        return aux.str();

    } else if (code == 5){
        aux << "TECMTY";
        return aux.str();

    } else if (code == 6){
        aux << "ANAHUAC";
        return aux.str();

    } else if (code == 7){
        aux << "MILENIO";
        return aux.str();

    } else if (code == 8){
        aux << "PASEO";
        return aux.str();

    } else if (code == 9){
        aux << "BOULEVA";
        return aux.str();

    }
    return 0;
}

int citytonumber(string city) {

    int auxi;

    if (city=="ALAMEDA")
    {
        auxi=0;
        return auxi;
    }

    else if (city=="ARCOS")
    {
        auxi=1;
        return auxi;
    }

    else if (city=="ANTEA")
    {
        auxi=2;
        return auxi;
    }

    else if (city=="REFUGIO")
    {
        auxi=3;
        return auxi;
    }

    else if (city=="JURIQUILLA")
    {
        auxi=4;
        return auxi;
    }
    else if (city=="TECMTY")
    {
        auxi=5;
        return auxi;
    }
    else if (city=="ANAHUAC")
    {
        auxi=6;
        return auxi;
    }
    else if (city=="MILENIO")
    {
        auxi=7;
        return auxi;
    }
    else if (city=="PASEO")
    {
        auxi=8;
        return auxi;
    }
    else if (city=="BOULEVARES")
    {
        auxi=9;
        return auxi;
    }

return 0;

}
