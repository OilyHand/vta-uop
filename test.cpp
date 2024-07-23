#include "uop.h"
using namespace std;

int main()
{
    uop user_uop(14, 4, 3);
    user_uop.print_val();

    user_uop = "01c01000";
    user_uop.print_val();
}