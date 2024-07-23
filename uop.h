#ifndef UOP_H
#define UOP_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

typedef struct {
    int acc_idx : 11;
    int inp_idx : 11;
    int wgt_idx : 10;
} uop_t;

class uop {
  private:
    uop_t  uop_raw;
    string uop_hex;
    string uop2hex(uop_t uop_code);
    uop_t  hex2uop(string hex_code);
  public:
    uop();
    uop(int acc_idx, int inp_idx, int wgt_idx);
    uop& operator=(string str_hex);
    string str();
    void print_val();
};

#endif