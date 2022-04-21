/* Generated by re2c 0.9.10 on Tue Jan 31 19:15:08 2006 */
#line 1 "OmfgScript/omfg_script_parser.h.re"
#include <memory>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <iostream>
using std::auto_ptr;

#include <boost/lexical_cast.hpp>
using boost::lexical_cast;
#include <string>
#include <map>
#include <stdexcept>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::map;

/*
IDENT : [A-Za-z][A-Za-z0-9]*
{
	CONSTRUCT(b, e) : str(b, e) {}
	
	virtual double toDouble()
	{ throw std::runtime_error("Object is not a double"); }
	
	virtual std::string const& toString()
	{ return str; }
	
	virtual std::list<TokenBase*> const& toList()
	{ throw std::runtime_error("Object is not a list"); }
	
	virtual TokenBase::Type::type type() { return TokenBase::Type::String; }
	
	std::string str;
} ;

NEWLINE : [\r\n]* ;

event<> = ON IDENT<name> LPARAN [parameters] RPARAN NEWLINE action* ;
*/

#define D(x) (std::cout << x << std::endl)

namespace OmfgScript{
template<class T>
struct TGrammar {
#define self (static_cast<T *>(this))
~TGrammar() { free(buffer); }
struct Token : public  TokenBase  { typedef std::auto_ptr<Token> ptr;

	Token(T& g_) : TokenBase(g_.getLoc()), g(g_) {}
	
	T& g;

virtual ~Token() {}
};

struct STRING : public Token {
typedef std::auto_ptr<STRING> ptr;
#define CONSTRUCT(b_, e_) STRING(T& g, char const* b_, char const* e_)

	CONSTRUCT(b, e) : Token(g), str(b, e) { }

	virtual std::string const& toString()
	{ return str; }
	
	virtual TokenBase::Type::type type() { return TokenBase::Type::String; }
	
	virtual std::ostream& output(std::ostream& s) { s << str; return s; }
	
	virtual void calcCRC(boost::crc_32_type& crc)
	{
		crc.process_bytes(str.data(), str.size());
	}
	
	std::string str;

#undef CONSTRUCT
};
struct INTEGER : public Token {
typedef std::auto_ptr<INTEGER> ptr;
#define CONSTRUCT(b_, e_) INTEGER(T& g, char const* b_, char const* e_)

	CONSTRUCT(b, e) : Token(g) { v = lexical_cast<int>(std::string(b, e)); }
	
	INTEGER(T& g, int i) : Token(g), v(i) {}
	
	virtual double toDouble()
	{ return v; }
	
	virtual int toInt()
	{ return v; }
	
	virtual TokenBase::Type::type type() { return TokenBase::Type::Int; }
	
	virtual std::ostream& output(std::ostream& s) { s << v; return s; }
	
	virtual void calcCRC(boost::crc_32_type& crc)
	{
		crc(v & 0xFF);
		crc((v >> 8) & 0xFF);
		crc((v >> 16) & 0xFF);
		crc((v >> 24) & 0xFF);
	}
	
	int v;

#undef CONSTRUCT
};
struct NUMBER : public Token {
typedef std::auto_ptr<NUMBER> ptr;
#define CONSTRUCT(b_, e_) NUMBER(T& g, char const* b_, char const* e_)

	CONSTRUCT(b, e) : Token(g) { v = lexical_cast<double>(std::string(b, e)); }
	
	virtual double toDouble()
	{ return v; }
	
	virtual int toInt()
	{
		this->g.semanticWarning("Number converted to integer may lose precision", this->loc);
		return static_cast<int>(v);
	}
	
	virtual TokenBase::Type::type type() { return TokenBase::Type::Double; }
	
	virtual std::ostream& output(std::ostream& s) { s << v; return s; }
	
	virtual void calcCRC(boost::crc_32_type& crc)
	{
		//TODO: Less tolerance
		int vi = (int)v;
		crc(vi & 0xFF);
		crc((vi >> 8) & 0xFF);
		crc((vi >> 16) & 0xFF);
		crc((vi >> 24) & 0xFF);
	}
	
