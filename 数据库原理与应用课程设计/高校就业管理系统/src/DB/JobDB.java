package DB;

import Entity.Job;
import Entity.User;

import java.sql.*;

public class JobDB {
    String sqlURL = "jdbc:mysql://localhost:3306/jobmanagesystem";
    String sqlUser = "root";
    String sqlPassword = "root";

    public ResultSet getSet(int jobID) {
        try {
            Connection connection = DriverManager.getConnection(sqlURL, sqlUser, sqlPassword);
            PreparedStatement preparedStatement = connection.prepareStatement("select * from jobinfo where Jobid = ?");
            preparedStatement.setObject(1, jobID);
            return preparedStatement.executeQuery();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public Job getJob(int jobID) {
        try {
            Connection connection = DriverManager.getConnection(sqlURL, sqlUser, sqlPassword);
            PreparedStatement preparedStatement = connection.prepareStatement("select * from jobinfo where Jobid = ?");
            preparedStatement.setObject(1, jobID);
            ResultSet set = preparedStatement.executeQuery();
            if (set.next()) {
                return new Job(set.getInt(1), set.getInt(2), set.getInt(3), set.getString(4));
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return null;
    }

    public boolean isFull(int jobID) {
        try {
            Connection connection = DriverManager.getConnection(sqlURL, sqlUser, sqlPassword);
            PreparedStatement preparedStatement = connection.prepareStatement("select * from jobinfo where Jobid = ?");
            preparedStatement.setObject(1, jobID);
            ResultSet set = preparedStatement.executeQuery();
            if (set.next()) {
                return set.getInt(3) >= set.getInt(2);
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return false;
    }

    public String getJobName(int jobID) {
        try {
            Connection connection = DriverManager.getConnection(sqlURL, sqlUser, sqlPassword);
            PreparedStatement preparedStatement = connection.prepareStatement("select * from jobinfo where Jobid = ?");
            preparedStatement.setObject(1, jobID);
            ResultSet set = preparedStatement.executeQuery();
            if (set.next()) {
                return set.getString(4);
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return null;
    }
}
