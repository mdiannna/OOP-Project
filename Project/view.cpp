#include "view.h"
#include "console.h"


void View::setTitle(string title){
	this->title = title;
}


string View::getTitle()  const{
	return this->title;
}


void View::render_header() const{
	cout << "\n";
	cout << "------------------------------\n";
	printBlue(this->getTitle() + "\n");
	// cout << this->title << "\n";
	cout << "------------------------------\n";
}


void View::render_content()  const{
	cout << "content will be here\n";
}



void View::render_footer()  const{
	cout << "\n";
	cout << "_________________________________\n";
	cout << "Copyright Console Tweet 2017" << "\n\n\n";
}


ostream & operator<<(ostream& out, const View& view){
	view.render_header();
	view.render_content();
	view.render_footer();
	return out;
}