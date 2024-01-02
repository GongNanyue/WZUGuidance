package DataBase;

import Entity.User;

import java.sql.*;

public class ReaderDB {
    public ResultSet query(User user) {
        try{
            Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306", "root", "root");
            Statement statement = connection.createStatement();
            statement.execute("use library");
            String sql = STR."select reader_name,bk.book_name from (select book_id,book_name from book) as bk join (select u.reader_name,br.book_id from (select reader_id,reader_name from user) as u join(select *from borrow)as br on u.reader_id = br.reader_id and u.reader_id = \{user.readerId}) as x on bk.book_id = x.book_id;";
            return statement.executeQuery(sql);

        }catch (Exception e){
            e.printStackTrace();
        }

        return null;
    }
}
