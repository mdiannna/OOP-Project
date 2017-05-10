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
    list<int> people_like_ids;
    // list of comments to post
    // list<Comments> comments_to_post; 
    

public:
	// methods:
	Postare(string, int);
    void postManager();
    void addLike();
};

// TO DO: operator << postare

#endif // POSTARI_H_INCLUDED
