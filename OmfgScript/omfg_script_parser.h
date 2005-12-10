/* Generated by re2c 0.9.9 on Fri Dec  9 23:55:43 2005 */
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

#define D(x) (cout << x << std::endl)

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

#line 133 "<stdout>"
{
	YYCTYPE yych;
	goto yy0;
	++YYCURSOR;
yy0:
	if((YYLIMIT - YYCURSOR) < 6) YYFILL(6);
	yych = *YYCURSOR;
	switch(yych){
	case 0x00:	goto yy2;
	case 0x09:	case 0x0D:	case ' ':	goto yy35;
	case 0x0A:	goto yy39;
	case '"':	goto yy41;
	case '#':	goto yy37;
	case '(':	goto yy10;
	case ')':	goto yy12;
	case '*':	goto yy28;
	case '+':	goto yy24;
	case ',':	goto yy22;
	case '-':	goto yy26;
	case '/':	goto yy30;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy33;
	case '=':	goto yy8;
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
	case 'z':	goto yy32;
	case '[':	goto yy14;
	case ']':	goto yy16;
	case 'f':	goto yy6;
	case 'o':	goto yy7;
	case 't':	goto yy4;
	case '{':	goto yy18;
	case '}':	goto yy20;
	default:	goto yy43;
	}
yy2:	++YYCURSOR;
	goto yy3;
yy3:
#line 131 "OmfgScript/omfg_script_parser.h.re"
{  cur = 0; return; }
#line 224 "<stdout>"
yy4:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case 'r':	goto yy64;
	default:	goto yy56;
	}
yy5:
#line 147 "OmfgScript/omfg_script_parser.h.re"
{  cur = 16; curData.reset(new STRING(*self, begin, YYCURSOR)); return; }
#line 233 "<stdout>"
yy6:	yych = *++YYCURSOR;
	switch(yych){
	case 'a':	goto yy59;
	default:	goto yy56;
	}
yy7:	yych = *++YYCURSOR;
	switch(yych){
	case 'n':	goto yy57;
	default:	goto yy56;
	}
yy8:	++YYCURSOR;
	goto yy9;
yy9:
#line 135 "OmfgScript/omfg_script_parser.h.re"
{  cur = 4; return; }
#line 249 "<stdout>"
yy10:	++YYCURSOR;
	goto yy11;
yy11:
#line 136 "OmfgScript/omfg_script_parser.h.re"
{  cur = 5; return; }
#line 255 "<stdout>"
yy12:	++YYCURSOR;
	goto yy13;
yy13:
#line 137 "OmfgScript/omfg_script_parser.h.re"
{  cur = 6; return; }
#line 261 "<stdout>"
yy14:	++YYCURSOR;
	goto yy15;
yy15:
#line 138 "OmfgScript/omfg_script_parser.h.re"
{  cur = 7; return; }
#line 267 "<stdout>"
yy16:	++YYCURSOR;
	goto yy17;
yy17:
#line 139 "OmfgScript/omfg_script_parser.h.re"
{  cur = 8; return; }
#line 273 "<stdout>"
yy18:	++YYCURSOR;
	goto yy19;
yy19:
#line 140 "OmfgScript/omfg_script_parser.h.re"
{  cur = 9; return; }
#line 279 "<stdout>"
yy20:	++YYCURSOR;
	goto yy21;
yy21:
#line 141 "OmfgScript/omfg_script_parser.h.re"
{  cur = 10; return; }
#line 285 "<stdout>"
yy22:	++YYCURSOR;
	goto yy23;
yy23:
#line 142 "OmfgScript/omfg_script_parser.h.re"
{  cur = 11; return; }
#line 291 "<stdout>"
yy24:	++YYCURSOR;
	goto yy25;
yy25:
#line 143 "OmfgScript/omfg_script_parser.h.re"
{  cur = 12; return; }
#line 297 "<stdout>"
yy26:	++YYCURSOR;
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
	case '9':	goto yy53;
	default:	goto yy27;
	}
yy27:
#line 144 "OmfgScript/omfg_script_parser.h.re"
{  cur = 13; return; }
#line 315 "<stdout>"
yy28:	++YYCURSOR;
	goto yy29;
yy29:
#line 145 "OmfgScript/omfg_script_parser.h.re"
{  cur = 14; return; }
#line 321 "<stdout>"
yy30:	++YYCURSOR;
	goto yy31;
yy31:
#line 146 "OmfgScript/omfg_script_parser.h.re"
{  cur = 15; return; }
#line 327 "<stdout>"
yy32:	yych = *++YYCURSOR;
	goto yy56;
yy33:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '.':	goto yy50;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy53;
	default:	goto yy34;
	}
