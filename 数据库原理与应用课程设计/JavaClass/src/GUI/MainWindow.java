package GUI;

import Entity.User;

import javax.management.Query;
import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MainWindow extends JFrame {
    JButton borrowBook;
    JButton returnBook;
    JButton queryBook;
    JButton readerInfo;
    JButton cancel;

    JButton showBooks;
    User user;
    public MainWindow(User user) {
        this.user = user;
        setLayout(null);
        setTitle("图书管理系统");
        setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        setBounds(300, 300, 700, 500);
        init();
        setVisible(true);
    }

    void init(){
        borrowBook = new JButton("借书");
        returnBook = new JButton("还书");
        queryBook = new JButton("查询");
        readerInfo = new JButton("我的信息");
        cancel = new JButton("退出");
        showBooks = new JButton("显示所有书籍");

        borrowBook.setBounds(0,0,100,30);
        returnBook.setBounds(0,50,100,30);
        queryBook.setBounds(0,100,100,30);
        readerInfo.setBounds(0,150,100,30);
        cancel.setBounds(0,200,100,30);
        showBooks.setBounds(150,0,200,30);

        borrowBook.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                BorrowWindow win = new BorrowWindow(user);
                MainWindow.this.dispose();
            }
        });

        returnBook.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                ReturnWindow win = new ReturnWindow(user);
                MainWindow.this.dispose();
            }
        });

        queryBook.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                QueryWindow win = new QueryWindow(user);
                MainWindow.this.dispose();
            }
        });

        readerInfo.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                ReaderWindow win =new ReaderWindow(user);
                MainWindow.this.dispose();
            }
        });

        showBooks.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new ShowBooksWindow(user);
                MainWindow.this.dispose();
            }
        });


        cancel.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new LoginWindow();
                MainWindow.this.dispose();
            }
        });

        this.add(borrowBook);
        this.add(returnBook);
        this.add(queryBook);
        this.add(readerInfo);
        this.add(showBooks);
        this.add(cancel);
    }
}
