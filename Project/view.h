#ifndef VIEWS_H
#define VIEWS_H

#include <iostream>

using namespace std;


/**********************************/
//Base class View
/**********************************/
class View{
	string title;

public:
	//constructor
	View(string);

	void setTitle(string);
	string getTitle() const;

	//(almost) same for each view
	virtual void render_header()  const;
	// customized for each view
	virtual void render_content() const;
	//(almost) same for each view
	virtual void render_footer() const;


	friend ostream& operator<<(ostream&, const View&);
};


/**********************************/
//class PostView
/**********************************/
class PostView : public View{
	int post_id;
public:
	PostView(int post_id, string title) : View(title){
		this->post_id = post_id;
	}
	PostView(int post_id) : View("Post view"){
		this->post_id = post_id;
	}
	PostView() : View("Post view"){}

	void render_content() const;
};


/**********************************/
//class AllPostsView
/**********************************/
class AllPostsView : public View{
public:
	AllPostsView(string title) : View(title){}
	AllPostsView() : View("All Posts View"){}

	void render_content() const;
};




class CommentView: public View
{
    int comment_id;
public:
    CommentView(int comm_id, string title): View(title)
    {
        comment_id = comm_id;
    }
    CommentView(): View("Comment View"){}

    void render_content() const;
};


class AllCommentsView: public View
{
public:
    AllCommentsView(string title): View(title){}
    AllCommentsView(): View("All Comments View: "){}

    void render_content() const;
};



/**********************************/
//class MenuView
/**********************************/
class MenuView : public View{
public:
	MenuView(string title) : View(title){}
	MenuView() : View("Console Tweet 2017 Menu"){}
	void render_content() const;
	void render_footer() const;
};



#endif
