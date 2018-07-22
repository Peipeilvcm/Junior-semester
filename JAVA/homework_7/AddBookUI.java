import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

public class AddBookUI extends JFrame{
	private static final long serialVersionUID = 1L;
	
	private JTextField bookIsbnField;
	private JTextField bookTitleField;
	private JTextField bookPriceField;
	private JComboBox<String> bookTypeCombox;
	
	public AddBookUI(BooksManageUI parent){
		addWindowListener(new WindowAdapter() {
			@Override
			public void windowClosing(WindowEvent e) {
				parent.setEnabled(true);
				//BookCatalog.getInstance().removeObserver(observer);
			}
		});
		
		initializeUI();
		
		
	}
	
	private void initializeUI(){
		
		this.setTitle("图书管理");
		this.setResizable(false);
		this.setLocationRelativeTo(null);
		
		this.setBounds(100, 100, 360, 270);
		this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		
		this.getContentPane().setLayout(null);
		
		JLabel label1 = new JLabel("ISBN号");
		label1.setFont(new Font("Microsoft YaHei UI", Font.BOLD, 15));
		label1.setBounds(30, 35, 65, 25);
		this.getContentPane().add(label1);
		
		bookIsbnField = new JTextField();
		bookIsbnField.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		bookIsbnField.setBounds(100, 35, 215, 25);
		bookIsbnField.setColumns(12);
		this.getContentPane().add(bookIsbnField);
		
		JLabel label2 = new JLabel("图书名称");
		label2.setFont(new Font("Microsoft YaHei UI", Font.BOLD, 15));
		label2.setBounds(30, 70, 60, 25);
		this.getContentPane().add(label2);
		
		bookTitleField = new JTextField();
		bookTitleField.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		bookTitleField.setBounds(100, 70, 215, 25);
		bookTitleField.setColumns(12);
		this.getContentPane().add(bookTitleField);
		
		JLabel label3 = new JLabel("图书种类");
		label3.setFont(new Font("Microsoft YaHei UI", Font.BOLD, 15));
		label3.setBounds(30, 105, 60, 25);
		this.getContentPane().add(label3);
		
		bookTypeCombox = new JComboBox<String>();
		bookTypeCombox.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		bookTypeCombox.setBounds(100, 105, 215, 25);
		bookTypeCombox.setModel(new DefaultComboBoxModel<String>(new String[] {
				"非教材类计算机图书", "教材类图书", "连环画类图书", "养生类图书", "其他"
		}));
		this.getContentPane().add(bookTypeCombox);
		
		JLabel label4 = new JLabel("图书价格");
		label4.setFont(new Font("Microsoft YaHei UI", Font.BOLD, 15));
		label4.setBounds(30, 140, 60, 25);
		this.getContentPane().add(label4);
		
		JLabel label5 = new JLabel("元");
		label5.setFont(new Font("Microsoft YaHei UI", Font.BOLD, 15));
		label5.setBounds(290, 140, 18, 25);
		this.getContentPane().add(label5);
		
		bookPriceField = new JTextField();
		bookPriceField.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		bookPriceField.setBounds(100, 140, 185, 25);
		bookPriceField.setColumns(12);
		this.getContentPane().add(bookPriceField);
		
		//返回键
	    JButton returnButton = new JButton("返回图书管理");
		returnButton.addActionListener((e) -> {
			//关闭窗口
			dispatchEvent(new WindowEvent(this, WindowEvent.WINDOW_CLOSING));		
		});
		returnButton.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 14));
		returnButton.setBounds(195, 180, 120, 30);
		this.getContentPane().add(returnButton);
		
		//确认添加
	    JButton confirmAddButton = new JButton("确认添加图书");
	    confirmAddButton.addActionListener((e) -> {
			//确认添加
			confirmAddBook();
		});
	    confirmAddButton.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 14));
	    confirmAddButton.setBounds(35, 180, 120, 30);
		this.getContentPane().add(confirmAddButton);
		
	}
	
	private void confirmAddBook(){
		String bookTitle = bookTitleField.getText();
		String bookIsbn = bookIsbnField.getText();
		if(bookIsbn.isEmpty() || bookTitle.isEmpty()){
			Controller.getInstance().messageBox("信息填写不完整！请检查", "WARNING");
			return;
		}
		int bookType = bookTypeCombox.getSelectedIndex() + 1;
		float bookPrice;
		try{
			bookPrice = Float.parseFloat(bookPriceField.getText());
		}
		catch(Exception ex){
			Controller.getInstance().messageBox("价格输入错误", "ERROR");
			return;
		}
		
		BookSpecification book = new BookSpecification(bookIsbn, bookTitle, bookPrice, bookType);
		
		if(Controller.getInstance().addBook(book)){
			Controller.getInstance().messageBox("添加新书成功", "SUCCESS");
			bookIsbnField.setText("");
			bookTitleField.setText("");
			bookPriceField.setText("");
		}
		
	}
	
}
