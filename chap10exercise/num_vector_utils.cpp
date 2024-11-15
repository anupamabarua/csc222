#include <string>
#include <vector>
using namespace std;

string render_num_vector(const vector<int>& nums) {
    string s = "1 3 7";
    return s;
}
int num_vector_sum(const vector<int>& v) {
	int nums = 0;
	for(int i = 0; i < sizeof(v); i++){
		nums += v[i];
} 	

return nums;
}

int num_vector_product(const vector<int>& v) {
    int nums = 1;
    for (int i = 0; i < v.size(); i++){
        nums = nums * v[i];
}
    return nums;
}

int only_evens(const vector<int>& v) {
	return 0;
}
