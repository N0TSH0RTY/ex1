#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Lab 01- OOP C++ Lab Exercise #1
//Henri Elvy

struct MovieRec
{
	int year;
	string title;
	int length;
};
int loadArray(MovieRec movie[]);
void showArray(ofstream& outFile, MovieRec movie[], int Length);




int main() {

	MovieRec movie[10];
	int Length;






	system("pause");
	
}



int loadArray(MovieRec movie[])
{
	ifstream fin("movie.data");

	if (!fin)
	{
		cout << "Error opening movie.datafile" << endl;
		system("pause"); 
		exit (-1);

	}

	int lenght = 0;	

	for (int index = 0; index < 10 && fin >> movie[index].year; index++) {
		if (fin.eof())
		{
			break;
		}
		fin.ignore(80, '\n');
		getline(fin, movie[index].title);
		fin >> movie[index].length;
		lenght++;
	}

	fin.close();
	return lenght;
	
};



void showArray(ofstream& outFile, MovieRec movie[], int Length)
{
	outFile << left << setw(10) << "Year" << setw(25) << "Title" << right << setw(10) << "Length" << endl;

	outFile << "--------------------------------------------------------" << endl;

	for (int index = 0; index < Length; index++)
	{
		outFile << left << setw(10) << movie[index].year << setw(25) << movie[index].title << right << setw(10) << movie[index].length << endl;
	}
}
