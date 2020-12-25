#include <iostream>

using namespace std;

int main() {
  
	int Num_jar;    
  	int tmp_position = 0;
	int jar;  
  	int tank = 0; 
  	int bucket[5] = {0};  

  	cin >> Num_jar;
  	for (int i = 0; i < Num_jar; i++) {
    	cin >> jar;

    for (int j = 0; j < 5; j++) {
        if (bucket[j] < bucket[tmp_position]) {
        tmp_position = j;
      }
    }
    bucket[tmp_position] += jar;
    if (bucket[tmp_position] >= 1000) {
      	bucket[tmp_position] = 0;
		tank += 1000;
      	
    } 
  }
  
  	cout << tank << endl;

}
