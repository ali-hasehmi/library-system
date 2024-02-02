#include "book.h"

int main()
{

    Book b("MidNightLibrary","Matt Haig","August 13, 2020",Book::Novel),
         c("The Metamorphosis","Franz Kafka","1915", Book::Novel),
         d("They Both Die at the End","Adam Silvera","September 5, 2017",Book::Novel),
         e("The clown", "Heinrich Böll","1963",Book::Fiction),
         f("book1","author1","August 8, 2001",Book::Fiction),
         g("book2","author2","August 8, 2002",Book::Fiction),
         h("book3","author3","August 8, 2004",Book::Fiction),
         i("book4","author1","August 8, 2005",Book::Fiction);
         b.saveToFile();
         c.saveToFile();
         d.saveToFile(),
         e.saveToFile(),
         f.saveToFile();
         h.saveToFile();
         i.saveToFile();
    return 0;
}