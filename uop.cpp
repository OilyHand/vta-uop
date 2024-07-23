#include "uop.h"

uop::uop(){
    uop_raw.acc_idx = 0;
    uop_raw.inp_idx = 0;
    uop_raw.wgt_idx = 0;
    uop_hex = "00000000";
}

uop::uop(int acc_idx, int inp_idx, int wgt_idx){
    uop_raw.acc_idx = acc_idx;
    uop_raw.inp_idx = inp_idx;
    uop_raw.wgt_idx = wgt_idx;
    uop_hex = uop2hex(uop_raw);
}

// convert micro-op code to hex string
string uop::uop2hex(uop_t uop_code){
    int uop_int;
    stringstream uop_sstream;
    
    uop_int = (uop_code.acc_idx << 21)
              + (uop_code.inp_idx << 10)
              + uop_code.wgt_idx;

    uop_sstream << setfill('0')
                << setw(sizeof(uop_t)*2)
                << hex << uop_int;

    return uop_sstream.str();
}

// convert hex string to micro-op code
uop_t uop::hex2uop(string hex_code){
    int hex_int;
    stringstream hex_ss;
    uop_t temp;
    
    hex_ss << hex << hex_code;
    hex_ss >> hex_int;

    temp.acc_idx = (hex_int >> 21);
    temp.inp_idx = ((hex_int%(1<<21))>>10);
    temp.wgt_idx = (hex_int % (1 << 10));

    return temp;
}

string uop::str(){
    return uop_hex;
}

uop& uop::operator=(string str_hex){
    uop_hex = str_hex;
    uop_raw = hex2uop(str_hex);
    return *this;
}

void uop::print_val(){
    cout << " -- micro-op status --" << endl;
    cout << "acc_idx: " << uop_raw.acc_idx << endl;
    cout << "inp_idx: " << uop_raw.inp_idx << endl;
    cout << "wgt_idx: " << uop_raw.wgt_idx << endl;
    cout << "hex_str: " << uop_hex << endl;
}