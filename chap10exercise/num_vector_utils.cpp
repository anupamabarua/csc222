#include <string>
#include <vector>
using namespace std;

string render_num_vector(const vector<int>& nums) {
    string s = "";
    for(int i=0;i<nums.size();i++){
        s.append(std::to_string(nums[i]));
        if(i != nums.size()-1){
            s.append(" ");
        }
    }

    return s;
}
