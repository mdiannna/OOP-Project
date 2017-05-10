#include "postare.h"


// Constructor
Postare::Postare(string text, int author_id){
	try{
		if(text.length() > this->TWEET_LIMIT)
			throw "Postarea nu a fost creata - depaseste lungimea de 140 caractere.";
		else
			this->text_len = text.length();	
	}
	catch(char const* error){
		printError(error);
		return;
	}

	this->text = text;
	this->text_len = text.length();
	this->author_id = author_id;
	this->post_date = getDateNow();
	this->post_time = getTimeNow();

	
	printSuccess("Postare creata cu succes");
}

void Postare::postManager(){
    cout << "Post Manager\n";
}

void Postare::addLike(){
	this->nr_likes++;
}


ostream &operator<<(ostream &out, const Postare& post){
	out << post.getAuthorId()<< " ";
	out << post.getDateAsString() << " ";
	out << post.getTimeAsString() << " ";
	out << "\n";
	out << post.getText();
	out << "\n";
	out << post.getNrLikes();
	
	return out;
}