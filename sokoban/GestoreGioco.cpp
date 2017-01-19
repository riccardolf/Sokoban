#include"GestoreGioco.h"

void GestoreGioco::Modalita()
{
	this->inizializzaAllegro();
	srand(time(0);
	int liv=0;

	cout<<"Scegli modalita"<<endl; 		// poi va cambiato con i bitmap
	if(arcade)
	{	
		Livello1();
		Livello2();
		Livello3();
	}
	if(scegliLiv)
	{
		cin>>liv;
		if(liv==1)
			Livello1();
		if(liv==2)
			Livello2();
		if(liv==3)
			Livelo3();
	}
}

void GestoreGioco::Livello1()
{
	Giocatore pl(3,5); 		//  uso il costruttore di player;
	player=pl;
	
	Cassa c1(152,8); // INSERIRE x e y iniziali delle casse
	casse.push_back(c);

	Cassa c2(152,8); // INSERIRE x e y iniziali delle casse
	casse.push_back(c2);

	Cassa c3(152,8); // INSERIRE x e y iniziali delle casse
	casse.push_back(c3);

	Cassa c4(152,8); // INSERIRE x e y iniziali delle casse
	casse.push_back(c4);

	Muro m1(6,120); 		// inserire x e y iniziali del muro
	muri.push_back(m1);

	Muro m2(6,120); 		// inserire x e y iniziali del muro
	muri.push_back(m2);
	Muro m3(6,120); 		// inserire x e y iniziali del muro
	muri.push_back(m3);
	Muro m4(6,120); 		// inserire x e y iniziali del muro
	muri.push_back(m4);
	
	Partita p(player,casse,muri);
	p.gioca();
}

void GestoreGioco::Livello2()
{

}

void GestoreGioco::Livello3()
{

}


const float FPS=30;
void Partita::inizializzaAllegro()
{
	if(!al_init())
	{
		cerr<<"no allegro"<<endl;
	}

	if(!al_init_image_addon())
	{ 
	  cerr<<"failed initialisation image"<<endl;
	}
	
	if(!al_init_primitives_addon())
	{ 
	  cerr<<"failed initialisation primitives"<<endl;
	}

	if(!al_init_native_dialog_addon())
	{ 
	  cerr<<"failed initialisation dialog"<<endl;
	}

	if(!al_install_keyboard())
	{
		cerr<<"no keyboard"<<endl;
	}

	display=al_create_display(800,600);

	if(!display)
	{
		cerr<<"no display"<<endl;
	}
	al_set_window_title(display,"Sokoban");

	timer=al_create_timer(1/FPS);
	if(!timer)
	{
		cerr<<"no timer"<<endl;
	}

	event_queue=al_create_event_queue();
	if(!event_queue)
	{
		cerr<<"no event_queue"<<endl;
	}

	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());	
	

