package GUI;

import DataBase.BookDB;
import DataBase.BorrowDB;
import DataBase.ReaderDB;
import Entity.User;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.ResultSet;

public class ReaderWindow extends JFrame {

    JTextArea textArea;
    JButton cancel;
    BookDB bookDB;
    BorrowDB borrowDB;
    User user;

    public ReaderWindow(User user) {
        bookDB = new BookDB();
        borrowDB = new BorrowDB();
        this.user = user;
        setLayout(null);
        setTitle("我的信息");
        setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        setBounds(300, 300, 700, 500);
        init();
        setVisible(true);
    }

    void init() {
        textArea = new JTextArea();
        cancel = new JButton("返回");

        textArea.setBounds(0, 0, 300, 300);
        cancel.setBounds(0, 350, 100, 30);


        textArea.setFont(new Font("宋体",Font.BOLD,20));

        cancel.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new MainWindow(user);
                ReaderWindow.this.dispose();
            }
        });

        this.add(textArea);
        this.add(cancel);

        ResultSet set = new ReaderDB().query(user);
        try {
            String s = "借书记录：\n";
            textArea.append(s);
            boolean f=false;
            while (set.next()) {
                s += set.getString(2) + "\n";
                f=true;
            }
            if(!f) s="没有借书记录\n";
            textArea.setText(s);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
