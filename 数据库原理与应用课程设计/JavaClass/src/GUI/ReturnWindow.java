package GUI;

import DataBase.BookDB;
import Entity.User;

import javax.swing.*;

public class ReturnWindow extends JFrame{
    JTextField bookName;

    JButton Return;

    JButton cancel;

    BookDB bookDB;

    User user;

    public ReturnWindow(User user) {
        this.user = user;
        setLayout(null);
        setTitle("还书界面");
        setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        setBounds(300, 300, 700, 500);
        init();
        setVisible(true);
    }
    public void init(){
        bookName = new JTextField();
        Return = new JButton("还书");
        cancel = new JButton("取消");
        bookDB = new BookDB();

        bookName.setBounds(0, 50, 100, 30);
        Return.setBounds(0, 100, 100, 30);
        cancel.setBounds(0, 150, 100, 30);


        cancel.addActionListener(e -> {
            ReturnWindow.this.dispose();
            new MainWindow(user);
        });

        this.add(bookName);
        this.add(Return);
        this.add(cancel);
    }

}
