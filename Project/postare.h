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
    int getTweetLimit() const;
    string getText() const;
    int getTextLength() const;
    int getAuthorId() const;
    // persoana getAuthor();
    Date getPostDate() const;
    string getPostDateAsString() const;
    Time getPostTime() const;
    string getPostTimeAsString() const;
    //TO DO: privacy level??
    int getNrLikes() const;
    // TO DO:
    list<int> getPeopleLikeIDs() const;

/*** SET functions ***/
    //implicit set length
    void setText(string);
    void setAuthorId(int author_id);
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


#endif // POSTARI_H_INCLUDED
