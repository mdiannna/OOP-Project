#ifndef VIEWS_H
#define VIEWS_H

#include <iostream>

using namespace std;

class View{
	string title;

public:
	void setTitle(string);
	string getTitle() const;

	void render_header()  const;
	// virtual? and customized for each view
	void render_content() const;
	void render_footer() const;

	//constructor
	View();

	friend ostream& operator<<(ostream&, const View&);
};


	
#endif