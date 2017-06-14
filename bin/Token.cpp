enum TokenType { OARR_TOK, CARR_TOK, FSLSH_TOK, QT_TOK, EQ_TOK, ATRB_TOK, NODE_TOK};

#include <string>

using namespace std;

struct Token {
private:
	string lexeme;
	TokenType tokType;
public:
	string getLexeme() { return lexeme; }
	TokenType getToken() { return tokType; }
	Token(TokenType token, string lex) { tokType = token; lexeme = lex; };
};
