#include "weapon_type.h"

#include "sprite.h"
#include "text.h"
#include "parser.h"

#include <string>
#include <vector>
#include <fstream>

using namespace std;

WeaponType::WeaponType()
{
	ammo = 1;
	reloadTime = 0;
	laserSightIntensity = 0;
	laserSightRange = 0;

   firecone = NULL;

	primaryShoot = NULL;
	primaryPressed = NULL;
	primaryReleased = NULL;
	outOfAmmo = NULL;
}

WeaponType::~WeaponType()
{
	if (primaryShoot) delete primaryShoot;
	if (primaryPressed) delete primaryPressed;
	if (primaryReleased) delete primaryReleased;
	if (outOfAmmo) delete outOfAmmo;
}

bool WeaponType::load(const string &filename)
{

	ifstream fileStream;
	
	fileStream.open( filename.c_str() );
	
	if ( fileStream.is_open() )
	{
		string parseLine;
		Event *currEvent = NULL;
		while ( !fileStream.eof() )
		{
			getline( fileStream, parseLine );
			if ( !parseLine.empty() )
			{
				string var;
				string val;
				
				vector<string> tokens;
				tokens = Parser::tokenize ( parseLine );
				int lineID = Parser::identifyLine( tokens );
				
				vector<string>::iterator iter = tokens.begin();
				
				if ( lineID == Parser::PROP_ASSIGMENT )
				{
					var = *iter;
					iter++;
					if ( iter != tokens.end() && *iter == "=")
					{
						iter++;
						if ( iter != tokens.end() )
							val = *iter;
					}
					
					if ( var == "ammo" ) ammo= cast<int>(val);
					else if ( var == "reload_time" ) reloadTime = cast<int>(val);
					else if ( var == "laser_sight_intensity" ) laserSightIntensity = cast<float>(val);
					else if ( var == "laser_sight_range" ) laserSightRange = cast<float>(val);
					else if ( var == "firecone" ) firecone = spriteList.load(val);
				}
				
				if ( lineID == Parser::EVENT_START )
				{
					iter++;
					string eventName = *iter;
					if ( eventName == "primary_shoot" )
					{
						currEvent = new Event;
						primaryShoot = currEvent;
					}
					else if ( eventName == "primary_press" )
					{
						currEvent = new Event;
						primaryPressed = currEvent;
					}
					else if ( eventName == "primary_release" )
					{
						currEvent = new Event;
						primaryReleased = currEvent;
					}
					else currEvent = NULL;
				}
				
				if ( lineID == Parser::ACTION && currEvent != NULL)
				{
					currEvent->addAction(*iter, Parser::getActionParams( tokens ));
				}
				
			}
		}
		fileStream.close();
		return true;
	} else
	{
		return false;
	}
}

