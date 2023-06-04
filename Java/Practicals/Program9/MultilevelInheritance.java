class Book {
    private int noOfPages;

    protected void setNoOfPages(int pages) {
        noOfPages = pages;
    }

    public int getPages() {
        return noOfPages;
    }

    public void msg() {
        System.out.println("This is Book.");
    }
}

// Single Level Inheritance
class StoryBook extends Book {
    @Override
    public void msg() {
        System.out.println("This is Story Book.");
    }
}
 // MultiLevel Inheritance
class EnglishStoryBook extends StoryBook {
    @Override
    public void msg() {
        setNoOfPages(250);
        System.out.println("\nThis is English Story Book with " + getPages() + " pages.\n" );
    }
}

public class MultilevelInheritance {
   public static void main(String[] args) {
       EnglishStoryBook engStrBook = new EnglishStoryBook();
       engStrBook.msg();
   }
}
