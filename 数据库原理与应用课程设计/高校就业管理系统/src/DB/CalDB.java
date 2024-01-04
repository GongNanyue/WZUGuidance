package DB;

import Entity.EmploymentRateByMajor;
import Entity.EmploymentStats;

import java.sql.*;
import java.util.ArrayList;

public class CalDB {
    String sqlURL = "jdbc:mysql://localhost:3306/jobmanagesystem";
    String sqlUser = "root";
    String sqlPassword = "root";

    public EmploymentStats getStats() {
        try {
            Connection connection = DriverManager.getConnection(sqlURL, sqlUser, sqlPassword);
            PreparedStatement statement = connection.prepareStatement("call GetEmploymentStats()");
            ResultSet set = statement.executeQuery();
            EmploymentStats stats = null;
            if (set.next()) {
                stats = new EmploymentStats(
                        set.getInt(1),
                        set.getInt(2),
                        set.getInt(3),
                        set.getInt(4));
            }
            set.close();
            statement.close();
            connection.close();
            return stats;
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public ArrayList<EmploymentRateByMajor> getMajorRate() {
        try {
            Connection connection = DriverManager.getConnection(sqlURL, sqlUser, sqlPassword);
            PreparedStatement statement = connection.prepareStatement("call GetEmploymentRateByMajor()");
            ResultSet set = statement.executeQuery();
            ArrayList<EmploymentRateByMajor> list = new ArrayList<>();
            while (set.next()) {
                list.add(new EmploymentRateByMajor(
                        set.getString(1),
                        set.getInt(2),
                        set.getInt(3),
                        set.getInt(4)));

            }
            return list;
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }
}
