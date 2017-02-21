#include"GestoreGioco.h"

GestoreGioco::GestoreGioco()
{
	this->inizializzaAllegro();
	numLivelli = 9;
	numCasse = new int[numLivelli + 1];
	numMuri = new int[numLivelli + 1];
	posCasseXi = new int*[numLivelli + 1];
	posCasseXf = new int*[numLivelli + 1];
	posCasseYi = new int*[numLivelli + 1];
	posCasseYf = new int*[numLivelli + 1];
	posMuriX = new int*[numLivelli + 1];
	posMuriY = new int*[numLivelli + 1];
	posGiocatoreX = new int[numLivelli + 1];
	posGiocatoreY = new int[numLivelli + 1];
	//  1   2   3   4   5   6   7   8   9  10
	int nCasse[] = { 2,  0,  0,  0,  0,  0,  0,  0,  0,  0 };
	int nMuri[] = { 23,  0,  0,  0,  0,  0,  0,  0,  0,  0 };
	int PGx[] = { 128,  0,  0,  0,  0,  0,  0,  0,  0,  0 };
	int PGy[] = { 192,  0,  0,  0,  0,  0,  0,  0,  0,  0 };

	for (int i = 0; i<numLivelli; i++)
	{
		posGiocatoreX[i] = PGx[i];
		posGiocatoreY[i] = PGy[i];
		numCasse[i] = nCasse[i];
		numMuri[i] = nMuri[i];
		posCasseXi[i] = new int[numCasse[i]];
		posCasseXf[i] = new int[numCasse[i]];
		posCasseYi[i] = new int[numCasse[i]];
		posCasseYf[i] = new int[numCasse[i]];
		posMuriX[i] = new int[numMuri[i]];
		posMuriY[i] = new int[numMuri[i]];
	}


	//livello 1
	int CasseXi[] = { 192,256 };
	int CasseYi[] = { 256,256 };
	int CasseXf[] = { 352,292 };
	int CasseYf[] = { 352,352 };
	int MuriX[] = { 64, 64, 64, 64, 64, 64,128,192,256,320,384,448,448,448,448,448,384,384,320,256,192,128, 192 };
	int MuriY[] = { 128,192,256,320,384,448,448,448,448,448,448,448,384,320,256,192,192,128,128,128,128,128,320 };

	for (int i = 0; i<numCasse[0]; i++)
	{
		posCasseXi[0][i] = CasseXi[i];
		posCasseXf[0][i] = CasseXf[i];
		posCasseYi[0][i] = CasseYi[i];
		posCasseYf[0][i] = CasseYf[i];
	}

	for (int i = 0; i<numMuri[0]; i++)
	{
		posMuriY[0][i] = MuriY[i];
		posMuriX[0][i] = MuriX[i];
	}
	/*
	// livello 2
	int CasseXi2[] ={  };
	int CasseXf2[] ={  };
	int CasseYi2[] = { };
	int CasseYf2[] = {  };
	for(int i=0; i<numCasse[1]; i++)
	{
	posCasseXi[1][i]=CasseXi2[i];
	posCasseXf[1][i]=CasseXf2[i];
	posCasseYi[1][i]=CasseYi2[i];
	posCasseYf[1][i]=CasseYf2[i];
	}
	int MuriX2[] = {   };
	int MuriY2[] = {  };
	for(int i=0; i<numMuri[1]; i++)
	{
	posMuriY[1][i]=MuriY2[i];
	posMuriX[1][i]=MuriX2[i];
	}
	//livello 3
	int CasseXi3[] ={  };
	int CasseXf3[] ={  };
	int CasseYi3[] = { };
	int CasseYf3[] = {  };
	for(int i=0; i<numCasse[2]; i++)
	{
	posCasseXi[2][i]=CasseXi3[i];
	posCasseXf[2][i]=CasseXf3[i];
	posCasseYi[2][i]=CasseYi3[i];
	posCasseYf[2][i]=CasseYf3[i];
	}
	int MuriX3[] = {   };
	int MuriY3[] = {  };
	for(int i=0; i<numMuri[2]; i++)
	{
	posMuriY[2][i]=MuriY3[i];
	posMuriX[2][i]=MuriX3[i];
	}
	//livello 4
	int CasseXi4[] ={  };
	int CasseXf4[] ={  };
	int CasseYi4[] = { };
	int CasseYf4[] = {  };
	for(int i=0; i<numCasse[3]; i++)
	{
	posCasseXi[3][i]=CasseXi4[i];
	posCasseXf[3][i]=CasseXf4[i];
	posCasseYi[3][i]=CasseYi4[i];
	posCasseYf[3][i]=CasseYf4[i];
	}
	int MuriX4[] = {   };
	int MuriY4[] = {  };
	for(int i=0; i<numMuri[3]; i++)
	{
	posMuriY[3][i]=MuriY4[i];
	posMuriX[3][i]=MuriX4[i];
	}
	//livello 5
	int CasseXi5[] ={  };
	int CasseXf5[] ={  };
	int CasseYi5[] = { };
	int CasseYf5[] = {  };
	for(int i=0; i<numCasse[4[; i++)
	{
	posCasseXi[4][i]=CasseXi5[i];
	posCasseXf[4][i]=CasseXf5[i];
	posCasseYi[4][i]=CasseYi5[i];
	posCasseYf[4][i]=CasseYf5[i];
	}
	int MuriX5[] = {   };
	int MuriY5[] = {  };
	for(int i=0; i<numMuri[4]; i++)
	{
	posMuriY[4][i]=MuriY5[i];
	posMuriX[4][i]=MuriX5[i];
	}
	//livello 6
	int CasseXi6[] ={  };
	int CasseXf6[] ={  };
	int CasseYi6[] = { };
	int CasseYf6[] = {  };
	for(int i=0; i<numCasse[5]; i++)
	{
	posCasseXi[5][i]=CasseXi6[i];
	posCasseXf[5][i]=CasseXf6[i];
	posCasseYi[5][i]=CasseYi6[i];
	posCasseYf[5][i]=CasseYf6[i];
	}
	int MuriX3[] = {   };
	int MuriY3[] = {  };
	for(int i=0; i<numMuri[5]; i++)
	{
	posMuriY[5][i]=MuriY6[i];
	posMuriX[5][i]=MuriX6[i];
	}
	//livello 7
	int CasseXi7[] ={  };
	int CasseXf7[] ={  };
	int CasseYi7[] = { };
	int CasseYf7[] = {  };
	for(int i=0; i<numCasse[6]; i++)
	{
	posCasseXi[6][i]=CasseXi7[i];
	posCasseXf[6][i]=CasseXf7[i];
	posCasseYi[6][i]=CasseYi7[i];
	posCasseYf[6][i]=CasseYf7[i];
	}
	int MuriX7[] = {   };
	int MuriY7[] = {  };
	for(int i=0; i<numMuri[6]; i++)
	{
	posMuriY[6][i]=MuriY7[i];
	posMuriX[6][i]=MuriX7[i];
	}
	//livello 8
	int CasseXi8[] ={  };
	int CasseXf8[] ={  };
	int CasseYi8[] = { };
	int CasseYf8[] = {  };
	for(int i=0; i<numCasse[7]; i++)
	{
	posCasseXi[7][i]=CasseXi8[i];
	posCasseXf[7][i]=CasseXf8[i];
	posCasseYi[7][i]=CasseYi8[i];
	posCasseYf[7][i]=CasseYf8[i];
	}
	int MuriX8[] = {   };
	int MuriY8[] = {  };
	for(int i=0; i<numMuri[7]; i++)
	{
	posMuriY[7][i]=MuriY8[i];
	posMuriX[7][i]=MuriX8[i];
	}
	//livello 9
	int CasseXi9[] ={  };
	int CasseXf9[] ={  };
	int CasseYi9[] = { };
	int CasseYf9[] = {  };
	for(int i=0; i<numCasse[8]; i++)
	{
	posCasseXi[8][i]=CasseXi9[i];
	posCasseXf[8][i]=CasseXf9[i];
	posCasseYi[8][i]=CasseYi9[i];
	posCasseYf[8][i]=CasseYf9[i];
	}
	int MuriX9[] = {   };
	int MuriY9[] = {  };
	for(int i=0; i<numMuri[8]; i++)
	{
	posMuriY[8][i]=MuriY9[i];
	posMuriX[8][i]=MuriX9[i];
	}
	//livello 10
	int CasseXi10[] ={  };
	int CasseXf10[] ={  };
	int CasseYi10[] = { };
	int CasseYf10[] = {  };
	for(int i=0; i<numCasse[9]; i++)
	{
	posCasseXi[9][i]=CasseXi10[i];
	posCasseXf[9][i]=CasseXf10[i];
	posCasseYi[9][i]=CasseYi10[i];
	posCasseYf[9][i]=CasseYf10[i];
	}
	int MuriX10[] = {   };
	int MuriY10[] = {  };
	for(int i=0; i<numMuri[9]; i++)
	{
	posMuriY[9][i]=MuriY10[i];
	posMuriX[9][i]=MuriX10[i];
	}
	*/
}
GestoreGioco::~GestoreGioco()
{

	for (int i = 0; i<numLivelli; i++)
	{
		delete[]posMuriX[i];
		delete[]posMuriY[i];
		delete[]posCasseXi[i];
		delete[]posCasseXf[i];
		delete[]posCasseYi[i];
		delete[]posCasseYf[i];
	}

	delete[]posGiocatoreX;
	delete[]posGiocatoreY;
	delete[]posMuriX;
	delete[]posMuriY;
	delete[]posCasseXi;
	delete[]posCasseXf;
	delete[]posCasseYi;
	delete[]posCasseYf;
	delete[]numMuri;
	delete[]numCasse;
}

