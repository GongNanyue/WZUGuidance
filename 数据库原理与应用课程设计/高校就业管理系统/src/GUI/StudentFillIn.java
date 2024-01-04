package GUI;

import DB.JobDB;
import DB.RecordDB;
import Entity.Job;
import Entity.Student;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class StudentFillIn extends JFrame {
    int ID;
    JLabel l1;
    JTextField jobID;
    JButton confirm;
    JButton back;

    public StudentFillIn(int ID) {
        this.ID = ID;
        setTitle("高校学生就业管理系统-学生登记界面");
        setBounds(500, 500, 1000, 700);
        setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        setLayout(null);
        init();
        setVisible(true);
    }

    void init() {
        l1 = new JLabel("请输入工作序号");
        jobID = new JTextField();
        confirm = new JButton("确定");
        back = new JButton("返回");

        l1.setBounds(50, 50, 100, 50);
        jobID.setBounds(200, 50, 200, 50);
        confirm.setBounds(50, 100, 100, 50);
        back.setBounds(200, 100, 100, 50);

        confirm.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int ID = Integer.parseInt(jobID.getText());
                Job job = new JobDB().getJob(ID);
                if (job != null) {
                    new RecordDB().insertRecord(ID, StudentFillIn.this.ID);
                } else {
                    JOptionPane.showMessageDialog(StudentFillIn.this, "不存在这个工作", "警告", JOptionPane.WARNING_MESSAGE);
                }

            }
        });

        back.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new StudentWin(StudentFillIn.this.ID);
                dispose();
            }
        });

        this.add(l1);
        this.add(jobID);
        this.add(confirm);
        this.add(back);
    }

}
