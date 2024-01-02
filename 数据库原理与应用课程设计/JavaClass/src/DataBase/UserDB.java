package DataBase;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;

public class UserDB {
    public ResultSet query(String userName, String password) throws Exception {
        Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306", "root", "root");
        Statement statement = connection.createStatement();
        statement.execute("use library");
        String sql = STR."select * from User where reader_name like '\{userName}' and reader_password like '\{password}'";
        return statement.executeQuery(sql);
    }
}
