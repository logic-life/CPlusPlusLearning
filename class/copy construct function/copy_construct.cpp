#include "copy_construct.h"

int main()
{

    MyCopyConstruct object1_('c');
    MyCopyConstruct b = (MyCopyConstruct)1;
    MyCopyConstruct object2_(7);
    //MyCopyConstruct object3_(object1_);
    //bool a = b;//无法隐式转化
    object1_.PrintValue();
    object2_.PrintValue();
    b.PrintValue();
    //object3_.PrintValue();
}
