#include "item.h"
#include "map.h"
#include <iostream>
#include "PLAYER.h"
using namespace std;

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
	} else  cout << "EMPTY" << endl;

}

void item::inventoryDonuts()
{
    char* input;
    input = new char[12];

    if (donuts == true) {
        cout << "Donuts!! Eat to regain health? (y/n)" << endl;
        cout << ">> "; cin >> input; cout << "\n \n";

        if (strcmp(input, "y") == 0) {
            
        }


    }
}

