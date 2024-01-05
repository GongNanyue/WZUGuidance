package GUI;

import DB.JobDB;
import DB.StudentDB;
import Entity.Student;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class StudentWin extends JFrame {
    int ID;
    JButton fillIn;

    JButton back;

    JLabel Stuid;
    JLabel Sname;
    JLabel Ssex;
    JLabel Sdept;
    JLabel Sclass;
    JLabel Enterprise;
    JLabel isWork;

    public StudentWin(int ID) {
        this.ID = ID;
        setTitle("高校学生就业管理系统-学生界面");
        setBounds(300, 300, 1000, 700);
        setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        setLayout(null);
        init();
        setVisible(true);
    }

    void init() {
        fillIn = new JButton("填入个人信息");
        back = new JButton("注销");
        Student tep = new StudentDB().getStudent(ID);
        Stuid = new JLabel("学号："+tep.ID);
        Sname = new JLabel("姓名："+tep.name);
        Ssex = new JLabel("性别:"+tep.sex);
        Sdept = new JLabel("院系："+tep.dept);
        String enter = new JobDB().getJobName(tep.jobID);
        Sclass = new JLabel("专业："+tep.major);
        String wk = "就业情况：";
        if(tep.isWork){
            wk += "已就业";
        }else{
            wk += "待业";
            enter = "暂无";
        }
        Enterprise = new JLabel("就业单位："+enter);
        isWork = new JLabel(wk);

        fillIn.setBounds(50, 50, 200, 50);
        back.setBounds(50, 150, 100, 50);
        Stuid.setBounds(550, 50, 200, 50);
        Sname.setBounds(550, 100, 200, 50);
        Ssex.setBounds(550, 150, 200, 50);
        Sdept.setBounds(550, 200, 200, 50);
        Sclass.setBounds(550, 250, 200, 50);
        Enterprise.setBounds(550, 300, 200, 50);
        isWork.setBounds(550, 350, 200, 50);

        fillIn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new StudentFillIn(ID);
                dispose();
            }
        });

        back.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new LoginWin();
                dispose();
            }
        });

        this.add(fillIn);
        this.add(Sname);
        this.add(Stuid);
        this.add(Ssex);
        this.add(Sdept);
        this.add(Sclass);
        this.add(Enterprise);
        this.add(isWork);
        this.add(back);
    }
}
