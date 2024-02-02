#include "book.h"

int main()
{

    Book b("MidNightLibrary","Matt Haig","August 13, 2020",Book::Novel),
         c("The Metamorphosis","Franz Kafka","1915", Book::Novel),
         d("They Both Die at the End","Adam Silvera","September 5, 2017",Book::Novel),
         e("The clown", "Heinrich Böll","1963",Book::Fiction),
         f("book1","","August 8, 2000",Book::Fiction);
         g("book2"," George R. R. Martin","August 8, 2000",Book::Fiction);
         h("book3"," George R. R. Martin","August 8, 2000",Book::Fiction);
         i("book4"," George R. R. Martin","August 8, 2000",Book::Fiction);
         b.saveToFile();
         c.saveToFile();
         d.saveToFile(),
         e.saveToFile(),
         f.saveToFile();
    return 0;
}