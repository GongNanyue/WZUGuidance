package DB;

import Entity.Job;
import Entity.Student;

import java.sql.*;

public class StudentDB {
    String sqlURL = "jdbc:mysql://localhost:3306";
    String sqlUser = "root";
    String sqlPassword = "root";

    public ResultSet getSet(int ID) {
        try {
            Connection connection = DriverManager.getConnection(sqlURL, sqlUser, sqlPassword);
            PreparedStatement preparedStatement = connection.prepareStatement("select * from student where ID = ?");
            preparedStatement.setObject(1, ID);
            ResultSet set = preparedStatement.executeQuery();
            preparedStatement.close();
            connection.close();
            return set;
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public Student getStudent(int ID) {
        try {
            Connection connection = DriverManager.getConnection(sqlURL, sqlUser, sqlPassword);
            PreparedStatement preparedStatement = connection.prepareStatement("select * from jobmanagesystem.student where Id = ?");
            preparedStatement.setInt(1, ID);
            ResultSet set = preparedStatement.executeQuery();
            Student stu = null;
            if (set.next()) {
                stu = new Student(set.getInt(1),
                        set.getString(2),
                        set.getString(3),
                        set.getString(4),
                        set.getString(5),
                        set.getInt(6),
                        set.getBoolean(7));
            }
            set.close();
            preparedStatement.close();
            connection.close();
            return stu;
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

}
