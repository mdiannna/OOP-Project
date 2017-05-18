#include "view.h"
#include "console.h"
#include "postare.h"
#include "comentariu.h"
#include "persoana.h"

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
	printBlue("================================\n");
	cout << this->getTitle() << "\n";
	printBlue("================================\n");

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
    Comentariu *comm = getComentariuById(comment_id);
    cout << *comm;
}

 void AllCommentsView::render_content() const
 {

 }


 void MenuView::render_content() const{
        printWhite("1. Creeaza postare\n");
        printWhite("2. Afiseaza toate postarile\n");
        printWhite("3. Afiseaza postare cu id\n");
        printWhite("4. Adauga comentariu\n");
        printWhite("5. Apreciaza un comentariu\n");
        printWhite("6. Afiseaza persoane sugerate pentru a fi urmarite\n");
        printWhite("7. Afiseaza o persoana sugerata pentru a fi urmarita\n");
        printWhite("8. Adauga like la postare\n");
        printWhite("9. Afiseaza toate persoanele\n");
        printWhite("10. Adauga o persoana\n");
        printWhite("11. Follow persoana\n");
    
        
        printYellow("12. Exit\n");

        printBlue("=======================\n");
        printBlue("Enter your selection:\n");
 }

 void MenuView::render_footer() const{
	// No footer for this class
 }


 void AllPersonsView::render_content() const{
    printBlue("-----AFISARE TOATE PERSOANELE-------:\n");
 	printAllPersons();
 	printBlue("-------------------------------------\n");
 }



