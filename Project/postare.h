#ifndef POSTARI_H_INCLUDED
#define POSTARI_H_INCLUDED

#include <iostream>
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
    

public:
	// methods:
    void postManager();
};


#endif // POSTARI_H_INCLUDED
