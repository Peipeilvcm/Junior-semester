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
            tableTitle.add("书名");
            tableTitle.add("ISBN");
            tableTitle.add("类型");
            tableTitle.add("价格");
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
		this.setTitle("图书管理");
		this.setResizable(false);
		this.setLocationRelativeTo(null);
		
		this.setBounds(100, 100, 625, 320);
		this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		
		//图书目录表格初始化
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
	    
	  //显示表格
		JScrollPane scrollPane = new JScrollPane();
		scrollPane.setBounds(10, 24 , 600, 225);
		this.getContentPane().add(scrollPane);
		scrollPane.setViewportView(table);
	    
	    this.getContentPane().setLayout(null);
	    
 //下面是功能按钮：
	    
	    //返回键
	    JButton returnButton = new JButton("返回主界面");
		returnButton.addActionListener((e) -> {
			//返回主界面
			dispatchEvent(new WindowEvent(this, WindowEvent.WINDOW_CLOSING));		
		});
		returnButton.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 14));
		returnButton.setBounds(457, 254, 120, 30);
		this.getContentPane().add(returnButton);
		
		//删除选中图书
		JButton delButton = new JButton("删除所选图书");
		delButton.addActionListener((e) -> {
			//删除动作
			delBook();
		});
		delButton.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 14));
		delButton.setBounds(317, 254, 120, 30);
		this.getContentPane().add(delButton);
		
		//编辑选中图书
		JButton editButton = new JButton("编辑选中图书");
		editButton.addActionListener((e) -> {
			//编辑动作
			editBook();
		});
		editButton.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 14));
		editButton.setBounds(177, 254, 120, 30);
		this.getContentPane().add(editButton);
		
		//增加图书
		JButton addButton = new JButton("新增图书");
		addButton.addActionListener((e) -> {
			//编辑动作
			addBook();
		});
		addButton.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 14));
		addButton.setBounds(37, 254, 120, 30);
		this.getContentPane().add(addButton);
		
	}
	
	private void delBook(){
		int selectedRow = table.getSelectedRow();
		if(selectedRow < 0){
			Controller.getInstance().messageBox("未选择要删除的图书", "WARNING");
			return;
		}
		//System.out.println(selectedRow);
		String isbn = (String) table.getValueAt(selectedRow, 0);
		Controller.getInstance().removeBook(isbn);
		Controller.getInstance().messageBox("删除成功！", "SUCCESS");
		table.clearSelection();
	}
	
	private void editBook(){
		int selectedRow = table.getSelectedRow();
		if(selectedRow < 0){
			Controller.getInstance().messageBox("未选择要编辑的图书", "WARNING");
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
