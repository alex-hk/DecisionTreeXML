enum TokenType { OARR_TOK, CARR_TOK, END_TOK, QT_TOK, EQT_TOK, EQ_TOK, ATRB_TOK, NODE_TOK, TXT_TOK };

#include <string>

using namespace std;

struct Token {
private:
	string lexeme;
	TokenType tokType;
public:
	string getLexeme() { return lexeme; }
	TokenType getToken() { return tokType; }
	Token(TokenType token, string lex) { tokType = token; lexeme = lex; }
	void pToken(){
		switch(tokType){
		case OARR_TOK: printf("OARR_TOK "); break;
		case CARR_TOK: printf("CARR_TOK "); break;
		case END_TOK: printf("END_TOK "); break;
		case QT_TOK: printf("QT_TOK "); break;
		case EQ_TOK: printf("EQ_TOK "); break;
		case ATRB_TOK: printf("ATRB_TOK "); break;
		case NODE_TOK: printf("NODE_TOK "); break;
		case TXT_TOK: printf("TXT_TOK "); break;
		case EQT_TOK: printf("EQT_TOK "); break;
		}
	}
};
