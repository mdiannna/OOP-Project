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

	//same for each view
	void render_header()  const;
	// customized for each view
	virtual void render_content() const;
	//same for each view
	void render_footer() const;

	
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

	
#endif