#ifndef POSTARE_H_INCLUDED
#define POSTARE_H_INCLUDED

#include <iostream>
#include <list>
#include <vector>
#include <map>
#include "persoana.h"
#include "util.h"
#include "console.h"

using namespace std;


class Postare{
    static int last_id;
    int id;
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
    list<int> comments_id; 

    friend ostream &operator<<(ostream &, const Postare&);
    


public:
	// methods:
	Postare(string, int); 
    int getID() const;

   


/*** GET functions ***/    
    int getTweetLimit() const;
    string getText() const;
    int getTextLength() const;
    int getAuthorId() const;
    Date getPostDate() const;
    string getPostDateAsString() const;
    Time getPostTime() const;
    string getPostTimeAsString() const;
    int getNrLikes() const;
    list<int> getComments() const;
    
    // TO DO:
    list<int> getPeopleLikeIDs() const;

/*** SET functions ***/
    void setText(string);
    void setAuthorId(int author_id);
    void setAuthor(Persoana);
    void setPostDate(Date);
    void setPostTime(Time);
    void setNrLikes(int);


    void printComments() const;
    void addLike();
    void addComment(int);

    // TO DO:
    // void addPeopleLikeID(int);
    // void addPeopleLike(Person);

};




static map<int, Postare*> postari;

void printAllPosts();
Postare * getPostareById(int);

#endif // POSTARI_H_INCLUDED
