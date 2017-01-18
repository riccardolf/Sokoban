#include <iostream>

using namespace std;
int main()
{
	int numLivelli=1;
	int numMuri;
	int numCasse;

	GestoreGioco sokoban(numCasse, numMuri);

	for(int i=0; i<numLivelli; i++)
		sokoban.gioca(i+1);

return 0;
}
