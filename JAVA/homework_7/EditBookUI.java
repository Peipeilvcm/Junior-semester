import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

public class EditBookUI extends JFrame{
	private static final long serialVersionUID = 1L;
	
	private JTextField bookIsbnField;
	private JTextField bookTitleField;
	private JTextField bookPriceField;
	private JComboBox<String> bookTypeCombox;
	
	public EditBookUI(BooksManageUI parent, String isbn){
		addWindowListener(new WindowAdapter() {
			@Override
			public void windowClosing(WindowEvent e) {
				parent.setEnabled(true);
				//BookCatalog.getInstance().removeObserver(observer);
			}
		});
		
		initializeUI(isbn);
	}
	
	private void initializeUI(String isbn){
		
		this.setTitle("ͼ����Ϣ�޸�");
		this.setResizable(false);
		this.setLocationRelativeTo(null);
		
		this.setBounds(100, 100, 360, 270);
		this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		
		this.getContentPane().setLayout(null);
		
		BookSpecification book = Controller.getInstance().getBook(isbn);
		
		JLabel label1 = new JLabel("ISBN��");
		label1.setFont(new Font("Microsoft YaHei UI", Font.BOLD, 15));
		label1.setBounds(30, 35, 65, 25);
		this.getContentPane().add(label1);
		
		bookIsbnField = new JTextField();
		bookIsbnField.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		bookIsbnField.setBounds(100, 35, 215, 25);
		bookIsbnField.setColumns(12);
		bookIsbnField.setText(isbn);
		bookIsbnField.setEditable(false);		//���ɱ༭
		this.getContentPane().add(bookIsbnField);
		
		JLabel label2 = new JLabel("ͼ������");
		label2.setFont(new Font("Microsoft YaHei UI", Font.BOLD, 15));
		label2.setBounds(30, 70, 60, 25);
		this.getContentPane().add(label2);
		
		bookTitleField = new JTextField();
		bookTitleField.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		bookTitleField.setBounds(100, 70, 215, 25);
		bookTitleField.setColumns(12);
		bookTitleField.setText(book.getTitle());
		this.getContentPane().add(bookTitleField);
		
		JLabel label3 = new JLabel("ͼ������");
		label3.setFont(new Font("Microsoft YaHei UI", Font.BOLD, 15));
		label3.setBounds(30, 105, 60, 25);
		this.getContentPane().add(label3);
		
		bookTypeCombox = new JComboBox<String>();
		bookTypeCombox.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		bookTypeCombox.setBounds(100, 105, 215, 25);
		bookTypeCombox.setModel(new DefaultComboBoxModel<String>(new String[] {
				"�ǽ̲�������ͼ��", "�̲���ͼ��", "��������ͼ��", "������ͼ��", "����"
		}));
		bookTypeCombox.setSelectedIndex(book.getType()-1);
		this.getContentPane().add(bookTypeCombox);
		
		JLabel label4 = new JLabel("ͼ��۸�");
		label4.setFont(new Font("Microsoft YaHei UI", Font.BOLD, 15));
		label4.setBounds(30, 140, 60, 25);
		this.getContentPane().add(label4);
		
		JLabel label5 = new JLabel("Ԫ");
		label5.setFont(new Font("Microsoft YaHei UI", Font.BOLD, 15));
		label5.setBounds(290, 140, 18, 25);
		this.getContentPane().add(label5);
		
		bookPriceField = new JTextField();
		bookPriceField.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		bookPriceField.setBounds(100, 140, 185, 25);
		bookPriceField.setColumns(12);
		bookPriceField.setText(book.getPrice()+"");
		this.getContentPane().add(bookPriceField);
		
		//���ؼ�
	    JButton returnButton = new JButton("����ͼ�����");
		returnButton.addActionListener((e) -> {
			//�رմ���
			dispatchEvent(new WindowEvent(this, WindowEvent.WINDOW_CLOSING));		
		});
		returnButton.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 14));
		returnButton.setBounds(195, 180, 120, 30);
		this.getContentPane().add(returnButton);
		
		//ȷ�����
	    JButton confirmAddButton = new JButton("ȷ���޸���Ϣ");
	    confirmAddButton.addActionListener((e) -> {
			//ȷ�����
			confirmEditBook();
		});
	    confirmAddButton.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 14));
	    confirmAddButton.setBounds(35, 180, 120, 30);
		this.getContentPane().add(confirmAddButton);
		
	}
	
	private void confirmEditBook(){
		String bookTitle = bookTitleField.getText();
		String bookIsbn = bookIsbnField.getText();
		if(bookTitle.isEmpty()){
			Controller.getInstance().messageBox("��Ϣ��д������������", "WARNING");
			return;
		}
		int bookType = bookTypeCombox.getSelectedIndex() + 1;
		float bookPrice;
		try{
			bookPrice = Float.parseFloat(bookPriceField.getText());
		}
		catch(Exception ex){
			Controller.getInstance().messageBox("�۸��������", "ERROR");
			return;
		}
		
		BookSpecification book = new BookSpecification(bookIsbn, bookTitle, bookPrice, bookType);
		
		Controller.getInstance().editBook(book);
		
		Controller.getInstance().messageBox("�ɹ��޸���Ϣ", "SUCCESS");
		
	}
	
}
