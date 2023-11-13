#include <iostream>
#include <random>
#include <fstream>
#include <string>


using namespace std;

int random_number(int n);

int main(void)
{
    ifstream fin;
    ofstream fout;

    string fileName = "input5000000.txt";


    fin.open(fileName);

    int n;

    fin >> n;

    fin.close();

    fout.open(fileName, ios::app);
    fout << endl;
    for (int i = 0; i < n; i++)
    {
        fout << random_number(n) << endl;
    }
    fout.close();

    return 0;
}


int random_number(int n)
{
    // Create a random number generator engine
    random_device rd;  // Use hardware entropy to seed the random number generator
    mt19937 gen(rd()); // Mersenne Twister 19937 generator

    int min_range = 0;
    int max_range = numeric_limits<int>::max();
    max_range = n;
    uniform_int_distribution<int> distribution(0, max_range);

    // Generate a random number
    int random_number = distribution(gen);

    return random_number;
}