yy34:
#line 148 "OmfgScript/omfg_script_parser.h.re"
{  cur = 17; curData.reset(new INTEGER(*self, begin, YYCURSOR)); return; }
#line 348 "<stdout>"
yy35:	++YYCURSOR;
	goto yy36;
yy36:
#line 150 "OmfgScript/omfg_script_parser.h.re"
{ goto retry;}
#line 354 "<stdout>"
yy37:	++YYCURSOR;
	yych = *YYCURSOR;
	goto yy49;
yy38:
#line 151 "OmfgScript/omfg_script_parser.h.re"
{ goto retry;}
#line 361 "<stdout>"
yy39:	++YYCURSOR;
	goto yy40;
yy40:
#line 152 "OmfgScript/omfg_script_parser.h.re"
{ ++this->line; goto retry;}
#line 367 "<stdout>"
yy41:	yych = *(YYMARKER = ++YYCURSOR);
	goto yy45;
yy42:
#line 161 "OmfgScript/omfg_script_parser.h.re"
{ semanticError(std::string("Unknown character '") + *begin + "'"); goto retry; }
#line 373 "<stdout>"
yy43:	yych = *++YYCURSOR;
	goto yy42;
yy44:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy45;
yy45:	switch(yych){
	case '"':	goto yy46;
	default:	goto yy44;
	}
yy46:	++YYCURSOR;
	goto yy47;
yy47:
#line 153 "OmfgScript/omfg_script_parser.h.re"
{ 
#define b (begin)
#define e (YYCURSOR)
 cur = 16; curData.reset(new STRING(*self, b + 1, e - 1)); return; 

#undef b
#undef e
}
#line 396 "<stdout>"
yy48:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy49;
yy49:	switch(yych){
	case 0x0A:	goto yy38;
	default:	goto yy48;
	}
yy50:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy51;
yy51:	switch(yych){
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy50;
	default:	goto yy52;
	}
yy52:
#line 149 "OmfgScript/omfg_script_parser.h.re"
{  cur = 18; curData.reset(new NUMBER(*self, begin, YYCURSOR)); return; }
#line 425 "<stdout>"
yy53:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy54;
yy54:	switch(yych){
	case '.':	goto yy50;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy53;
	default:	goto yy34;
	}
yy55:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy56;
yy56:	switch(yych){
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
	case 'z':	goto yy55;
	default:	goto yy5;
	}
yy57:	++YYCURSOR;
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
	case 'z':	goto yy55;
	default:	goto yy58;
	}
yy58:
#line 134 "OmfgScript/omfg_script_parser.h.re"
{  cur = 3; return; }
#line 584 "<stdout>"
yy59:	yych = *++YYCURSOR;
	switch(yych){
	case 'l':	goto yy60;
	default:	goto yy56;
	}
yy60:	yych = *++YYCURSOR;
	switch(yych){
	case 's':	goto yy61;
	default:	goto yy56;
	}
yy61:	yych = *++YYCURSOR;
	switch(yych){
	case 'e':	goto yy62;
	default:	goto yy56;
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
	case 'z':	goto yy55;
	default:	goto yy63;
	}
yy63:
#line 133 "OmfgScript/omfg_script_parser.h.re"
{  cur = 2; return; }
#line 670 "<stdout>"
yy64:	yych = *++YYCURSOR;
	switch(yych){
	case 'u':	goto yy65;
	default:	goto yy56;
	}
yy65:	yych = *++YYCURSOR;
	switch(yych){
	case 'e':	goto yy66;
	default:	goto yy56;
	}
yy66:	++YYCURSOR;
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
	case 'z':	goto yy55;
	default:	goto yy67;
	}
yy67:
#line 132 "OmfgScript/omfg_script_parser.h.re"
{  cur = 1; return; }
#line 751 "<stdout>"
}
#line 162 "OmfgScript/omfg_script_parser.h.re"

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
if(amountRead < toRead) { memset(&buffer[l+amountRead], 0, toRead-amountRead); }
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
bool set_1[23];
bool set_3[23];
bool set_17[23];
TGrammar() : cur(-1), begin(0), marker(0), buffer(0), curp(0), limit(0), line(1), syncTokens(false), error(false) {
memset(set_1, 0, sizeof(bool)*23);
set_1[1] = true;
set_1[2] = true;
set_1[5] = true;
set_1[7] = true;
set_1[16] = true;
set_1[17] = true;
set_1[18] = true;
memset(set_3, 0, sizeof(bool)*23);
set_3[12] = true;
set_3[13] = true;
memset(set_17, 0, sizeof(bool)*23);
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
bool syncTokens;
bool error;
#undef self
};
}
