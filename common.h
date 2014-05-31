#pragma once
#include <cstdio>
#include <cstring>
#include <string>
#include <memory>
#include <vector>
#include <map>
#include <utility>
#include <iostream>
using namespace std;
inline double atof(const char * str){
	int l = strlen(str);
	double total = 0;
	int shift = 0;
	while((*str) != '\0'){	
		if(*str == '.')
			shift = -shift;
		else{
			total = total * 10 + *str - '0';
		}
		if(shift >= 0)	
			++shift;
		++str; 
	}
	shift = l + shift - 1;
	while(shift--){
		total /= 10;
	}
	return total;
}
inline string itoa(int x){
	char _int[20];
	sprintf(_int, "%d", x);
	return string(_int);
}
inline string ftoa(double x){
	char real[20];
	sprintf(real, "%.2f", x);
	return string(real);
}