/***********************************************************************
* Program:
*    2142 Custom Launcher exe for gameranger
* Author:
*    Bryan Muller
* Summary: 
*   This will launch the game using custom commands that gameranger
*   does not allow through shortcuts. Simply make a .txt file called 
*   commands.txt and put BF2142.exe +(your commands in your launcher shortcut)
*   place this exe in your 2142 install directory and point gameranger to it
*
*
************************************************************************/
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

const string FILENAME = "commands.txt";
/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
   ifstream fin(FILENAME);
   if (fin.fail())
   {
      cout << "ERROR: Cannot find commands.txt! Now exiting\n";
      cout << "Press any key to exit...\n";
      return 0;
   }

   string launch;
   getline(fin, launch);
   system((launch).c_str());
   return 0;
}
