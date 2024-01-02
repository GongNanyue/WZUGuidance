package GUI;

import DataBase.BookDB;
import DataBase.BorrowDB;
import Entity.Book;
import Entity.User;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.ResultSet;

public class BorrowWindow extends JFrame {
    JTextField bookName;
    JButton borrow;
    JButton cancel;
    JLabel borrowNum;
    BookDB bookDB;
    User user;

    public BorrowWindow(User user) {
        this.user = user;
        setLayout(null);
        setTitle("借书界面");
        setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        setBounds(300, 300, 700, 500);
        init();
        setVisible(true);
    }

    void init() {
        bookName = new JTextField();
        borrow = new JButton("借书");
        cancel = new JButton("取消");
        bookDB = new BookDB();

        String borrowNumStr = "您的已借书籍数量为： " + user.Capacity;
        borrowNum = new JLabel(borrowNumStr);

        bookName.setBounds(0, 50, 100, 30);
        borrow.setBounds(0, 100, 100, 30);
        borrowNum.setBounds(300, 100, 200, 30);
        cancel.setBounds(0, 150, 100, 30);

        borrow.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String bookName = BorrowWindow.this.bookName.getText();
                int borrowedBooks = user.Capacity;
                if (borrowedBooks >= user.getMaxBooks()) {
                    JOptionPane.showMessageDialog(null, "借书数量已达上限");
                    return;
                }
                try (ResultSet rs = bookDB.query(bookName)) {
                    if (rs.next()) {
                        Book book = new Book(rs.getInt("book_id"), rs.getString("book_name"),
                                rs.getString("book_type"), rs.getInt("book_num"),
                                rs.getInt("book_price"), rs.getString("book_author"));
                        if (book.bookNum > 0) {
                            JOptionPane.showMessageDialog(null, "借书成功");
                            bookDB.update(book);
                            user.Capacity+=1;
                            new BorrowDB().insert(user,book);

                            String borrowNumStr = "您的已借书籍数量为： " + user.Capacity;
                            borrowNum.setText(borrowNumStr);
                        } else {
                            JOptionPane.showMessageDialog(null, "该书已被借完");
                        }

                    } else {
                        JOptionPane.showMessageDialog(null, "没有该本书");
                    }
                } catch (Exception e1) {
                    e1.printStackTrace();
                }
            }
        });

        cancel.addActionListener(e -> {
            BorrowWindow.this.dispose();
            new MainWindow(user);
        });

        this.add(bookName);
        this.add(borrow);
        this.add(borrowNum);
        this.add(cancel);
    }
}
