
import javax.swing.*;
import javax.swing.event.*;
import javax.swing.table.*;

import java.awt.*;
import java.util.ArrayList;
import java.util.Vector;

public class MainUI extends JFrame{
	private static final long serialVersionUID = 1L;
	
	private JTable table;			//显示图书目录
	private Observer observer;		
	private ShoppingCartUI shopCartUI;	//购物车目录
	private JSpinner spinner;
	private JLabel bookSelected;
	
	public MainUI(){
		initializeUI();
		observer = new MainUIObserver();
		BookCatalog.getInstance().registerObserver(observer);
		//是否进行初始化
		shopCartUI = null;
		if(JOptionPane.showConfirmDialog(null, "请选择是否先自动生成图书与策略",
				"图书电商",JOptionPane.YES_NO_OPTION) == JOptionPane.YES_OPTION){
			Controller.getInstance().initInfo();
			openShopCartUI();
			observer.update();
		}
		//BookCatalog.getInstance().update();
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
	
	class MainUIObserver implements Observer{
		public void update(){
			ModelTable model = (ModelTable) table.getModel();
			model.updateUI();
		}
	}
	
	private void openShopCartUI(){
		if(shopCartUI == null ){
			shopCartUI = new ShoppingCartUI(this);
			shopCartUI.setVisible(true);
		}
	}
	
	public void closeShopCartUI(){
		shopCartUI = null;
	}
	
	private void initializeUI(){
		
		this.setTitle("图书电商购物平台");
		this.setResizable(false);
		this.setLocationRelativeTo(null);
		
		this.setBounds(100, 100, 625, 400);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		JMenuBar menuBar = new JMenuBar();
		this.setJMenuBar(menuBar);
		
		//一级菜单1,管理
		JMenu manage = new JMenu("管理");
		manage.setFont(new Font("Microsoft YaHei UI", Font.BOLD, 15));
		menuBar.add(manage);
		
		//二级菜单1-1,图书管理
		JMenuItem bookManage = new JMenuItem("图书管理");
		bookManage.addActionListener((e) -> {
			//打开图书管理
			BooksManageUI booksUI = new BooksManageUI(this);
			booksUI.setVisible(true);
			this.setEnabled(false);
		});
		manage.add(bookManage);
		
		//二级菜单1-2,策略管理
		JMenuItem strategyManage = new JMenuItem("策略管理");
		strategyManage.addActionListener((e) -> {
			//打开策略管理
			StrategiesUI strategiesUI = new StrategiesUI(this);
			strategiesUI.setVisible(true);
			this.setEnabled(false);
			
		});
		manage.add(strategyManage);
		
		//一级菜单2,我的购物车
		JMenu shopCart = new JMenu("购物车");
		shopCart.setFont(new Font("Microsoft YaHei UI", Font.BOLD, 15));
		menuBar.add(shopCart);
		
		//二级菜单2-1,清空购物车
		JMenuItem clearCart = new JMenuItem("清空购物车");
		clearCart.addActionListener((e) -> {
			if(JOptionPane.showConfirmDialog(null, "是否真的清空购物车？请三思！",
					"clearCart",JOptionPane.YES_NO_OPTION) == JOptionPane.YES_OPTION){
				Controller.getInstance().clearShopCart();
				Controller.getInstance().messageBox("购物车已经清空", "Right");
			}
		});
		shopCart.add(clearCart);
		
		bookSelected = new JLabel("您未选中任何图书");
		bookSelected.setFont(new Font("Microsoft YaHei UI", Font.BOLD, 15));
		bookSelected.setBounds(10, 260, 370, 30);
		this.getContentPane().add(bookSelected);
		
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
	    
	    table.getSelectionModel().addListSelectionListener(new ListSelectionListener(){
            public void valueChanged(ListSelectionEvent e) {
            	boolean bl=e.getValueIsAdjusting();
            	if(!bl){
            		int selectedRow = table.getSelectedRow();
            		if (selectedRow < 0){
            			bookSelected.setText("未选中任何图书");
            		}else {
	            		bookSelected.setText("选中图书：" +
	            			table.getModel().getValueAt(selectedRow, 0) + " 《" +
	            			table.getModel().getValueAt(selectedRow, 1) + "》");
            		}
            	}                
            }
        });
	    
	  //显示表格
		JScrollPane scrollPane = new JScrollPane();
		scrollPane.setBounds(10, 24 , 600, 225);
		this.getContentPane().add(scrollPane);
		scrollPane.setViewportView(table);
	    
	    this.getContentPane().setLayout(null);
	    
	    JLabel label1 = new JLabel("购买数量");
		label1.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		label1.setBounds(470, 260, 65, 30);
		this.getContentPane().add(label1);
		
		JLabel label2 = new JLabel("本");
		label2.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		label2.setBounds(599, 268, 17, 15);
		this.getContentPane().add(label2);
		
		spinner = new JSpinner();
		spinner.setModel(new SpinnerNumberModel(new Integer(0), new Integer(0), null, new Integer(1)));
		spinner.setBounds(541, 260, 54, 30);
		this.getContentPane().add(spinner);
		
		JButton addToCartButton = new JButton("加入购物车");
		addToCartButton.addActionListener((e) -> {
			//打开添加图书至购物车
			addToShopCart();
			
		});
		addToCartButton.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		addToCartButton.setBounds(350, 301, 120, 30);
		this.getContentPane().add(addToCartButton);
		
		JButton watchCartButton = new JButton("查看购物车");
		watchCartButton.addActionListener((e) -> {
			//打开购物车对话框
			openShopCartUI();
		});
		watchCartButton.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		watchCartButton.setBounds(488, 301, 120, 30);
		this.getContentPane().add(watchCartButton);
		
	}
	
	private void addToShopCart(){
		int selectedRow = table.getSelectedRow();
		int copies = 0;
		copies = (int) spinner.getValue();
		if(selectedRow < 0){
			Controller.getInstance().messageBox("请选择一样图书！", "ERROR");
			return;
		}
		if(copies <= 0){
			Controller.getInstance().messageBox("数量设置错误！", "ERROR");
			return;
		}
		
		String isbn = (String) table.getValueAt(selectedRow, 0);
		
		if(Controller.getInstance().addSaleItem(isbn, copies)){
			Controller.getInstance().messageBox("添加 "+copies+"本 《"+
					BookCatalog.getInstance().getBook(isbn).getTitle()
					+"》", "SUCCESS");
			spinner.setValue(0);
		}
		else{
			Controller.getInstance().messageBox("添加错误", "SUCCESS");
		}
	}
	
	
	
}
