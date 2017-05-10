#ifndef POSTARE_H_INCLUDED
#define POSTARE_H_INCLUDED

#include <iostream>
#include <list>
#include "persoana.h"
#include "util.h"
#include "console.h"

using namespace std;

class Postare{
	// constants:
    const int TWEET_LIMIT = 140;

    //variables:
    string text;
    int text_len;
    int author_id;

    Date post_date;
    Time post_time;

	enum privacyLevel{
        all, 
        friends, 
        followers
    };
    
    int nr_likes;
    // TO DO:
    list<int> people_like_ids;
    // list of comments to post
    // list<Comments> comments_to_post; 

    friend ostream &operator<<(ostream &, const Postare&);
    

public:
	// methods:
	Postare(string, int);
    void postManager();
    void addLike();

/*** GET functions ***/    
    int getTweetLimit();
    int getText();
    int getLength();
    int getAuthorId();
    // persoana getAuthor();
    Date getPostDate();
    string getPostDateAsString();
    Time getPostTime();
    string getPostTimeAsString();
    //TO DO: privacy level??
    int getNrLikes();
    // TO DO:
    list<int> getPeopleLikeIDs();

/*** SET functions ***/
    //implicit set length
    void setText(string);
    void setAuthorId();
    //???:
    // void setAuthor(Persoana);
    void setPostDate(Date);
    void setPostTime(Time);
    //TO DO: privacy level??
    void setNrLikes(int);
    // TO DO:
    // void addPeopleLikeID(int);
    // void addPeopleLike(Person);

};

// TO DO: operator << postare

#endif // POSTARI_H_INCLUDED
