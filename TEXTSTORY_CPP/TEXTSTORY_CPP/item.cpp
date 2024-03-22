#include "item.h"
#include "map.h"
#include <iostream>
#include "PLAYER.h"
#include "String.h"
using namespace std;
int donutamount = 3;
bool magicactivate = false;

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
               // edit: door mechanic was added in map, loser 

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
            donutsactivate = false;

        } else cout << "Donuts!! There are " << donutamount << " in the box!\nEat to regain health ? (y / n)" << endl;
        

    }
}

void item::magicUse()
{
    String* MAGIC = new String("fire, ice, water, air");
    

    char* input;
    input = new char[12];

    cout << ">> You cast: "; cin >> input; cout << endl;

    String* choice = new String(input);

    choice->Find(*MAGIC);


}

void item::magic()
{

 
    magicactivate = true;
}

