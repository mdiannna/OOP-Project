#include "postare.h"

int Postare::last_id = 0;

Postare::Postare(){
}

// Constructor
Postare::Postare(string text, int author_id){
	try{
		if(text.length() > this->TWEET_LIMIT)
			throw "Postarea '" + text 
			+ "' nu a fost creata - depaseste lungimea de 140 caractere.";
		else
			this->text_len = text.length();	
	}
	catch(string error){
		printError(error);
		cout << "\n";
		return;
	}

	this->text = text;
	this->text_len = text.length();
	this->author_id = author_id;
	this->post_date = getDateNow();
	this->post_time = getTimeNow();
	this->nr_likes = 0;
	
	last_id++;
	this->id = last_id;

	
	postari.insert({this->id, this});
	// postari[this->id] = *this;
	
	printSuccess("Postare creata cu succes");
}


int Postare::getID() const{
	return this->id;
}



/*** GET functions ***/    
int Postare::getTweetLimit() const{
	return this->TWEET_LIMIT;
}


string Postare::getText() const{
	return this->text;
}


int Postare::getTextLength() const{
	return this->text_len;
}


int Postare::getAuthorId() const{
	return this->author_id;
}    


Date Postare::getPostDate() const{
	return this->post_date;
}


string Postare::getPostDateAsString() const{
	return convertDateToString(this->getPostDate());
}


Time Postare::getPostTime() const{
	return this->post_time;
}


string Postare::getPostTimeAsString() const{
	return convertTimeToString(this->getPostTime());
}


int Postare::getNrLikes() const{
	return this->nr_likes;
}


list<int> Postare::getComments() const{
	return this->comments_id;
}



/*** SET functions ***/
void Postare::setText(string text){
	try{
		if(text.length() > this->TWEET_LIMIT)
			throw "Textul depaseste lungimea de 140 caractere.";
	}
	catch(char const* error){
		printError(error);
		return;
	}
	
	this->text_len = text.length();	
	this->text = text;
}


void Postare::setAuthorId(int author_id){
	this->author_id = author_id;
}

void Postare::setAuthor(Persoana author){
	this->author_id	= author.indice;
}	


void Postare::setPostDate(Date date){
	this->post_date = date;
}


void Postare::setPostTime(Time time){
	this->post_time = time;
}


void Postare::setNrLikes(int nr_likes){
	this->nr_likes = nr_likes;
}


void Postare::printComments() const{
	cout << "Comentarii  la postarea " << this->getID() << ":\n";
	list<int> comments_id = this->getComments();
	for(list<int>::iterator it = comments_id.begin(); it != comments_id.end(); it++){
		printCyan(*it);
		cout << " ";
	}
	cout << "\n";
}


/***************************/
void Postare::addLike(){
	this->nr_likes++;
}

		
void Postare::addComment(int comment_id){
	this->comments_id.push_back(comment_id);
}


/***************************/
//operator overload
/***************************/
ostream &operator<<(ostream &out, const Postare& post){
	out << "--------------POSTARE----" << post.getID() << "--------\n";
	printBlue("@");
	printBlue(getPersoanaNameById(post.getAuthorId()));
	out << "          ";
	printYellow(post.getPostDateAsString());
	out << " ";
	printMagenta(post.getPostTimeAsString());
	out << "\n";
	out << post.getText();
	out << "\n";
	printGreen(post.getNrLikes());
	printGreen(" likes");
	out << "\n---------------------------------\n";
	
	post.printComments();
	return out;
}



/************************/
//General functions
/************************/
void printAllPosts(){
	cout << "Toate postarile:\n";

	for(map<int, Postare*>::iterator it= postari.begin(); it!=postari.end(); it++){
		cout << *(it->second);
		cout << "\n";
	}
}


Postare * getPostareById(int id){
	return postari[id];
}