	double v;

#undef CONSTRUCT
};
void next() {
#define YYCTYPE char
#define YYCURSOR curp
#define YYLIMIT limit
#define YYMARKER marker
#define YYFILL(n) fill(n)
retry:
begin = curp;
goto append; append:
#line 155 "OmfgScript/omfg_script_parser.h.re"

switch(state) {case 0:

#line 160 "<stdout>"
{
	YYCTYPE yych;
	unsigned int yyaccept;
	goto yy0;
	++YYCURSOR;
yy0:
	if((YYLIMIT - YYCURSOR) < 6) YYFILL(6);
	yych = *YYCURSOR;
	switch(yych){
	case 0x00:	goto yy42;
	case 0x09:	case 0x0D:	case ' ':	goto yy33;
	case 0x0A:	goto yy37;
	case '"':	goto yy39;
	case '#':	goto yy35;
	case '(':	goto yy8;
	case ')':	goto yy10;
	case '*':	goto yy26;
	case '+':	goto yy22;
	case ',':	goto yy20;
	case '-':	goto yy24;
	case '/':	goto yy28;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy31;
	case '<':	goto yy41;
	case '=':	goto yy6;
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case '_':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':	case 'p':
	case 'q':
	case 'r':
	case 's':	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy30;
	case '[':	goto yy12;
	case ']':	goto yy14;
	case 'f':	goto yy4;
	case 'o':	goto yy5;
	case 't':	goto yy2;
	case '{':	goto yy16;
	case '}':	goto yy18;
	default:	goto yy44;
	}
yy2:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case 'r':	goto yy69;
	default:	goto yy61;
	}
yy3:
#line 173 "OmfgScript/omfg_script_parser.h.re"
{  cur = 16; curData.reset(new STRING(*self, begin, YYCURSOR)); return; }
#line 256 "<stdout>"
yy4:	yych = *++YYCURSOR;
	switch(yych){
	case 'a':	goto yy64;
	default:	goto yy61;
	}
yy5:	yych = *++YYCURSOR;
	switch(yych){
	case 'n':	goto yy62;
	default:	goto yy61;
	}
yy6:	++YYCURSOR;
	goto yy7;
yy7:
#line 161 "OmfgScript/omfg_script_parser.h.re"
{  cur = 4; return; }
#line 272 "<stdout>"
yy8:	++YYCURSOR;
	goto yy9;
yy9:
#line 162 "OmfgScript/omfg_script_parser.h.re"
{  cur = 5; return; }
#line 278 "<stdout>"
yy10:	++YYCURSOR;
	goto yy11;
yy11:
#line 163 "OmfgScript/omfg_script_parser.h.re"
{  cur = 6; return; }
#line 284 "<stdout>"
yy12:	++YYCURSOR;
	goto yy13;
yy13:
#line 164 "OmfgScript/omfg_script_parser.h.re"
{  cur = 7; return; }
#line 290 "<stdout>"
yy14:	++YYCURSOR;
	goto yy15;
yy15:
#line 165 "OmfgScript/omfg_script_parser.h.re"
{  cur = 8; return; }
#line 296 "<stdout>"
yy16:	++YYCURSOR;
	goto yy17;
yy17:
#line 166 "OmfgScript/omfg_script_parser.h.re"
{  cur = 9; return; }
#line 302 "<stdout>"
yy18:	++YYCURSOR;
	goto yy19;
yy19:
#line 167 "OmfgScript/omfg_script_parser.h.re"
{  cur = 10; return; }
#line 308 "<stdout>"
yy20:	++YYCURSOR;
	goto yy21;
yy21:
#line 168 "OmfgScript/omfg_script_parser.h.re"
{  cur = 11; return; }
#line 314 "<stdout>"
yy22:	++YYCURSOR;
	goto yy23;
yy23:
#line 169 "OmfgScript/omfg_script_parser.h.re"
{  cur = 12; return; }
#line 320 "<stdout>"
yy24:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy58;
	default:	goto yy25;
	}
yy25:
#line 170 "OmfgScript/omfg_script_parser.h.re"
{  cur = 13; return; }
#line 338 "<stdout>"
yy26:	++YYCURSOR;
	goto yy27;
yy27:
#line 171 "OmfgScript/omfg_script_parser.h.re"
{  cur = 14; return; }
#line 344 "<stdout>"
yy28:	++YYCURSOR;
	goto yy29;
yy29:
#line 172 "OmfgScript/omfg_script_parser.h.re"
{  cur = 15; return; }
#line 350 "<stdout>"
yy30:	yych = *++YYCURSOR;
	goto yy61;
yy31:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '.':	goto yy55;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy58;
	default:	goto yy32;
	}
yy32:
#line 174 "OmfgScript/omfg_script_parser.h.re"
{  cur = 17; curData.reset(new INTEGER(*self, begin, YYCURSOR)); return; }
#line 371 "<stdout>"
yy33:	++YYCURSOR;
	goto yy34;
yy34:
#line 176 "OmfgScript/omfg_script_parser.h.re"
{ 
#define linecounter() (++this->line)
#define skip() goto retry
#define append() goto append
#define setstate(x_) (state = (x_))
 skip(); 
#undef setstate
#undef append
#undef skip
#undef linecounter
 cur = 19; return; }
#line 387 "<stdout>"
yy35:	++YYCURSOR;
	yych = *YYCURSOR;
	goto yy54;
yy36:
#line 187 "OmfgScript/omfg_script_parser.h.re"
{ 
#define linecounter() (++this->line)
#define skip() goto retry
#define append() goto append
#define setstate(x_) (state = (x_))
 skip(); 
#undef setstate
#undef append
#undef skip
#undef linecounter
 cur = 20; return; }
#line 404 "<stdout>"
yy37:	++YYCURSOR;
	goto yy38;
yy38:
#line 198 "OmfgScript/omfg_script_parser.h.re"
{ 
#define linecounter() (++this->line)
#define skip() goto retry
#define append() goto append
#define setstate(x_) (state = (x_))
 linecounter(); skip(); 
#undef setstate
#undef append
#undef skip
#undef linecounter
 cur = 21; return; }
#line 420 "<stdout>"
yy39:	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	if(yych >= 0x01)	goto yy50;
	goto yy40;
yy40:
#line 229 "OmfgScript/omfg_script_parser.h.re"
{ semanticError(std::string("Unknown character '") + *begin + "'"); goto retry; }
#line 428 "<stdout>"
yy41:	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	switch(yych){
	case '<':	goto yy45;
	default:	goto yy40;
	}
yy42:	++YYCURSOR;
	goto yy43;
yy43:
#line 228 "OmfgScript/omfg_script_parser.h.re"
{ cur = 0; return; }
#line 440 "<stdout>"
yy44:	yych = *++YYCURSOR;
	goto yy40;
yy45:	yych = *++YYCURSOR;
	switch(yych){
	case '<':	goto yy47;
	default:	goto yy46;
	}
yy46:	YYCURSOR = YYMARKER;
	switch(yyaccept){
	case 0:	goto yy40;
	}
yy47:	++YYCURSOR;
	goto yy48;
yy48:
#line 217 "OmfgScript/omfg_script_parser.h.re"
{ 
#define linecounter() (++this->line)
#define skip() goto retry
#define append() goto append
#define setstate(x_) (state = (x_))
 setstate(1); skip(); 
#undef setstate
#undef append
#undef skip
#undef linecounter
 cur = 23; return; }
#line 467 "<stdout>"
yy49:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy50;
yy50:	switch(yych){
	case 0x00:	goto yy46;
	case '"':	goto yy51;
	default:	goto yy49;
	}
yy51:	++YYCURSOR;
	goto yy52;
yy52:
#line 209 "OmfgScript/omfg_script_parser.h.re"
{ 
#define b (begin)
#define e (YYCURSOR)
 cur = 16; curData.reset(new STRING(*self, b + 1, e - 1)); return; 

#undef b
#undef e
}
#line 489 "<stdout>"
yy53:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy54;
yy54:	switch(yych){
	case 0x00:	case 0x0A:	case 0x0D:	goto yy36;
	default:	goto yy53;
	}
yy55:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy56;
yy56:	switch(yych){
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy55;
	default:	goto yy57;
	}
yy57:
#line 175 "OmfgScript/omfg_script_parser.h.re"
{  cur = 18; curData.reset(new NUMBER(*self, begin, YYCURSOR)); return; }
#line 518 "<stdout>"
yy58:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy59;
yy59:	switch(yych){
	case '.':	goto yy55;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy58;
	default:	goto yy32;
	}
yy60:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy61;
yy61:	switch(yych){
	case '-':
	case '.':
	case '/':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case '_':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy60;
	default:	goto yy3;
	}
yy62:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '-':
	case '.':
	case '/':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case '_':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy60;
	default:	goto yy63;
	}
yy63:
#line 160 "OmfgScript/omfg_script_parser.h.re"
{  cur = 3; return; }
#line 677 "<stdout>"
yy64:	yych = *++YYCURSOR;
	switch(yych){
	case 'l':	goto yy65;
	default:	goto yy61;
	}
yy65:	yych = *++YYCURSOR;
	switch(yych){
	case 's':	goto yy66;
	default:	goto yy61;
	}
yy66:	yych = *++YYCURSOR;
	switch(yych){
	case 'e':	goto yy67;
	default:	goto yy61;
	}
yy67:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '-':
	case '.':
	case '/':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case '_':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy60;
	default:	goto yy68;
	}
