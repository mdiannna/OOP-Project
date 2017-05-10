#include "postare.h"
#include "colors.h"

// Constructor
Postare::Postare(string text, int author_id){
	try{
		if(text.length() > this->TWEET_LIMIT)
			throw "!Eroare. Postarea nu a fost creata - depaseste lungimea de 140 caractere.";
		else
			this->text_len = text.length();	
	}
	catch(char const* error){
    	cout << red << error << "\n";
		cout << green << error << "\n";
		cout << yellow << error << "\n";
		cout << blue << error << "\n";
		cout << magenta << error << "\n";
		cout << cyan << error << "\n";
		return;
	}

	this->text = text;
	this->text_len = text.length();
	this->author_id = author_id;
	
	cout << "postarE:" << this->text;


}

void Postare::postManager(){
    cout << "Post Manager\n";
}

void Postare::addLike(){
	this->nr_likes++;
}
