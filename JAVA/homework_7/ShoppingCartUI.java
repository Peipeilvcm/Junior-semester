import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;
import java.util.Vector;

import javax.swing.*;
import javax.swing.table.*;

public class ShoppingCartUI extends JFrame{
	private static final long serialVersionUID = 1L;
	
	private JTable table;
	private JLabel cost;
	
	private Observer observer;	//观察者	
	
	public ShoppingCartUI(MainUI parent){
		addWindowListener(new WindowAdapter() {
			@Override
			public void windowClosing(WindowEvent e) {
				parent.closeShopCartUI();
			}
		});
		initializeUI();
		observer = new CartObserver();
		Controller.getInstance().getSale().registerObserver(observer);
		
		observer.update();
	}
	
	class CartObserver implements Observer{
		public void update(){
			ModelShopCart model = (ModelShopCart) table.getModel();
			model.updateUI(Controller.getInstance().getSale());
		}
	}
	
	class ModelShopCart extends DefaultTableModel{
		private static final long serialVersionUID = 1L;
		private Vector< ArrayList<String> > tableData;
		private Vector<String> tableTitle;
		
		public ModelShopCart(){
			tableData = new Vector< ArrayList<String> >();
            tableTitle = new Vector<String>();
            setDataVector(tableData, tableTitle);
            tableTitle.add("记录号");
            tableTitle.add("ISBN");
            tableTitle.add("书名");
            tableTitle.add("数量");
            tableTitle.add("各项总额");
		}
		
		public void addItem(SaleLineItem item){
			ArrayList<String> line = new ArrayList<String>();
			line.add(""+item.getSaleItemNum());
			line.add(item.getProdSpec().getIsbn());
			line.add(item.getProdSpec().getTitle());
			line.add(""+item.getCopies());
			line.add(""+item.getSubTotal());
			tableData.add(line);
		}
		
		public void updateUI(Sale sale){
			tableData.clear();
			//double total = 0;
			for(SaleLineItem item : sale.getItems()){
				addItem(item);
				//total += item.getSubTotal();
			}
			cost.setText(String.format("总价: %.2f 元", sale.getTotal()));	
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
	
	private void initializeUI(){
		this.setTitle("购物车");
		this.setResizable(false);
		this.setLocationRelativeTo(null);
		this.setBounds(100, 100, 555, 390);
		this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		
		JLabel label = new JLabel("我的购物车");
		label.setFont(new Font("Microsoft YaHei UI", Font.BOLD, 24));
		label.setBounds(220, 22, 150, 33);
		this.getContentPane().add(label);

		
		//图书目录表格初始化
		table = new JTable();
		table.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		
		table.setModel(new ModelShopCart());
		table.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		DefaultTableCellRenderer tcr = new DefaultTableCellRenderer();
		tcr.setHorizontalAlignment(SwingConstants.CENTER);
		table.setDefaultRenderer(Object.class, tcr);
		table.getTableHeader().setReorderingAllowed(false);
		table.getTableHeader().setResizingAllowed(false);
	    table.getColumnModel().getColumn(0).setPreferredWidth(10);
	    table.getColumnModel().getColumn(1).setPreferredWidth(120);
	    table.getColumnModel().getColumn(2).setPreferredWidth(120);
	    table.getColumnModel().getColumn(3).setPreferredWidth(20);
	    table.getColumnModel().getColumn(4).setPreferredWidth(20);
	    
	    JScrollPane scrollPane = new JScrollPane();
		scrollPane.setBounds(10, 70 , 530, 230);
		this.getContentPane().add(scrollPane);
		scrollPane.setViewportView(table);
		
		this.getContentPane().setLayout(null);
	    
	    //删除选中记录
	    JButton delItemButton = new JButton("删除选中记录");
		delItemButton.addActionListener((e) -> {
			//删除动作
			delSaleLineItem();
		});
		delItemButton.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 14));
		delItemButton.setBounds(290, 310, 120, 30);
		this.getContentPane().add(delItemButton);
		
		//关闭购物车
		JButton closeButton = new JButton("关闭购物车");
		closeButton.addActionListener((e) -> {
			closeShopCart();
		});
		closeButton.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		closeButton.setBounds(420, 310, 120, 30);
		this.getContentPane().add(closeButton);
		
		cost = new JLabel("总价: 0.00 元");
		cost.setFont(new Font("Microsoft YaHei UI", Font.BOLD, 15));
		cost.setBounds(20, 306, 120, 35);
		this.getContentPane().add(cost);
	}
	
	//关闭购物车动作
	public void closeShopCart(){
		dispatchEvent(new WindowEvent(this, WindowEvent.WINDOW_CLOSING));
	}
	
	private void delSaleLineItem(){
		int selectedRow = table.getSelectedRow();
		if(selectedRow < 0){
			Controller.getInstance().messageBox("请选择一项纪录以删除！", "WARNING");
			return;
		}
		int saleLineNum = -1;
		saleLineNum = Integer.parseInt((String)table.getValueAt(selectedRow, 0));
		
		if(Controller.getInstance().removeSaleItem(saleLineNum)){
			Controller.getInstance().messageBox("移除纪录成功", "SUCCESS");
			Controller.getInstance().updateSale();
			table.clearSelection();
		}
		else{
			Controller.getInstance().messageBox("删除失败！", "ERROR");
		}
		
	}
	
}
