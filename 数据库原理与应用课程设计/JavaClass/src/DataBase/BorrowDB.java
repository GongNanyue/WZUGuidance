package DataBase;

import Entity.Book;
import Entity.User;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;

public class BorrowDB {
    public int id;
    public int reader_id;
    public int book_id;


    public void insert(User user, Book book) throws Exception {
        try (Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306", "root", "root");
             Statement statement = connection.createStatement();) {
            statement.execute("use library");
            statement.execute(STR."insert into borrow(reader_id,book_id) values('\{user.readerId}','\{book.bookId}')");
        }
    }

}
