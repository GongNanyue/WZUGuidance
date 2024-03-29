package DataBase;

import Entity.Book;

import java.sql.*;

public class BookDB {

    public ResultSet query(String bookName) throws Exception {
        Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306", "root", "root");
        Statement statement = connection.createStatement();
        statement.execute("use library");
        String sql = STR."select * from Book where book_name like '\{bookName}'";
        return statement.executeQuery(sql);
    }

    public void update(Book book) throws Exception {
        Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306", "root", "root");
        Statement statement = connection.createStatement();
        statement.execute("use library");
        String sql = STR."update book set book_num = book_num - 1 where book_id = '\{book.bookId}'";
        statement.execute(sql);
    }

    public ResultSet getAllBooks() throws SQLException {
        Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306", "root", "root");
        Statement statement = connection.createStatement();
        statement.execute("use library");
        String sql = STR."select * from Book";
        return statement.executeQuery(sql);
    }

    public int getBookIdByName(String bookName) throws SQLException {
        Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306", "root", "root");
        Statement statement = connection.createStatement();
        statement.execute("use library");
        String sql="select book_id from book where book_name like '" + bookName + "'";
        ResultSet x = statement.executeQuery(sql);
        if(x.next()){
            return x.getInt("book_id");
        }
        return -1;
    }

}

