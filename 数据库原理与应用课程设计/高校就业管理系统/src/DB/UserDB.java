package DB;

import Entity.User;

import java.sql.*;

public class UserDB {
    String sqlURL = "jdbc:mysql://localhost:3306/jobmanagesystem";
    String sqlUser = "root";

    String sqlPassword = "root";

    public ResultSet getSet(String username) {
        try {
            Connection connection = DriverManager.getConnection(sqlURL, sqlUser, sqlPassword);
            PreparedStatement preparedStatement = connection.prepareStatement("select * from user where username like ?");
            preparedStatement.setObject(1, username);
            return preparedStatement.executeQuery();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public User getUser(String username) {
        try {
            Connection connection = DriverManager.getConnection(sqlURL, sqlUser, sqlPassword);
            PreparedStatement preparedStatement = connection.prepareStatement("select * from user where Username like ?");
            preparedStatement.setObject(1, username);
            ResultSet set = preparedStatement.executeQuery();
            if (set.next()) {
                return new User(set.getString(1), set.getString(2), set.getInt(3));
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return null;
    }

    public User getUser(String username,int userType) {
        try {
            Connection connection = DriverManager.getConnection(sqlURL, sqlUser, sqlPassword);
            PreparedStatement preparedStatement = connection.prepareStatement("select * from user where username like ? and Usertype = ?");
            preparedStatement.setObject(1, username);
            preparedStatement.setObject(2, userType);
            ResultSet set = preparedStatement.executeQuery();
            if (set.next()) {
                return new User(set.getString(1), set.getString(2), set.getInt(3));
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return null;
    }
}
