#include"livello.h"

Livello::Livello(const Giocatore& g, vector<Cassa*> c, vector<Muro*> m)
{
	this->inizializzaAllegro();
	mosse.push(new Mossa(g, c));		// mossa 0		come inizia il livello
	muri=m;

	mappa=new int*[12];
	for(int i=0; i<12; i++)
		mappa[i]=new int [10];
	
	for(int i=0; i<12; i++)
		for(int j=0; j<10; j++)
			mappa[i][j]=0;

	// 0=niente	 1=muri	 2=casse  4=giocatore
	int x=g.getX()*12/768;
	int y=g.getY()*10/640;
	mappa[x][y]=4;
	
	for(int i=0; i<c.size(); i++)
	{	
		x=c[i]->getX()*12/768;
		y=c[i]->getY()*10/640;		
		mappa[x][y]=2;
	}
	
	for(int i=0; i<m.size(); i++)
	{
		x=m[i]->getX()*12/768;
		y=m[i]->getY()*10/640;
		mappa[x][y]=1;
	}
	
	for(int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
			cout<<mappa[j][i]<<" ";
		cout<<endl;
	}
	cout<<endl;
}
	
bool clear(stack<Mossa*> mosse)
{
	if(mosse.size()<2)
		return false;
	
	while(mosse.size()>1)
	{
		mosse.pop();
	}

	return true;

}