yy68:
#line 159 "OmfgScript/omfg_script_parser.h.re"
{  cur = 2; return; }
#line 763 "<stdout>"
yy69:	yych = *++YYCURSOR;
	switch(yych){
	case 'u':	goto yy70;
	default:	goto yy61;
	}
yy70:	yych = *++YYCURSOR;
	switch(yych){
	case 'e':	goto yy71;
	default:	goto yy61;
	}
yy71:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '-':
	case '.':
	case '/':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case '_':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy60;
	default:	goto yy72;
	}
yy72:
#line 158 "OmfgScript/omfg_script_parser.h.re"
{  cur = 1; return; }
#line 844 "<stdout>"
}
#line 230 "OmfgScript/omfg_script_parser.h.re"

break;
case 1:

#line 851 "<stdout>"
{
	YYCTYPE yych;
	unsigned int yyaccept;
	goto yy73;
	++YYCURSOR;
yy73:
	if((YYLIMIT - YYCURSOR) < 3) YYFILL(3);
	yych = *YYCURSOR;
	switch(yych){
	case 0x00:	goto yy78;
	case '>':	goto yy75;
	default:	goto yy77;
	}
yy75:	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	switch(yych){
	case '>':	goto yy80;
	default:	goto yy76;
	}
yy76:
#line 252 "OmfgScript/omfg_script_parser.h.re"
{ 
#define linecounter() (++this->line)
#define skip() goto retry
#define append() goto append
#define setstate(x_) (state = (x_))
 append(); 
#undef setstate
#undef append
#undef skip
#undef linecounter
 cur = 25; return; }
#line 884 "<stdout>"
yy77:	yych = *++YYCURSOR;
	goto yy76;
yy78:	++YYCURSOR;
	goto yy79;
yy79:
#line 263 "OmfgScript/omfg_script_parser.h.re"
{ cur = 0; return; }
#line 892 "<stdout>"
yy80:	yych = *++YYCURSOR;
	switch(yych){
	case '>':	goto yy82;
	default:	goto yy81;
	}
yy81:	YYCURSOR = YYMARKER;
	switch(yyaccept){
	case 0:	goto yy76;
	}
yy82:	++YYCURSOR;
	goto yy83;
yy83:
#line 234 "OmfgScript/omfg_script_parser.h.re"
{ 
#define linecounter() (++this->line)
#define skip() goto retry
#define append() goto append
#define setstate(x_) (state = (x_))
 setstate(0); 
#undef setstate
#undef append
#undef skip
#undef linecounter

#define b (begin)
#define e (YYCURSOR)
 cur = 16; curData.reset(new STRING(*self, b, e - 3)); return; 

#undef b
#undef e
}
#line 924 "<stdout>"
}
#line 265 "OmfgScript/omfg_script_parser.h.re"

