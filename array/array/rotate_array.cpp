#include <iostream>
#include <vector>
using namespace std;



 void move_right(vector<int>&nums){
          int space;
          int pointer=nums.size()-1;
          space=nums[pointer];
        
          for(;pointer>0;pointer-- ){
                    nums[pointer]=nums[pointer-1];
          }
            nums[pointer]=space;

    } 

 void rotate(vector<int>& nums, int k) {
    int remainder=k%nums.size();
    int space;
    if(remainder!=0){
     for(;k>0;k--){
    move_right(nums);
     }
    }      
    }

   


    int main(){
        vector<int> data={1,2,3,4,5,6,7};
        rotate(data,4);
        for(auto i:data)
        cout<<i;
        cout<<endl;

        return 1;
    }
