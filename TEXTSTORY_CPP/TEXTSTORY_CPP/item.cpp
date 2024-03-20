#include "item.h"
#include "map.h"
#include <iostream>
#include "PLAYER.h"
using namespace std;
int donutamount = 3;

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
		cout << "A silver key. This should open a door somewhere.\n Maybe in the future that mechanic will be implimented." << endl;
        cout << "Press any key to continue" << endl;
        cout << ">> "; cin >> input;

        // add door mechanic here

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
    

    if (donuts == true) {
        if (donutamount <= 0) {
            cout << "Donuts!! There are " << donutamount << " in the box!\nToo bad you ate them all." << endl;
            cout << "Press any key to continue" << endl;

        } else cout << "Donuts!! There are " << donutamount << " in the box!\nEat to regain health ? (y / n)" << endl;
        

      /*  if (strcmp(input, "y") == 0) {
            
        }*/


    }
}

