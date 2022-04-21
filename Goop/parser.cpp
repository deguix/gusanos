#include "parser.h"

#include <vector>
#include <string>

namespace Parser
{
	
	const std::vector<std::string> tokenize(const std::string &text)
	{
		size_t left = 0;
		size_t right = 0;
	
		std::string lastChar = " ";
		
		std::vector<std::string> stringList;
		
		while (right != std::string::npos)
		{
			left = text.find_first_not_of(lastChar, right);
			
			if (left != std::string::npos)
			{
				right = text.find_first_of(", =()",left);
				if (right != std::string::npos)
				{
					lastChar = text[right];
					
					if (right > left)
					stringList.push_back( text.substr(left, right - left) );
					
					if ( lastChar != " " )
					{
						stringList.push_back( lastChar );
					}
				}else
				stringList.push_back( text.substr(left) );
			}
			else
				right = std::string::npos;
		}
		
		return stringList;
	}
	
	// May the god of inderdaad forgive me for this sin :(
	int identifyLine( const std::vector<std::string> & tokens )
	{
		int id = INVALID;
		
		if ( tokens.size() > 1 )
		{
			std::vector<std::string>::const_iterator token = tokens.begin();
			
			if( (*token)[0] == '#' ) // Is it a comment?
				return INVALID;
			
			if ( *token == "on" ) //First token is 'on'? Then its the start of an event
			{
				id = EVENT_START;
			} else
			{
				token++;
				
				if ( *token == "=" ) // Second token is '='? Then its a property assignment
				{
					token++;
					if ( token != tokens.end() )
					{
						id = PROP_ASSIGMENT;
					}
				}
				
				if ( *token == "(" ) // Second token is '('? Then its an action
				{
					// I check for the closing brackets of the action
					for(; token != tokens.end() ; token++) 
					{
						if ( *token == ")" )
							id = ACTION;
					}
				}
				
			}
		}
		return id;
	}
	
	std::vector<std::string> getActionParams( const std::vector<std::string> & tokens )
	{
		std::vector<std::string>::const_iterator token = tokens.begin();
		
		std::vector<std::string> params;
		
		if( tokens.size() > 3 )
		{
			token++;
			token++;
			while( token != tokens.end())
			{
				if ( *token == ")" ) break;
				if ( *token != "," )
				{
					params.push_back(*token);
				}
				token++;
			}
		}
		
		return params;
	}
}












