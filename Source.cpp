//Jonathan Thomason
//Timothy Capehart 
//Josh Holzhauser


#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

const int SIZE = 100;

int StrToArray(char **&, char *, char);
void get_string(char *&);


int main() {

	char str[SIZE];
	char **str_array = nullptr;
	char delimeter = ' ';
	
	//get_string(str);


	cin.getline(str, SIZE);
	int size = StrToArray(str_array, str, delimeter);
	
	cout << "\n\n";
	cout << size << endl;
	for (int i = 0; i < size; i++)
		cout << str_array[i] << endl;

	if (size != -1) {
	
		for (int i = 0; i < size; i++) {
			delete[] str_array[i];
			cout << "memory chunk " << i << " deallocated" << endl;
		}
		delete[] str_array;
		delete[] str_array;
		cout << "memory chunk of main array deallocated" << endl;
		
	}

	system("pause");
}

int StrToArray(char **& str_array, char *str, char delimiter) {

	char **old_array = 0;
	int ret = -1;
	char *token = nullptr;
	size_t array_size;
	int object_size = 0;
	char delim[2] = { delimiter, '\0' };

	if (!str) {
		return ret;
	}

	/* initial token */
	token = strtok(str, delim);

	/* token is not NULL */
	if (token) {
		/* size of initial token */
		array_size = strlen(token) + 1;
		/* allocate an array of c strings with max possible size */
		str_array = new char*[strlen(str) + 1];
		str = nullptr;
		str_array[0] = new char[array_size];
		/* Copy the intial token into index 0 */
		strcpy(str_array[0], token);
		object_size++;
	} else {
		str = nullptr;
		return -1;
	}

	do {
		token = strtok(0, delim);
		
		if (token) {
			array_size = strlen(token) + 1;

			str_array[object_size] = new char[array_size];
			strcpy(str_array[object_size], token);

			object_size++;
		}

	} while (token);

	//str_array = new char *[object_size + 1];
	
	/*for (int i = 0; i < object_size; i++)
	{
		cout << i << endl;
		str_array[i] = new char[strlen(old_array[i]) + 1];
		strcpy(str_array[i], old_array[i]);
		delete[] old_array[i];
	}*/

	//delete[] old_array;
	
	return object_size;
}