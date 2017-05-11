#include "postare.h"

int Postare::id = 0;

// Constructor
Postare::Postare(string text, int author_id){
	try{
		if(text.length() > this->TWEET_LIMIT)
			throw "Postarea '" + text + "' nu a fost creata - depaseste lungimea de 140 caractere.";
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
	this->id = id+1;

	
	printSuccess("Postare creata cu succes");
}


int Postare::getID() const{
	return this->id;
}


void Postare::postManager(){
    cout << "Post Manager\n";
}


void Postare::addLike(){
	this->nr_likes++;
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


    void Postare::setPostDate(Date date){
    	this->post_date = date;
    }


    void Postare::setPostTime(Time time){
    	this->post_time = time;
    }

    
    void Postare::setNrLikes(int nr_likes){
    	this->nr_likes = nr_likes;
    }

		

ostream &operator<<(ostream &out, const Postare& post){
	out << "--------------POSTARE----" << post.getID() << "--------\n";
	printBlue("@author");
	printBlue(post.getAuthorId());
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
	
	return out;
}