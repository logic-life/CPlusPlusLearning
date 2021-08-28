#include  "array.h"
# include <vector>
int main(){
    vector<int> num1={1,2,3,4,4,5,6,7,7};
    cout<<num1.size()<<endl;
    Solution  new_solution;
    cout<<new_solution.removeDuplicates(num1)<<endl;
    for(auto m:num1)
    cout<<m<<endl;


}