void GestoreGioco::creaLivello(int liv)
{
	Giocatore player(posGiocatoreX[liv], posGiocatoreY[liv]); 		//  uso il costruttore di player;

	for (int i = 0; i<numCasse[liv]; i++)
		casse.push_back(new Cassa(posCasseXi[liv][i], posCasseYi[liv][i], posCasseXf[liv][i], posCasseYf[liv][i]));

	for (int i = 0; i<numMuri[liv]; i++)
		muri.push_back(new Muro(posMuriX[liv][i], posMuriY[liv][i]));

	Livello l(player, casse, muri);
	l.gioca();

	/*for(int i=0; i<numMuri[liv]; i++)
	delete muri[i];
	for(int i=0; i<numCasse[liv]; i++)
	delete casse[i];*/
}

void rimuovi(vector<int> livelli, int pos, int& num)
{
	for (int i = pos; i<num; i++)
		livelli[i] = livelli[i + 1];
	livelli.pop_back();
	num--;
}

void GestoreGioco::Modalita()
{

	srand(time(0));
	creaLivello(0);
	/*ALLEGRO_DISPLAY* display=al_create_display(800,700);
	if(!display)
	{
	cerr<<"no display"<<endl;
	}

	const float FPS=30;
	ALLEGRO_TIMER* timer=al_create_timer(1/FPS);
	if(!timer)
	{
	cerr<<"no timer"<<endl;
	}
	ALLEGRO_EVENT_QUEUE* event_queue=al_create_event_queue();
	if(!event_queue)
	{
	cerr<<"no event_queue"<<endl;
	}

	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_mouse_event_source());
	//ALLEGRO_BITMAP* arcade=al_load_bitmap("");
	//	ALLEGRO_BITMAP* scegli=al_load_bitmap("");

	int arcade_x, arcade_y, scegli_x, scegli_y, x=0, y=0;

	//cout<<"Scegli modalita"<<endl; 		// poi va cambiato con i bitmap per i messaggi
	al_clear_to_color(al_map_rgb(0,0,0));
	//al_draw_bitmap(arcade, arcade_x,arcade_y,0);
	//al_draw_bitmap(scegli, scegli_x,scegli_y,0);
	al_flip_display();
	al_start_timer(timer);
	/*while(true)
	{
	ALLEGRO_EVENT ev;
	al_wait_for_event(event_queue, &ev);
	if(ev.type == ALLEGRO_EVENT_TIMER)
	if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
	{
	x=ev.mouse.x;
	y=ev.mouse.y;
	break;
	}
	}

	if(x>=arcade_x && x<=arcade_x+64 && y>=arcade_y && y<=arcade_y+64)			// 64 è la dimensione del bitmap, da cambiare in caso
	{
	int num=numLivelli;
	vector<int> livelli;
	for(int i=0; i<num; i++)
	livelli.push_back(i+1);
	while(num>0)
	{
	int liv=rand()%num;
	creaLivello(liv);
	rimuovi(livelli, liv, num);
	}
	creaLivello(9);
	}

	else if(x>=scegli_x && x<=scegli_x+64 && y>=scegli_y && y<=scegli_y+64)			// 64 è la dimensione del bitmap, da cambiare in caso
	{
	int liv_x[numLivelli]={ };
	int liv_y[numLivelli]={ };
	vector<ALLEGRO_BITMAP*> liv;
	for(int i=0; i<numLivelli; i++)
	liv.push_back(NULL);
	liv[0]=al_load_bitmap("liv1");
	liv[1]=al_load_bitmap("liv2");
	liv[2]=al_load_bitmap("liv3");
	liv[3]=al_load_bitmap("liv4");
	liv[4]=al_load_bitmap("liv5");
	liv[5]=al_load_bitmap("liv6");
	liv[6]=al_load_bitmap("liv7");
	liv[7]=al_load_bitmap("liv8");
	liv[8]=al_load_bitmap("liv9");
	al_clear_to_color(al_map_rgb(0,0,0));

	for(int i=0; i<numLivelli; i++)
	al_draw_bitmap(liv[i],liv_x[i],liv_y[i],0);

	al_flip_display();

	while(true)
	{
	int x1=0, y1=0;
	ALLEGRO_EVENT ev;
	al_wait_for_event(event_queue, &ev);
	if(ev.type == ALLEGRO_EVENT_TIMER)
	{
	if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
	{
	x1=ev.mouse.x;
	y1=ev.mouse.y;
	}

	for(int i=0; i<numLivelli; i++)
	if(x1>=liv_x[i] && x1<=liv_x[i]+64 && y1>=liv_y[i] && y1<=liv_y[i]+64)
	{
	creaLivello(i);
	break;
	}
	}
	else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
	break;
	}
	for(int i=0; i<numLivelli; i++)
	al_destroy_bitmap(liv[i]);
	}
	al_destroy_bitmap(arcade);
	al_destroy_bitmap(scegli);
	al_destroy_timer(timer);
	al_destroy_event_queue(event_queue);
	al_destroy_display(display);*/
}

void GestoreGioco::inizializzaAllegro()
{
	if (!al_init())
	{
		cerr << "no allegro" << endl;
	}

	if (!al_init_image_addon())
	{
		cerr << "failed initialisation image" << endl;
	}

	if (!al_init_primitives_addon())
	{
		cerr << "failed initialisation primitives" << endl;
	}

	if (!al_init_native_dialog_addon())
	{
		cerr << "failed initialisation dialog" << endl;
	}

	if (!al_install_mouse())
	{
		cerr << "no mouse" << endl;
	}
}