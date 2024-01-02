package DataBase;

import Entity.Book;
import Entity.User;

import java.sql.*;

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

    public int getBookIdByName(String bookName) throws SQLException {
        Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306", "root", "root");
        Statement statement = connection.createStatement();
        statement.execute("use library");
        String sql="select book_id from book where book_name like '" + bookName + "'";
        return statement.executeQuery(sql).getInt("book_id");
    }

}
