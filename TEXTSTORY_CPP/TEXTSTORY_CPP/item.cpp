#include "item.h"
#include "map.h"
#include <iostream>
#include "PLAYER.h"
#include "String.h"
#include <vector>

using namespace std;
int donutamount = 3;
int magicactivate;
extern vector<string> Magic;
bool knownMagic = false;
bool knownSpell(const char* input);


item::item()
{
	cout << "++ item constructor ++" << endl;
}

item::~item()
{
	cout << "-- item deconstructor --" << endl;
}

void item::inventoryKey()
{
    char* input;
    input = new char[12];

	if (key == true) {
		cout << "A silver key. This should open a door somewhere.\nSomething tells you that you will find it at the furthest corners...\n" << endl;
        cout << "Press any key to continue" << endl;
        cout << ">> "; cin >> input;

        // add door mechanic here
               // edit: door mechanic was added in map file, loser 

	} else cout << "EMPTY" << endl;
	
}

void item::inventoryToast()
{
    char* input;
    input = new char[12];

	if (toast == true) {
        cout << R"(


                                                                  
                                       ==                         
                  =:.   .      #=:  =   .%%#*%*+**#**             
             ...  .-::   :          *%*  #=*::*%#%%*%%%*%**       
            *                      =%%+ =*%*==*#%%+##*%%%#%#      
            -                      %%%* -*%==+#%=*##*#%%%%%%      
                                  -%%%=*%%*=.*****=*%#*%#%#%      
           :                      %*#*:#%*=:--#=%+##=#***###      
             .                   .*#%=+**% .+**=**-*++=*#***      
          + .                    ##%+=*=+%:.=***+#*++****#*#      
                                .%%%===*++::=*:*==+*+=+*****      
         :                      +%**=-==*-=.=+%++++*+*+*##*       
        +                      .%*%*:==**=:::-+%+#*#=#**#*#       
        .                      :***+.=**#+-::*%#%####=*%%**       
       :                       **%*-:***%+==:*%#%%+#%#**%#%       
       =:==*==+-===::.    .   .***%=-=+***+=:*#%%%%*#****%%       
         %@%@@%%%%%%%%%%%#*%*****@%%*#***#****##%%%%%%%%%@========
                           =@@##%@@@@%**+========                
                                                                  
                                                                  
>> It's cold. Darn
)";
        cout << "Press any key to continue" << endl;
        cout << ">> "; cin >> input;

	} else  cout << "EMPTY" << endl;

}

void item::inventoryDonuts()
{
    char* input;
    input = new char[12];
    donutsactivate = true;

    if (donuts == true) {
        if (donutamount <= 0) {
            cout << "Donuts!! There are " << donutamount << " in the box!\nToo bad you ate them all." << endl;
            cout << "Press any key to continue" << endl;
            donutsactivate = false; // ate themb :(

        } else cout << "Donuts!! There are " << donutamount << " in the box!\nEat to regain health ? (y / n)" << endl;
        

    }
}

void item::magicUse(const char* input)
{
    // fun stuff to jump around between files

    if (knownSpell(input) == true) {
        knownMagic = true;
        return;
    }
    if (knownSpell(input) == false) {
        cout << "You do not know this spell." << endl;
    }








    //if ((strcmp(input, "fire") == 0)) {
    //    magicactivate = 1;
    //    return;
    //}
    //if ((strcmp(input, "ice") == 0)) {
    //    magicactivate = 2;
    //    return;
    //}
    //if ((strcmp(input, "water") == 0)) {
    //    magicactivate = 3;
    //    return;
    //}
    //if ((strcmp(input, "air") == 0)) {
    //    magicactivate = 4;
    //    return;
    //}
    //else magicactivate = 5;

}

bool knownSpell(const char* spell) {
    int bottom = 0;
    int top = size(Magic) - 1;

    while (bottom <= top) {

        int middle = (bottom + top) / 2;

        if (Magic[middle] == spell) return true;
        else if (Magic[middle] < spell) bottom = middle + 1;
        else top = middle - 1;
    }
    return false; // if spell is not found



}

