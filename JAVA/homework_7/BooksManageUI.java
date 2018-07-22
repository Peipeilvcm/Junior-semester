import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;
import java.util.Vector;

import javax.swing.*;
import javax.swing.table.*;


public class BooksManageUI extends JFrame{
	private static final long serialVersionUID = 1L;
	
	private JTable table;
	private Observer observer;
	
	public BooksManageUI(MainUI parent){
		addWindowListener(new WindowAdapter() {
			@Override
			public void windowClosing(WindowEvent e) {
				parent.setEnabled(true);
				BookCatalog.getInstance().removeObserver(observer);
				//parent.closeShopCartUI();
			}
		});
		initializeUI();
		observer = new BooksMagUIObserver();
		BookCatalog.getInstance().registerObserver(observer);
		observer.update();

	}
	
	class ModelTable extends DefaultTableModel{
		private static final long serialVersionUID = 1L;
		private Vector< ArrayList<String> > tableData;
		private Vector<String> tableTitle;
		
		public ModelTable(){
			tableData = new Vector< ArrayList<String> >();
            tableTitle = new Vector<String>();
            setDataVector(tableData, tableTitle);
            tableTitle.add("����");
            tableTitle.add("ISBN");
            tableTitle.add("����");
            tableTitle.add("�۸�");
		}
		
		public void addBook(BookSpecification book){
			ArrayList<String> line = new ArrayList<String>();
			line.add(book.getIsbn());
			line.add(book.getTitle());
			line.add(book.getTypeName());
			line.add(book.getPrice()+"");
			tableData.add(line);
		}
		
		public String getISDN(int rowIndex){
			ArrayList<String> list = this.tableData.get(rowIndex);
			return list.get(0);
		}
		
		
		public void updateUI(){
			tableData.clear();
			for(BookSpecification book : BookCatalog.getInstance().getBooks()){
				addBook(book);
			}
			table.repaint();
			table.updateUI();
		}
		
		public String getValueAt(int rowIndex, int colIndex){
			ArrayList<String> list = this.tableData.get(rowIndex);
			return list.get(colIndex);
		}
		
		public boolean isCellEditable(int rowIndex, int colIndex){
			return false;
		}
		
	}
	
	class BooksMagUIObserver implements Observer{
		public void update(){
			ModelTable model = (ModelTable) table.getModel();
			model.updateUI();
		}
	}
	
	private void initializeUI(){
		this.setTitle("ͼ�����");
		this.setResizable(false);
		this.setLocationRelativeTo(null);
		
		this.setBounds(100, 100, 625, 320);
		this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		
		//ͼ��Ŀ¼����ʼ��
		table = new JTable();
		table.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		
		table.setModel(new ModelTable());
		table.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		DefaultTableCellRenderer tcr = new DefaultTableCellRenderer();
		tcr.setHorizontalAlignment(SwingConstants.CENTER);
		table.setDefaultRenderer(Object.class, tcr);
		table.getTableHeader().setReorderingAllowed(false);
		table.getTableHeader().setResizingAllowed(false);
	    table.getColumnModel().getColumn(0).setPreferredWidth(100);
	    table.getColumnModel().getColumn(1).setPreferredWidth(100);
	    table.getColumnModel().getColumn(2).setPreferredWidth(100);
	    table.getColumnModel().getColumn(3).setPreferredWidth(20);
	    
	  //��ʾ���
		JScrollPane scrollPane = new JScrollPane();
		scrollPane.setBounds(10, 24 , 600, 225);
		this.getContentPane().add(scrollPane);
		scrollPane.setViewportView(table);
	    
	    this.getContentPane().setLayout(null);
	    
 //�����ǹ��ܰ�ť��
	    
	    //���ؼ�
	    JButton returnButton = new JButton("����������");
		returnButton.addActionListener((e) -> {
			//����������
			dispatchEvent(new WindowEvent(this, WindowEvent.WINDOW_CLOSING));		
		});
		returnButton.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 14));
		returnButton.setBounds(457, 254, 120, 30);
		this.getContentPane().add(returnButton);
		
		//ɾ��ѡ��ͼ��
		JButton delButton = new JButton("ɾ����ѡͼ��");
		delButton.addActionListener((e) -> {
			//ɾ������
			delBook();
		});
		delButton.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 14));
		delButton.setBounds(317, 254, 120, 30);
		this.getContentPane().add(delButton);
		
		//�༭ѡ��ͼ��
		JButton editButton = new JButton("�༭ѡ��ͼ��");
		editButton.addActionListener((e) -> {
			//�༭����
			editBook();
		});
		editButton.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 14));
		editButton.setBounds(177, 254, 120, 30);
		this.getContentPane().add(editButton);
		
		//����ͼ��
		JButton addButton = new JButton("����ͼ��");
		addButton.addActionListener((e) -> {
			//�༭����
			addBook();
		});
		addButton.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 14));
		addButton.setBounds(37, 254, 120, 30);
		this.getContentPane().add(addButton);
		
	}
	
	private void delBook(){
		int selectedRow = table.getSelectedRow();
		if(selectedRow < 0){
			Controller.getInstance().messageBox("δѡ��Ҫɾ����ͼ��", "WARNING");
			return;
		}
		//System.out.println(selectedRow);
		String isbn = (String) table.getValueAt(selectedRow, 0);
		Controller.getInstance().removeBook(isbn);
		Controller.getInstance().messageBox("ɾ���ɹ���", "SUCCESS");
		table.clearSelection();
	}
	
	private void editBook(){
		int selectedRow = table.getSelectedRow();
		if(selectedRow < 0){
			Controller.getInstance().messageBox("δѡ��Ҫ�༭��ͼ��", "WARNING");
			return;
		}
		String isbn = (String) table.getValueAt(selectedRow, 0);
		
		EditBookUI editBookUI = new EditBookUI(this, isbn);
		editBookUI.setVisible(true);
		this.setEnabled(false);
		
	}
	
	private void addBook(){
		AddBookUI addBookUI = new AddBookUI(this);
		addBookUI.setVisible(true);
		this.setEnabled(false);
	}
}
