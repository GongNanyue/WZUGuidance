package DataBase;

import Entity.Book;
import Entity.User;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;

public class ReturnDB {
    public void update(User user, int bookId) {
        try (Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306", "root", "root");
             Statement statement = connection.createStatement()) {
            statement.execute("use library");
            statement.execute(STR."delete from borrow where reader_id = \{user.readerId} and book_id = \{bookId}");
            statement.execute(STR."update book set book_num = book_num + 1 where book_id = '\{bookId}'");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

}
