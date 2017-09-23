// Try compiling this and running this to see how fileIO works

#include<iostream>
#include<fstream>
using namespace std;

int main()
{
  ifstream fin ("table.txt", ios::in);
  char x; int count;
  while (fin >> x)  // can read another line?
    { cout << "Got " << x << " and " << endl;
      fin >> count;
      for (int i = 1; i <= count; i++) // for count times
	{
	  fin >> x;
          cout << "got " << x << " ";
	} 
      cout << endl;
    }
  fin.close();
}
