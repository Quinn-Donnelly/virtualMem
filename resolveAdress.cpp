#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>
#include "tlb.h"

using namespace std;

// This will check if the given file name currently exists on disk
bool doesExist (const string& fileName);
// This function is simply to clean the output to the user where endl() would be used instead use end() on next line
// at any return point in the main program 2 endl should be added just before exit to keep this style
void end(){ cout << "\n>> "; }

int main(int argc, char *argv[])
{
  // Start our program by outputing out "status terminal"
  end();

  // This program requires there be a file name given to the program
  if(argc != 2)
  {
    cout << "Please enter the correct filename as an arg to this program";
    cout << endl << endl;
    //return 1;
  }

  ifstream inf;
  ofstream outf;

  inf.open(argv[1]);

  string inputIncorrect;
  while(!inf.is_open())
  {
    cout << "File not found!";
    end();
    cout << "Please enter the name of the input data file: ";
    end();
    cin >> inputIncorrect;
    end();
    inf.open(inputIncorrect.c_str());
  }

  // We check for the file that we will write our data to and prompt the user if it is before overwriting it
  if(doesExist("results.data"))
  {
    cout << "file: \"results.data\"  exits if you continue this file will be overwritten.\nWould you like to continue?";
    end();
    cout << "(y,n): ";
    char ans;
    cin >> ans;
    end();

    if(ans == 'n' || ans == 'N')
    {
      cout << "Exiting...\n";
      return 0;
    }
    else
    {
        cout << "Resuming...\n";
        end();
    }
  }

  outf.open("results.data");

  // Open the bin file
  ifstream bin;
  bin.open("BACKING_STORE.bin");

  if (!bin.is_open())
  {
	  cout << "Error BACKING_STORE not found, exiting...";
	  end();
  }

  // Begin parsing input here

  TLB tlb;
  tlb.insert(50, 1);
  tlb.insert(10, 2);

  cout << "Loading 10: " << tlb.isLoaded(10);
  end();

  cout << "Loading 100: " << tlb.isLoaded(100);
  end();
  



  // End parsing input here

  inf.close();
  outf.close();
  bin.close();
  cout << "Done!" << endl << endl;
  return 0;
}

bool doesExist (const string& fileName) {
  struct stat buffer;
  return (stat (fileName.c_str(), &buffer) == 0);
}
