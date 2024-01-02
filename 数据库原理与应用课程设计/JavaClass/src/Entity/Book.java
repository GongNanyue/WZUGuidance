package Entity;

public class Book {
    /**
     * 这个类是用于封装书库信息的，对应了数据库中的表tb_books
     * 解释：
     * 			类中的属性:       tb_books表的字段:
     * 			bookId    ->     book_id
     * 			bookName  ->     book_name
     * 			bookPrice ->     book_price
     * 			bookNum   ->     book_num
     * 			bookType  ->     book_type
     * 		    bookAuthor ->    book_author
     */
    public int bookId;		// 书籍Id
    public String bookName;	// 书籍名称
    public String bookType;	// 书籍类型
    public int bookNum;		// 书籍剩余数量
    public int bookPrice;	// 书籍价格
    public String bookAuthor;  // 书籍作者

    public Book(int bookId, String bookName, String bookType, int bookNum, int bookPrice, String bookAuthor) {
        this.bookId = bookId;
        this.bookName = bookName;
        this.bookType = bookType;
        this.bookNum = bookNum;
        this.bookPrice = bookPrice;
        this.bookAuthor = bookAuthor;
    }
}
