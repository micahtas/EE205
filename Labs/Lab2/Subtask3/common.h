//
//  common.h
//  ee205_hw1
//
//  Created by Joseph Felix on 2/5/14.
//  Copyright (c) 2014 Joseph Phillip Felix Jr. All rights reserved.
//
#ifndef common_h
#define common_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

using std::string;

void Error(string s);

void Warning(string s);

void printString(string s);

void debug(string s);

enum boolean {FALSE,TRUE};

#endif