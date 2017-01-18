#include <iostream>
#include"GestoreGioco.h"
using namespace std;
int main()
{
	int numLivelli=1;
	int numMuri=3;
	int numCasse=3;

	GestoreGioco sokoban(numCasse, numMuri);

	for(int i=0; i<numLivelli; i++)
		sokoban.gioca();

return 0;
}
