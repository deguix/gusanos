#include "sounds.h"

class sound_list *sounds;

sound::~sound()
{
  if(prev!=NULL) prev->next=next;
  if(next!=NULL) next->prev=prev;
  else sounds->end=prev;
  destroy_sample(snd);
};

sound_list::sound_list()
{
	start=new sound;
	end = start;
	start->next = start->prev = NULL;
};

sound_list::~sound_list()
{

};

class sound* sound_list::load(char* sound_name)
{
	class sound *curr;
	char tmp3[1024];
	
	curr=start;
	while (curr->next!=NULL)
	{
		curr=curr->next;
		if (strcmp(curr->name,sound_name)==0)
		{
			return curr;
		};
	};
	
	end->next=new sound;
	curr=end->next;
	curr->prev=end;
	curr->next=NULL;
	end=curr;
	
	strcpy(end->name,sound_name);
  strcpy(tmp3,game->mod);
	strcat(tmp3,"/sounds/");
	strcat(tmp3,sound_name);
	end->snd=load_sample(tmp3);
  if (end->snd==NULL)
  {
    strcpy(tmp3,"default/sounds/");
    strcat(tmp3,sound_name);
    end->snd=load_sample(tmp3);
  };
	return end;
};
