package GUI;

import DB.CalDB;
import Entity.EmploymentRateByMajor;
import Entity.EmploymentStats;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

public class AdminCal extends JFrame {
    JTextArea statsInfo;
    JTable rateTable;
    JScrollPane scrollPane;

    JButton back;
    public AdminCal() {
        setTitle("高校学生就业管理系统-就业汇总界面");
        setBounds(300, 300, 1000, 700);
        setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        setLayout(null);
        init();
        setVisible(true);
    }

    void init() {
        statsInfo = new JTextArea();
        statsInfo.setBounds(50, 50, 700, 50);
        EmploymentStats stats = new CalDB().getStats();
        String r1 = "毕业生数\t就业学生数\t待业学生数\t就业率\n";
        String r2 = stats.GraduationCount + "\t" + stats.EmployedCount + "\t" + stats.UnemployedCount + "\t" + stats.EmploymentRate + "%\n";
        statsInfo.append(r1);
        statsInfo.append(r2);


        ArrayList<EmploymentRateByMajor> list = new CalDB().getMajorRate();
        Object[] title = new String[]{"专业", "总毕业数", "就业人数", "就业率"};
        Object[][] data = new Object[list.size()][4];
        for (int i = 0; i < list.size(); i++) {
            data[i][0] = list.get(i).Major;
            data[i][1] = list.get(i).TotalGraduates;
            data[i][2] = list.get(i).EmployedCount;
            data[i][3] = list.get(i).EmploymentRate + "%";
        }

        rateTable = new JTable(data, title);

        scrollPane = new JScrollPane(rateTable);
        scrollPane.setBounds(50, 150, 700, 400);


        back = new JButton("返回");
        back.setBounds(50,600,100,50);
        back.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new AdminWin();
                dispose();
            }
        });

        this.add(statsInfo);
        this.add(scrollPane);
        this.add(back);
    }
}
