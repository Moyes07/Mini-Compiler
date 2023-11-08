#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>

using namespace std;

enum TokenType {
	KEYWORD,
	COUT,
	IF,
	INT,
	EF,
	MAIN,
	FOR, assign, plusequal,
	ELSE,
	RETURN,
	PLUS,
	MINUS,
	MULTIPLY,
	DIVIDE,
	OPRB,
	CLRB,
	OPCB,
	CLCB,
	SC,
	C,
	IDENTIFIER,
	LITERAL,
	OPERATOR,
	PUNCTUATION,
	END_OF_FILE
};
struct moeeztoken {
	TokenType Tk;
	string name = "";
	int value;
};

ifstream file("example.txt");
char moeez;
char mchar;
int id = 0;
vector<moeeztoken> tokens;
moeeztoken tks;
void symbol_table(string tok)
{
	bool check = false;
	for (int i = 0; i < tokens.size(); i++)
	{
		if (tok == tokens[i].name)
		{
			check = true;
		}
	}
	if (check == false)
	{
		tks.Tk = IDENTIFIER;
		tks.name = tok;
		tokens.push_back(tks);
	}
}
vector<moeeztoken> Lexical()
{
	file.get(moeez);
	string token;
	do {
		if (isalpha(moeez))
		{
			do {
				token += moeez;
				file.get(moeez);
			} while (isalpha(moeez));

			if (token == "int") {
				tks.Tk = INT;
				tks.name = "INT";
				tokens.push_back(tks);
			}
			else if (token == "main") {
				tks.Tk = MAIN;
				tks.name = "Main";
				tokens.push_back(tks);
			}
			else if (token == "if") {
				tks.Tk = IF;
				tks.name = "IF";
				tokens.push_back(tks);
			}
			else if (token == "eof") {
				tks.Tk = EF;
				tks.name = "eof";
				tokens.push_back(tks);
			}
			else if (token == "cout") {
				tks.Tk = COUT;
				tks.name = "cout";
				tokens.push_back(tks);
			}
			else if (token == "return") {
				tks.Tk = RETURN;
				tks.name = "return";
				tokens.push_back(tks);
			}
			else if (isalpha(token[0])) {
				symbol_table(token);
			}
		}
		if (isdigit(moeez))
		{
			if (isdigit(moeez))
			{
				do {
					token += moeez;
					file.get(moeez);
				} while (isdigit(moeez));
				if (isdigit(token[0]))
				{
					tks.Tk = LITERAL;
					tks.value = stoi(token);
					tokens.push_back(tks);
				}
			}

		}   token += moeez;
		if (token == "+") {
			tks.Tk = PLUS;
			tks.name = "PLUS";
			tokens.push_back(tks);
		}
		else if (token == "=") {
			file.get(moeez);
			if (token == "=")
			{
				tks.Tk = OPERATOR;
				tks.name = "equals";
				tokens.push_back(tks);
			}
		}
		else if (token == "=") {
			tks.Tk = assign;
			tks.name = "assignment";
			tokens.push_back(tks);
		}
		else if (token == "-")
		{
			tks.Tk = OPERATOR;
			tks.name = "MINUS";
			tokens.push_back(tks);
		}
		else if (token == "*")
		{
			tks.Tk = OPERATOR;
			tks.name = "MULTIPLY";
			tokens.push_back(tks);
		}
		else if (token == "/")
		{
			tks.Tk = OPERATOR;
			tks.name = "DIVIDE";
			tokens.push_back(tks);
		}
		else if (token == "(") {
			tks.Tk = OPRB;
			tks.name = "OP round barckets";
			tokens.push_back(tks);
		}
		else if (token == ")") {
			tks.Tk = CLRB;
			tks.name = "Closing round barckets";
			tokens.push_back(tks);
		}
		else if (token == "{") {
			tks.Tk = OPCB;
			tks.name = "OP CUrly barckets";
			tokens.push_back(tks);
		}
		else if (token == "}") {
			tks.Tk = CLCB;
			tks.name = "Closing CUrly barckets";
			tokens.push_back(tks);
		}
		else if (token == ";") {
			tks.Tk = SC;
			tks.name = "semi colon";
			tokens.push_back(tks);
		}
		else if (token == ",") {
			tks.Tk = C;
			tks.name = "comma";
			tokens.push_back(tks);
		}
		else if (token == "+") {
			file.get(moeez);
			if (token == "=")
			{
				tks.Tk = plusequal;
				tks.name = "+=";
				tokens.push_back(tks);
			}
		}

		token.clear();
	} while (file.get(moeez));
	tks.Tk = END_OF_FILE;
	tks.name = "END_OF_FILE";
	tokens.push_back(tks);
	file.close();

	return tokens;
}

void execLexical()
{
	vector<moeeztoken> T;
	T = Lexical();
	cout << " TOKEN" << endl;
	for (int i = 0; i < tokens.size(); i++)
	{
		if (T[i].value != NULL)
		{
			cout << T[i].Tk << endl;
		}
		cout << T[i].Tk << endl;
	}
	cout << "\t------------" << endl;
}

//int main()
//{
//	vector<moeeztoken> T;
//	T = Lexical();
//	cout << " TOKEN" << endl;
//	for (int i = 0; i < tokens.size(); i++)
//	{
//		if (T[i].value != NULL)
//		{
//			cout << T[i].Tk << endl;
//		}
//		cout << T[i].Tk << endl;
//	}
//	cout << "\t------------" << endl;
//	cout << "SYMBOL TABLE" << endl;
//	cout << "\t------------" << endl;
//	for (int i = 0; i < tokens.size(); i++)
//	{
//		if (T[i].Tk == IDENTIFIER)
//		{
//			if (T[i].value != NULL)
//			{
//				cout << T[i].value << endl;
//			}
//			else
//			{
//				cout << T[i].name << endl;
//			}
//
//		}
//
//	}
//	return 0;
//}
