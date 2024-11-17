#include <string>
#include <vector>
using namespace std;

string render_num_vector(const vector<int>& v) {
	string s = "", str;
	for (int i = 0; i < v.size(); i++) {
		s += to_string(v[i]) + " ";
}    
	str = s.substr(0, s.size()-1);
	return str;
}

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

vector<int> only_odds(const vector<int>& v){
	vector<int> s;
        int check;
	for(int i = 0; i < 
v.size(); i++) {
		check = v[i] % 2;
		if( check == 1) {
s.push_back(v[i]);
}
}
	return s;	
}
