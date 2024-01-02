package DataBase;

import Entity.User;

import java.sql.*;

public class UserDB {
    public ResultSet query(String userName, String password) throws Exception {
        Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306", "root", "root");
        Statement statement = connection.createStatement();
        statement.execute("use library");
        String sql = STR."select * from User where reader_name like '\{userName}' and reader_password like '\{password}'";
        return statement.executeQuery(sql);
    }

    public void updateUser(User user) throws SQLException {
        Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306", "root", "root");
        Statement statement = connection.createStatement();
        statement.execute("use library");
        String sql = "UPDATE user SET reader_name = '"
                + user.readerName
                + "', reader_password = '"
                + user.readerPassword
                + "', reader_sex = "
                + user.readerSex
                + ", reader_type = "
                + user.readerType
                + ", Capacity = "
                + user.Capacity
                + " WHERE reader_id = " + user.readerId;
        statement.execute(sql);
    }
}
