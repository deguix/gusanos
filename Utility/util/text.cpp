#include "text.h"
#include <list>
#include <cctype>

/********************** separate_str_by ****************************************** 
*  separates the string in 2 chunks the first chunk is from index 0 to the first *
*  occurence of the given char, the second chunk is the rest of the src string   *
*********************************************************************************/

/*
// should be changed to std::pair<std::string,std::string> acording to Gliptitc
void separate_str_by(char ch, const std::string &src, std::string &left, std::string &right)
{
	int leftIndex = 0;
	int rightIndex = 0;
	
	if (!src.empty())
	{
		leftIndex = src.find_first_not_of(ch);
		if (leftIndex != std::string::npos)
		{
			rightIndex = src.find_first_of(ch, leftIndex);
			if (rightIndex != std::string::npos)
			{
				left = src.substr(leftIndex, rightIndex - leftIndex);
				
				leftIndex = src.find_first_not_of(ch,rightIndex);
				if (leftIndex != std::string::npos)
				{
					right = src.substr(leftIndex);
				}
			}else
			{
				left = src.substr(leftIndex);
				right.clear();
			}
		}
	}
}

std::list<std::string> tokenize(const std::string &text)
{
	int left = 0;
	int right = 0;

	char lastChar = ' ';
	
	std::list<std::string> stringList;
	
	while (right != std::string::npos)
	{
		left = text.find_first_not_of(lastChar, right);
		
		if (left != std::string::npos)
		{
			if ( text[left] == '"' )
			{
				left++;
				right = text.find_first_of('"',left);
			}else
				right = text.find_first_of("; ",left);
			if (right != std::string::npos)
			{
				lastChar = text[right];
				
				if (right > left)
				stringList.push_back( text.substr(left, right - left) );
				
				if ( lastChar == ';' )
					stringList.push_back( ";" );
			}else
			stringList.push_back( text.substr(left) );
		}
		else
			right = std::string::npos;
	}
	
	return stringList;
}


std::list< std::list<std::string> > text2Tree(const std::string &text)
{
	int left = 0;
	int right = 0;
	
	std::list< std::list<std::string> > argTree;
	
	std::list<std::string> stringList = tokenize(text);
	
	if (!stringList.empty())
	{
		argTree.push_back(std::list<std::string>());
		std::list<std::string>::iterator tokensIter = stringList.begin();
		while (tokensIter != stringList.end())
		{
			if ( (*tokensIter) == ";" )
			{
				argTree.push_back(std::list<std::string>());
			}else
			{
				std::list< std::list<std::string> >::iterator iter = argTree.end();
				iter--;
				(*iter).push_back( (*tokensIter) );
			}
			tokensIter++;
		}
	}
	return argTree;
}
*/
namespace
{
	typedef std::string::size_type size_type; 
	
	int minimum(size_type a, size_type b, size_type c)
	{
		size_type min = a;
		if(b < min)
			min = b;
		if(c < min)
			min = c;
		return min;
	}
}

int levenshteinDistance(std::string const& a, std::string const& b)
{
	if(a == b)
		return 0;

	// n = alen, m = blen
	size_type alen = a.size();
	size_type blen = b.size();
	
	if(alen && blen)
	{
		++alen; ++blen;
		size_type* d = new size_type[alen * blen];
		
		for(size_type k = 0; k < alen; ++k)
			d[k] = k;
		
		for(size_type k = 0; k < blen; ++k)
			d[k * alen] = k;
			
		for(size_type i = 1; i < alen; ++i)
		for(size_type j = 1; j < blen; ++j)
		{
			size_type cost = (tolower(a[i - 1]) == tolower(b[j - 1])) ? 0 : 1;

        	d[j*alen + i] = minimum(
				d[(j - 1)*alen + i] + 1,
				d[j*alen + i - 1] + 1,
				d[(j - 1)*alen + i - 1] + cost
			);
		}
		size_type distance = d[alen*blen - 1];
		delete[] d;
		return distance;
	}
	else
		return std::max(alen, blen);
}
