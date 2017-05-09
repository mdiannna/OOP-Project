#ifndef POSTARI_H_INCLUDED
#define POSTARI_H_INCLUDED

#include <iostream>
#include <list>
#include "persoana.h"
#include "util.h"

using namespace std;

class Postare{
	// constants:
    int TWEET_LIMIT = 140;

    //variables:
    char * text;
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
    // list<Persoana> people_like;
    list<int> people_like_ids;
    //comments?
    //shares?

public:
	// methods:
    void postManager();
    void addLike();
};

// TO DO: operator << postare

#endif // POSTARI_H_INCLUDED
