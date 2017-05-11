#include "view.h"
#include "console.h"
#include "postare.h"

View::View(string title){
	this->title = title;
}


void View::setTitle(string title){
	this->title = title;
}


string View::getTitle()  const{
	return this->title;
}


void View::render_header() const{
	cout << "\n";
	printBlue("------------------------------\n");
	cout << this->getTitle() << "\n";
	// cout << this->title << "\n";
	printBlue("------------------------------\n");

}


void View::render_content()  const{
	printYellow("content will be here\n");
}



void View::render_footer()  const{
	// cout << "\n";
	printBlue("_________________________________\n");
	printBlue("Copyright Console Tweet 2017");
	cout << "\n\n\n";
}


ostream & operator<<(ostream& out, const View& view){
	view.render_header();
	view.render_content();
	view.render_footer();
	return out;
}



/**********************************/
//PostView
/**********************************/
void PostView::render_content()  const{
	Postare * p = getPostareById(this->post_id);
	cout << *p;
}


/**********************************/
//AllPostsView
/**********************************/
void AllPostsView::render_content()  const{
	printAllPosts();
}

void CommentView::render_content() const
{
    Comment *comm = getComentariuById(comment_id);
    cout << *comm;
}

 void AllCommentsView::render_content() const
 {

 }
