#include <iostream>
#include <vector>

// что будет выведено программой?

int example_vector_back() {
    std::vector<int> myVector;

    myVector.push_back(10);

    while(myVector.back() != 0) {
        myVector.push_back(myVector.back() - 1);
    }

    std::cout << "myVector contains:";
	for (unsigned i = 0; i < myVector.size(); i++) {
		std::cout << ' ' << myVector[i];
	}
    std::cout << '\n';

    return 0;
}

int main() {
	example_vector_back();
	system("pause");	
	return 0;
}