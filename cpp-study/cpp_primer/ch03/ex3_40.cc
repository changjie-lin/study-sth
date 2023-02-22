#include <iostream>
#include <cstring>

int main() {

	const char s1[] = "Hello";
	const char s2[] = "World!";

	size_t size = strlen(s1) + strlen(" ") + strlen(s2) + 1;
	char* s3 = new char[size];

	strcpy(s3, s1);
	strcat(s3, " ");
	strcat(s3, s2);

	std::cout << s3 << std::endl;

	delete [] s3;
	return 0;
}