break;
}
#undef YYCTYPE
#undef YYCURSOR
#undef YYLIMIT
#undef YYMARKER
#undef YYFILL
}
void fill(size_t s) {
size_t l = limit - begin;
if(buffer)
	memmove(buffer, begin, l);
size_t newSize = std::max(static_cast<size_t>(1024), l + s);
buffer = (char *)realloc(buffer, newSize);
size_t toRead = newSize - l;
size_t amountRead = self->read(&buffer[l], toRead);
if(amountRead == 0) { memset(&buffer[l], 0, toRead); }
else newSize = l+amountRead;
ptrdiff_t offs = buffer - begin;
curp += offs;
marker += offs;
begin = buffer;
limit = buffer + newSize;
}
struct ParsingAborted : public std::exception { };
void fatalError(std::string const& msg = "Syntax error") {
self->reportError(msg, self->getLoc());
throw ParsingAborted();
}
void syntaxError(std::string const& msg = "Syntax error") {
syntaxError(msg, self->getLoc());
}
void syntaxError(std::string const& msg, Location loc) {
self->reportError(msg, loc);
syncTokens = true;
error = true;
}
void semanticError(std::string const& msg = "Semantic error") {
semanticError(msg, self->getLoc());
}
void semanticError(std::string const& msg, Location loc) {
self->reportError(msg, loc);
error = true;
}
void semanticWarning(std::string const& msg = "Semantic warning") {
semanticWarning(msg, self->getLoc());
}
void semanticWarning(std::string const& msg, Location loc) {
self->reportError("warning: " + msg, loc);
}
bool matchToken(int token) {
if(syncTokens) {
while(cur != token && cur != 0) next();
if(cur == 0 && token != 0) fatalError("Unexpected end of file");
syncTokens = false;} else {
if(cur != token) {
syntaxError("Unexpected token");
return false;
 }}
return true; }
bool optionalMatch(int token) {
if(syncTokens) {
while(cur != token && cur != 0) next();
syncTokens = false;if(cur != token) return false;
} else {
if(cur != token) {
return false;
 }}
return true; }
bool full() { return cur == 0 && !error; }
void rule_action(EventDef* event, std::vector<BaseAction*>& actions) {
if(!matchToken(16)) return;
std::auto_ptr<STRING> name(static_cast<STRING*>(curData.release()));
next();

		ActionDef* action(self->getAction(name->str));
		if(!action)
		{
	
while(cur != 6 && cur != 0) next();
next();

		}
		else if((action->requireMask & event->provideMask) != action->requireMask)
		{
			semanticError("Event does not provide the necessary requirements for this action");
	
while(cur != 6 && cur != 0) next();
next();

		}
		else
		{
			auto_ptr<Parameters> param(new Parameters(action->paramDef, self->getLoc()));
	
if(!matchToken(5)) return;
next();
if(set_1[cur]) {
rule_parameters(*param);
}
if(!matchToken(6)) return;
next();

			param->checkParams();
			if(param->flags & Parameters::Error)
				semanticError("Malformed parameters", param->loc);
			else
				actions.push_back(self->createAction(action, param));
		}
	
}
void rule_event() {
if(!matchToken(3)) return;
next();
if(!matchToken(16)) return;
std::auto_ptr<STRING> name(static_cast<STRING*>(curData.release()));
next();

		EventDef* event(self->getEventDef(name->str));
		if(!event)
		{
	
while(cur != 3 && cur != 0) next();

		}
		else
		{
			auto_ptr<Parameters> param(new Parameters(event->paramDef, self->getLoc()));
	
if(!matchToken(5)) return;
next();
if(set_1[cur]) {
rule_parameters(*param);
}
if(!matchToken(6)) return;
next();
 std::vector<BaseAction*> actions; 
while((cur == 16)) {
rule_action(event, actions);
}

			param->checkParams();
			if(param->flags & Parameters::Error)
				semanticError("Malformed parameters", param->loc);
			else
				self->addEvent(event, param, actions);
		}
	
}
void rule_expr(TokenBase::ptr& a) {
 int t; TokenBase::ptr b; 
Location exprLoc(self->getLoc());
rule_term(a);
while(set_3[cur]) {
if((cur == 12)) {
next();
 t = 0; 
}
else if((cur == 13)) {
next();
 t = 1; 
}
else { syntaxError(); return; }
rule_term(b);

			switch(t)
			{
				case 0: a.reset( new Add(exprLoc, a.release(), b.release()) ); break;
				case 1: a.reset( new Sub(exprLoc, a.release(), b.release()) ); break;
			}
		
}
}
void rule_leaf(TokenBase::ptr& a) {
if((cur == 1)) {
next();
 a.reset(new INTEGER(*self, 1)); 
}
else if((cur == 2)) {
next();
 a.reset(new INTEGER(*self, 0)); 
}
else if((cur == 16)) {
std::auto_ptr<STRING> x(static_cast<STRING*>(curData.release()));
next();
if((cur == 5)) {
 auto_ptr<Func> l(new Func(self->getLoc(), x->str)); TokenBase::ptr el; 
next();
rule_leaf(el);
 l->add(el); 
while((cur == 11)) {
next();
rule_leaf(el);
 l->add(el); 
}
if(!matchToken(6)) return;
next();
 a = l; 
}
else if(true) {
 a = x; 
}
else { syntaxError(); return; }
}
else if((cur == 17)) {
a.reset(curData.release());
next();
}
else if((cur == 18)) {
a.reset(curData.release());
next();
}
else if((cur == 7)) {
 auto_ptr<List> l(new List(self->getLoc())); TokenBase::ptr el; 
next();
rule_expr(el);
 l->add(el); 
while((cur == 11)) {
next();
rule_expr(el);
 l->add(el); 
}
if(!matchToken(8)) return;
next();
 a = l; 
}
else if((cur == 5)) {
next();
rule_expr(a);
if(!matchToken(6)) return;
next();
}
else { syntaxError(); return; }
}
void rule_lines() {
while((cur == 16)) {
rule_prop();
}
while((cur == 3)) {
rule_event();
}
}
void rule_parameter(Parameters& params) {
 TokenBase::ptr v; 
Location paramLoc(self->getLoc());
if((cur == 16)) {
std::auto_ptr<STRING> name(static_cast<STRING*>(curData.release()));
next();
if((cur == 4)) {
next();
rule_expr(v);
 params.addParam(name->str, v, paramLoc); 
}
else if(true) {
 params.addParam(TokenBase::ptr(name), paramLoc); 
}
else { syntaxError(); return; }
}
else if(set_1[cur]) {
rule_expr(v);
 params.addParam(v, paramLoc); 
}
else { syntaxError(); return; }
}
void rule_parameters(Parameters& params) {
rule_parameter(params);
while((cur == 11)) {
next();
rule_parameter(params);
}
}
void rule_prop(std::string const& prefix = "") {
 TokenBase::ptr v; 
Location propLoc(self->getLoc());
if(!matchToken(16)) return;
std::auto_ptr<STRING> name(static_cast<STRING*>(curData.release()));
next();
if((cur == 4)) {
next();
rule_expr(v);
 self->property(prefix + name->str, v.release(), propLoc); 
}
else if((cur == 9)) {
next();
while((cur == 16)) {
rule_prop((*name).str + "_");
}
if(!matchToken(10)) return;
next();
}
else { syntaxError(); return; }
}
void rule_term(TokenBase::ptr& a) {
 int t; TokenBase::ptr b; 
Location termLoc(self->getLoc());
rule_leaf(a);
while(set_17[cur]) {
if((cur == 14)) {
next();
 t = 0; 
}
else if((cur == 15)) {
next();
 t = 1; 
}
else { syntaxError(); return; }
rule_leaf(b);

			switch(t)
			{
				case 0: a.reset( new Mul(termLoc, a.release(), b.release()) ); break;
				case 1: a.reset( new Div(termLoc, a.release(), b.release()) ); break;
			}
		
}
}
bool set_1[26];
bool set_3[26];
bool set_17[26];
TGrammar() : cur(-1), begin(0), marker(0), buffer(0), curp(0), limit(0), line(1), syncTokens(false), error(false), state(0) {
memset(set_1, 0, sizeof(bool)*26);
set_1[1] = true;
set_1[2] = true;
set_1[5] = true;
set_1[7] = true;
set_1[16] = true;
set_1[17] = true;
set_1[18] = true;
memset(set_3, 0, sizeof(bool)*26);
set_3[12] = true;
set_3[13] = true;
memset(set_17, 0, sizeof(bool)*26);
set_17[14] = true;
set_17[15] = true;
}
int cur;
std::auto_ptr<Token> curData;
char* curp;
char* limit;
char* marker;
char* begin;
char* buffer;
int line;
int state;
bool syncTokens;
bool error;
#undef self
};
}