void Livello::gioca()
{
// DISEGNA I MURI
	for(int i=0; i<muri.size(); i++)
		al_draw_bitmap(muro, muri[i]->getX(), muri[i]->getY(), 0);

	vector<Cassa*> casse=mosse.top()->getCasse();	

// disegna le casse in posizione iniziale
	for(int i=0; i<casse.size(); i++)
		al_draw_bitmap(cassa, casse[i]->getX(), casse[i]->getY(), 0);

	al_flip_display();
	
	enum DIR {DOWN = 0, LEFT,UP, RIGHT};  
	ALLEGRO_KEYBOARD_STATE keystate;
	
	ALLEGRO_BITMAP* giocatore = al_load_bitmap("bgeorge.png");
	//ALLEGRO_BITMAP* undo = al_load_bitmap("undo");
	//ALLEGRO_BITMAP* rigioca = al_load_bitmap("rigioca");

	int undo_x, undo_y, rigioca_x, rigioca_y, a,b;
	bool active = false, draw=false;
	int dir = DOWN, sourceY = 0;

	al_set_target_bitmap(giocatore);
	al_set_target_bitmap(al_get_backbuffer(display));

	Giocatore player=mosse.top()->getPlayer();
	int x=player.getX();
	int y=player.getY();
	
	al_flip_display();
	
	al_start_timer(timer);

	while (true) 
	{	
		int player_x=player.getX()*12/768;
		int player_y=player.getY()*10/640;
	
		ALLEGRO_EVENT events;
		al_wait_for_event(event_queue, &events);
		al_get_keyboard_state(&keystate);

		if (events.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			break;
      
		if (events.type == ALLEGRO_EVENT_TIMER)
		{
			active = true;
			draw=true;
		
			// 0=niente	 1=muri	 2=casse  4=giocatore
			if (al_key_down(&keystate, ALLEGRO_KEY_DOWN))
			{	
				dir = DOWN;
				if(mappa[player_x][player_y+1]==0)
				{
					y=player.sposta(dir);
					mappa[player_x][player_y+1]=4;
					mappa[player_x][player_y]=0;
for(int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
			cout<<mappa[j][i]<<" ";
		cout<<endl;
	}
		cout<<endl;
				}
				if(mappa[player_x][player_y+1]==2 && (mappa[player_x][player_y+2]==0 || mappa[player_x][player_y+2]==3))
				{	
					int indice=0; // playerX*800/12=200		playerX=200*12/800
					cout<<"x= "<<(player_x-1)*768/12<<"  y="<<(player_y-1)*640/10<<endl;
					for(int i=0; i<casse.size();i++)
						if(casse[i]->getX()==(player_x-1)*768/12 && casse[i]->getY()==(player_y-1)*640/10)
						{
							indice=i;
							cout<<"prima  "<<casse[i]->getX()<<"   "<<casse[indice]->getY()<<endl;
							casse[i]->sposta(dir);
							break;		
						}
					cout<<"dopo  "<<casse[indice]->getX()<<"   "<<casse[indice]->getY()<<endl;
					y=player.sposta(dir);		
					mappa[player_x][player_y+1]=4;
					mappa[player_x][player_y]=0;
					mappa[player_x][player_y+1]=2;
				}
					
			}
			else if (al_key_down(&keystate, ALLEGRO_KEY_UP))
			{
				dir = UP;
				if(mappa[player_x][player_y-1]==0)
				{
					y=player.sposta(dir);
					mappa[player_x][player_y-1]=4;
					mappa[player_x][player_y]=0;
for(int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
			cout<<mappa[j][i]<<" ";
		cout<<endl;
	}
		cout<<endl;
				}
				else if(mappa[player_x][player_y-1]==2 && (mappa[player_x][player_y-2]==0 || mappa[player_x][player_y-2]==3))
				{	
					for(int i=0; i<casse.size();i++)
						if(casse[i]->getX()==player_x*768/12 && casse[i]->getY()==player_y*640/10)
						{
							casse[i]->sposta(dir);
							break;		
						}
					y=player.sposta(dir);		
					mappa[player_x][player_y-1]=4;
					mappa[player_x][player_y]=0;
					mappa[player_x][player_y-1]=2;
				}
				
			}
			else if (al_key_down(&keystate, ALLEGRO_KEY_RIGHT))
			{
				dir = RIGHT;				
				if(mappa[player_x+1][player_y]==0)
				{
					x=player.sposta(dir);
					mappa[player_x+1][player_y]=4;
					mappa[player_x][player_y]=0;
for(int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
			cout<<mappa[j][i]<<" ";
		cout<<endl;
	}
		cout<<endl;
				}			
				else if(mappa[player_x+1][player_y]==2 && (mappa[player_x+2][player_y]==0 || mappa[player_x+2][player_y]==3))
				{	
					for(int i=0; i<casse.size();i++)
						if(casse[i]->getX()==(player_x-1)*768/12 && casse[i]->getY()==(player_y-1)*640/10 )
						{
							casse[i]->sposta(dir);
							break;		
						}
					x=player.sposta(dir);		
					mappa[player_x+1][player_y]=4;
					mappa[player_x][player_y]=0;
					mappa[player_x+2][player_y]=2;
				}
			}
			else if (al_key_down(&keystate, ALLEGRO_KEY_LEFT))
			{
				dir = LEFT;
				if(mappa[player_x-1][player_y]==0)
				{
					x=player.sposta(dir);
					mappa[player_x-1][player_y]=4;
					mappa[player_x][player_y]=0;
for(int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
			cout<<mappa[j][i]<<" ";
		cout<<endl;
	}
		cout<<endl;
				}
				else if(mappa[player_x-1][player_y]==2 && (mappa[player_x-2][player_y]==0 || mappa[player_x-2][player_y]==3))
				{	
					for(int i=0; i<casse.size();i++)
						if(casse[i]->getX()==player_x*768/12 && casse[i]->getY()==player_y*640/10)
						{
							casse[i]->sposta(dir);
							break;		
						}
					x=player.sposta(dir);		
					mappa[player_x-1][player_y]=4;
					mappa[player_x][player_y]=0;
					mappa[player_x-2][player_y]=2;

				}
			}
			else
				active = false;

			if (active)
				sourceY += al_get_bitmap_width(giocatore) / 4;
			if(!active || sourceY >= al_get_bitmap_width(giocatore))
				sourceY = 0;

			if(draw && al_is_event_queue_empty(event_queue))
			{
				draw=false;
				for(int i=0; i<muri.size(); i++)
					al_draw_bitmap(muro, muri[i]->getX(), muri[i]->getY(), 0);

				for(int i=0; i<casse.size(); i++)
				{
					al_draw_bitmap(cassa, casse[i]->getX(), casse[i]->getY(), 0);
					al_draw_filled_circle(casse[i]->getEndX(),casse[i]->getEndY(), 7, al_map_rgb(255,0,0));
				}

				al_draw_bitmap_region(giocatore, dir * al_get_bitmap_width(giocatore)/4, sourceY, al_get_bitmap_width(giocatore)/4, 										al_get_bitmap_height(giocatore) /4 , x, y, 0);
	
			//	al_draw_bitmap(undo, undo_x, undo_y, 0);
			//	al_draw_bitmap(rigioca, rigioca_x, rigioca_y,0);
				al_flip_display();
				al_clear_to_color(al_map_rgb(0,0,0));
			}
		}
		
		mosse.push(new Mossa(player, casse));

		if(events.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
		{
			a=events.mouse.x;
			b=events.mouse.y;
			
			if(a>=rigioca_x && a<=rigioca_x+64 && b>=rigioca_y && b<=rigioca_y+64)
			{
				clear(mosse);
				casse=mosse.top()->getCasse();			
				player=mosse.top()->getPlayer();
				x=player.getX();
				y=player.getY();	
			}
		
			if(a>=undo_x && a<=undo_x+64 && b>=undo_y && b<=undo_y+64)
			{
				mosse.pop();
				casse=mosse.top()->getCasse();
				player=mosse.top()->getPlayer();
				x=player.getX();
				y=player.getY();	
			}
		}

		if(Superato(casse))
		{
			clear(mosse);
			mosse.pop();
		//	delete muri;
			al_destroy_bitmap(cassa);
			al_destroy_bitmap(muro);
			al_destroy_timer(timer);
			al_destroy_event_queue(event_queue);
			al_destroy_display(display);
			al_destroy_bitmap(giocatore);
		//	al_destroy_bitmap(rigioca);
		//	al_destroy_bitmap(undo);
			break;
		}
	}

}

bool Livello::Superato(vector<Cassa*> casse)	const
{
	for(int i=0; i<casse.size(); i++)
		if(!casse[i]->verifica())
			return false;
	
	return true;
}

void Livello::inizializzaAllegro()
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
	
	if(!al_install_mouse())
	{
		cerr<<"no mouse"<<endl;
	}		
	
	display=al_create_display(800,700);

	if(!display)
	{
		cerr<<"no display"<<endl;
	}
	al_set_window_title(display,"Sokoban");

	const float FPS=10;
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
	
	cassa=al_load_bitmap("box.png");
	muro=al_load_bitmap("wall.png");
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_mouse_event_source());		
}


