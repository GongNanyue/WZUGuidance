package DB;

import javax.swing.*;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class RecordDB {
    String sqlURL = "jdbc:mysql://localhost:3306/jobmanagesystem";
    String sqlUser = "root";
    String sqlPassword = "root";

    public void insertRecord(int jobID, int studentID) {
        try {
            Connection connection = DriverManager.getConnection(sqlURL, sqlUser, sqlPassword);
            if(new JobDB().isFull(jobID)){
                JOptionPane.showMessageDialog(null, "这份工作已经满了");
                return;
            }
            PreparedStatement statement = connection.prepareStatement("insert into record values(?,?)");
            statement.setInt(1, jobID);
            statement.setInt(2, studentID);
            statement.execute();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }
}
