#include"GestoreGioco.h"

GestoreGioco::GestoreGioco(int nC, int nM)
{
	this->inizializzaAllegro();
	numCasse=nC;
	numMuri=nM;
}	
void GestoreGioco::gioca()
{
	creaPartita();
	
	while(true)
	{
		ALLEGRO EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if(ev.type==ALLEGRO_EVENT_DISPLAY_CLOSE)
			break;
	}

}

void GestoreGioco::creaPartita()
{
	Giocatore pl(0,0); 		//  uso il costruttore di player;
	
	player=pl;

	for(int i=0; i<numCasse; i++)
	{
		Cassa c(); // INSERIRE x e y iniziali delle casse
		casse.push_back(c);
	}
	for(int i=0; i<numMuri; i++)
	{
		Muro m(); 		// inserire x e y iniziali del muro
		muri.push_back(m);
	}
	
//disegna il player	in posizione iniziale
	al_draw_bitmap(player.getPlayer(), player.getX(), player.getY(), 0);

// DISEGNA I MURI
	for(int i=0; i<numMuri; i++)
		al_draw_bitmap(muri[i].getMuro(), muri[i].getX(), muri[i].getY(), 0);

// disegna le casse in posizione iniziale
	for(int i=0; i<numCasse; i++)
		al_draw_bitmap(casse[i].getCassa(), casse[i].getX(), casse[i].getY(), 0);
	
	al_flip_display();
}

void GestoreGioco::inizializzaAllegro()
{
	if(!al_init())
	{
		cerr<<"no allegro"<<endl;
	}

	display=al_create_display(640,480);

	if(!display)
	{
		cerr<<"no display"<<endl;
	}
	al_set_window_title("Sokoban");

	timer=al_create_timer(1/60);
	if(!timer)
	{
		cerr<<"no timer"<<endl;
	}

	event_queue=al_create_event_queue();
	if(!event_queue)
	{
		cerr<<"no event_queue"<<endl;
	}
}
